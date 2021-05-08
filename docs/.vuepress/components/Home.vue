<!--<template>-->
<!--    <div>-->
<!--      <div class="nav">-->
<!--        <div class="nav-logo"></div>-->
<!--        <div class="nav-icon" @click="isMenuOpen = true"></div>-->
<!--        <div class="nav-menu" :class="{active: isMenuOpen}">-->
<!--          <div class="nav-menu__mask" @click="isMenuOpen = false"></div>-->
<!--          <div class="nav-menu__list">-->
<!--            <a class="nav-menu__item active">首页</a>-->
<!--            <a-->
<!--              class="nav-menu__item"-->
<!--              href="/quick-start/install_raft.html"-->
<!--            >快速上手</a>-->
<!--            <a-->
<!--              class="nav-menu__item"-->
<!--              href="/guide/"-->
<!--            >使用指南</a>-->
<!--            <a-->
<!--              class="nav-menu__item"-->
<!--              href="http://market.raft.oa.com/"-->
<!--              target="_blank"-->
<!--            >组件市场</a>-->
<!--            <a-->
<!--              class="nav-menu__item"-->
<!--              href="https://iwiki.woa.com/pages/viewpage.action?pageId=359787913"-->
<!--              target="_blank"-->
<!--            >徽章</a>-->
<!--            <a-->
<!--              class="nav-menu__item"-->
<!--              href="https://git.code.oa.com/raft/docs"-->
<!--              target="_blank"-->
<!--            >工蜂</a>-->
<!--          </div>-->
<!--        </div>-->
<!--      </div>-->
<!--      <div class="part-show" :class="classType">-->
<!--        <div-->
<!--          :class="`part-show-item part-show-${item}`"-->
<!--          v-for="(item, index) in animationList"-->
<!--        >-->
<!--          <div class="show-title"></div>-->
<!--          <div class="show-circle-big"></div>-->
<!--          <div class="show-pic"></div>-->
<!--          <div class="show-text"></div>-->
<!--          <div class="show-rect"></div>-->
<!--          <div class="show-circle-1"></div>-->
<!--          <div class="show-circle-2"></div>-->
<!--          <div class="show-phone"></div>-->
<!--        </div>-->
<!--      </div>-->
<!--      <div class="contain-main">  -->
<!--        <div class="part-container with-bg">-->
<!--          <div class="content-part">-->
<!--            <h3 class="part-left__title">腾讯轻舟</h3>-->
<!--            <p class="content-part__desc">腾讯轻舟平台(RAFT，Rapid Application Framework of Tencent)，是一个提供高品质组件和标准化集成工具为一体的组件治理平台，由PCG各部门中开发人员发起共建。其致力于形成“端云一体，开箱即用”的组件标准化体系；建立组件共建与共用的协同秩序；并最终建成机制完善且有市场活力的组件生态。</p>-->
<!--            <a class="part-left__btn" href="./quick-start/install_raft.html">快速开始</a>-->
<!--          </div>-->
<!--        </div> -->
<!--        <div class="part-container">-->
<!--          <div class="feature-item__wrap">-->
<!--            <div class="feature-item">-->
<!--              <i class="feature-item__icon cloud"></i>-->
<!--              <h3 class="feature-item__title">开箱即用</h3>-->
<!--              <p class="feature-item__desc">RAFT组件市场以统一标准的前、后端组件依赖描述为牵引，通过CLI工具打通实现组件一键自动安装、后台组件自动部署能力。结合终端RAFT IoC框架，让组件集成达到组件端云一体，开箱即用的清爽体验。</p>-->
<!--            </div>-->
<!--            <div class="feature-item">-->
<!--              <i class="feature-item__icon safe"></i>-->
<!--              <h3 class="feature-item__title">高品质精品化</h3>-->
<!--              <p class="feature-item__desc">RAFT组件市场中每个组件都经过了严苛的上架流程层层检查，以及人工审核体验，组件更易懂易复用。通过对组件通用质量监控、组件SLA治理，让组件运行质量更有保障。</p>-->
<!--            </div>-->
<!--            <div class="feature-item">-->
<!--              <i class="feature-item__icon fast"></i>-->
<!--              <h3 class="feature-item__title">协同可持续</h3>-->
<!--              <p class="feature-item__desc">组件市场提供的组件协同社区能力，搭建了组件消费者和开发者之间交流的桥梁，让组件能在社区中不断成长完善。平台组件回源协同监控、需求响应周期监控等多方位监控给组件可持续性维护提供有力支撑。</p>-->
<!--            </div>-->
<!--          </div>-->
<!--        </div>-->
<!--        <div class="part-container">-->
<!--          <div class="part-flex">-->
<!--            <div class="part-left">-->
<!--              <h3 class="part-left__title">组件市场</h3>-->
<!--              <p class="part-left__desc">RAFT 组件市场精选了腾讯各领域近百款优质组件，助力新业务快速成型。组件市场提供了组件的全方位评价，可交互式预览运行效果。组件的依赖关系、开源协议、API 文档等一目了然，引入码客与工蜂，连通开发者与用户。随着组件数量与日俱增，我们对质量的要求也只会更高。</p>-->
<!--            </div>-->
<!--            <div class="part-image">-->
<!--              <img class="market-image" src="../images/market.png" alt="">-->
<!--            </div>-->
<!--          </div>-->
<!--        </div>-->
<!--        <div class="part-container">-->
<!--          <div class="part-flex"> -->
<!--            <div class="part-left">-->
<!--              <h3 class="part-left__title">他们都在使用 RAFT</h3>-->
<!--            </div>-->
<!--            <div class="part-logo">-->
<!--              <div class="logo-item" v-for="(item, index) in logoList"-->
<!--                :key="index">-->
<!--                <div-->
<!--                class="logo-img"-->
<!--                :style="`background-image: url(${item.imgUrl})`"-->
<!--              ></div>-->
<!--              <div>{{item.name}}</div>-->
<!--              </div>-->
<!--            </div>-->
<!--          </div>-->
<!--        </div>-->
<!--        <div class="part-container with-bg">-->
<!--          <div class="content-part">-->
<!--            <h4 class="part-left__title">立刻体验腾讯轻舟</h4>-->
<!--            <p class="part-left__desc">它不仅免费，而且开源</p>-->
<!--            <a class="part-left__btn" href="./quick-start/install_raft.html">快速开始</a>-->
<!--          </div>-->
<!--        </div>-->
<!--        <div class="part-container with-bg">-->
<!--          <div class="content-part">-->
<!--            <h4 class="part-left__title">贡献者</h4>-->
<!--            <p class="part-left__desc">按英文名首字母排序，如果遇到任何问题，可以联系他们进行反馈</p>-->
<!--            <div class="part-logo">-->
<!--              <div class="logo-item" v-for="(item, index) in developers"-->
<!--                :key="index">-->
<!--                <div-->
<!--                class="avatar-img"-->
<!--                :style="`background-image: url(${getAvatar(item)})`"-->
<!--              ></div>-->
<!--              <div>{{item}}</div>-->
<!--              </div>-->
<!--            </div>-->
<!--          </div>-->
<!--        </div>-->
<!--      </div>-->

<!--      <div class="part-footer">-->
<!--        <div class="footer-text">©2020 RAFT</div>-->
<!--        <div class="footer-divider"></div>-->
<!--        <a href="https://git.woa.com/raft/docs" class="footer-text">Git</a>-->
<!--        <a href="https://git.woa.com/raft/docs/issues" class="footer-text">Issue</a>-->
<!--      </div>-->
<!--    </div>-->
<!--</template>-->
<!--<script>-->
<!--const getRootFontSize = (width) =>{-->
<!--  return width > 1200 ? 'font-size: 1200px;' : 'font-size: 100vw;';-->
<!--};-->
<!--export default {-->
<!--  data() {-->
<!--    return {-->
<!--      logoList: [-->
<!--        {-->
<!--          imgUrl: 'https://pag.io/img/qq.png',-->
<!--          name: 'QQ',-->
<!--        },-->
<!--        {-->
<!--          imgUrl: 'https://pag.io/img/tencentvideo.jpg',-->
<!--          name: '腾讯视频',-->
<!--        },-->
<!--        {-->
<!--          imgUrl: 'https://pag.io/img/now.png',-->
<!--          name: 'NOW直播',-->
<!--        },-->
<!--        {-->
<!--          imgUrl: 'https://pag.io/img/weishi.png',-->
<!--          name: '微视',-->
<!--        },-->
<!--        {-->
<!--          imgUrl: 'https://qpic.url.cn/feeds_pic/PiajxSqBRaEJagsYBTibBh6myFcwNpARPh6uk9RQnxaGttcKhuBRE3LQ/',-->
<!--          name: '腾讯新闻',-->
<!--        },-->
<!--        {-->
<!--          imgUrl: 'https://pag.io/img/bodongxingqiu.png',-->
<!--          name: '波动星球',-->
<!--        },-->
<!--        {-->
<!--          imgUrl: 'https://raft-market-1251316161.cos.ap-guangzhou.myqcloud.com/static/tencentlive.png',-->
<!--          name: '腾讯直播',-->
<!--        }-->
<!--      ],-->
<!--      developerList: ['vinneywang', 'injoeqiu','allenlcheng','andrefeng', 'parikepeng','tomasszhang','wedwang','zuqingxie','yannizhang','bethonxyfu', 'krinceliu',-->
<!--      'cheeqi',  'cliffyan',  'herbertzhou', 'jayceewang',-->
<!--      'jumpingfu', 'junfeng', 'lucaxlu','lukehuang', 'rioyao','shaneyu', 'vivinouyang', 'youkunhuang','andrewychen', 'rebootyang', 'showxdxu','siriushe',-->
<!--      'deviwei'],-->
<!--      classType: '',-->
<!--      count: 1,-->
<!--      animationList: [1, 2, 3, 4],-->
<!--      isMenuOpen: false,-->
<!--      screenWidth: 1200,-->
<!--      htmlDom: '',-->
<!--    }-->
<!--  },-->
<!--  mounted() {-->
<!--    this.htmlDom = document.getElementsByTagName('html')[0];-->
<!--    this.screenWidth = document.documentElement.clientWidth;-->
<!--    this.htmlDom.setAttribute('style', getRootFontSize(this.screenWidth));-->
<!--    window.onresize = () => {-->
<!--      this.screenWidth = document.documentElement.clientWidth;-->
<!--    };-->
<!--    this.animationFn();-->
<!--  },-->
<!--  watch: {-->
<!--    screenWidth(value) {-->
<!--      this.htmlDom.setAttribute('style', getRootFontSize(this.screenWidth));-->
<!--    },-->
<!--  },-->
<!--  computed: {-->
<!--    developers() {-->
<!--      return this.developerList.sort();-->
<!--    }-->
<!--  },-->
<!--  methods: {-->
<!--    getAvatar(user) {-->
<!--      return `http://r.hrc.oa.com/photo/150/${user}.png`;-->
<!--    },-->
<!--    animationFn() {-->
<!--      setTimeout(()=>{-->
<!--        const { count } = this;-->
<!--        this.classType = `animation-${count}`;-->
<!--        if (count === 4) {-->
<!--          this.count = 1;-->
<!--        } else {-->
<!--          this.count += 1;-->
<!--        }-->
<!--        setTimeout(()=>{-->
<!--          this.classType = '';-->
<!--          this.animationFn();-->
<!--        },4000);-->
<!--      }, 1000);-->
<!--    }-->
<!--  },-->
<!--}-->
<!--</script>-->
<!--<style lang="less">-->
<!--// 因二级页面也使用rem，故此页面:root font-size设置改为js动态修改-->
<!--@vw: 1 / 2 / 1300 * 1rem;-->
<!--@color-theme: #1389FD;-->
<!--@color-gradient: linear-gradient(225deg, #32C5FF 0%, #B620E0 51%, #F7B500 100%);-->
<!--@color-gradient-opacity: linear-gradient(225deg, rgba(#32C5FF, 0.2)  10%,rgba(#B620E0, 0.2) 51%,rgba(#F7B500, 0.2)  100%);-->
<!--.contain-main {-->
<!--  padding: 100px 50px 150px;-->
<!--}-->
<!--.nav {-->
<!--  padding: 10px 35px;-->
<!--  display: flex;-->
<!--  align-items: center;-->
<!--  justify-content: space-between;-->
<!--  font-size: 0;-->
<!--  line-height: 0;-->
<!--  .nav-logo {-->
<!--    width: 145px;-->
<!--    height: 36px;-->
<!--    background-image: url("../images/logo.png");-->
<!--    background-size: 100% 100%;-->
<!--    margin-right: 50px;-->
<!--  }-->
<!--  a {-->
<!--    text-decoration: none;-->
<!--  }-->
<!--}-->
<!--.nav-icon {-->
<!--  width: 28px;-->
<!--  height: 28px;-->
<!--  display: none;-->
<!--  background-image: url("../images/menu.png");-->
<!--  background-size: 100% 100%;-->
<!--  margin-right: 20px;-->
<!--}-->
<!--.nav-menu {-->
<!--  &__item {-->
<!--    position: relative;-->
<!--    display: inline-block;-->
<!--    font-size: 14px;-->
<!--    color: #000;-->
<!--    opacity: 0.8;-->
<!--    font-weight: normal;-->
<!--    line-height: 32px;-->
<!--    padding: 0 10px;-->
<!--    border-radius: 16px;-->
<!--    &.active {-->
<!--      font-weight: 600;-->
<!--      opacity: 1;-->
<!--    }-->
<!--    &.active::after {-->
<!--      content: "";-->
<!--      position: absolute;-->
<!--      width: 100%;-->
<!--      height: 100%;-->
<!--      left: 0;-->
<!--      top: 0;-->
<!--      border-radius: 16px;-->
<!--      background-color: @color-theme;-->
<!--      opacity: 0.2;-->
<!--    }-->
<!--    & + & {-->
<!--      margin-left: 10px;-->
<!--    }-->
<!--    &:hover {-->
<!--      cursor: pointer;-->
<!--      opacity: 1;-->
<!--    }-->
<!--  }-->
<!--}-->
<!--.part-container {-->
<!--  font-size: 16px;-->
<!--  margin: 0 auto;-->
<!--  max-width: 1080px;-->
<!--  padding: 50px 80px;-->
<!--  min-height: 250px;-->
<!--  background: #fff;-->
<!--  border: 1px solid rgba(151,151,151,0.1);-->
<!--  box-shadow: 0 0 10px rgba(0,0,0,0.05);-->
<!--  border-radius: 2px;-->
<!--  color: #3D3D3D;-->
<!--  box-sizing: border-box;-->
<!--  &.with-bg {-->
<!--    background-image: url('../images/item-bg.png');-->
<!--    background-repeat: no-repeat;-->
<!--    background-position: right bottom;-->
<!--    background-size: 55% auto;-->
<!--  }-->
<!--  & + & {-->
<!--    margin-top: 50px;-->
<!--  }-->
<!--}-->
<!--.part-flex {-->
<!--  display: flex;-->
<!--  align-items: center;-->
<!--  justify-content: space-around;-->
<!--}-->
<!--.part-image {-->
<!--  margin-left: 25px;-->
<!--  margin-top: 10px;-->
<!--  box-shadow: 0 0 8px rgba(0, 0, 0, 0.1);-->
<!--}-->
<!--.market-image {-->
<!--  display: inline-block;-->
<!--  width: 100%;-->
<!--  max-width: 500px;-->
<!--}-->
<!--.feature-item {-->
<!--  flex: 1;-->
<!--  & + & {-->
<!--    margin-left: 5%;-->
<!--  }-->
<!--  &__wrap {-->
<!--    display: flex;-->
<!--    align-items: flex-start;-->
<!--  }-->
<!--  &__icon {-->
<!--    display: block;-->
<!--    margin: 0 auto;-->
<!--    width: 70px;-->
<!--    height: 70px;-->
<!--    background-color: @color-theme;-->
<!--    border-radius: 100%;-->
<!--    &.cloud {-->
<!--      background-image: url('../images/home/icon-cloud.png');-->
<!--      background-size: 100% 100%;-->
<!--    }-->
<!--    &.safe {-->
<!--      background-image: url('../images/home/icon-safe.png');-->
<!--      background-size: 100% 100%;-->
<!--    }-->
<!--    &.fast {-->
<!--      background-image: url('../images/home/icon-fast.png');-->
<!--      background-size: 100% 100%;-->
<!--    }-->
<!--  }-->
<!--  &__title {-->
<!--    font-size: 18px;-->
<!--    line-height: 25px;-->
<!--    margin-top: 18px 0;-->
<!--    text-align: center;-->
<!--  }-->
<!--  &__desc {-->
<!--    font-size: 14px;-->
<!--    line-height: 20px;-->
<!--    text-align: center;-->
<!--  }-->
<!--}-->
<!--@font-face {-->
<!--  font-family: DINB;-->
<!--  src: url(../images/DIN-B.ttf);-->
<!--}-->
<!--.part-left {-->
<!--  max-width: 420px;-->
<!--  flex: 1;-->
<!--  &__title {-->
<!--    font-size: 50px;-->
<!--    line-height: 60px;-->
<!--    margin: 0;-->
<!--    font-family: DINB;-->
<!--  }-->
<!--  &__desc {-->
<!--    font-size: 16px;-->
<!--    line-height: 28px;-->
<!--    margin: 10px 0 0;-->

<!--  }-->
<!--  &__btn {-->
<!--    display: inline-block;-->
<!--    min-width: 170px;-->
<!--    height: 50px;-->
<!--    border: none;-->
<!--    background-color: @color-theme;-->
<!--    border-radius: 25px;-->
<!--    font-size: 16px;-->
<!--    margin-top: 30px;-->
<!--    outline: none;-->
<!--    color: #fff;-->
<!--    text-align: center;-->
<!--    line-height: 50px;-->
<!--    &:hover {-->
<!--      cursor: pointer;-->
<!--    }-->
<!--  }-->
<!--}-->
<!--.content-part {-->
<!--  text-align: center;-->
<!--  &__title {-->
<!--    font-size: 50px;-->
<!--    line-height: 60px;-->
<!--    margin: 0;-->
<!--    font-family: DINB; -->
<!--  }-->
<!--  &__desc {-->
<!--    font-size: 16px;-->
<!--    line-height: 25px;-->
<!--    margin: 10px 0 0;-->
<!--  }-->
<!--  .part-logo {-->
<!--    margin-top: 20px;-->
<!--    margin-left: 0;-->
<!--    justify-content: center;-->
<!--  }-->
<!--  .logo-item {-->
<!--    display: flex;-->
<!--    align-items: center;-->
<!--    width: 110px;-->
<!--    margin: 10px;-->
<!--  }-->
<!--}-->
<!--.theme-default-content:not(.custom) a:hover {-->
<!--  text-decoration: none;-->
<!--}-->
<!--.feature-item__desc, .part-left__desc {-->
<!--    color: #878b99;-->
<!--}-->
<!--.part-logo {-->
<!--  display: flex;-->
<!--  margin-left: 20px;-->
<!--  margin-top: -10px;-->
<!--  text-align: center;-->
<!--  flex: 1;-->
<!--  flex-wrap: wrap;-->
<!--}-->
<!--.logo-item {-->
<!--  display: flex;-->
<!--  flex-direction: column;-->
<!--  margin: 10px 1.8% 0;-->
<!--}-->
<!--.logo-img {-->
<!--  display: inline-block;-->
<!--  background-size: contain;-->
<!--  background-repeat: no-repeat;-->
<!--  background-position: center center;-->
<!--  width: 80px;-->
<!--  height: 80px;-->
<!--  margin-bottom: 10px;-->
<!--  border-radius: 18px;-->
<!--  box-shadow: 0 0 8px rgba(0,0,0,.1);-->
<!--}-->
<!--.avatar-img {-->
<!--  display: inline-block;-->
<!--  background-size: contain;-->
<!--  background-repeat: no-repeat;-->
<!--  background-position: center center;-->
<!--  width: 80px;-->
<!--  height: 80px;-->
<!--  margin-bottom: 10px;-->
<!--  border-radius: 50%;-->
<!--  box-shadow: 0 0 8px rgba(0,0,0,.1);-->
<!--}-->
<!--.part-footer {-->
<!--  height: 50px;-->
<!--  background-color: @color-theme;-->
<!--  display: flex;-->
<!--  align-items: center;-->
<!--  justify-content: center;-->
<!--}-->
<!--.footer-text {-->
<!--  font-size: 14px;-->
<!--  color: #fff;-->
<!--  opacity: 0.8;-->
<!--  transition: all 0.2s;-->
<!--  & + & {-->
<!--    margin-left: 20px;-->
<!--  }-->
<!--}-->
<!--a.footer-text {-->
<!--  &:hover {-->
<!--    cursor: pointer;-->
<!--    opacity: 1;-->
<!--    text-decoration: underline;-->
<!--  }-->
<!--}-->
<!--.footer-divider {-->
<!--  width: 1px;-->
<!--  height: 6px;-->
<!--  background-color: #fff;-->
<!--  border-radius: 1px;-->
<!--  margin: 3px 20px 0;-->
<!--}-->
<!--.part-show {-->
<!--  margin: 100px auto 0;-->
<!--  position: relative;-->
<!--  height: 1554 * @vw;-->
<!--  z-index: 1;-->
<!--}-->
<!--.part-show-item {-->
<!--  transition: all 1s;-->
<!--}-->
<!--.show-phone {-->
<!--  position: absolute;-->
<!--  top: 50%;-->
<!--  left: 50%;-->
<!--  z-index: 10;-->
<!--  width: 788  * @vw;-->
<!--  height: 1554 * @vw;-->
<!--  transform: translate(-50%, -50%);-->
<!--  background-image: url("../images/phone-bg.png");-->
<!--  background-size: 100% 100%;-->
<!--}-->
<!--.part-show-1 {-->
<!--  .show-title {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 680 * @vw;-->
<!--    z-index: 20;-->
<!--    margin-left: -960 * @vw;-->
<!--    width: 1912 * @vw;-->
<!--    height: 154 * @vw;-->
<!--    background-image: url("../images/home/1/title.png");-->
<!--    background-size: 100% 100%;-->
<!--  }-->
<!--  .show-circle-big {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 400 * @vw;-->
<!--    z-index: 15;-->
<!--    margin-left: -1200 * @vw;-->
<!--    width: 2156 * @vw;-->
<!--    height: 632 * @vw;-->
<!--    background-image: url("../images/home/2/circle.png");-->
<!--    background-size: 100% 100%;-->
<!--  }-->
<!--  .show-pic {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 200 * @vw;-->
<!--    z-index: 8;-->
<!--    margin-left: -100 * @vw;-->
<!--    width: 1400 * @vw;-->
<!--    height: 1200 * @vw;-->
<!--    background-image: url("../images/home/1/pic.jpg");-->
<!--    background-size: 100% 100%;-->
<!--  }-->
<!--  .show-rect {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 1160 * @vw;-->
<!--    z-index: 7;-->
<!--    margin-left: -160 * @vw;-->
<!--    width: 1246 * @vw;-->
<!--    height: 216 * @vw;-->
<!--    background-color: @color-theme;-->
<!--  }-->
<!--  .show-text {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 370 * @vw;-->
<!--    z-index: 6;-->
<!--    margin-left: -1140 * @vw;-->
<!--    width: 530 * @vw;-->
<!--    height: 562 * @vw;-->
<!--    background-image: url("../images/home/1/text.png");-->
<!--    background-size: 100% 100%;-->
<!--  }-->
<!--  .show-circle-1 {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 1140 * @vw;-->
<!--    z-index: 6;-->
<!--    margin-left: -1000 * @vw;-->
<!--    width: 216 * @vw;-->
<!--    height: 216 * @vw;-->
<!--    border-radius: 50%;-->
<!--    background-color: @color-theme;-->
<!--  }-->
<!--  .show-circle-2 {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 80 * @vw;-->
<!--    z-index: 9;-->
<!--    margin-left: 900 * @vw;-->
<!--    width: 248 * @vw;-->
<!--    height: 248 * @vw;-->
<!--    border-radius: 50%;-->
<!--    background-color: @color-theme;-->
<!--  }-->
<!--}-->
<!--.part-show-2 {-->
<!--  .show-title {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 680 * @vw;-->
<!--    z-index: 20;-->
<!--    margin-left: -860 * @vw;-->
<!--    width: 1590 * @vw;-->
<!--    height: 154 * @vw;-->
<!--    background-image: url("../images/home/2/title.png");-->
<!--    background-size: 100% 100%;-->
<!--  }-->
<!--  .show-circle-big {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 400 * @vw;-->
<!--    z-index: 15;-->
<!--    margin-left: -1200 * @vw;-->
<!--    width: 2156 * @vw;-->
<!--    height: 632 * @vw;-->
<!--    background-image: url("../images/home/2/circle.png");-->
<!--    background-size: 100% 100%;-->
<!--  }-->
<!--  .show-pic {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 180 * @vw;-->
<!--    z-index: 8;-->
<!--    margin-left: -1240 * @vw;-->
<!--    width: 1400 * @vw;-->
<!--    height: 1200 * @vw;-->
<!--    background-image: url("../images/home/2/pic.jpg");-->
<!--    background-size: 100% 100%;-->
<!--  }-->
<!--  .show-rect {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 100 * @vw;-->
<!--    z-index: 7;-->
<!--    margin-left: -1060 * @vw;-->
<!--    width: 1246 * @vw;-->
<!--    height: 216 * @vw;-->
<!--    background-color: @color-theme;-->
<!--  }-->
<!--  .show-text {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 400 * @vw;-->
<!--    z-index: 6;-->
<!--    margin-left: 400 * @vw;-->
<!--    width: 638 * @vw;-->
<!--    height: 764 * @vw;-->
<!--    background-image: url("../images/home/2/text.png");-->
<!--    background-size: 100% 100%;-->
<!--  }-->
<!--  .show-circle-1 {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 1240 * @vw;-->
<!--    z-index: 6;-->
<!--    margin-left: -740 * @vw;-->
<!--    width: 216 * @vw;-->
<!--    height: 216 * @vw;-->
<!--    border-radius: 50%;-->
<!--    background-color: @color-theme;-->
<!--  }-->
<!--  .show-circle-2 {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 140 * @vw;-->
<!--    z-index: 9;-->
<!--    margin-left: 400 * @vw;-->
<!--    width: 124 * @vw;-->
<!--    height: 124 * @vw;-->
<!--    border-radius: 50%;-->
<!--    background-color: @color-theme;-->
<!--  }-->
<!--}-->
<!--.part-show-3 {-->
<!--  .show-title {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 680 * @vw;-->
<!--    z-index: 20;-->
<!--    margin-left: -880 * @vw;-->
<!--    width: 1766 * @vw;-->
<!--    height: 154 * @vw;-->
<!--    background-image: url("../images/home/3/title.png");-->
<!--    background-size: 100% 100%;-->
<!--  }-->
<!--  .show-circle-big {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 400 * @vw;-->
<!--    z-index: 15;-->
<!--    margin-left: -1200 * @vw;-->
<!--    width: 2156 * @vw;-->
<!--    height: 632 * @vw;-->
<!--    background-image: url("../images/home/2/circle.png");-->
<!--    background-size: 100% 100%;-->
<!--  }-->
<!--  .show-pic {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 220 * @vw;-->
<!--    z-index: 8;-->
<!--    margin-left: -540 * @vw;-->
<!--    width: 1522 * @vw;-->
<!--    height: 1018 * @vw;-->
<!--    background-image: url("../images/home/3/pic.jpg");-->
<!--    background-size: 100% 100%;-->
<!--  }-->
<!--  .show-rect {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 1200 * @vw;-->
<!--    z-index: 7;-->
<!--    margin-left: -160 * @vw;-->
<!--    width: 1246 * @vw;-->
<!--    height: 216 * @vw;-->
<!--    background-color: @color-theme;-->
<!--  }-->
<!--  .show-text {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 700 * @vw;-->
<!--    z-index: 6;-->
<!--    margin-left: -1150 * @vw;-->
<!--    width: 564 * @vw;-->
<!--    height: 758 * @vw;-->
<!--    background-image: url("../images/home/3/text.png");-->
<!--    background-size: 100% 100%;-->
<!--  }-->
<!--  .show-circle-1 {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 120 * @vw;-->
<!--    z-index: 6;-->
<!--    margin-left: -1100 * @vw;-->
<!--    width: 216 * @vw;-->
<!--    height: 216 * @vw;-->
<!--    border-radius: 50%;-->
<!--    background-color: @color-theme;-->
<!--  }-->
<!--  .show-circle-2 {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 240 * @vw;-->
<!--    z-index: 9;-->
<!--    margin-left: 920 * @vw;-->
<!--    width: 124 * @vw;-->
<!--    height: 124 * @vw;-->
<!--    border-radius: 50%;-->
<!--    background-color: @color-theme;-->
<!--  }-->
<!--}-->
<!--.part-show-4 {-->
<!--  .show-title {-->
<!--    position: absolute;-->
<!--    left: 48%;-->
<!--    top: 1000 * @vw;-->
<!--    z-index: 20;-->
<!--    margin-left: -1040 * @vw;-->
<!--    width: 2084 * @vw;-->
<!--    height: 154 * @vw;-->
<!--    background-image: url("../images/home/4/title.png");-->
<!--    background-size: 100% 100%;-->
<!--  }-->
<!--  .show-circle-big {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 500 * @vw;-->
<!--    z-index: 15;-->
<!--    margin-left: -1200 * @vw;-->
<!--    width: 2156 * @vw;-->
<!--    height: 1000 * @vw;-->
<!--    background-image: url("../images/home/2/circle.png");-->
<!--    background-size: 100% 100%;-->
<!--  }-->
<!--  .show-pic {-->
<!--    position: absolute;-->
<!--    left: 45%;-->
<!--    top: 300 * @vw;-->
<!--    z-index: 8;-->
<!--    margin-left: -800 * @vw;-->
<!--    width: 1500 * @vw;-->
<!--    height: 900 * @vw;-->
<!--    background-image: url("../images/home/4/pic.jpg");-->
<!--    background-size: 100% 100%;-->
<!--  }-->
<!--  .show-rect {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 200 * @vw;-->
<!--    z-index: 7;-->
<!--    margin-left: -1160 * @vw;-->
<!--    width: 1246 * @vw;-->
<!--    height: 216 * @vw;-->
<!--    background-color: @color-theme;-->
<!--  }-->
<!--  .show-text {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 400 * @vw;-->
<!--    z-index: 6;-->
<!--    margin-left: 650 * @vw;-->
<!--    width: 524 * @vw;-->
<!--    height: 758 * @vw;-->
<!--    background-image: url("../images/home/4/text.png");-->
<!--    background-size: 100% 100%;-->
<!--  }-->
<!--  .show-circle-1 {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 1220 * @vw;-->
<!--    z-index: 6;-->
<!--    margin-left: -1100 * @vw;-->
<!--    width: 216 * @vw;-->
<!--    height: 216 * @vw;-->
<!--    border-radius: 50%;-->
<!--    background-color: @color-theme;-->
<!--  }-->
<!--  .show-circle-2 {-->
<!--    position: absolute;-->
<!--    left: 50%;-->
<!--    top: 50 * @vw;-->
<!--    z-index: 9;-->
<!--    margin-left: 820 * @vw;-->
<!--    width: 166 * @vw;-->
<!--    height: 166 * @vw;-->
<!--    border-radius: 50%;-->
<!--    background-color: @color-theme;-->
<!--  }-->
<!--}-->
<!--.part-show {-->
<!--  .show-title {-->
<!--    opacity: 0;-->
<!--    transform: translateY(200 * @vw);-->
<!--    transition: all 1s;-->
<!--  }-->
<!--  .show-circle-big {-->
<!--    opacity: 0;-->
<!--    transform: translateY(100 * @vw);-->
<!--    transition: all 1s;-->
<!--  }-->
<!--  .show-pic {-->
<!--    opacity: 0;-->
<!--    transform: translateY(240 * @vw);-->
<!--    transition: all 1s;-->
<!--  }-->
<!--  .show-text {-->
<!--    opacity: 0;-->
<!--    transform: translateY(160 * @vw);-->
<!--    transition: all 1s;-->
<!--  }-->
<!--  .show-rect {-->
<!--    opacity: 0;-->
<!--    transform: translateY(360 * @vw);-->
<!--    transition: all 1s;-->
<!--  }-->
<!--  .show-circle-1 {-->
<!--    opacity: 0;-->
<!--    transform: translateY(100 * @vw);-->
<!--    transition: all 1s;-->
<!--  }-->
<!--  .show-circle-2 {-->
<!--    opacity: 0;-->
<!--    transform: translateY(160 * @vw);-->
<!--    transition: all 1s;-->
<!--  }-->
<!--}-->

<!--.animation-1 {-->
<!--  .part-show-1 {-->
<!--    .show-title,-->
<!--    .show-pic,-->
<!--    .show-text,-->
<!--    .show-circle-big,-->
<!--    .show-rect,-->
<!--    .show-circle-1,-->
<!--    .show-circle-2 {-->
<!--      transform: translateY(0);-->
<!--      opacity: 1;-->
<!--    }-->
<!--    .show-circle-big {-->
<!--      opacity: 0.3;-->
<!--    }-->
<!--    .show-circle-1 {-->
<!--      opacity: 0.44;-->
<!--    }-->
<!--    .show-circle-2 {-->
<!--      opacity: 0.44;-->
<!--    }-->
<!--  }-->
<!--}-->
<!--.animation-2 {-->
<!--  .part-show-2 {-->
<!--    .show-title,-->
<!--    .show-pic,-->
<!--    .show-text,-->
<!--    .show-circle-big,-->
<!--    .show-rect,-->
<!--    .show-circle-1,-->
<!--    .show-circle-2 {-->
<!--      transform: translateY(0);-->
<!--      opacity: 1;-->
<!--    }-->
<!--    .show-circle-big {-->
<!--      opacity: 0.3;-->
<!--    }-->
<!--    .show-circle-1 {-->
<!--      opacity: 0.33;-->
<!--    }-->
<!--    .show-circle-2 {-->
<!--      opacity: 0.23;-->
<!--    }-->
<!--  }-->
<!--}-->
<!--.animation-3 {-->
<!--  .part-show-3 {-->
<!--    .show-title,-->
<!--    .show-pic,-->
<!--    .show-text,-->
<!--    .show-circle-big,-->
<!--    .show-rect,-->
<!--    .show-circle-1,-->
<!--    .show-circle-2 {-->
<!--      transform: translateY(0);-->
<!--      opacity: 1;-->
<!--    }-->
<!--    .show-circle-big {-->
<!--      opacity: 0.3;-->
<!--    }-->
<!--    .show-circle-1 {-->
<!--      opacity: 0.26;-->
<!--    }-->
<!--    .show-circle-2 {-->
<!--      opacity: 0.23;-->
<!--    }-->
<!--  }-->
<!--}-->
<!--.animation-4 {-->
<!--  .part-show-4 {-->
<!--    .show-title,-->
<!--    .show-pic,-->
<!--    .show-text,-->
<!--    .show-circle-big,-->
<!--    .show-rect,-->
<!--    .show-circle-1,-->
<!--    .show-circle-2 {-->
<!--      transform: translateY(0);-->
<!--      opacity: 1;-->
<!--    }-->
<!--    .show-circle-big {-->
<!--      opacity: 0.3;-->
<!--    }-->
<!--    .show-circle-1 {-->
<!--      opacity: 0.26;-->
<!--    }-->
<!--    .show-circle-2 {-->
<!--      opacity: 0.23;-->
<!--    }-->
<!--  }-->
<!--}-->
<!--@media (max-width: 1200px) {-->
<!--  .logo-item {-->
<!--    margin: 20px 4.8% 0;-->
<!--  }-->
<!--}-->
<!--@media (max-width: 1000px) {-->
<!--  .logo-item {-->
<!--    margin: 20px 2% 0;-->
<!--  }-->
<!--}-->
<!--@media (max-width: 800px) {-->
<!--  .nav .nav-logo {-->
<!--    margin-right: 0;-->
<!--  }-->
<!--  .nav .nav-icon {-->
<!--    margin-right: 0;-->
<!--  }-->
<!--  .part-flex {-->
<!--    display: block;-->
<!--  }-->
<!--  .feature-item__wrap {-->
<!--    display: block;-->
<!--  }-->
<!--  .part-logo {-->
<!--    margin-top: 30px;-->
<!--    margin-left: 0;-->
<!--  }-->
<!--  .logo-item {-->
<!--    margin: 10px 1.5% 0;-->
<!--    width: 64px;-->
<!--    font-size: 14px;-->
<!--  }-->
<!--  .logo-img {-->
<!--    width: 64px;-->
<!--    height: 64px;-->
<!--  }-->
<!--  .feature-item {-->
<!--    & + & {-->
<!--      margin-left: 0;-->
<!--      margin-top: 40px;-->
<!--    }-->
<!--    &__desc {-->
<!--      text-align: center;-->
<!--    }-->
<!--  }-->
<!--  -->
<!--  .nav-icon {-->
<!--    display: block;-->
<!--  }-->
<!--  .nav-menu {-->
<!--    position: fixed;-->
<!--    top: 0;-->
<!--    left: 0;-->
<!--    z-index: 100;-->
<!--    width: 100%;-->
<!--    height: 100%;-->
<!--    opacity: 0;-->
<!--    visibility: hidden;-->
<!--    pointer-events: none;-->
<!--    transition: all 0.2s;-->
<!--    &.active {-->
<!--      opacity: 1;-->
<!--      visibility: visible;-->
<!--      pointer-events: auto;-->
<!--    }-->
<!--    &__mask {-->
<!--      position: absolute;-->
<!--      top: 0;-->
<!--      left: 0;-->
<!--      width: 100%;-->
<!--      height: 100%;-->
<!--      background-color: rgba(0,0,0,0.8);-->
<!--    }-->
<!--    &__list {-->
<!--      max-width: 80px;-->
<!--    }-->
<!--    &__item {-->
<!--      display: block;-->
<!--      max-width: 80px;-->
<!--      color: #fff;-->
<!--      opacity: 0.8;-->
<!--      margin-left: 20px;-->
<!--      margin-top: 10px;-->
<!--      padding: 0;-->
<!--      line-height: 46px;-->
<!--      & + & {-->
<!--        margin-left: 20px;-->
<!--      }-->
<!--      &.active {-->
<!--        opacity: 1;-->
<!--        &::after {-->
<!--          width: 30px;-->
<!--          height: 4px;-->
<!--          top: auto;-->
<!--          bottom: 0;-->
<!--          opacity: 1;-->
<!--        }-->
<!--      }-->
<!--    }-->
<!--  }-->
<!--}-->
<!--@media (max-width: 600px){-->
<!--  .nav {-->
<!--    padding: 6px 20px;-->
<!--    .nav-logo {-->
<!--      width: 108px;-->
<!--      height: 27px;-->
<!--      margin-right: 0;-->
<!--    }-->
<!--    .nav-icon {-->
<!--      width: 20px;-->
<!--      height: 20px;-->
<!--    }-->
<!--  }-->
<!--  .contain-main {-->
<!--    padding: 30px 20px 50px;-->
<!--  }-->
<!--  .part-container {-->
<!--    padding: 40px 20px;-->
<!--    & + & {-->
<!--      margin-top: 30px;-->
<!--    }-->
<!--  }-->
<!--  .part-show {-->
<!--    margin-top: 30px;-->
<!--  }-->
<!--  .part-left__title {-->
<!--    font-size: 30px;-->
<!--    line-height: 40px;-->
<!--  }-->
<!--  .part-left__btn {-->
<!--    width: 120px;-->
<!--    height: 40px;-->
<!--    line-height: 40px;-->
<!--    font-size: 14px;-->
<!--  }-->
<!--  .feature-item__icon {-->
<!--    width: 40px;-->
<!--    height: 40px;-->
<!--  }-->
<!--  .feature-item__title {-->
<!--    font-size: 16px;-->
<!--    margin: 10px 0;-->
<!--  }-->
<!--  .feature-item__desc {-->
<!--    margin-top: 10px;-->
<!--  }-->
<!--  .part-footer {-->
<!--    height: 40px;-->
<!--  }-->
<!--  .footer-text {-->
<!--    font-size: 12px;-->
<!--  }-->
<!--  .logo-item {-->
<!--    margin: 10px 3vw 0;-->
<!--    width: 18vw;-->
<!--    font-size: 12px;-->
<!--  }-->
<!--  .logo-img {-->
<!--    border-radius: 10px;-->
<!--    margin: 0 auto 8px;-->
<!--    width: 15vw;-->
<!--    height: 15vw;-->
<!--  }-->
<!--}-->
<!--</style>-->
