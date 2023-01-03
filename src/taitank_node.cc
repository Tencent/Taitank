/*
 *
 * Tencent is pleased to support the open source community by making Taitank available.
 * Copyright (C) 2021 THL A29 Limited, a Tencent company.  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the “License”);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http:// www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed in writing, software
 * distributed under the License is distributed on an “AS IS” BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and limitations
 * under the License.
 *
 */

#include "taitank_node.h"

#include <memory.h>

#include <algorithm>
#include <cstring>
#include <string>

namespace taitank {

// the layout progress refers
// https://www.w3.org/TR/css-flexbox-1/#layout-algorithm

std::string getIndentString(int indent) {
  std::string str;
  for (int i = 0; i < indent; i++) {
    str += " ";
  }
  return str;
}

std::string toString(float value) {
  if (isUndefined(value)) {
    return "NAN";
  } else {
    char str[10] = {0};
    snprintf(str, 9, "%0.f", PixelRoundInt(value));
    return str;
  }
}

void TaitankNode::PrintNode(uint32_t indent) {
  std::string indent_string = getIndentString(static_cast<int>(indent));
  std::string start_string;
  start_string =
      indent_string + "<div layout=\"width:%s; height:%s; left:%s; top:%s;\" style=\"%s\">\n";
  TaitankLogd(start_string.c_str(), toString(this->layout_result_.dim[0]).c_str(),
              toString(this->layout_result_.dim[1]).c_str(),
              toString(this->layout_result_.position[0]).c_str(),
              toString(this->layout_result_.position[1]).c_str(), this->style_.toString().c_str());

  std::vector<TaitankNodeRef>& items = this->children_;
  for (auto item : items) {    
    item->PrintNode(indent + 4);
  }
  std::string end_string = indent_string + "</div>\n";
  TaitankLogd(end_string.c_str());
}

TaitankNode::TaitankNode(TaitankConfigRef config) {
  context_ = nullptr;
  parent_ = nullptr;
  measure_ = nullptr;
  dirtied_function_ = nullptr;
  config_ = config;

  InitLayoutResult();
  in_initail_state_ = true;
}

TaitankNode::~TaitankNode() {
  // remove from parent
  if (parent_ != nullptr) {
    parent_->RemoveChild(this);
    parent_ = nullptr;
  }

  // set child's parent as null
  for (auto item : children_) {  
    if (item != nullptr) {
      item->SetParent(nullptr);
    }
  }

  children_.clear();
}

void TaitankNode::InitLayoutResult() {
#ifdef LAYOUT_TIME_ANALYZE
  fetchCount = 0;
#endif
  is_frozen_ = false;
  is_dirty_ = true;
  has_new_layout_ = false;
  layout_result_.dim[DIMENSION_WIDTH] = 0;
  layout_result_.dim[DIMENSION_HEIGHT] = 0;

  memset(reinterpret_cast<void*>(layout_result_.position), 0, sizeof(float) * 4);
  memset(reinterpret_cast<void*>(layout_result_.cached_position), 0, sizeof(float) * 4);
  memset(reinterpret_cast<void*>(layout_result_.margin), 0, sizeof(float) * 4);
  memset(reinterpret_cast<void*>(layout_result_.padding), 0, sizeof(float) * 4);
  memset(reinterpret_cast<void*>(layout_result_.border), 0, sizeof(float) * 4);

  layout_result_.had_overflow = false;
  layout_result_.direction = DIRECTION_INHERIT;
}

bool TaitankNode::Reset() {
  if (ChildCount() != 0 || GetParent() != nullptr) return false;
  children_.clear();
  children_.shrink_to_fit();
  InitLayoutResult();
  in_initail_state_ = true;
  return true;
}

void TaitankNode::ResetLayoutRecursive(bool is_display_none) {
  if (in_initail_state_ && is_display_none) {
    return;
  }
  InitLayoutResult();
  if (!is_display_none) {  // see HPNode::removeChild
    // set result as undefined.see HPNodeChildTest.cpp
    // in tests/folder
    layout_result_.dim[DIMENSION_WIDTH] = VALUE_UNDEFINED;
    layout_result_.dim[DIMENSION_HEIGHT] = VALUE_UNDEFINED;
  } else {
    in_initail_state_ = true;  // prevent resetLayoutRecursive run many times in recursive
    // in DisplayNone state, set hasNewLayout as true;
    // set dirty false;
    SetHasNewLayout(true);
    SetDirty(false);
  }
  // if just because parent's display type change,
  // not to clear child layout cache, can be reused.
  layout_cache_.ClearCache();
  for (size_t i = 0; i < children_.size(); i++) {
    TaitankNodeRef item = children_[i];
    item->ResetLayoutRecursive(is_display_none);
  }
}

TaitankStyle TaitankNode::GetStyle() const { return style_; }

void TaitankNode::SetStyle(const TaitankStyle& st) { style_ = st; }

bool TaitankNode::SetMeasureFunction(TaitankMeasureFunction measure_function) {
  if (measure_ == measure_function) {
    return true;
  }

  // not leaf node , not set measure
  if (ChildCount() > 0) {
    return false;
  }

  measure_ = measure_function;
  style_.node_type_ = measure_function ? NODETYPE_TEXT : NODETYPE_DEFAULT;
  MarkAsDirty();
  return true;
}

void TaitankNode::SetParent(TaitankNodeRef parent) { parent_ = parent; }

TaitankNodeRef TaitankNode::GetParent() const { return parent_; }

void TaitankNode::AddChild(TaitankNodeRef item) {
  if (item == nullptr) {
    return;
  }
  item->SetParent(this);
  children_.push_back(item);
  MarkAsDirty();
}

bool TaitankNode::InsertChild(TaitankNodeRef item, uint32_t index) {
  // measure node cannot have child.
  if (item == nullptr || measure_ != nullptr) {
    return false;
  }
  item->SetParent(this);
  children_.insert(children_.begin() + index, item);
  MarkAsDirty();
  return true;
}

TaitankNodeRef TaitankNode::GetChild(uint32_t index) {
  if (index > children_.size() - 1) {
    return nullptr;
  }
  return children_[index];
}

bool TaitankNode::RemoveChild(TaitankNodeRef child) {
  auto p = std::find(children_.begin(), children_.end(), child);
  if (p != children_.end()) {
    children_.erase(p);
    child->SetParent(nullptr);
    child->ResetLayoutRecursive(false);
    MarkAsDirty();
    return true;
  }
  return false;
}

bool TaitankNode::RemoveChild(uint32_t index) {
  if (index > children_.size() - 1) {
    return false;
  }
  TaitankNodeRef child = GetChild(index);
  if (child != nullptr) {
    child->SetParent(nullptr);
    child->ResetLayoutRecursive(false);
  }
  children_.erase(children_.begin() + index);
  MarkAsDirty();
  return true;
}

uint32_t TaitankNode::ChildCount() const { return children_.size(); }

void TaitankNode::SetDisplayType(DisplayType display_type) {
  if (style_.display_type_ == display_type) return;
  style_.display_type_ = display_type;
  is_dirty_ = false;  // force following markAsDirty did effect to its parent
  MarkAsDirty();
}

void TaitankNode::MarkAsDirty() {
  if (!is_dirty_) {
    SetDirty(true);
    if (parent_) {
      parent_->MarkAsDirty();
    }
  }
}

void TaitankNode::SetHasNewLayout(bool has_new_layout) { has_new_layout_ = has_new_layout; }

bool TaitankNode::GetHasNewLayout() { return has_new_layout_; }

void TaitankNode::SetDirty(bool dirty) {
  if (is_dirty_ == dirty) {
    return;
  }
  is_dirty_ = dirty;
  if (is_dirty_) {
    // reset layout direction to initial state
    // need to calculated again
    SetLayoutDirection(DIRECTION_INHERIT);
    // if is dirty, reset frozen.
    is_frozen_ = false;
    // if is dirty, layout cache muse be in clear state.
    layout_cache_.ClearCache();
    if (dirtied_function_ != nullptr) {
      dirtied_function_(this);
    }
  }
}

void TaitankNode::SetDirtiedFunction(TaitankDirtiedFunction dirtied_function) {
  dirtied_function_ = dirtied_function;
}

void TaitankNode::SetContext(void* context) { context_ = context; }

void* TaitankNode::GetContext() { return context_; }

bool TaitankNode::IsLayoutDimensionDefined(FlexDirection axis) {
  return isDefined(layout_result_.dim[kAxisDim[axis]]);
}

void TaitankNode::SetLayoutDimension(FlexDirection axis, float value) {
  layout_result_.dim[kAxisDim[axis]] = value;
}

inline void TaitankNode::SetLayoutDirection(TaitankDirection direction) {
  layout_result_.direction = direction;
}

inline TaitankDirection TaitankNode::GetLayoutDirection() { return layout_result_.direction; }

float TaitankNode::GetLayoutDimension(FlexDirection axis) {
  if (!IsLayoutDimensionDefined(axis)) {
    return VALUE_UNDEFINED;
  }
  return layout_result_.dim[kAxisDim[axis]];
}

float TaitankNode::GetMainAxisDimension() {
  FlexDirection mainAxis = style_.flex_direction_;
  if (!IsLayoutDimensionDefined(mainAxis)) {
    return VALUE_UNDEFINED;
  }
  return layout_result_.dim[kAxisDim[mainAxis]];
}

float TaitankNode::GetStartBorder(FlexDirection axis) { return style_.GetStartBorder(axis); }

float TaitankNode::GetEndBorder(FlexDirection axis) { return style_.GetEndBorder(axis); }

float TaitankNode::GetStartPaddingAndBorder(FlexDirection axis) {
  return style_.GetStartPadding(axis) + style_.GetStartBorder(axis);
}

float TaitankNode::GetEndPaddingAndBorder(FlexDirection axis) {
  return style_.GetEndPadding(axis) + style_.GetEndBorder(axis);
}

float TaitankNode::GetPaddingAndBorder(FlexDirection axis) {
  return GetStartPaddingAndBorder(axis) + GetEndPaddingAndBorder(axis);
}

float TaitankNode::GetStartMargin(FlexDirection axis) { return style_.GetStartMargin(axis); }

float TaitankNode::GetEndMargin(FlexDirection axis) { return style_.GetEndMargin(axis); }

float TaitankNode::GetMargin(FlexDirection axis) {
  return style_.GetStartMargin(axis) + style_.GetEndMargin(axis);
}

bool TaitankNode::IsAutoStartMargin(FlexDirection axis) { return style_.IsAutoStartMargin(axis); }

bool TaitankNode::IsAutoEndMargin(FlexDirection axis) { return style_.IsAutoEndMargin(axis); }

void TaitankNode::SetLayoutStartMargin(FlexDirection axis, float value) {
  layout_result_.margin[kAxisStart[axis]] = value;
}

void TaitankNode::SetLayoutEndMargin(FlexDirection axis, float value) {
  layout_result_.margin[kAxisEnd[axis]] = value;
}

inline float TaitankNode::GetLayoutMargin(FlexDirection axis) {
  return GetLayoutStartMargin(axis) + GetLayoutEndMargin(axis);
}

float TaitankNode::GetLayoutStartMargin(FlexDirection axis) {
  return isDefined(layout_result_.margin[kAxisStart[axis]])
             ? layout_result_.margin[kAxisStart[axis]]
             : 0;
}

float TaitankNode::GetLayoutEndMargin(FlexDirection axis) {
  return isDefined(layout_result_.margin[kAxisEnd[axis]]) ? layout_result_.margin[kAxisEnd[axis]]
                                                          : 0;
}

/* If both axisStart and axisEnd are defined,
 * then use axisStart. Otherwise use which is defined.
 * @param axis flex direction
 * @param forAxisStart
 * 		  true  get relative value for axis start
 * 		  false get relative value for axis end
 */
float TaitankNode::ResolveRelativePosition(FlexDirection axis, bool for_axis_start) {
  if (style_.position_type_ != POSITION_TYPE_RELATIVE) {
    return 0.0f;
  }

  if (isDefined(style_.GetStartPosition(axis))) {
    float value = style_.GetStartPosition(axis);
    return for_axis_start ? value : -value;
  } else if (isDefined(style_.GetEndPosition(axis))) {
    float value = style_.GetEndPosition(axis);
    return for_axis_start ? -value : value;
  }

  return 0.0f;
}

void TaitankNode::SetLayoutStartPosition(FlexDirection axis, float value,
                                         bool add_relative_position) {
  if (add_relative_position && style_.position_type_ == POSITION_TYPE_RELATIVE) {
    value += ResolveRelativePosition(axis, true);
  }

  if (!FloatIsEqual(layout_result_.cached_position[kAxisStart[axis]], value)) {
    layout_result_.cached_position[kAxisStart[axis]] = value;
    SetHasNewLayout(true);
  }

  layout_result_.position[kAxisStart[axis]] = value;
}

void TaitankNode::SetLayoutEndPosition(FlexDirection axis, float value,
                                       bool add_relative_position) {
  if (add_relative_position && style_.position_type_ == POSITION_TYPE_RELATIVE) {
    value += ResolveRelativePosition(axis, false);
  }

  if (!FloatIsEqual(layout_result_.cached_position[kAxisEnd[axis]], value)) {
    layout_result_.cached_position[kAxisEnd[axis]] = value;
    SetHasNewLayout(true);
  }

  layout_result_.position[kAxisEnd[axis]] = value;
}

float TaitankNode::GetLayoutStartPosition(FlexDirection axis) {
  return layout_result_.position[kAxisStart[axis]];
}

float TaitankNode::GetLayoutEndPosition(FlexDirection axis) {
  return layout_result_.position[kAxisEnd[axis]];
}

// calculate main axis by refer this node's flex direction
// and layout direction which resolved in resolveDirection.
FlexDirection TaitankNode::ResolveMainAxis() {
  FlexDirection mainAxis = style_.flex_direction_;
  TaitankDirection direction = GetLayoutDirection();
  if (direction == DIRECTION_RTL) {
    if (mainAxis == FLEX_DIRECTION_ROW) {
      return FLEX_DIRECTION_ROW_REVERSE;
    } else if (mainAxis == FLEX_DIRECTION_ROW_REVERSE) {
      return FLEX_DIRECTION_ROW;
    }
  }
  return mainAxis;
}

/* calculate cross axis by refer this node's flex properties
 * and layout direction which resolved in resolveDirection.
 * must use this method when cross axis alignment
 * to determine cross start & cross end
 */
FlexDirection TaitankNode::ResolveCrossAxis() {
  FlexDirection mainAxis = style_.flex_direction_;
  FlexDirection crossAxis;
  // cross axis's direction rely on flex wrap mode.
  if (IsRowDirection(mainAxis)) {
    if (style_.flex_wrap_ == FLEX_WRAP_REVERSE) {
      crossAxis = FLEX_DIRECTION_COLUNM_REVERSE;
    } else {
      crossAxis = FLEX_DIRECTION_COLUMN;
    }
  } else {
    if (style_.flex_wrap_ == FLEX_WRAP_REVERSE) {
      crossAxis = FLEX_DIRECTION_ROW_REVERSE;
    } else {
      crossAxis = FLEX_DIRECTION_ROW;
    }
    // in this situation crossAxis is Row Direction
    // should think about node's layout direction(HPDirection)
    TaitankDirection direction = GetLayoutDirection();
    if (direction == DIRECTION_RTL) {
      if (crossAxis == FLEX_DIRECTION_ROW) {
        crossAxis = FLEX_DIRECTION_ROW_REVERSE;
      } else if (crossAxis == FLEX_DIRECTION_ROW_REVERSE) {
        crossAxis = FLEX_DIRECTION_ROW;
      }
    }
  }
  return crossAxis;
}

FlexAlign TaitankNode::GetNodeAlign(TaitankNodeRef item) {
  ASSERT(item != nullptr);
  if (item->style_.align_self_ == FLEX_ALIGN_AUTO) {
    return style_.align_items_;
  }
  return item->style_.align_self_;
}

float TaitankNode::GetBoundAxis(FlexDirection axis, float value) {
  float min = style_.min_dim_[kAxisDim[axis]];
  float max = style_.max_dim_[kAxisDim[axis]];
  float boundValue = value;
  if (!isUndefined(max) && max >= 0.0 && boundValue > max) {
    boundValue = max;
  }
  if (!isUndefined(min) && min >= 0.0 && boundValue < min) {
    boundValue = min;
  }
  return boundValue;
}

void TaitankNode::SetConfig(TaitankConfigRef config) {
  config_ = config;
}

TaitankConfigRef TaitankNode::GetConfig() const {
  return config_;
};

inline TaitankDirection TaitankNode::ResolveDirection(TaitankDirection parent_direction) {
  return style_.direction_ == DIRECTION_INHERIT
             ? (parent_direction > DIRECTION_INHERIT ? parent_direction : DIRECTION_LTR)
             : style_.direction_;
}

// called after resolveDirection
void TaitankNode::ResolveStyleValues() {
  //  if (!isDirty) {
  //    return;
  //  }
  FlexDirection mainAxis = ResolveMainAxis();
  FlexDirection crossAxis = ResolveCrossAxis();
  // set layout margin value
  // auto margins are treated as zero. may be modified during layout process
  SetLayoutStartMargin(mainAxis, GetStartMargin(mainAxis));
  SetLayoutEndMargin(mainAxis, GetEndMargin(mainAxis));
  SetLayoutStartMargin(crossAxis, GetStartMargin(crossAxis));
  SetLayoutEndMargin(crossAxis, GetEndMargin(crossAxis));

  // set layout padding value
  layout_result_.padding[kAxisStart[mainAxis]] = style_.GetStartPadding(mainAxis);
  layout_result_.padding[kAxisEnd[mainAxis]] = style_.GetEndPadding(mainAxis);
  layout_result_.padding[kAxisStart[crossAxis]] = style_.GetStartPadding(crossAxis);
  layout_result_.padding[kAxisEnd[crossAxis]] = style_.GetEndPadding(crossAxis);

  // set layout border value;
  layout_result_.border[kAxisStart[mainAxis]] = style_.GetStartBorder(mainAxis);
  layout_result_.border[kAxisEnd[mainAxis]] = style_.GetEndBorder(mainAxis);
  layout_result_.border[kAxisStart[crossAxis]] = style_.GetStartBorder(crossAxis);
  layout_result_.border[kAxisEnd[crossAxis]] = style_.GetEndBorder(crossAxis);
}

#ifdef LAYOUT_TIME_ANALYZE
static int layoutCount = 0;
static int layoutCacheCount = 0;
static int measureCount = 0;
static int measureCacheCount = 0;
#endif

void TaitankNode::Layout(float parent_width, float parent_height, TaitankConfigRef config,
                         TaitankDirection parent_direction, void* layout_context) {
#ifdef LAYOUT_TIME_ANALYZE
  layoutCount = 0;
  layoutCacheCount = 0;
  measureCount = 0;
  measureCacheCount = 0;
#endif
  if (isUndefined(style_.flex_basis_) &&
      !isUndefined(style_.dim_[kAxisDim[style_.flex_direction_]])) {
    style_.flex_basis_ = style_.dim_[kAxisDim[style_.flex_direction_]];
  }

  // if container not set itself width and parent width is set,
  // set container width  as parentWidth subtract margin
  bool styleWidthReset = false;
  if (isUndefined(style_.dim_[DIMENSION_WIDTH]) && isDefined(parent_width)) {
    float containerWidth = parent_width - GetMargin(FLEX_DIRECTION_ROW);
    style_.SetDimension(DIMENSION_WIDTH, containerWidth > 0.0f ? containerWidth : 0.0f);
    styleWidthReset = true;
  }

  bool styleHeightReset = false;
  if (isUndefined(style_.dim_[DIMENSION_HEIGHT]) && isDefined(parent_height)) {
    float containerHeight = parent_height - GetMargin(FLEX_DIRECTION_COLUMN);
    style_.SetDimension(DIMENSION_HEIGHT, containerHeight > 0.0f ? containerHeight : 0.0f);
    styleHeightReset = true;
  }
  LayoutImpl(parent_width, parent_height, parent_direction, LAYOUT_ACTION_LAYOUT, layout_context);
  if (styleWidthReset) {
    style_.SetDimension(DIMENSION_WIDTH, VALUE_UNDEFINED);
  }
  if (styleHeightReset) {
    style_.SetDimension(DIMENSION_HEIGHT, VALUE_UNDEFINED);
  }

  // calculate container's position
  FlexDirection mainAxis = ResolveMainAxis();
  FlexDirection crossAxis = ResolveCrossAxis();
  SetLayoutStartPosition(mainAxis, GetStartMargin(mainAxis), true);
  SetLayoutEndPosition(mainAxis, GetEndMargin(mainAxis), true);
  SetLayoutStartPosition(crossAxis, GetStartMargin(crossAxis), true);
  SetLayoutEndPosition(crossAxis, GetEndMargin(crossAxis), true);

  // node 's layout is complete
  // convert its and its descendants position and size to a integer value.
  ConvertLayoutResult(0.0f, 0.0f, config->GetScaleFactor());

#ifdef LAYOUT_TIME_ANALYZE
  HPLog(LogLevelDebug, "TaitankLayoutTime layout: count %d cache %d, measure: count %d cache %d",
        layoutCount, layoutCacheCount, measureCount, measureCacheCount);
#endif
}

// 3.Determine the flex base size and hypothetical main size of each item
void TaitankNode::CalculateItemsFlexBasis(TaitankSize available_size, void* layout_context) {
  FlexDirection mainAxis = style_.flex_direction_;
  std::vector<TaitankNodeRef>& items = children_;
  for (size_t i = 0; i < items.size(); i++) {
    TaitankNodeRef item = items[i];
    // for display none item, reset its and its descendants layout result.
    if (item->style_.display_type_ == DISPLAY_TYPE_NONE) {
      item->ResetLayoutRecursive();
      continue;
    }
    // https://stackoverflow.com/questions/34352140/what-are-the-differences-between-flex-basis-and-width
    // flex-basis has no effect on absolutely-positioned flex items. width and
    // height properties would be necessary. Absolutely-positioned flex items do
    // not participate in flex layout.
    if (item->style_.position_type_ == POSITION_TYPE_ABSOLUTE) {
      continue;
    }
    // 3.Determine the flex base size and hypothetical main size of each item:
    // 3.1 If the item has a definite used flex basis, that's the flex base
    // size.
    if (isDefined(item->style_.GetFlexBasis()) && isDefined(style_.dim_[kAxisDim[mainAxis]])) {
      item->layout_result_.flex_base_size = item->style_.GetFlexBasis();
    } else if (isDefined(item->style_.dim_[kAxisDim[mainAxis]])) {
      // flex-basis:auto:
      // When specified on a flex item, the auto keyword retrieves the value
      // of the main size property as the used flex-basis.
      // If that value is itself auto, then the used value is content.
      item->layout_result_.flex_base_size = item->style_.dim_[kAxisDim[mainAxis]];
    } else {
      // 3.2 Otherwise, size the item into the available space using its used
      // flex basis in place of its main size,
      float oldMainDim = item->style_.GetDimension(mainAxis);
      // item->style.flexBasis is auto value
      item->style_.SetDimension(mainAxis, item->style_.flex_basis_);
      item->LayoutImpl(
          available_size.width, available_size.height, GetLayoutDirection(),
          IsRowDirection(mainAxis) ? LAYOUT_ACTION_MEASURE_WIDTH : LAYOUT_ACTION_MEASURE_HEIGHT,
          layout_context);
      item->style_.SetDimension(mainAxis, oldMainDim);

      item->layout_result_.flex_base_size = isDefined(item->layout_result_.dim[kAxisDim[mainAxis]])
                                                ? item->layout_result_.dim[kAxisDim[mainAxis]]
                                                : 0;
    }

    // item->result.dim[axisDim[mainAxis]] = item->boundAxis(mainAxis,
    // item->result.flexBasis); The hypothetical main size is the item's flex
    // base size clamped according to its min and max main size properties (and
    // flooring the content box size at zero).
    item->layout_result_.hypothetical_main_axis_size =
        item->GetBoundAxis(mainAxis, item->layout_result_.flex_base_size);
    item->layout_result_.hypothetical_main_axis_margin_boxsize =
        item->layout_result_.hypothetical_main_axis_size + item->GetMargin(mainAxis);
  }
}

bool TaitankNode::CollectFlexLines(std::vector<FlexLine*>& flex_lines, TaitankSize available_size) {
  std::vector<TaitankNodeRef>& items = children_;
  bool sumHypotheticalMainSizeOverflow = false;
  float availableWidth = kAxisDim[style_.flex_direction_] == DIMENSION_WIDTH
                             ? available_size.width
                             : available_size.height;
  if (isUndefined(availableWidth)) {
    availableWidth = INFINITY;
  }

  FlexLine* line = nullptr;
  auto itemsSize = items.size();
  size_t i = 0;
  while (i < itemsSize) {
    TaitankNodeRef item = items[i];
    if (item->style_.position_type_ == POSITION_TYPE_ABSOLUTE ||
        item->style_.display_type_ == DISPLAY_TYPE_NONE) {
      // see TaitankTest.dirty_mark_all_children_as_dirty_when_display_changes
      // when display changes.
      if (i == itemsSize - 1 && line != nullptr) {
        flex_lines.push_back(line);
        break;
      }
      //
      i++;
      continue;
    }

    if (line == nullptr) {
      line = new FlexLine(this);
    }

    float leftSpace = availableWidth - (line->sum_hypothetical_main_size_ +
                                        item->layout_result_.hypothetical_main_axis_margin_boxsize);
    if (leftSpace < 0) {
      // may be line wrap happened
      sumHypotheticalMainSizeOverflow = true;
    }

    if (style_.flex_wrap_ == FLEX_NO_WRAP) {
      line->AddItem(item);
      if (i == itemsSize - 1) {
        flex_lines.push_back(line);
        break;
      }
      i++;
    } else {
      if (leftSpace >= 0 || line->IsEmpty()) {
        line->AddItem(item);
        if (i == itemsSize - 1) {
          flex_lines.push_back(line);
          line = nullptr;
        }
        i++;
      } else {
        flex_lines.push_back(line);
        line = nullptr;
      }
    }
  }

  return sumHypotheticalMainSizeOverflow;
}

void TaitankNode::CacheLayoutOrMeasureResult(TaitankSize available_size,
                                             TaitankSizeMode measure_mode,
                                             FlexLayoutAction layout_action) {
  TaitankSize resultSize = {layout_result_.dim[DIMENSION_WIDTH],
                            layout_result_.dim[DIMENSION_HEIGHT]};
  layout_cache_.CacheResult(available_size, resultSize, measure_mode, layout_action);
  if (layout_action == LAYOUT_ACTION_LAYOUT) {
    SetDirty(false);
    SetHasNewLayout(true);
    in_initail_state_ = false;
  }
}

/*
 * availableWidth/availableHeight  has subtract its margin and padding.
 */
void TaitankNode::LayoutSingleNode(float available_width, MeasureMode width_measure_mode,
                                   float available_height, MeasureMode height_measure_mode,
                                   FlexLayoutAction layout_action, void* layout_context) {
  if (width_measure_mode == MEASURE_MODE_EXACTLY && height_measure_mode == MEASURE_MODE_EXACTLY) {
    layout_result_.dim[DIMENSION_WIDTH] = available_width + GetPaddingAndBorder(FLEX_DIRECTION_ROW);
    layout_result_.dim[DIMENSION_HEIGHT] =
        available_height + GetPaddingAndBorder(FLEX_DIRECTION_COLUMN);
  } else {
    // measure text, image etc. content node;
    TaitankSize dim = {0, 0};
    bool needMeasure = true;
    if (style_.flex_grow_ > 0 && style_.flex_shrink_ > 0 && parent_ && parent_->ChildCount() == 1 &&
        !parent_->style_.IsDimensionAuto(FLEX_DIRECTION_ROW) &&
        !parent_->style_.IsDimensionAuto(FLEX_DIRECTION_COLUMN)) {
      // don't measure single grow shrink child
      // see HPMeasureTest.cpp dont_measure_single_grow_shrink_child
      needMeasure = false;
    }

    if (!needMeasure) {
      dim.width = available_width;
      dim.height = available_height;
    } else if (measure_ != nullptr && needMeasure) {
      dim = measure_(this, available_width, width_measure_mode, available_height,
                     height_measure_mode, layout_context);
    }

    layout_result_.dim[DIMENSION_WIDTH] = GetBoundAxis(
        FLEX_DIRECTION_ROW, width_measure_mode == MEASURE_MODE_EXACTLY
                                ? (available_width + GetPaddingAndBorder(FLEX_DIRECTION_ROW))
                                : (dim.width + GetPaddingAndBorder(FLEX_DIRECTION_ROW)));

    layout_result_.dim[DIMENSION_HEIGHT] = GetBoundAxis(
        FLEX_DIRECTION_COLUMN, height_measure_mode == MEASURE_MODE_EXACTLY
                                   ? (available_height + GetPaddingAndBorder(FLEX_DIRECTION_COLUMN))
                                   : (dim.height + GetPaddingAndBorder(FLEX_DIRECTION_COLUMN)));
  }

  TaitankSize availableSize = {available_width, available_height};
  TaitankSizeMode measureMode = {width_measure_mode, height_measure_mode};
  CacheLayoutOrMeasureResult(availableSize, measureMode, layout_action);
}

// reference: https://www.w3.org/TR/css-flexbox-1/#layout-algorithm
void TaitankNode::LayoutImpl(float parent_width, float parent_height,
                             TaitankDirection parent_direction, FlexLayoutAction layout_action,
                             void* layout_context) {
#ifdef LAYOUT_TIME_ANALYZE
  if (layoutAction == LAYOUT_ACTION_LAYOUT) {
    layoutCount++;
  } else {
    measureCount++;
  }
#endif

  TaitankDirection direction = ResolveDirection(parent_direction);
  if (GetLayoutDirection() != direction) {
    SetLayoutDirection(direction);
    layout_cache_.ClearCache();
    ResolveStyleValues();
  }

  FlexDirection mainAxis = style_.flex_direction_;
  bool performLayout = layout_action == LAYOUT_ACTION_LAYOUT;
  if (isDefined(parent_width)) {
    parent_width -= GetMargin(FLEX_DIRECTION_ROW);
    parent_width = parent_width >= 0.0f ? parent_width : 0.0f;
  }

  if (isDefined(parent_height)) {
    parent_height -= GetMargin(FLEX_DIRECTION_COLUMN);
    parent_height = parent_height >= 0.0f ? parent_height : 0.0f;
  }

  // get node dim from style
  float nodeWidth = isDefined(style_.dim_[DIMENSION_WIDTH])
                        ? GetBoundAxis(FLEX_DIRECTION_ROW, style_.dim_[DIMENSION_WIDTH])
                        : VALUE_UNDEFINED;

  float nodeHeight = isDefined(style_.dim_[DIMENSION_HEIGHT])
                         ? GetBoundAxis(FLEX_DIRECTION_COLUMN, style_.dim_[DIMENSION_HEIGHT])
                         : VALUE_UNDEFINED;

  // layoutMeasuredWidth  layoutMeasuredHeight used in
  // "Determine the flex base size and hypothetical main size of each item"
  if (layout_action == LAYOUT_ACTION_MEASURE_WIDTH && isDefined(nodeWidth)) {
#ifdef LAYOUT_TIME_ANALYZE
    measureCacheCount++;
#endif
    layout_result_.dim[DIMENSION_WIDTH] = nodeWidth;
    return;
  } else if (layout_action == LAYOUT_ACTION_MEASURE_HEIGHT && isDefined(nodeHeight)) {
#ifdef LAYOUT_TIME_ANALYZE
    measureCacheCount++;
#endif
    layout_result_.dim[DIMENSION_HEIGHT] = nodeHeight;
    return;
  }

  // 9.2.Line Length Determination
  // Determine the available main and cross space for the flex items.
  // For each dimension, if that dimension of the flex container's content box
  // is a definite size, use that; if that dimension of the flex container is
  // being sized under a min or max-content constraint, the available space in
  // that dimension is that constraint; otherwise, subtract the flex container's
  // margin, border, and padding from the space available to the flex container
  // in that dimension and use that value. This might result in an infinite
  // value.

  // get available size for layout or measure
  float availableWidth = VALUE_UNDEFINED;
  if (isDefined(nodeWidth)) {
    availableWidth = nodeWidth - GetPaddingAndBorder(FLEX_DIRECTION_ROW);
  } else if (isDefined(parent_width)) {
    availableWidth = parent_width - GetPaddingAndBorder(FLEX_DIRECTION_ROW);
  }

  float availableHeight = VALUE_UNDEFINED;
  if (isDefined(nodeHeight)) {
    availableHeight = nodeHeight - GetPaddingAndBorder(FLEX_DIRECTION_COLUMN);
  } else if (isDefined(parent_height)) {
    availableHeight = parent_height - GetPaddingAndBorder(FLEX_DIRECTION_COLUMN);
  }

  if (isDefined(style_.max_dim_[DIMENSION_WIDTH])) {
    if (FloatIsEqual(style_.max_dim_[DIMENSION_WIDTH], style_.min_dim_[DIMENSION_WIDTH])) {
      style_.dim_[DIMENSION_WIDTH] = style_.min_dim_[DIMENSION_WIDTH];
    }
    float maxDimWidth = style_.max_dim_[DIMENSION_WIDTH] - GetPaddingAndBorder(FLEX_DIRECTION_ROW);
    if (maxDimWidth >= 0.0f && maxDimWidth < NanAsINF(availableWidth)) {
      availableWidth = maxDimWidth;
    }
  }

  if (isDefined(style_.max_dim_[DIMENSION_HEIGHT])) {
    if (FloatIsEqual(style_.max_dim_[DIMENSION_HEIGHT], style_.min_dim_[DIMENSION_HEIGHT])) {
      style_.dim_[DIMENSION_HEIGHT] = style_.min_dim_[DIMENSION_HEIGHT];
    }
    float maxDimHeight =
        style_.max_dim_[DIMENSION_HEIGHT] - GetPaddingAndBorder(FLEX_DIRECTION_COLUMN);
    if (maxDimHeight >= 0.0f && maxDimHeight < NanAsINF(availableHeight)) {
      availableHeight = maxDimHeight;
    }
  }

  // available size to layout...
  availableWidth = availableWidth < 0.0f ? 0.0f : availableWidth;
  availableHeight = availableHeight < 0.0f ? 0.0f : availableHeight;

  MeasureMode widthMeasureMode = MEASURE_MODE_UNDEFINED;
  if (isDefined(style_.dim_[DIMENSION_WIDTH])) {
    widthMeasureMode = MEASURE_MODE_EXACTLY;
  } else if (isDefined(availableWidth)) {
    if (parent_ && parent_->style_.IsOverflowScroll() &&
        IsRowDirection(parent_->style_.flex_direction_)) {
      widthMeasureMode = MEASURE_MODE_UNDEFINED;
      availableWidth = VALUE_AUTO;
    } else {
      widthMeasureMode = MEASURE_MODE_AT_MOST;
    }
  }

  MeasureMode heightMeasureMode = MEASURE_MODE_UNDEFINED;
  if (isDefined(style_.dim_[DIMENSION_HEIGHT])) {
    heightMeasureMode = MEASURE_MODE_EXACTLY;
  } else if (isDefined(availableHeight)) {
    if (parent_ && parent_->style_.IsOverflowScroll() &&
        IsColumnDirection(parent_->style_.flex_direction_)) {
      heightMeasureMode = MEASURE_MODE_UNDEFINED;
      availableHeight = VALUE_AUTO;
    } else {
      heightMeasureMode = MEASURE_MODE_AT_MOST;
    }
  }

  TaitankSize availableSize = {availableWidth, availableHeight};
  TaitankSizeMode measureMode = {widthMeasureMode, heightMeasureMode};
  MeasureResult* cacheResult = layout_cache_.GetCachedMeasureResult(
      availableSize, measureMode, layout_action, measure_ != nullptr);
  if (cacheResult != nullptr && layout_action != LAYOUT_ACTION_LAYOUT) {
    // set Result....
    switch (layout_action) {
      case LAYOUT_ACTION_MEASURE_WIDTH:
#ifdef LAYOUT_TIME_ANALYZE
        measureCacheCount++;
#endif
        ASSERT(isDefined(cacheResult->result_size.width));
        layout_result_.dim[DIMENSION_WIDTH] = cacheResult->result_size.width;
        break;
      case LAYOUT_ACTION_MEASURE_HEIGHT:
#ifdef LAYOUT_TIME_ANALYZE
        measureCacheCount++;
#endif
        ASSERT(isDefined(cacheResult->result_size.height));
        layout_result_.dim[DIMENSION_HEIGHT] = cacheResult->result_size.height;
        break;
      case LAYOUT_ACTION_LAYOUT:

        // if it's a measure node and cache result cached by
        // LAYOUT_ACTION_MEASURE_WIDTH or LAYOUT_ACTION_MEASURE_HEIGHT so this
        // is first layout for current Measure Node, set hasNewLayout as true,
        // if not, this node's layout result value has been fetched to java and
        // set hasNewLayout false in FlexNode.cc so not set hasNewLayout as true
        // to avoid JNI call again in FLexNode.cc
        if (cacheResult->layout_action != LAYOUT_ACTION_LAYOUT && measure_ != nullptr) {
          // need assign result size if layoutAction is different 3.14.2018
          layout_result_.dim[DIMENSION_WIDTH] = cacheResult->result_size.width;
          layout_result_.dim[DIMENSION_HEIGHT] = cacheResult->result_size.height;
          CacheLayoutOrMeasureResult(availableSize, measureMode, layout_action);
        } else {
#ifdef LAYOUT_TIME_ANALYZE
          layoutCacheCount++;
#endif
          // do nothing..
          // layoutCache.cachedLayout object is last layout result.
          // used to determine need layout or not.
        }

        // if it's a measure node , layout could be cache by
        // LAYOUT_ACTION_MEASURE_WIDTH or LAYOUT_ACTION_MEASURE_HEIGHT,so in
        // this case, we need set dirty as false;
        SetDirty(false);

        break;
      default:
        break;
    }
    return;
  }
  // before layout set result's hadOverflow as false.
  if (layout_action == LAYOUT_ACTION_LAYOUT) {
    layout_result_.had_overflow = false;
  }
  // single element measure width and height
  if ((children_.size() == 0)) {
    LayoutSingleNode(availableWidth, widthMeasureMode, availableHeight, heightMeasureMode,
                     layout_action, layout_context);
    return;
  }
  // 3.Determine the flex base size and hypothetical main size of each item
  CalculateItemsFlexBasis(availableSize, layout_context);
  // 9.3. Main Size Determination
  // 5. Collect flex items into flex lines:
  std::vector<FlexLine*> flexLines;
  bool sumHypotheticalMainSizeOverflow = CollectFlexLines(flexLines, availableSize);

  // get max line's  main size
  float maxSumItemsMainSize = 0;
  for (size_t i = 0; i < flexLines.size(); i++) {
    if (flexLines[i]->sum_hypothetical_main_size_ > maxSumItemsMainSize) {
      maxSumItemsMainSize = flexLines[i]->sum_hypothetical_main_size_;
    }
  }

  // 4. Determine the main size of the flex container using the rules of the
  // formatting context in which it participates. For this computation, auto
  // margins on flex items are treated as 0.
  // TODO: if has set , what to do for next run in determineCrossAxisSize's
  // layoutImpl
  float containerInnerMainSize = 0.0f;
  if (isDefined(style_.dim_[kAxisDim[mainAxis]])) {
    // MEASURE_MODE_EXACTLY
    containerInnerMainSize = style_.dim_[kAxisDim[mainAxis]] - GetPaddingAndBorder(mainAxis);
  } else {
    if (sumHypotheticalMainSizeOverflow) {  // MEASURE_MODE_AT_MOST
      // if sum of hypothetical MainSize > available size;
      float mainInnerSize =
          kAxisDim[mainAxis] == DIMENSION_WIDTH ? availableSize.width : availableSize.height;

      if (maxSumItemsMainSize > mainInnerSize && !style_.IsOverflowScroll()) {
        if (parent_ && parent_->GetNodeAlign(this) == FLEX_ALIGN_STRETCH &&
            kAxisDim[mainAxis] == kAxisDim[parent_->ResolveCrossAxis()] &&
            style_.position_type_ != POSITION_TYPE_ABSOLUTE) {
          // it this node has text child and node main axis(width) is stretch
          // ,cross axis length(height) is undefined
          // text can has multi-line, text's height can affect parent's height
          // in this situation, use availableSize if possible
          containerInnerMainSize = mainInnerSize;
        } else {
          containerInnerMainSize = maxSumItemsMainSize;
        }
      } else {
        containerInnerMainSize = mainInnerSize;
      }
    } else {
      containerInnerMainSize = maxSumItemsMainSize;
    }
  }
  layout_result_.dim[kAxisDim[mainAxis]] =
      GetBoundAxis(mainAxis, containerInnerMainSize + GetPaddingAndBorder(mainAxis));
  // return if its just in measure
  if ((layout_action == LAYOUT_ACTION_MEASURE_WIDTH && IsRowDirection(mainAxis)) ||
      (layout_action == LAYOUT_ACTION_MEASURE_HEIGHT && IsColumnDirection(mainAxis))) {
    // cache layout result & state...
    CacheLayoutOrMeasureResult(availableSize, measureMode, layout_action);
    // free flexLines, allocate in collectFlexLines.
    // TODO: opt.
    for (size_t i = 0; i < flexLines.size(); i++) {
      delete flexLines[i];
    }
    return;
  }

  // 6. Resolving Flexible Lengths
  // To resolve the flexible lengths of the items within a flex line:
  // TODO: //this's the only place that confirm child items main axis size, see
  // item->setLayoutDim
  DetermineItemsMainAxisSize(flexLines, layout_action);

  // 9.4. Cross Size Determination
  // calculate line's cross size in flexLines
  // TODO: The real place that Determine
  // the flex container's used cross size is at step 15.

  float sumLinesCrossSize =
      DetermineCrossAxisSize(flexLines, availableSize, layout_action, layout_context);

  if (!performLayout) {
    // TODO: for measure, I put the calculate of flex container's cross size in
    // here..
    // TODO: why must in step 15 in W3 flex layout algorithm
    // noted by ianwang 12.30.2017.

    // 15.Determine the flex container's used cross size:
    // If the cross size property is a definite size, use that,
    // clamped by the min and max cross size properties of the flex container.
    // Otherwise, use the sum of the flex lines' cross sizes,
    // clamped by the min and max cross size properties of the flex container.
    FlexDirection crossAxis = ResolveCrossAxis();
    float crossDimSize;
    if (isDefined(style_.dim_[kAxisDim[crossAxis]])) {
      crossDimSize = style_.dim_[kAxisDim[crossAxis]];
    } else {
      crossDimSize = (sumLinesCrossSize + GetPaddingAndBorder(crossAxis));
    }
    layout_result_.dim[kAxisDim[crossAxis]] = GetBoundAxis(crossAxis, crossDimSize);
    // cache layout result & state...
    CacheLayoutOrMeasureResult(availableSize, measureMode, layout_action);

    // free flexLines, allocate in collectFlexLines.
    for (size_t i = 0; i < flexLines.size(); i++) {
      delete flexLines[i];
    }
    return;
  }

  // 9.5. Main-Axis Alignment
  MainAxisAlignment(flexLines);

  // 9.6. Cross-Axis Alignment
  // if contianer's innerCross size not defined,
  // then it will be determined in step 15 of crossAxisAlignment
  CrossAxisAlignment(flexLines);

  // free flexLines, allocate in collectFlexLines.
  for (size_t i = 0; i < flexLines.size(); i++) {
    delete flexLines[i];
  }

  // cache layout result & state...
  CacheLayoutOrMeasureResult(availableSize, measureMode, layout_action);
  // layout fixed elements...
  LayoutFixedItems(measureMode, layout_context);

  return;
}

// 9.4. Cross Size Determination
float TaitankNode::DetermineCrossAxisSize(std::vector<FlexLine*>& flex_lines,
                                          TaitankSize available_size,
                                          FlexLayoutAction layout_action, void* layout_context) {
  FlexDirection mainAxis = style_.flex_direction_;
  FlexDirection crossAxis = ResolveCrossAxis();
  float sumLinesCrossSize = 0;
  for (size_t i = 0; i < flex_lines.size(); i++) {
    FlexLine* line = flex_lines[i];
    float maxItemCrossSize = 0;
    for (size_t j = 0; j < line->items_.size(); j++) {
      TaitankNodeRef item = line->items_[j];
      // item's main axis size has been determined.
      // try to calculate the hypothetical cross size of each item
      // that would be stored in result.dim[crossAxis]
      // align stretch may be modify this value in the later step.

      // WARNING TODO: this is the only place that the Recursive flex layout
      // happen. 7.Determine the hypothetical cross size of each item by
      // performing layout with the used main size and the available space,
      // treating auto as fit-content.
      FlexLayoutAction oldLayoutAction = layout_action;
      if (GetNodeAlign(item) == FLEX_ALIGN_STRETCH && item->style_.IsDimensionAuto(crossAxis) &&
          !item->style_.IsAutoMargin(crossAxis) && layout_action == LAYOUT_ACTION_LAYOUT) {
        // Delay layout for stretch item, do layout later in step 11.
        layout_action = kAxisDim[crossAxis] == DIMENSION_WIDTH ? LAYOUT_ACTION_MEASURE_WIDTH
                                                               : LAYOUT_ACTION_MEASURE_HEIGHT;
      }
      float oldMainDim = item->style_.GetDimension(mainAxis);
      item->style_.SetDimension(mainAxis, item->GetLayoutDimension(mainAxis));
      item->LayoutImpl(available_size.width, available_size.height, GetLayoutDirection(),
                       layout_action, layout_context);
      item->style_.SetDimension(mainAxis, oldMainDim);
      layout_action = oldLayoutAction;
      // if child item had overflow , then transfer this state to its parent.
      // see TaitankTest_HadOverflowTests.spacing_overflow_in_nested_nodes in
      // ./tests/HPHadOverflowTest.cpp
      layout_result_.had_overflow = layout_result_.had_overflow | item->layout_result_.had_overflow;

      // TODO: if need support baseline add here
      // 8.Calculate the cross size of each flex line.
      // 1)Collect all the flex items whose inline-axis is parallel to the
      // main-axis, whose align-self is baseline, and whose cross-axis margins
      // are both non-auto. Find the largest of the distances between each
      // item's baseline and its hypothetical outer cross-start edge, and the
      // largest of the distances between each item's baseline and its
      // hypothetical outer cross-end edge, and sum these two values. 2)Among
      // all the items not collected by the previous step, find the largest
      // outer hypothetical cross size. 3)The used cross-size of the flex line
      // is the largest of the numbers found in the previous two steps and zero.

      // Max item cross size
      float itemOutCrossSize = item->GetLayoutDimension(crossAxis) + item->GetMargin(crossAxis);
      if (itemOutCrossSize > maxItemCrossSize) {
        maxItemCrossSize = itemOutCrossSize;
      }
    }

    // 8.Calculate the cross size of each flex line.
    // clip current container cross axis size..
    maxItemCrossSize = GetBoundAxis(crossAxis, maxItemCrossSize);
    line->line_cross_size_ = maxItemCrossSize;
    sumLinesCrossSize += maxItemCrossSize;

    // single line , set line height as container inner height
    if (flex_lines.size() == 1 && isDefined(style_.dim_[kAxisDim[crossAxis]])) {
      // if following assert is true, means front-end's style is in unsuitable
      // state .. such as main axis is undefined but set flex-wrap as FlexWrap.
      // ASSERT(style.flexWrap == FlexNoWrap);
      float innerCrossSize = GetBoundAxis(crossAxis, style_.dim_[kAxisDim[crossAxis]]) -
                             GetPaddingAndBorder(crossAxis);

      line->line_cross_size_ = innerCrossSize;
      sumLinesCrossSize = innerCrossSize;
    }
  }

  // 9.Handle 'align-content: stretch' for lines
  if (isDefined(style_.dim_[kAxisDim[crossAxis]]) && style_.align_content_ == FLEX_ALIGN_STRETCH) {
    float innerCrossSize =
        GetBoundAxis(crossAxis, style_.dim_[kAxisDim[crossAxis]]) - GetPaddingAndBorder(crossAxis);
    if (sumLinesCrossSize < innerCrossSize) {
      for (size_t i = 0; i < flex_lines.size(); i++) {
        FlexLine* line = flex_lines[i];
        line->line_cross_size_ += (innerCrossSize - sumLinesCrossSize) / static_cast<float>(flex_lines.size());
      }
    }
  }

  // 11.Determine the used cross size of each flex item
  // Think about item align-self: stretch
  for (auto line : flex_lines) {  
    for (size_t j = 0; j < line->items_.size(); j++) {
      TaitankNodeRef item = line->items_[j];

      // 1): If a flex item has align-self: stretch, its computed cross size
      // property is auto,
      //    and neither of its cross-axis margins are auto, the used outer cross
      //    size is the used cross size of its flex line, clamped according to
      //    the item's min and max cross size properties.
      // 2):Otherwise,the used cross size is the item's hypothetical cross size.
      if (GetNodeAlign(item) == FLEX_ALIGN_STRETCH && item->style_.IsDimensionAuto(crossAxis) &&
          !item->style_.IsAutoMargin(crossAxis)) {
        item->layout_result_.dim[kAxisDim[crossAxis]] =
            item->GetBoundAxis(crossAxis, line->line_cross_size_ - item->GetMargin(crossAxis));
        // If the flex item has align-self: stretch, redo layout for its
        // contents, treating this used size as its definite cross size so that
        // percentage-sized children can be resolved.
        float oldMainDim = item->style_.GetDimension(mainAxis);
        float oldCrossDim = item->style_.GetDimension(crossAxis);
        item->style_.SetDimension(mainAxis, item->GetLayoutDimension(mainAxis));
        item->style_.SetDimension(crossAxis, item->GetLayoutDimension(crossAxis));
        item->LayoutImpl(available_size.width, available_size.height, GetLayoutDirection(),
                         layout_action, layout_context);
        item->style_.SetDimension(mainAxis, oldMainDim);
        item->style_.SetDimension(crossAxis, oldCrossDim);

      } else {
        // Otherwise, the used cross size is the item's hypothetical cross size.
        // see the step7.
        // item's hypothetical cross size. has been set in
        // result.dim[axisDim[crossAxis]].
      }
    }
  }

  // TODO: Why Determine  the flex container's used cross size in step 15.
  return sumLinesCrossSize;
}

// See  9.7 Resolving Flexible Lengths.
void TaitankNode::DetermineItemsMainAxisSize(std::vector<FlexLine*>& flexLines,
                                             FlexLayoutAction layoutAction) {
  FlexDirection mainAxis = style_.flex_direction_;
  float mainAxisContentSize =
      layout_result_.dim[kAxisDim[mainAxis]] - GetPaddingAndBorder(mainAxis);
  // 6. Resolve the flexible lengths of all the flex items to find their used
  // main size (see section 9.7.)
  for (size_t i = 0; i < flexLines.size(); i++) {
    FlexLine* line = flexLines[i];
    line->SetContainerMainInnerSize(mainAxisContentSize);
    line->FreezeInflexibleItems(layoutAction);
    while (!line->ResolveFlexibleLengths()) {
      ASSERT(line->total_flex_grow_ >= 0);
      ASSERT(line->total_flex_grow_ >= 0);
    }

    if (layoutAction == LAYOUT_ACTION_LAYOUT && line->remaining_free_space_ < 0) {
      layout_result_.had_overflow = true;
    }
  }
}

// 9.5 Main-Axis Alignment
void TaitankNode::MainAxisAlignment(std::vector<FlexLine*>& flexLines) {
  // TODO: RTL::
  // 12. Distribute any remaining free space. For each flex line:
  FlexDirection mainAxis = style_.flex_direction_;
  float mainAxisContentSize = GetLayoutDimension(mainAxis) - GetPaddingAndBorder(mainAxis);
  for (size_t i = 0; i < flexLines.size(); i++) {
    FlexLine* line = flexLines[i];
    line->SetContainerMainInnerSize(mainAxisContentSize);
    line->AlignItems();
  }
}

// 9.6 Cross-Axis Alignment
void TaitankNode::CrossAxisAlignment(std::vector<FlexLine*>& flexLines) {
  FlexDirection crossAxis = ResolveCrossAxis();
  float sumLinesCrossSize = 0;
  auto linesCount = flexLines.size();
  for (size_t i = 0; i < linesCount; i++) {
    FlexLine* line = flexLines[i];
    sumLinesCrossSize += line->line_cross_size_;
    for (size_t j = 0; j < line->items_.size(); j++) {
      TaitankNodeRef item = line->items_[j];
      // 13.Resolve cross-axis auto margins. If a flex item has auto cross-axis
      // margins:
      float remainingFreeSpace = line->line_cross_size_ -
                                 item->layout_result_.dim[kAxisDim[crossAxis]] -
                                 item->GetMargin(crossAxis);
      if (remainingFreeSpace > 0) {
        // If its outer cross size (treating those auto margins as zero) is less
        // than the cross size of its flex line, distribute the difference in
        // those sizes equally to the auto margins.
        if (item->IsAutoStartMargin(crossAxis) && item->IsAutoEndMargin(crossAxis)) {
          item->SetLayoutStartMargin(crossAxis, remainingFreeSpace / 2);
          item->SetLayoutEndMargin(crossAxis, remainingFreeSpace / 2);
        } else if (item->IsAutoStartMargin(crossAxis)) {
          item->SetLayoutStartMargin(crossAxis, remainingFreeSpace);
        } else if (item->IsAutoEndMargin(crossAxis)) {
          item->SetLayoutEndMargin(crossAxis, remainingFreeSpace);
        } else {
          // For margin:: assign style value to result value at this place..
          item->SetLayoutStartMargin(crossAxis, item->GetStartMargin(crossAxis));
          item->SetLayoutEndMargin(crossAxis, item->GetEndMargin(crossAxis));
        }
      } else {
        // Otherwise, if the block-start or inline-start margin
        // (whichever is in the cross axis) is auto, set it to zero.
        // Set the opposite margin so that the outer cross size of the
        // item equals the cross size of its flex line.
        item->SetLayoutStartMargin(crossAxis, item->GetStartMargin(crossAxis));
        item->SetLayoutEndMargin(crossAxis, item->GetEndMargin(crossAxis));
      }

      // 14.Align all flex items along the cross-axis per align-self,
      // if neither of the item's cross-axis margins are auto.
      // calculate item's offset in its line by style align-self
      remainingFreeSpace = line->line_cross_size_ - item->layout_result_.dim[kAxisDim[crossAxis]] -
                           item->GetLayoutMargin(crossAxis);
      float offset = item->GetLayoutStartMargin(crossAxis);
      switch (GetNodeAlign(item)) {  // when align self is auto , it overwrite by align items
        case FLEX_ALIGN_START:
          break;
        case FLEX_ALIGN_CENTER:
          offset += remainingFreeSpace / 2;
          break;
        case FLEX_ALIGN_END:
          offset += remainingFreeSpace;
          break;
          // TODO: case baseline alignment
        default:
          break;
      }
      // include (axisStart[crossAxis] == CSSTop) and (axisStart[crossAxis] ==
      // CSSBottom) For temporary store. use false parameter
      item->SetLayoutStartPosition(crossAxis, offset, false);
    }
  }

  // 15.Determine  the flex container's used cross size:
  // If the cross size property is a definite size, use that,
  // clamped by the min and max cross size properties of the flex container.
  // Otherwise, use the sum of the flex lines' cross sizes,
  // clamped by the min and max cross size properties of the flex container.

  float crossDimSize;
  if (isDefined(style_.dim_[kAxisDim[crossAxis]])) {
    crossDimSize = style_.dim_[kAxisDim[crossAxis]];
  } else {
    crossDimSize = (sumLinesCrossSize + GetPaddingAndBorder(crossAxis));
  }
  layout_result_.dim[kAxisDim[crossAxis]] = GetBoundAxis(crossAxis, crossDimSize);

  // when container's cross size determined align all flex lines by
  // align-content 16.Align all flex lines per align-content
  float innerCrossSize = layout_result_.dim[kAxisDim[crossAxis]] - GetPaddingAndBorder(crossAxis);
  float remainingFreeSpace = innerCrossSize - sumLinesCrossSize;
  float offset = GetStartPaddingAndBorder(crossAxis);
  float space = 0;
  switch (style_.align_content_) {
    case FLEX_ALIGN_START:
      break;
    case FLEX_ALIGN_CENTER:
      offset += remainingFreeSpace / 2;
      break;
    case FLEX_ALIGN_END:
      offset += remainingFreeSpace;
      break;
    case FLEX_ALIGN_SPACE_BETWEEN:
      space = remainingFreeSpace / static_cast<float>(linesCount - 1);
      break;
    case FLEX_ALIGN_SPACE_AROUND:
      space = remainingFreeSpace / static_cast<float>(linesCount);
      offset += space / 2;
      break;
    default:
      break;
  }

  // flex-end::
  // The cross-end margin edge of the flex item is placed flush with the
  // cross-end edge of the line. crossAxisPostionStart calculated along the
  // cross axis direction.
  float crossAxisPostionStart = offset;
  for (size_t i = 0; i < linesCount; i++) {
    FlexLine* line = flexLines[i];
    for (auto item : line->items_) {  
      // include (axisStart[crossAxis] == CSSTop) and (axisStart[crossAxis] ==
      // CSSBottom) getLayoutStartPosition set in step 14.
      item->SetLayoutStartPosition(crossAxis,
                                   crossAxisPostionStart + item->GetLayoutStartPosition(crossAxis));
      // layout start position has use relative ,so end position not use it ,use
      // false parameter.
      item->SetLayoutEndPosition(
          crossAxis,
          (GetLayoutDimension(crossAxis) - item->GetLayoutStartPosition(crossAxis) -
           item->GetLayoutDimension(crossAxis)),
          false);
    }

    crossAxisPostionStart += line->line_cross_size_ + space;
  }
}

// 4.1. Absolutely-Positioned Flex Children
// As it is out-of-flow, an absolutely-positioned child of a flex container
// does not participate in flex layout.
// The static position of an absolutely-positioned child of a flex container
// is determined such that the child is positioned as if it were the sole flex
// item in the flex container, assuming both the child and the flex container
// were fixed-size boxes of their used size. For this purpose, auto margins are
// treated as zero.
void TaitankNode::LayoutFixedItems(TaitankSizeMode measure_mode, void* layout_context) {
  FlexDirection mainAxis = ResolveMainAxis();
  FlexDirection crossAxis = ResolveCrossAxis();
  std::vector<TaitankNodeRef>& items = children_;
  for (size_t i = 0; i < items.size(); i++) {
    TaitankNodeRef item = items[i];
    // for display none item, reset its layout result.
    if (item->style_.display_type_ == DISPLAY_TYPE_NONE) {
      item->ResetLayoutRecursive();
      continue;
    }
    if (item->style_.position_type_ != POSITION_TYPE_ABSOLUTE) {
      continue;
    }

    float parentWidth =
        GetLayoutDimension(FLEX_DIRECTION_ROW) - GetPaddingAndBorder(FLEX_DIRECTION_ROW);
    float parentHeight =
        GetLayoutDimension(FLEX_DIRECTION_COLUMN) - GetPaddingAndBorder(FLEX_DIRECTION_COLUMN);

    float itemOldStyleDimMainAxis = item->style_.GetDimension(mainAxis);
    float itemOldStyleDimCrossAxis = item->style_.GetDimension(crossAxis);

    if (isUndefined(itemOldStyleDimMainAxis) &&
        isDefined(item->style_.GetStartPosition(mainAxis)) &&
        isDefined(item->style_.GetEndPosition(mainAxis))) {
      item->style_.SetDimension(
          mainAxis, (GetLayoutDimension(mainAxis) - style_.GetStartBorder(mainAxis) -
                     style_.GetEndBorder(mainAxis) - item->style_.GetStartPosition(mainAxis) -
                     item->style_.GetEndPosition(mainAxis) - item->GetMargin(mainAxis)));
    }

    if (isUndefined(itemOldStyleDimCrossAxis) &&
        isDefined(item->style_.GetStartPosition(crossAxis)) &&
        isDefined(item->style_.GetEndPosition(crossAxis))) {
      item->style_.SetDimension(
          crossAxis, (GetLayoutDimension(crossAxis) - style_.GetStartBorder(crossAxis) -
                      style_.GetEndBorder(crossAxis) - item->style_.GetStartPosition(crossAxis) -
                      item->style_.GetEndPosition(crossAxis) - item->GetMargin(crossAxis)));
    }

    item->LayoutImpl(parentWidth, parentHeight, GetLayoutDirection(), LAYOUT_ACTION_LAYOUT,
                     layout_context);
    // recover item's previous style value
    item->style_.SetDimension(mainAxis, itemOldStyleDimMainAxis);
    item->style_.SetDimension(crossAxis, itemOldStyleDimCrossAxis);
    // after layout, calculate fix item 's postion
    // 1) for main axis
    CalculateFixedItemPosition(item, mainAxis);
    // 2)for cross axis
    CalculateFixedItemPosition(item, crossAxis);
  }
}

// when item's layout complete, update fixed item's position on Specified axis
// called in layoutFixedItems
// should be called twice, one for main axis ,one for cross axis
void TaitankNode::CalculateFixedItemPosition(TaitankNodeRef item, FlexDirection axis) {
  if (isDefined(item->style_.GetStartPosition(axis))) {
    item->SetLayoutStartPosition(axis, GetStartBorder(axis) + item->GetLayoutStartMargin(axis) +
                                           item->style_.GetStartPosition(axis));
    item->SetLayoutEndPosition(axis, GetLayoutDimension(axis) - item->GetLayoutStartPosition(axis) -
                                         item->GetLayoutDimension(axis));

  } else if (isDefined(item->style_.GetEndPosition(axis))) {
    item->SetLayoutEndPosition(axis, GetEndBorder(axis) + item->GetLayoutEndMargin(axis) +
                                         item->style_.GetEndPosition(axis));
    item->SetLayoutStartPosition(axis, GetLayoutDimension(axis) - item->GetLayoutEndPosition(axis) -
                                           item->GetLayoutDimension(axis));
  } else {
    float remainingFreeSpace =
        GetLayoutDimension(axis) - GetPaddingAndBorder(axis) - item->GetLayoutDimension(axis);
    float offset = GetStartPaddingAndBorder(axis);
    FlexAlign alignMode =
        (axis == ResolveMainAxis() ? style_.justify_content_ : GetNodeAlign(item));
    switch (alignMode) {
      case FLEX_ALIGN_START:
        break;
      case FLEX_ALIGN_CENTER:
        offset += remainingFreeSpace / 2;
        break;
      case FLEX_ALIGN_END:
        offset += remainingFreeSpace;
        break;
      default:
        break;
    }

    item->SetLayoutStartPosition(
        axis, GetStartPaddingAndBorder(axis) + item->GetLayoutStartMargin(axis) + offset);
    item->SetLayoutEndPosition(axis, GetLayoutDimension(axis) - item->GetLayoutStartPosition(axis) -
                                         item->GetLayoutDimension(axis));
  }
}

// convert position and dimension values to integer value..
// absLeft, absTop is mainly think about the influence of parent's Fraction
// offset for example: if parent's Fraction offset is 0.3 and current child
// offset is 0.4 then the child's absolute offset  is 0.7. if use roundf ,
// roundf(0.7) == 1 so we need absLeft, absTop  parameter
void TaitankNode::ConvertLayoutResult(float absLeft, float absTop, float scaleFactor) {
  const float left = layout_result_.position[CSS_LEFT];
  const float top = layout_result_.position[CSS_TOP];
  const float width = layout_result_.dim[DIMENSION_WIDTH];
  const float height = layout_result_.dim[DIMENSION_HEIGHT];

  absLeft += left;
  absTop += top;
  bool isTextNode = style_.node_type_ == NODETYPE_TEXT;
  layout_result_.position[CSS_LEFT] = RoundValueToPixelGrid(left, scaleFactor, false, isTextNode);
  layout_result_.position[CSS_TOP] = RoundValueToPixelGrid(top, scaleFactor, false, isTextNode);

  const bool hasFractionalWidth =
      !FloatIsEqual(fmodf(width * scaleFactor, 1.0), 0) && !FloatIsEqual(fmodf(width * scaleFactor, 1.0), 1.0);
  const bool hasFractionalHeight =
      !FloatIsEqual(fmodf(height * scaleFactor, 1.0), 0) && !FloatIsEqual(fmodf(height * scaleFactor, 1.0), 1.0);

  const float absRight = absLeft + width;
  const float absBottom = absTop + height;
  layout_result_.dim[DIMENSION_WIDTH] =
      RoundValueToPixelGrid(absRight, scaleFactor, (isTextNode && hasFractionalWidth),
                            (isTextNode && !hasFractionalWidth)) -
      RoundValueToPixelGrid(absLeft, scaleFactor, false, isTextNode);

  layout_result_.dim[DIMENSION_HEIGHT] =
      RoundValueToPixelGrid(absBottom, scaleFactor, (isTextNode && hasFractionalHeight),
                            (isTextNode && !hasFractionalHeight)) -
      RoundValueToPixelGrid(absTop, scaleFactor, false, isTextNode);
  std::vector<TaitankNodeRef>& items = children_;
  for (size_t i = 0; i < items.size(); i++) {
    TaitankNodeRef item = items[i];
    item->ConvertLayoutResult(absLeft, absTop, scaleFactor);
  }
}
}  // namespace taitank
