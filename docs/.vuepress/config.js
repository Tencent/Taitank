const auto = require("./config-auto");

module.exports = {
    title: "Titank Engine",
    description: "Tencent Titank Layout Engine",
    head: [
        ['link', { rel: 'icon', href: '/favicon.ico' }]
    ],
    markdown: {
        lineNumbers: false,
        toc: {
            includeLevel: [2, 3, 4],
            markerPattern: /^\[toc\]/im
        },
        anchor: { permalink: true, permalinkBefore: true, permalinkSymbol: '#' },
        extendMarkdown: md => {
            md.use(require("markdown-it-disable-url-encode"));
        }
    },
    base: "/Taitank/",
    dest: "./docs/.vuepress/dist",
    themeConfig: {
        logo: "/logo_notitle.svg",
        nav: [
            { text: "Documentation", link: "/documentation/overview.html" },
            { text: "Playground", link: "/playground/" },
        ],
        sidebarDepth: 1,
        sidebar: {
            "/": [
                {
                    title: "Why Titank",
                    path: "/"
                },
                {
                    title: "Documentation",
                    collapsable: false,
                    children: [
                        "/documentation/overview.md",
                        "/documentation/properties.md",
                        "/documentation/examples.md",
                        "/documentation/contributing.md"
                    ]
                }
            ]
        },
        repo: "https://github.com/ilikethese/Taitank",
        repoLabel: "GitHub"
    },
    plugins: [
        ["vuepress-plugin-element-tabs"],
        ['vuepress-plugin-smooth-scroll'],
        [
            "container",
            {
                type: "code",
                before: '<pre class="code-container"><code>',
                after: "</code></pre>"
            }
        ],
        [
            "container",
            {
                type: "card-container",
                before: '<div class="card-container">',
                after: "</div>"
            }
        ],
        [
            "container",
            {
                type: "card",
                before: title =>
                    `<div class="card-warp"><div class="card"><p class="title">${title}</p>`,
                after: "</div></div>"
            }
        ],
        [
            "container",
            {
                type: "left",
                before: title => `<div class="left" style="float:left">`,
                after: "</div>"
            }
        ],
        [
            "container",
            {
                type: "right",
                before: title => `<div class="right" style="float:right">`,
                after: "</div>"
            }
        ],
        [
            "mermaidjs",
            {
                theme: "forest",
                fontFamily:
                    '-apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Oxygen, Ubuntu, Cantarell, "Fira Sans", "Droid Sans", "Helvetica Neue", sans-serif;',
                themeCSS: `
                    .node path{fill:#3eaf7c;stroke: #487343;}
                    .node.default .label{color:#fff}
                    .node rect,.node polygon,.node circle{fill:#3eaf7c;stroke: transparent;}

                    .cluster rect{fill: #a1a4a730;stroke: transparent;}
                    .cluster .label{color:#2c3e50;font-weight: 600;}

                    .edgeLabel {background: #fff;padding:0.5em}
                    .edgeLabel rect{opacity: 0;}

                    .note{fill:#fff7d3; stroke: transparent;}

                    .actor{stroke: none;fill: #3eae7c;rx:6;ry:6}
                    text.actor{fill: #fff;stroke: none;font-weight: 600;}

                    .messageLine1{stroke-dasharray: '8, 3';}

                    .labelBox {stroke: none;fill: #6fa8dc;}
                    .labelText {fill: #fff;stroke: none;}
                    .nodeLabel {color: #fff}
                    .cluster .nodeLabel {color: #000}
                    .loopLine {stroke: #6fa8dc;}
                `,
                sequence: {
                    diagramMarginX: 0,
                    messageMargin: 40,
                    actorMargin: 20,
                    width: 150,
                    height: 50
                },
                flowchart: {
                    width: "100%",
                    nodeSpacing: 10,
                    rankSpacing: 50,
                    curve: "basis"
                }
            }
        ],
        // [require("./plugins/kityminder/index.js")]
    ]
};