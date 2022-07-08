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

The `width` property in Taitank specifies the width of the element's content area. Similarly `height` property specifies the height of the element's content area.

Both `width` and `height` can take following values:

**AUTO** Is the default Value, Taitank calculates the width/height for the element based on its content, whether that is other children, text, or an image.

**PIXELS** Defines the width/height in absolute pixels. Depending on other properties set on the Taitank node this may or may not be the final dimension of the node.




