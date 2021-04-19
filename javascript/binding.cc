#include <emscripten/bind.h>

#include "taitank.h"

using namespace taitank;
using namespace emscripten;

void DoLayout(TaitankNodeRef node, float parent_width, float parent_height,
              TaitankDirection direction = DIRECTION_LTR) {
  TaitankNodeDoLayout(node, parent_width, parent_height, direction);
}

EMSCRIPTEN_BINDINGS(taitank) {
  enum_<TaitankDirection>("TaitankDirection")
      .value("DIRECTION_INHERIT", DIRECTION_INHERIT)
      .value("DIRECTION_LTR", DIRECTION_LTR)
      .value("DIRECTION_RTL", DIRECTION_RTL);

  enum_<FlexDirection>("FlexDirection")
      .value("FLEX_DIRECTION_ROW", FLEX_DIRECTION_ROW)
      .value("FLEX_DIRECTION_ROW_REVERSE", FLEX_DIRECTION_ROW_REVERSE)
      .value("FLEX_DIRECTION_COLUMN", FLEX_DIRECTION_COLUMN)
      .value("FLEX_DIRECTION_COLUNM_REVERSE", FLEX_DIRECTION_COLUNM_REVERSE);

  enum_<PositionType>("PositionType")
      .value("POSITION_TYPE_RELATIVE", POSITION_TYPE_RELATIVE)
      .value("POSITION_TYPE_ABSOLUTE", POSITION_TYPE_ABSOLUTE);

  enum_<CSSDirection>("CSSDirection")
      .value("CSS_LEFT", CSS_LEFT)
      .value("CSS_TOP", CSS_TOP)
      .value("CSS_RIGHT", CSS_RIGHT)
      .value("CSS_BOTTOM", CSS_BOTTOM)
      .value("CSS_START", CSS_START)
      .value("CSS_END", CSS_END)
      .value("CSS_HORIZONTAL", CSS_HORIZONTAL)
      .value("CSS_VERTICAL", CSS_VERTICAL)
      .value("CSS_ALL", CSS_ALL)
      .value("CSS_NONE", CSS_NONE);

  enum_<FlexWrapMode>("FlexWrapMode")
      .value("FLEX_NO_WRAP", FLEX_NO_WRAP)
      .value("FLEX_WRAP", FLEX_WRAP)
      .value("FLEX_WRAP_REVERSE", FLEX_WRAP_REVERSE);

  enum_<FlexAlign>("FlexAlign")
      .value("FLEX_ALIGN_AUTO", FLEX_ALIGN_AUTO)
      .value("FLEX_ALIGN_START", FLEX_ALIGN_START)
      .value("FLEX_ALIGN_CENTER", FLEX_ALIGN_CENTER)
      .value("FLEX_ALIGN_END", FLEX_ALIGN_END)
      .value("FLEX_ALIGN_STRETCH", FLEX_ALIGN_STRETCH)
      .value("FLEX_ALIGN_BASE_LINE", FLEX_ALIGN_BASE_LINE)
      .value("FLEX_ALIGN_SPACE_BETWEEN", FLEX_ALIGN_SPACE_BETWEEN)
      .value("FLEX_ALIGN_SPACE_AROUND", FLEX_ALIGN_SPACE_AROUND)
      .value("FLEX_ALIGN_SPACE_EVENLY", FLEX_ALIGN_SPACE_EVENLY);

  enum_<DisplayType>("DisplayType")
      .value("DISPLAY_TYPE_FLEX", DISPLAY_TYPE_FLEX)
      .value("DISPLAY_TYPE_NONE", DISPLAY_TYPE_NONE);

  enum_<OverflowType>("OverflowType")
      .value("OVERFLOW_VISIBLE", OVERFLOW_VISIBLE)
      .value("OVERFLOW_HIDDEN", OVERFLOW_HIDDEN)
      .value("OVERFLOW_SCROLL", OVERFLOW_SCROLL);

  enum_<NodeType>("NodeType").value("NODETYPE_DEFAULT", NODETYPE_DEFAULT).value("NODETYPE_TEXT", NODETYPE_TEXT);

  class_<TaitankNode>("TaitankNode");

  function("TaitankNodeCreate", &TaitankNodeCreate, allow_raw_pointers());
  function("TaitankNodeFree", &TaitankNodeFree, allow_raw_pointers());
  function("TaitankNodeFreeRecursive", &TaitankNodeFreeRecursive, allow_raw_pointers());
  //   function("set_taitank_node_measure_function", &set_taitank_node_measure_function, allow_raw_pointers());

  function("set_taitank_node_style_direction", &set_taitank_node_style_direction, allow_raw_pointers());
  function("set_taitank_node_style_width", &set_taitank_node_style_width, allow_raw_pointers());
  function("set_taitank_node_style_height", &set_taitank_node_style_height, allow_raw_pointers());
  function("set_taitank_node_style_flex", &set_taitank_node_style_flex, allow_raw_pointers());
  function("set_taitank_node_style_flex_grow", &set_taitank_node_style_flex_grow, allow_raw_pointers());
  function("set_taitank_node_style_flex_shrink", &set_taitank_node_style_flex_shrink, allow_raw_pointers());
  function("set_taitank_node_style_flex_basis", &set_taitank_node_style_flex_basis, allow_raw_pointers());
  function("set_taitank_node_style_flex_direction", &set_taitank_node_style_flex_direction, allow_raw_pointers());
  function("set_taitank_node_style_position_type", &set_taitank_node_style_position_type, allow_raw_pointers());
  function("set_taitank_node_style_position", &set_taitank_node_style_position, allow_raw_pointers());
  function("set_taitank_node_style_margin", &set_taitank_node_style_margin, allow_raw_pointers());
  function("set_taitank_node_style_margin_auto", &set_taitank_node_style_margin_auto, allow_raw_pointers());
  function("set_taitank_node_style_padding", &set_taitank_node_style_padding, allow_raw_pointers());
  function("set_taitank_node_style_border", &set_taitank_node_style_border, allow_raw_pointers());

  function("set_taitank_node_style_flex_wrap", &set_taitank_node_style_flex_wrap, allow_raw_pointers());
  function("set_taitank_node_style_justify_content", &set_taitank_node_style_justify_content, allow_raw_pointers());
  function("set_taitank_node_style_align_content", &set_taitank_node_style_align_content, allow_raw_pointers());
  function("set_taitank_node_style_align_items", &set_taitank_node_style_align_items, allow_raw_pointers());
  function("set_taitank_node_style_align_self", &set_taitank_node_style_align_self, allow_raw_pointers());
  function("set_taitank_node_style_display", &set_taitank_node_style_display, allow_raw_pointers());
  function("set_taitank_node_style_max_width", &set_taitank_node_style_max_width, allow_raw_pointers());
  function("set_taitank_node_style_max_height", &set_taitank_node_style_max_height, allow_raw_pointers());
  function("set_taitank_node_style_min_width", &set_taitank_node_style_min_width, allow_raw_pointers());
  function("set_taitank_node_style_min_height", &set_taitank_node_style_min_height, allow_raw_pointers());
  function("set_taitank_node_style_overflow", &set_taitank_node_style_overflow, allow_raw_pointers());
  function("set_taitank_node_node_type", &set_taitank_node_node_type, allow_raw_pointers());

  function("get_taitank_node_layout_left", &get_taitank_node_layout_left, allow_raw_pointers());
  function("get_taitank_node_layout_top", &get_taitank_node_layout_top, allow_raw_pointers());
  function("get_taitank_node_layout_right", &get_taitank_node_layout_right, allow_raw_pointers());
  function("get_taitank_node_layout_bottom", &get_taitank_node_layout_bottom, allow_raw_pointers());
  function("get_taitank_node_layout_width", &get_taitank_node_layout_width, allow_raw_pointers());
  function("get_taitank_node_layout_height", &get_taitank_node_layout_height, allow_raw_pointers());
  function("get_taitank_node_layout_margin", &get_taitank_node_layout_margin, allow_raw_pointers());
  function("get_taitank_node_layout_padding", &get_taitank_node_layout_padding, allow_raw_pointers());
  function("get_taitank_node_layout_border", &get_taitank_node_layout_border, allow_raw_pointers());
  function("get_taitank_node_layout_had_overflow", &get_taitank_node_layout_had_overflow, allow_raw_pointers());

  function("TaitankNodeInsertChild", &TaitankNodeInsertChild, allow_raw_pointers());
  function("TaitankNodeRemoveChild", &TaitankNodeRemoveChild, allow_raw_pointers());
  function("get_taitank_node_has_new_layout", &get_taitank_node_has_new_layout, allow_raw_pointers());
  function("set_taitank_node_has_new_layout", &set_taitank_node_has_new_layout, allow_raw_pointers());
  function("TaitankNodeMarkDirty", &TaitankNodeMarkDirty, allow_raw_pointers());
  function("TaitankNodeIsDirty", &TaitankNodeIsDirty, allow_raw_pointers());
  function("DoLayout", &DoLayout, allow_raw_pointers());
  function("TaitankNodePrint", &TaitankNodePrint, allow_raw_pointers());
  function("TaitankNodeReset", &TaitankNodeReset, allow_raw_pointers());
}