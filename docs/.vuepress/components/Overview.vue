<template>
  <div class="overview-row">
    <div class="category">
      <h2>Properties</h2>
      <RouterLink to="/documentation/properties.html#absolute-relative-layout">Absolute/Relative Layout</RouterLink>
      <RouterLink to="/documentation/properties.html#align-content">Align Content</RouterLink>
      <RouterLink to="/documentation/properties.html#align-items">Align Items</RouterLink>
      <RouterLink to="/documentation/properties.html#align-self">Align Self</RouterLink>
      <RouterLink to="/documentation/properties.html#aspect-ratio">Aspect Ratio</RouterLink>
      <RouterLink to="/documentation/properties.html#flex-direction">Flex Direction</RouterLink>
      <RouterLink to="/documentation/properties.html#flex-wrap">Flex Wrap</RouterLink>
      <RouterLink to="/documentation/properties.html#flex-basis-grow-and-shrink">Flex Basis, Grow, and Shrink</RouterLink>
      <RouterLink to="/documentation/properties.html#justify-content">Justify Content</RouterLink>
      <RouterLink to="/documentation/properties.html#layout-direction">Layout Direction</RouterLink>
      <RouterLink to="/documentation/properties.html#margins-paddings-and-borders">Margins, Paddings, and Borders</RouterLink>
      <RouterLink to="/documentation/properties.html#max-min-width-and-height">Max / Min Width and Height</RouterLink>
      <RouterLink to="/documentation/properties.html#width-and-height">Width and Height</RouterLink></div>
    <div class="category">
      <h2>Examples</h2>
      <RouterLink class='disabled' to="">Flexible Text</RouterLink>
      <RouterLink class='disabled' to="">Floating Buttons</RouterLink>
      <RouterLink class='disabled' to="">Overlays</RouterLink>
    </div>
    <div class="category">
      <h2>Contributing</h2>
      <RouterLink class='disabled' to="">Opening a Pull Request</RouterLink>
      <RouterLink class='disabled' to="">Testing</RouterLink>
      <RouterLink class='disabled' to="">Writing Documentation</RouterLink>
    </div>
  </div>
</template>

<script>
export default {
  name: "Overview"
}
</script>

<style lang="less">
.overview-row {
  width: auto;
  display: flex;
  flex-direction: row;
  justify-content: space-between;
  flex-wrap: wrap;
  .category {
    display: flex;
    flex-direction: column;
    margin: 1rem 0;
    h2 {
      font-size: 16px;
      font-weight: 700;
    }
    a {
      font-size: 16px;
      font-weight: 500;
      line-height: 250%;
      color: #74a9ff;
      &.disabled{
        &:hover {
          text-decoration: none;
          cursor: default;
        }
        color: #dcdfe6;
      }
    }
  }
}
</style>