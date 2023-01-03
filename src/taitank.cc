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

#include "taitank.h"

#include "taitank_util.h"

namespace taitank {

TaitankNodeRef NodeCreate() { return new TaitankNode(); }

TaitankNodeRef NodeCreateWithConfig(TaitankConfigRef config) { return new TaitankNode(config); }

void NodeFree(TaitankNodeRef node) {
  if (node == nullptr) return;
  // free self
  delete node;
}

void NodeFreeRecursive(TaitankNodeRef node) {
  if (node == nullptr) {
    return;
  }

  while (node->ChildCount() > 0) {
    TaitankNodeRef child = node->GetChild(0);
    NodeFreeRecursive(child);
  }

  NodeFree(node);
}

void SetDirection(TaitankNodeRef node, TaitankDirection direction) {
  if (node == nullptr || node->style_.direction_ == direction) {
    return;
  }

  node->style_.direction_ = direction;
  node->MarkAsDirty();
}

bool SetMeasureFunction(TaitankNodeRef node, TaitankMeasureFunction measure_function) {
  if (node == nullptr) return false;

  return node->SetMeasureFunction(measure_function);
}

void SetWidth(TaitankNodeRef node, float width) {
  if (node == nullptr || FloatIsEqual(node->style_.dim_[DIMENSION_WIDTH], width)) {
    return;
  }

  node->style_.dim_[DIMENSION_WIDTH] = width;
  node->MarkAsDirty();
}

void SetHeight(TaitankNodeRef node, float height) {
  if (node == nullptr || FloatIsEqual(node->style_.dim_[DIMENSION_HEIGHT], height)) return;

  node->style_.dim_[DIMENSION_HEIGHT] = height;
  node->MarkAsDirty();
}

void SetFlex(TaitankNodeRef node, float flex) {
  if (node == nullptr || FloatIsEqual(node->style_.flex_, flex)) return;
  if (FloatIsEqual(flex, 0.0f)) {
    SetFlexGrow(node, 0.0f);
    SetFlexShrink(node, 0.0f);
  } else if (flex > 0.0f) {
    SetFlexGrow(node, flex);
    SetFlexShrink(node, 1.0f);
  } else {
    SetFlexGrow(node, 0.0f);
    SetFlexShrink(node, -flex);
  }
  node->style_.flex_ = flex;
  node->MarkAsDirty();
}

void SetFlexGrow(TaitankNodeRef node, float flex_grow) {
  if (node == nullptr || FloatIsEqual(node->style_.flex_grow_, flex_grow)) return;

  node->style_.flex_grow_ = flex_grow;
  node->MarkAsDirty();
}

void SetFlexShrink(TaitankNodeRef node, float flex_shrink) {
  if (node == nullptr || FloatIsEqual(node->style_.flex_shrink_, flex_shrink)) return;

  node->style_.flex_shrink_ = flex_shrink;
  node->MarkAsDirty();
}

void SetFlexBasis(TaitankNodeRef node, float flex_basis) {
  if (node == nullptr || FloatIsEqual(node->style_.flex_basis_, flex_basis)) return;

  node->style_.flex_basis_ = flex_basis;
  node->MarkAsDirty();
}

void SetFlexDirection(TaitankNodeRef node, FlexDirection direction) {
  if (node == nullptr || node->style_.flex_direction_ == direction) return;

  node->style_.flex_direction_ = direction;
  node->MarkAsDirty();
}

void SetPositionType(TaitankNodeRef node, PositionType position_type) {
  if (node == nullptr || node->style_.position_type_ == position_type) return;
  node->style_.position_type_ = position_type;
  node->MarkAsDirty();
}

void SetPosition(TaitankNodeRef node, CSSDirection dir, float value) {
  if (node == nullptr || FloatIsEqual(node->style_.position_[dir], value)) return;
  if (node->style_.SetPosition(dir, value)) {
    node->MarkAsDirty();
  }
}

void SetMargin(TaitankNodeRef node, CSSDirection dir, float value) {
  if (node == nullptr) return;
  if (node->style_.SetMargin(dir, value)) {
    node->MarkAsDirty();
  }
}

void SetMarginAuto(TaitankNodeRef node, CSSDirection dir) { SetMargin(node, dir, VALUE_AUTO); }

void SetPadding(TaitankNodeRef node, CSSDirection dir, float value) {
  if (node == nullptr) return;
  if (node->style_.SetPadding(dir, value)) {
    node->MarkAsDirty();
  }
}

void SetBorder(TaitankNodeRef node, CSSDirection dir, float value) {
  if (node == nullptr) return;
  if (node->style_.SetBorder(dir, value)) {
    node->MarkAsDirty();
  }
}

void SetFlexWrap(TaitankNodeRef node, FlexWrapMode wrap_mode) {
  if (node == nullptr || node->style_.flex_wrap_ == wrap_mode) return;

  node->style_.flex_wrap_ = wrap_mode;
  node->MarkAsDirty();
}

void SetJustifyContent(TaitankNodeRef node, FlexAlign justify) {
  if (node == nullptr || node->style_.justify_content_ == justify) return;
  node->style_.justify_content_ = justify;
  node->MarkAsDirty();
}

void SetAlignContent(TaitankNodeRef node, FlexAlign align) {
  if (node == nullptr || node->style_.align_content_ == align) return;
  node->style_.align_content_ = align;
  node->MarkAsDirty();
}

void SetAlignItems(TaitankNodeRef node, FlexAlign align) {
  if (node == nullptr || node->style_.align_items_ == align) return;
  // FlexAlignStart == FlexAlignBaseline
  node->style_.align_items_ = align;
  node->MarkAsDirty();
}

void SetAlignSelf(TaitankNodeRef node, FlexAlign align) {
  if (node == nullptr || node->style_.align_self_ == align) return;
  node->style_.align_self_ = align;
  node->MarkAsDirty();
}

void SetDisplay(TaitankNodeRef node, DisplayType display_type) {
  if (node == nullptr) return;
  node->SetDisplayType(display_type);
}

void SetMaxWidth(TaitankNodeRef node, float value) {
  if (node == nullptr || FloatIsEqual(node->style_.max_dim_[DIMENSION_WIDTH], value)) return;
  node->style_.max_dim_[DIMENSION_WIDTH] = value;
  node->MarkAsDirty();
}

void SetMaxHeight(TaitankNodeRef node, float value) {
  if (node == nullptr || FloatIsEqual(node->style_.max_dim_[DIMENSION_HEIGHT], value)) return;
  node->style_.max_dim_[DIMENSION_HEIGHT] = value;
  node->MarkAsDirty();
}

void SetMinWidth(TaitankNodeRef node, float value) {
  if (node == nullptr || FloatIsEqual(node->style_.min_dim_[DIMENSION_WIDTH], value)) return;
  node->style_.min_dim_[DIMENSION_WIDTH] = value;
  node->MarkAsDirty();
}

void SetMinHeight(TaitankNodeRef node, float value) {
  if (node == nullptr || FloatIsEqual(node->style_.min_dim_[DIMENSION_HEIGHT], value)) return;
  node->style_.min_dim_[DIMENSION_HEIGHT] = value;
  node->MarkAsDirty();
}

void SetOverflow(TaitankNodeRef node, OverflowType overflow_type) {
  if (node == nullptr || overflow_type == node->style_.overflow_type_) return;

  node->style_.overflow_type_ = overflow_type;
  node->MarkAsDirty();
}

void SetNodeType(TaitankNodeRef node, NodeType node_type) {
  if (node == nullptr || node_type == node->style_.node_type_) return;
  node->style_.node_type_ = node_type;
  //  node->markAsDirty();
}

float GetLeft(TaitankNodeRef node) {
  if (node == nullptr) return 0;
  return node->layout_result_.position[CSS_LEFT];
}

float GetTop(TaitankNodeRef node) {
  if (node == nullptr) return 0;
  return node->layout_result_.position[CSS_TOP];
}

float GetRight(TaitankNodeRef node) {
  if (node == nullptr) return 0;
  return node->layout_result_.position[CSS_RIGHT];
}

float GetBottom(TaitankNodeRef node) {
  if (node == nullptr) return 0;
  return node->layout_result_.position[CSS_BOTTOM];
}

float GetWidth(TaitankNodeRef node) {
  if (node == nullptr) return 0;
  return node->layout_result_.dim[DIMENSION_WIDTH];
}

float GetHeight(TaitankNodeRef node) {
  if (node == nullptr) return 0;
  return node->layout_result_.dim[DIMENSION_HEIGHT];
}

float GetMaxWidth(TaitankNodeRef node) {
  if (node == nullptr) return 0;
  return node->style_.max_dim_[DIMENSION_WIDTH];
}

float GetMaxHeight(TaitankNodeRef node) {
  if (node == nullptr) return 0;
  return node->style_.max_dim_[DIMENSION_HEIGHT];
}

float GetMinWidth(TaitankNodeRef node) {
  if (node == nullptr) return 0;
  return node->style_.min_dim_[DIMENSION_WIDTH];
}

float GetMinHeight(TaitankNodeRef node) {
  if (node == nullptr) return 0;
  return node->style_.min_dim_[DIMENSION_HEIGHT];
}

float GetMargin(TaitankNodeRef node, CSSDirection dir) {
  if (node == nullptr || dir > CSS_BOTTOM) return 0;
  return node->layout_result_.margin[dir];
}

float GetPadding(TaitankNodeRef node, CSSDirection dir) {
  if (node == nullptr || dir > CSS_BOTTOM) return 0;
  return node->layout_result_.padding[dir];
}

float GetBorder(TaitankNodeRef node, CSSDirection dir) {
  if (node == nullptr || dir > CSS_BOTTOM) return 0;
  return node->layout_result_.border[dir];
}

float GetFlexGrow(TaitankNodeRef node) {
  if (node == nullptr) return 0;
  return node->style_.flex_grow_;
}

float GetFlexShrink(TaitankNodeRef node) {
  if (node == nullptr) return 0;
  return node->style_.flex_shrink_;
}

DisplayType GetDisplay(TaitankNodeRef node) {
  if (node == nullptr) return DISPLAY_TYPE_FLEX;
  return node->style_.display_type_;
}

float GetFlexBasis(TaitankNodeRef node) {
  if (node == nullptr) return 0;
  return node->style_.GetFlexBasis();
}

FlexDirection GetFlexDirection(TaitankNodeRef node) {
  if (node == nullptr) return FLEX_DIRECTION_ROW;
  return node->style_.flex_direction_;
}

FlexAlign GetJustifyContent(TaitankNodeRef node) {
  if (node == nullptr) return FLEX_ALIGN_START;
  return node->style_.align_content_;
}

FlexAlign GetAlignSelf(TaitankNodeRef node) {
  if (node == nullptr) return FLEX_ALIGN_AUTO;
  return node->style_.align_self_;
}

FlexAlign GetAlignItems(TaitankNodeRef node) {
  if (node == nullptr) return FLEX_ALIGN_START;
  return node->style_.align_items_;
}

PositionType GetPositionType(TaitankNodeRef node) {
  if (node == nullptr) return POSITION_TYPE_RELATIVE;
  return node->style_.position_type_;
}

FlexWrapMode GetFlexWrap(TaitankNodeRef node) {
  if (node == nullptr) return FLEX_NO_WRAP;
  return node->style_.flex_wrap_;
}

OverflowType HPNodeLayoutGetOverflow(TaitankNodeRef node) {
  if (node == nullptr) return OVERFLOW_VISIBLE;
  return node->style_.overflow_type_;
}

bool GetHadOverflow(TaitankNodeRef node) {
  if (node == nullptr) return false;
  return node->layout_result_.had_overflow;
}

void SetConfig(TaitankNodeRef node, TaitankConfigRef config) { node->SetConfig(config); }

void ConfigFree(TaitankConfigRef config) { delete config; }

TaitankConfigRef ConfigGetDefault() {
  static TaitankConfigRef defaultConfig = new TaitankConfig();
  return defaultConfig;
}

void SetContext(TaitankNodeRef node, void *context) {
  if (node) {
    node->SetContext(context);
  }
}

void *GetContext(TaitankNodeRef node) {
  if (node) {
    return node->GetContext();
  }
  return nullptr;
}

bool InsertChild(TaitankNodeRef node, TaitankNodeRef child, uint32_t index) {
  if (node == nullptr) return false;

  return node->InsertChild(child, index);
}

bool RemoveChild(TaitankNodeRef node, TaitankNodeRef child) {
  if (node == nullptr) return false;
  return node->RemoveChild(child);
}

uint32_t ChildCount(TaitankNodeRef node) {
  if (node == nullptr) return 0;
  return node->ChildCount();
}

TaitankNodeRef GetChild(TaitankNodeRef node, uint32_t index) {
  if (node == nullptr) return 0;
  if (index >= node->ChildCount()) return nullptr;
  return node->GetChild(index);
}

bool GetHasNewLayout(TaitankNodeRef node) {
  if (node == nullptr) return false;
  return node->GetHasNewLayout();
}

void SetHasNewLayout(TaitankNodeRef node, bool has_new_layout) {
  if (node == nullptr) return;
  node->SetHasNewLayout(has_new_layout);
}

void MarkDirty(TaitankNodeRef node) {
  if (node == nullptr) return;
  node->MarkAsDirty();
}

bool IsDirty(TaitankNodeRef node) {
  if (node == nullptr) return false;
  return node->is_dirty_;
}

void DoLayout(TaitankNodeRef node, float parent_width, float parent_height,
              TaitankDirection direction, void *layoutContext) {
  if (node == nullptr) return;

  node->Layout(parent_width, parent_height, node->GetConfig(), direction, layoutContext);
}

void Print(TaitankNodeRef node) {
  if (node == nullptr) return;
  node->PrintNode();
}

bool Reset(TaitankNodeRef node) {
  if (node == nullptr || node->ChildCount() != 0 || node->GetParent() != nullptr) return false;

  return node->Reset();
}
}  // namespace taitank
