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

  function("NodeCreate", &NodeCreate, allow_raw_pointers());
  function("NodeFree", &NodeFree, allow_raw_pointers());
  function("NodeFreeRecursive", &NodeFreeRecursive, allow_raw_pointers());
  //   function("set_taitank_node_measure_function", &set_taitank_node_measure_function, allow_raw_pointers());

  function("SetDirection", &SetDirection, allow_raw_pointers());
  function("SetWidth", &SetWidth, allow_raw_pointers());
  function("SetHeight", &SetHeight, allow_raw_pointers());
  function("SetFlex", &SetFlex, allow_raw_pointers());
  function("SetFlexGrow", &SetFlexGrow, allow_raw_pointers());
  function("SetFlexShrink", &SetFlexShrink, allow_raw_pointers());
  function("SetFlexBasis", &SetFlexBasis, allow_raw_pointers());
  function("SetFlexDirection", &SetFlexDirection, allow_raw_pointers());
  function("SetPositionType", &SetPositionType, allow_raw_pointers());
  function("SetPosition", &SetPosition, allow_raw_pointers());
  function("SetMargin", &SetMargin, allow_raw_pointers());
  function("SetMarginAuto", &SetMarginAuto, allow_raw_pointers());
  function("SetPadding", &SetPadding, allow_raw_pointers());
  function("SetBorder", &SetBorder, allow_raw_pointers());

  function("SetFlexWrap", &SetFlexWrap, allow_raw_pointers());
  function("SetJustifyContent", &SetJustifyContent, allow_raw_pointers());
  function("SetAlignContent", &SetAlignContent, allow_raw_pointers());
  function("SetAlignItems", &SetAlignItems, allow_raw_pointers());
  function("SetAlignSelf", &SetAlignSelf, allow_raw_pointers());
  function("SetDisplay", &SetDisplay, allow_raw_pointers());
  function("SetMaxWidth", &SetMaxWidth, allow_raw_pointers());
  function("SetMaxHeight", &SetMaxHeight, allow_raw_pointers());
  function("SetMinWidth", &SetMinWidth, allow_raw_pointers());
  function("SetMinHeight", &SetMinHeight, allow_raw_pointers());
  function("SetOverflow", &SetOverflow, allow_raw_pointers());
  function("SetNodeType", &SetNodeType, allow_raw_pointers());

  function("GetLeft", &GetLeft, allow_raw_pointers());
  function("GetTop", &GetTop, allow_raw_pointers());
  function("GetRight", &GetRight, allow_raw_pointers());
  function("GetBottom", &GetBottom, allow_raw_pointers());
  function("GetWidth", &GetWidth, allow_raw_pointers());
  function("GetHeight", &GetHeight, allow_raw_pointers());
  function("GetMargin", &GetMargin, allow_raw_pointers());
  function("GetPadding", &GetPadding, allow_raw_pointers());
  function("GetBorder", &GetBorder, allow_raw_pointers());
  function("GetHadOverflow", &GetHadOverflow, allow_raw_pointers());

  function("InsertChild", &InsertChild, allow_raw_pointers());
  function("RemoveChild", &RemoveChild, allow_raw_pointers());
  function("GetHasNewLayout", &GetHasNewLayout, allow_raw_pointers());
  function("SetHasNewLayout", &SetHasNewLayout, allow_raw_pointers());
  function("MarkDirty", &MarkDirty, allow_raw_pointers());
  function("IsDirty", &IsDirty, allow_raw_pointers());
  function("DoLayout", &DoLayout, allow_raw_pointers());
  function("Print", &Print, allow_raw_pointers());
  function("Reset", &Reset, allow_raw_pointers());
}