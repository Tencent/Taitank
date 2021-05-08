<template>
  <div class="logo-group">
    <a href="https://im.qq.com/mobileqq/" target="_blank" class="logo">
      <img src="//pp.myapp.com/ma_icon/0/icon_6633_1603250105/256" alt="Mobile QQ"/>
      <h3>Mobile QQ</h3>
    </a>
    <a href="https://mb.qq.com/" target="_blank" class="logo">
      <img src="//pp.myapp.com/ma_icon/0/icon_11384_1543315194/256" alt="Mobile QQ Browser"/>
      <h3>Mobile QQ Browser</h3>
    </a>
    <a href="http://v.qq.com/download.html" target="_blank" class="logo">
      <img src="//pp.myapp.com/ma_icon/0/icon_3040_1619574150/256" alt="Tencent Video"/>
      <h3>Tencent Video</h3>
    </a>
    <a href="https://y.qq.com/download/download.html" target="_blank" class="logo">
      <img src="//pp.myapp.com/ma_icon/0/icon_6259_1619515732/256" alt="QQ Music"/>
      <h3>QQ Music</h3>
    </a>
    <a href="https://kg.qq.com/html/contest/kg-intro.html" target="_blank" class="logo">
      <img src="//pp.myapp.com/ma_icon/0/icon_10966186_1533019715/256" alt="WeSing"/>
      <h3>WeSing</h3>
    </a>
    <a href="https://news.qq.com/mobile/index.htm" target="_blank" class="logo">
      <img src="//pp.myapp.com/ma_icon/0/icon_5613_1619430858/256" alt="Tencent News"/>
      <h3>Tencent News</h3>
    </a>
    <a href="https://weishi.qq.com/" target="_blank" class="logo">
      <img src="//pp.myapp.com/ma_icon/0/icon_10261931_1551433926/256" alt="weishi"/>
      <h3>WeiShi</h3>
    </a>
  </div>
</template>

<script>
export default {
  name: "LogoGroup"
}
</script>

<style lang="less">
div.logo-group {
  display: -ms-flexbox;
  display: flex;
  -ms-flex-direction: row;
  flex-direction: row;
  -ms-flex-wrap: wrap;
  flex-wrap: wrap;
  margin-top: 50px;
  .logo {
    display: flex;
    -ms-flex-direction: column;
    flex-direction: column;
    -ms-flex-align: center;
    align-items: center;
    margin-right: 100px;
    margin-top: 1rem;
    margin-bottom: 1rem;
    img {
      height: 130px;
    }
    h3 {
      font-size: 10px;
      margin-top: 10px;
      text-align: center;
      color: #4e6e8e
    }
  }
}
@media only screen and (max-width: 576px) {
  div.logo-group .logo {
    width: 33%;
    padding: 20px;
    margin-right: 0;
    img{
      height: 118px;
    }
  }
}
</style>