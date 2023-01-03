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

#pragma once

#include <memory.h>

#include <string>

#include "taitank_flex.h"
#include "taitank_util.h"

namespace taitank {

const int kCssPropsCount = 6;

class TaitankStyle {
 public:
  TaitankStyle();
  virtual ~TaitankStyle() = default;
  TaitankStyle(const TaitankStyle&) = default;
  TaitankStyle& operator=(const TaitankStyle&) = default;

  std::string toString();
  void SetDirection(const TaitankDirection direction) { direction_ = direction; }
  bool SetMargin(CSSDirection dir, float value);
  bool SetPadding(CSSDirection dir, float value);
  bool SetBorder(CSSDirection dir, float value);
  bool SetPosition(CSSDirection dir, float value);
  float GetStartPosition(FlexDirection axis);
  float GetEndPosition(FlexDirection axis);
  void SetDimension(FlexDirection axis, float value);
  void SetDimension(Dimension dimension, float value);
  float GetDimension(FlexDirection axis);
  float GetDimension(Dimension dimension);

  bool IsDimensionAuto(FlexDirection axis);
  float GetStartBorder(FlexDirection axis);
  float GetEndBorder(FlexDirection axis);
  float GetStartPadding(FlexDirection axis);
  float GetEndPadding(FlexDirection axis);
  float GetStartMargin(FlexDirection axis);
  float GetEndMargin(FlexDirection axis);
  float GetMargin(FlexDirection axis);
  bool IsAutoStartMargin(FlexDirection axis);
  bool IsAutoEndMargin(FlexDirection axis);
  bool IsAutoMargin(FlexDirection axis);

  bool IsOverflowScroll();
  float GetFlexBasis();

 public:
  NodeType node_type_;
  TaitankDirection direction_;
  FlexDirection flex_direction_;
  FlexAlign justify_content_;
  FlexAlign align_content_;
  FlexAlign align_items_;
  FlexAlign align_self_;
  FlexWrapMode flex_wrap_;
  PositionType position_type_;
  DisplayType display_type_;
  OverflowType overflow_type_;

  float flex_basis_;
  float flex_grow_;
  float flex_shrink_;
  float flex_;

  float margin_[kCssPropsCount];
  CSSDirection margin_from_[kCssPropsCount];
  float padding_[kCssPropsCount];
  CSSDirection padding_from_[kCssPropsCount];
  float border_[kCssPropsCount];
  CSSDirection border_from_[kCssPropsCount];
  float position_[kCssPropsCount];

  float dim_[2];
  float min_dim_[2];
  float max_dim_[2];

  float item_space_;
  float line_space_;
};

}  // namespace taitank
