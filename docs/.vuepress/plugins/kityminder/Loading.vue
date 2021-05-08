<template>
 <transition name="fade">
  <div class="spinner-box" v-if="show">
    <div class="spinner" :style="{ background: color }"></div>
  </div>  </transition>

</template>

<script>
// Loading indicator by https://tobiasahlin.com/spinkit/

export default {
    props: {
        color: {
            required: false,
            default: 'rgb(66, 185, 131)'
        },
        show:{
          type:Boolean,default:true
        }
    }
}
</script>

<style scoped>
.spinner-box {
  position: absolute;
  width: 100%;
  height: 100%;    
  background: #fbfbfb;  
}

.spinner {
  width: 40px;
  height: 40px;

  margin: auto auto;
  background: rgb(66, 185, 131);
  transform: translate(-50%,-50%);
  position: absolute;
  top: 50%;
  left: 50%;

  -webkit-animation: sk-rotateplane 1.2s infinite ease-in-out;
  animation: sk-rotateplane 1.2s infinite ease-in-out;
}

@-webkit-keyframes sk-rotateplane {
  0% { -webkit-transform:translate(-50%,-50%) perspective(120px) }
  50% { -webkit-transform:translate(-50%,-50%) perspective(120px) rotateY(180deg) }
  100% { -webkit-transform:translate(-50%,-50%) perspective(120px) rotateY(180deg)  rotateX(180deg) }
}

@keyframes sk-rotateplane {
  0% {
    transform:translate(-50%,-50%) perspective(120px) rotateX(0deg) rotateY(0deg);
    -webkit-transform:translate(-50%,-50%) perspective(120px) rotateX(0deg) rotateY(0deg)
  } 50% {
    transform:translate(-50%,-50%) perspective(120px) rotateX(-180.1deg) rotateY(0deg);
    -webkit-transform:translate(-50%,-50%) perspective(120px) rotateX(-180.1deg) rotateY(0deg)
  } 100% {
    transform:translate(-50%,-50%) perspective(120px) rotateX(-180deg) rotateY(-179.9deg);
    -webkit-transform:translate(-50%,-50%) perspective(120px) rotateX(-180deg) rotateY(-179.9deg);
  }
}


.fade-enter-active, .fade-leave-active {
  transition: opacity .5s;
}
.fade-enter, .fade-leave-to /* .fade-leave-active below version 2.1.8 */ {
  opacity: 0;
}
</style>
