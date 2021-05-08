# Properties

## Absolute/Relative Layout

The `position type` of an element defines how it is positioned within its parent.
The position values top, right, bottom, and left behave differently depending on the position type of the element. For a relative element they offset the position of the element in the direction specified. For absolute element though these properties specify the offset of the element's side from the same side on the parent.

#### RELATIVE (DEFAULT)

  By default an element is positioned relatively. This means an element is positioned according to the normal flow of the layout, and then offset relative to that position based on the values of `top`, `right`, `bottom`, and `left`. The offset does not affect the position of any sibling or parent elements.

#### ABSOLUTE

  When positioned absolutely an element doesn't take part in the normal layout flow. It is instead laid out independent of its siblings. The position is determined based on the `top`, `right`, `bottom`, and `left` values.


## Align Content

Align content defines the distribution of lines along the cross-axis. This only has effect when items are wrapped to multiple lines using `flex wrap`.

#### FLEX START (DEFAULT)

  Align wrapped lines to the start of the container's cross axis.

#### FLEX END 

  Align wrapped lines to the end of the container's cross axis.

#### STRETCH 

  Stretch wrapped lines to match the height of the container's cross axis.

#### CENTER 

  Align wrapped lines in the center of the container's cross axis.

#### SPACE BETWEEN

  Evenly space wrapped lines across the container's main axis, distributing remaining space between the lines.

#### SPACE AROUND 

  Evenly space wrapped lines across the container's main axis, distributing remaining space around the lines. Compared to space between using space around will result in space being distributed to the begining of the first lines and end of the last line.

## Align Items

Align items describes how to align children along the cross axis of their container. Align items is very similar to `justify content` but instead of applying to the main axis, `align items` applies to the cross axis.

#### STRETCH (DEFAULT) 
  
  Stretch children of a container to match the height of the container's cross axis.

#### FLEX START 
  
  Align children of a container to the start of the container's cross axis.

#### FLEX END 

  Align children of a container to the end of the container's cross axis.

#### CENTER 

  Align children of a container in the center of the container's cross axis.

#### BASELINE 

  Align children of a container along a common baseline. Individual children can be set to be the reference baseline for their parents.

## Align Self

Align self has the same options and effect as `align items` but instead of affecting the children within a container, you can apply this property to a single child to change its alignment within its parent. `align self` overrides any option set by the parent with `align items`.

## Aspect Ratio

AspectRatio is a property introduced by Titank and is not present as a settable property in the css flexbox specification. Flexbox does has the notion of aspect ratio though for things with intrinsic aspect ratio such as images.

The `aspect ratio` property in Titank has the following properties:

+ Accepts any floating point value > 0, the default is undefined.
+ Defined as the ratio between the `width` and the `height` of a node e.g. if a node has an aspect ratio of 2 then its `width` is twice the size of its `height`.
+ Respects the `min` and `max` dimensions of an item.
+ Has higher priority than `flex grow`.
+ If `aspect ratio`, `width`, and `height` are set then the cross axis dimension is overridden.


## Flex Direction

Flex direction controls the direction in which children of a node are laid out. This is also referred to as the main axis. The main axis is the direction in which children are laid out. The cross axis the the axis perpendicular to the main axis, or the axis which wrapping lines are laid out in.

#### ROW (DEFAULT) 

Align children from left to right. If `wrapping` is enabled then the next line will start under the first item on the left of the container.

#### COLUMN 

Align children from top to bottom. If `wrapping` is enabled then the next line will start to the left first item on the top of the container.

#### ROW REVERSE 

Align children from right to left. If `wrapping` is enabled then the next line will start under the first item on the right of the container.

#### COLUMN REVERSE 

Align children from bottom to top. If `wrapping` is enabled then the next line will start to the left first item on the bottom of the container.

## Flex Wrap

The flex wrap property is set on containers and controls what happens when children overflow the size of the container along the main axis. By default children are forced into a single line (which can shrink elements).

If wrapping is allowed items are wrapped into multiple lines along the main axis if needed. wrap reverse behaves the same, but the order of the lines is reversed.

When wrapping lines align content can be used to specify how the lines are placed in the container.

## Flex Basis, Grow, and Shrink

#### FLEX GROW 

It describes how any space within a container should be distributed among its children along the main axis. After laying out its children, a container will distribute any remaining space according to the flex grow values specified by its children.

Flex grow accepts any floating point value >= 0, with 0 being the default value. A container will distribute any remaining space among its children weighted by the child’s flex grow value.

#### FLEX SHRINK 

It describes how to shrink children along the main axis in the case that the total size of the children overflow the size of the container on the main axis. flex shrink is very similar to flex grow and can be thought of in the same way if any overflowing size is considered to be negative remaining space. These two properties also work well together by allowing children to grow and shrink as needed.

Flex shrink accepts any floating point value >= 0, with 1 being the default value. A container will shrink its children weighted by the child’s flex shrink value.


#### FLEX BASIS 

It is an axis-independent way of providing the default size of an item along the main axis. Setting the flex basis of a child is similar to setting the `width` of that child if its parent is a container with `flex direction: row` or setting the `height` of a child if its parent is a container with `flex direction: column`. The flex basis of an item is the default size of that item, the size of the item before any flex grow and flex shrink calculations are performed.

## Justify Content

Justify content describes how to align children within the main axis of their container. For example, you can use this property to center a child horizontally within a container with `flex direction` set to `row` or vertically within a container with `flex direction` set to `column`.

#### FLEX START (DEFAULT) 

Align children of a container to the start of the container's main axis.

#### FLEX END 

Align children of a container to the end of the container's main axis.

#### CENTER 

Align children of a container in the center of the container's main axis.

#### SPACE BETWEEN 

Evenly space of children across the container's main axis, distributing remaining space between the children.

#### SPACE AROUND

Evenly space of children across the container's main axis, distributing remaining space around the children. Compared to space between using space around will result in space being distributed to the beginning of the first child and end of the last child.

#### SPACE EVENLY

Evenly distributed within the alignment container along the main axis. The spacing between each pair of adjacent items, the main-start edge and the first item, and the main-end edge and the last item, are all exactly the same.

## Layout Direction

Layout direction specifies the direction in which children and text in a hierarchy should be laid out. Layout direction also effects what edge `start` and end refer to. By default Titank lays out with `LTR` layout direction. In this mode `start` refers to `left` and `end` refers to `right`. When localizing your apps for markets with RTL languages you should customize this by either by passing a direction to the `CalculateLayout` call or by setting the direction on the root node.

#### LTR (DEFAULT) 

Text and children and laid out from left to right. Margin and padding applied the start of an element are applied on the left side.

#### RTL 

Text and children and laid out from right to left. Margin and padding applied the start of an element are applied on the right side.

## Margins, Paddings, and Borders

#### MARGIN

It effects the spacing around the outside of a node. A node with margin will offset itself from the bounds of its parent but also offset the location of any siblings. The margin of a node contributes to the total size of its parent if the parent is auto sized.

#### PADDING 

It affects the size of the node it is applied to. Padding in Titank acts as if box-sizing: border-box; was set. That is padding will not add to the total size of an element if it has an explicit size set. For auto sized nodes padding will increase the size of the node as well as offset the location of any children.

#### BORDER

In Titank it acts exactly like padding and only exists as a seperate property so that higher level frameworks get a hint as to how thick to draw a border. Titank however does not do any drawing so just uses this information during layout where border acts exactly like padding.

## Max / Min Width and Height

All the following properties set the maximum and minimum size constraints of an element. These properties have higher priority than all other properties and will always be respected. Constraints can be specified as either absolute pixel values or as percentages of their parent's size. By default all these constraints are `undefined`.

## Width and Height

The `width` property in Titank specifies the width of the element's content area. Similarly `height` property specifies the height of the element's content area.

Both `width` and `height` can take following values:

**AUTO** Is the default Value, Titank calculates the width/height for the element based on its content, whether that is other children, text, or an image.

**PIXELS** Defines the width/height in absolute pixels. Depending on other properties set on the Titank node this may or may not be the final dimension of the node.

**PERCENTAGE** Defines the width or height in percentage of its parent's width or height respectively.

[comment]: <> (```bash)

[comment]: <> (fef genyaml)

[comment]: <> (```)

[comment]: <> (::: tip Raft中的客户端配置文件)

[comment]: <> (app_raft.yaml/com_raft.yaml: [RAFT 描述文件]&#40;http://raft.oa.com/client/standard/raft-standard.html#%E5%AE%A2%E6%88%B7%E7%AB%AF-raft-%E6%A0%87%E5%87%86&#41;)

[comment]: <> (app_config.yaml/com_config.yaml: [RAFT 配置文件]&#40;http://raft.oa.com/client/standard/raft-standard.html#raft-%E9%85%8D%E7%BD%AE%E6%96%87%E4%BB%B6&#41;)

[comment]: <> (:::)

[comment]: <> (还需要对应用工程做一些修改：)

[comment]: <> (:::: tabs type:border-card)

[comment]: <> (::: tab iOS)

[comment]: <> (在 `app_raft.yaml` 中填写应用的 Xcode Target 名称，比如：)

[comment]: <> (```yaml)

[comment]: <> (apiVersion: com.raft.uas/v1alpha2)

[comment]: <> (description: 这是集成 RAFT 组件的示例应用。)

[comment]: <> (name: SampleApp     )

[comment]: <> (kind: Application)

[comment]: <> (version: 1.0.0)

[comment]: <> (platform: iOS   )

[comment]: <> (target: MySampleApp # 【重要】填写 Xcode 中 App 的 Target 名)

[comment]: <> (```)

[comment]: <> (:::)

[comment]: <> (::: tab Android)

[comment]: <> (1. 项目工程内引入Raft框架)

[comment]: <> (```java)

[comment]: <> (maven {)

[comment]: <> (    url "https://mirrors.tencent.com/repository/maven/thirdparty/")

[comment]: <> (})

[comment]: <> (classpath 'com.tencent.raft:gradlesdk:+')

[comment]: <> (classpath 'com.tencent.raft.component:framework-tools:+')

[comment]: <> (```)

[comment]: <> (2. module引入Raft插件和框架依赖（只有需要使用Raft框架的module才需改造）)

[comment]: <> (```java)

[comment]: <> (apply plugin: 'com.tencent.raft.raftgradle')

[comment]: <> (apply plugin: 'raft-framework-tools')

[comment]: <> (dependencies {)

[comment]: <> (  implementation "com.tencent.raft:framework:+")

[comment]: <> (  annotationProcessor "com.tencent.raft:compiler:+")

[comment]: <> (})

[comment]: <> (```)

[comment]: <> (:::)

[comment]: <> (::::)
  
[comment]: <> (::: tip 创建新工程？)

[comment]: <> (如果你想创建一个新的 RAFT 应用工程，可以[使用 `fef init` 命令]&#40;../external_raft-cli-guide/1.2.init.md&#41;。)

[comment]: <> (::: )

[comment]: <> (接着[运行 `fef i` 命令]&#40;../external_raft-cli-guide/1.4.import.md&#41;就可以在应用工程中集成组件了，选择组件时注意区分平台，这里以 GuestBook 组件为例：)

[comment]: <> (:::: tabs type:border-card)

[comment]: <> (::: tab iOS)

[comment]: <> (::: code)

[comment]: <> (fef i [GuestBook-iOS]&#40;http://market.raft.oa.com/detail/320862/0.0.12&#41;  )

[comment]: <> (:::)

[comment]: <> (你也可以在 RAFT 组件上使用 `fef i` 为其添加对其他 RAFT 组件的依赖。`fef i` 还支持使用 `--targets` 指定安装到多个 Xcode Target 上。)

[comment]: <> (::: tab Android)

[comment]: <> (::: code)

[comment]: <> (fef i [GuestBook-Android]&#40;http://market.raft.oa.com/detail/321582/0.3.5&#41;  )

[comment]: <> (:::)

[comment]: <> (::::)

[comment]: <> (::: tip 有哪些组件可供使用？)

[comment]: <> (RAFT [组件市场]&#40;http://market.raft.oa.com&#41;提供了很多组件任你挑选，你可以查看组件详细信息，然后复制命令来很方便地集成组件。)

[comment]: <> (::: )

[comment]: <> (在[执行 `fef i`]&#40;../external_raft-cli-guide/1.4.import.md&#41; 的同时，RAFT 框架也会被集成到应用工程中。在引入 RAFT 框架的头文件或包之后，就可以通过框架来获取和使用组件提供的 Service 了：)

[comment]: <> (:::: tabs type:border-card)

[comment]: <> (::: tab iOS)

[comment]: <> (``` objectivec)

[comment]: <> ([RAServiceManager.sharedManger serviceForKey:RAGuestBookService.class]; )

[comment]: <> (```)

[comment]: <> (有关 [iOS RAFT 框架]&#40;https://git.code.oa.com/raft/framework-iOS&#41; 的详细用法可以参考 [API 文档]&#40;../client/ioc/raft-framework-ios.md&#41;。)

[comment]: <> (:::)

[comment]: <> (::: tab Android)

[comment]: <> (``` java)

[comment]: <> (RAApplicationContext.getGlobalContext&#40;&#41;.getService&#40;IGuestBook.class&#41;;)

[comment]: <> (```)

[comment]: <> (有关 [Android RAFT 框架]&#40;https://git.code.oa.com/raft/framework-android&#41; 的详细用法可以参考 [API 文档]&#40;../client/ioc/raft-framework-android.md&#41;。)

[comment]: <> (:::)

[comment]: <> (::::)

[comment]: <> (::: tip 使用的组件依赖了后台服务？)

[comment]: <> (如果你要使用的组件还包含后台服务，可以使用 `fef d` 命令来[部署后台服务]&#40;http://docs.raft.oa.com/external_raft-cli-guide/1.5.deploy.html&#41;。通过 RAFT 框架使用客户端组件时，[其依赖的后台服务配置（AppID 等）会被自动回填]&#40;../guide/config-auto-injection.md&#41;。)

[comment]: <> (::: )



