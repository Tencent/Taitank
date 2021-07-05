# Properties

## Absolute/Relative Layout

The `position type` of an element defines how an element is positioned in the document.
The top, right, bottom and left properties determine the final location of the position depending on the position type of the element.

#### RELATIVE

  An element is positioned relatively. This means an element is positioned according to the normal flow of layout, and the relative position based on the properties of `top`, `right`, `bottom` and `left`.  

#### ABSOLUTE

  An element is positioned absolutely. This means an element dosen't take part in the normal layout flow. The position is determined based on the `top`, `right`, `bottom` and `left` values.

## Align Content

Align content defines the distribution space of lines along the cross-axis. This only take effect under condition when items are wrapped to multiple lines using `flex wrap`. 

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

  Evenly space wrapped lines across the container's main axis, distributing remaining space around the lines. 

## Align Items

Align items defines the distribution space of the cross-aixs for all items.
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

Align self defines the distribution space on the cross-axis for it self. `align self` overrrides any options set by the parent with `align items`.

## Flex Direction

Flex direction defines how flex items are laid out in an flex container.

#### ROW (DEFAULT) 

Align children from left to right.
#### COLUMN 

Align children from top to bottom. 
#### ROW REVERSE 

Align children from right to left. 

#### COLUMN REVERSE 

Align children from bottom to top. 

## Flex Wrap

Flex wrap defines weather flex itmes can be laid out onto one line or can be wrap onto multiple lines.

#### No Wrap 

Flex item should be laid out onto one line.

#### Wrap 

Flex item can be laid out onto multiple lines.

#### Wrap Reverse

The same as wrap but cross-start and cross-end are premuted. 

## Flex Basis, Grow, and Shrink

#### FLEX GROW 

The flex-grow defines the flex grow factor of a flex item.
#### FLEX SHRINK 

The flex-shrink defines the flex shrink factor of a flex item.

#### FLEX BASIS 

The flex-basis defines the initial main size of a flex item.

## Justify Content

Justify Content defines the distribution space on the main-axis.

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

## Direction

Direction specifies the direction in which children and text should be laid out.

#### LTR (DEFAULT) 

Text and children and laid out from left to right.

#### RTL 

Text and children and laid out from right to left. 
## Margins, Paddings, and Borders

#### MARGIN

It effects the spacing around a node's border.

#### PADDING 

It affects the spacing between a node's border and the node's content.

#### BORDER

It affects the node's border space.
## Max / Min Width and Height

All the following properties set the maximum and minimum size constraints of an element.

## Width and Height

The `width` property in Titank specifies the width of the element's content area. Similarly `height` property specifies the height of the element's content area.

Both `width` and `height` can take following values:

**AUTO** Is the default Value, Titank calculates the width/height for the element based on its content, whether that is other children, text, or an image.

**PIXELS** Defines the width/height in absolute pixels. Depending on other properties set on the Titank node this may or may not be the final dimension of the node.

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



