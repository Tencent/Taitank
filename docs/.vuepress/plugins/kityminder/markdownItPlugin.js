// Inspired by https://github.com/ulivz/vuepress-plugin-flowchart

const { hash } = require("@vuepress/shared-utils");

module.exports = function minderPlugin(md, options = {}) {
    // Handle ```minder blocks
    const fence = md.renderer.rules.fence;
    md.renderer.rules.fence = (...args) => {
        const [tokens, idx] = args;
        const { info } = tokens[idx];
        if (info.trim(" ") === "kityminder") {
            return minderRender(tokens, idx);
        }
        const rawCode = fence(...args);
        return `${rawCode}`;
    };

    // Handle <minder> blocks
    options = options || {};
    const openMarker = options.openMarker || "<kityminder"; // Not ending with '>' to allow attributes
    const openChar = openMarker.charCodeAt(0);
    const closeMarker = options.closeMarker || "</kityminder>";
    const closeChar = closeMarker.charCodeAt(0);

    // Takes the context of the parsed section and turns in into a Kityminder component
    function minderRender(tokens, idx, options, env, self) {
        const token = tokens[idx];
        const key = `kityminder${hash(idx)}`;
        const { content } = token;
        md.$dataBlock[key] = content;
        return `<Kityminder id="${key}" :graph="$dataBlock.${key}"></Kityminder>`;
    }

    // Finds minder sections in the Markdown and creates context
    function minderReplacer(state, startLine, endLine, silent) {
        let nextLine;
        let i;
        let autoClosed = false;
        let start = state.bMarks[startLine] + state.tShift[startLine];
        let max = state.eMarks[startLine];

        // Check out the first character quickly,
        // this should filter out most of non-uml blocks
        if (openChar !== state.src.charCodeAt(start)) {
            return false;
        }

        // Check out the rest of the marker string
        for (i = 0; i < openMarker.length; ++i) {
            if (openMarker[i] !== state.src[start + i].toLowerCase()) {
                return false;
            }
        }

        const markup = state.src.slice(start, start + i);
        const params = state.src.slice(start + i, max);

        // Since start is found, we can report success here in validation mode
        if (silent) {
            return true;
        }

        // Search for the end of the block
        nextLine = startLine;

        for (;;) {
            nextLine++;
            if (nextLine >= endLine) {
                // unclosed block should be autoclosed by end of document.
                // also block seems to be autoclosed by end of parent
                break;
            }

            start = state.bMarks[nextLine] + state.tShift[nextLine];
            max = state.eMarks[nextLine];

            if (start < max && state.sCount[nextLine] < state.blkIndent) {
                // non-empty line with negative indent should stop the list:
                // - ```
                //  test
                break;
            }

            if (closeChar !== state.src.charCodeAt(start)) {
                // didn't find the closing fence
                continue;
            }

            if (state.sCount[nextLine] > state.sCount[startLine]) {
                // closing fence should not be indented with respect of opening fence
                continue;
            }

            let closeMarkerMatched = true;
            for (i = 0; i < closeMarker.length; ++i) {
                if (closeMarker[i] !== state.src[start + i].toLowerCase()) {
                    closeMarkerMatched = false;
                    break;
                }
            }

            if (!closeMarkerMatched) {
                continue;
            }

            // make sure tail has spaces only
            if (state.skipSpaces(start + i) < max) {
                continue;
            }

            // found!
            autoClosed = true;
            break;
        }

        const contents = state.src
            .split("\n")
            .slice(startLine + 1, nextLine)
            .join("\n");

        const token = state.push("kityminder", "fence", 0);
        token.block = true;
        token.info = params;
        token.content = contents;
        token.map = [startLine, nextLine];
        token.markup = markup;

        state.line = nextLine + (autoClosed ? 1 : 0);

        return true;
    }

    // See https://markdown-it.github.io/markdown-it/#Ruler.before
    md.block.ruler.before("fence", "kityminder", minderReplacer, {
        alt: ["paragraph", "reference", "blockquote", "list"]
    });

    md.renderer.rules.minder = minderRender;
};
