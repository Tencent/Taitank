// @ts-check

import Loading from "./Loading.vue";

const Kityminder = {
    name: "Kityminder",
    props: {
        id: {
            type: String,
            required: true
        },
        graph: {
            type: String,
            required: true
        }
    },
    data() {
        return {
            isLoading: true,
            minder: undefined,
            height: "600px"
        };
    },
    render(h) {
        return h(
            "div",
            {
                ref: "outter",
                class: "minder-container",
                style: {
                    height: this.height,
                    position: "relative",
                    borderRadius: "6px"
                }
            },
            [
                h("Loading", { props: { show: this.isLoading } }),
                h("div", {
                    ref: "minder-container",
                    style: { height: this.height }
                })
            ]
        );
    },
    async mounted() {
        await import("kity");
        await import("kityminder-core/dist/kityminder.core.js");
        try {
            const SETTING_REG = /^%(?<setting>.*)/g;

            const settings = [...this.graph.matchAll(SETTING_REG)].map(i =>
                JSON.parse(i.groups.setting)
            );

            // console.log(this.graph, settings);

            if (settings[0].height !== undefined)
                this.height = settings[0].height;
        } catch (e) {
            console.warn("脑图配置解析失败：");
            console.warn(e);
        }
        var minder = new kityminder.Minder({
            renderTo: this.$refs["minder-container"]
        });

        minder.importData("markdown", this.graph);
        await sleep(100);

        // 需要初始化之后才能设置主题。。。。
        minder.useTheme("fresh-green-compat");
        await sleep(50);

        // 设置居中
        minder.execCommand("camera", 0);
        await sleep(210);

        this.isLoading = false;

        this.minder = minder;
    },
    components: {
        Loading
    }
};

async function sleep(delay) {
    return new Promise(resolve => {
        setTimeout(resolve, delay);
    });
}

export default ({ Vue }) => {
    Vue.component("Kityminder", Kityminder);
};
