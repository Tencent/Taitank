const path = require('path')

module.exports = (options, ctx) => {
  return {
    define: {
      MINDER_OPTIONS: options
    },
    chainMarkdown (config) {
      config
        .plugin('minder')
        .use(require('./markdownItPlugin'))
    },
    enhanceAppFiles: path.resolve(__dirname, 'kityminder.js')
  }
}
