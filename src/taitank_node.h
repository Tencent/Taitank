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

#include <vector>

#include "taitank_cache.h"
#include "taitank_config.h"
#include "taitank_flex.h"
#include "taitank_flexline.h"
#include "taitank_style.h"
#include "taitank_util.h"

namespace taitank {

TaitankConfigRef ConfigGetDefault();

class TaitankNode;
typedef TaitankNode* TaitankNodeRef;
typedef TaitankSize (*TaitankMeasureFunction)(TaitankNodeRef node, float width,
                                              MeasureMode width_measure_mode, float height,
                                              MeasureMode height_measure_mode,
                                              void* layout_context);
typedef void (*TaitankDirtiedFunction)(TaitankNodeRef node);

class TaitankNode {
 public:
  TaitankNode() : TaitankNode{ConfigGetDefault()} {}
  TaitankNode(TaitankConfigRef config);
  virtual ~TaitankNode();
  void InitLayoutResult();
  bool Reset();
  void PrintNode(uint32_t indent = 0);
  TaitankStyle GetStyle() const;
  void SetStyle(const TaitankStyle& st);
  bool SetMeasureFunction(TaitankMeasureFunction measure_function);
  void SetParent(TaitankNodeRef parent_ref);
  TaitankNodeRef GetParent() const;
  void AddChild(TaitankNodeRef item);
  bool InsertChild(TaitankNodeRef item, uint32_t index);
  TaitankNodeRef GetChild(uint32_t index);
  bool RemoveChild(TaitankNodeRef child);
  bool RemoveChild(uint32_t index);
  uint32_t ChildCount() const;

  void SetDisplayType(DisplayType display_type);
  void SetHasNewLayout(bool has_new_layout);
  bool GetHasNewLayout();
  void MarkAsDirty();
  void SetDirty(bool dirty);
  void SetDirtiedFunction(TaitankDirtiedFunction dirtied_function);

  void SetContext(void* context);
  void* GetContext();

  float GetStartBorder(FlexDirection axis);
  float GetEndBorder(FlexDirection axis);
  float GetStartPaddingAndBorder(FlexDirection axis);
  float GetEndPaddingAndBorder(FlexDirection axis);
  float GetPaddingAndBorder(FlexDirection axis);
  float GetMargin(FlexDirection axis);
  float GetStartMargin(FlexDirection axis);
  float GetEndMargin(FlexDirection axis);
  bool IsAutoStartMargin(FlexDirection axis);
  bool IsAutoEndMargin(FlexDirection axis);

  void SetLayoutStartMargin(FlexDirection axis, float value);
  void SetLayoutEndMargin(FlexDirection axis, float value);
  float GetLayoutMargin(FlexDirection axis);
  float GetLayoutStartMargin(FlexDirection axis);
  float GetLayoutEndMargin(FlexDirection axis);

  float ResolveRelativePosition(FlexDirection axis, bool for_axis_start);
  void SetLayoutStartPosition(FlexDirection axis, float value, bool add_relative_position = true);
  void SetLayoutEndPosition(FlexDirection axis, float value, bool add_relative_position = true);
  float GetLayoutStartPosition(FlexDirection axis);
  float GetLayoutEndPosition(FlexDirection axis);

  // FlexDirection resolveMainAxis(HPDirection direction);
  FlexDirection ResolveMainAxis();
  FlexDirection ResolveCrossAxis();
  float GetBoundAxis(FlexDirection axis, float value);
  void Layout(float parent_width, float parent_height, TaitankConfigRef config,
              TaitankDirection parent_direction = DIRECTION_LTR, void* layout_context = nullptr);
  float GetMainAxisDimension();
  float GetLayoutDimension(FlexDirection axis);
  bool IsLayoutDimensionDefined(FlexDirection axis);
  void SetLayoutDimension(FlexDirection axis, float value);
  void SetLayoutDirection(TaitankDirection direction);
  TaitankDirection GetLayoutDirection();
  FlexAlign GetNodeAlign(TaitankNodeRef item);
  void SetConfig(TaitankConfigRef config);
  TaitankConfigRef GetConfig() const;
  void ResetLayoutRecursive(bool is_display_none = true);

 protected:
  TaitankDirection ResolveDirection(TaitankDirection parentDirection);
  void ResolveStyleValues();
  void CacheLayoutOrMeasureResult(TaitankSize available_size, TaitankSizeMode measure_mode,
                                  FlexLayoutAction layout_action);
  void LayoutSingleNode(float available_width, MeasureMode width_measure_mode,
                        float available_height, MeasureMode height_measure_mode,
                        FlexLayoutAction layout_action, void* layout_context = nullptr);
  void LayoutImpl(float parent_width, float parent_height, TaitankDirection parent_direction,
                  FlexLayoutAction layout_action, void* layout_context = nullptr);
  void CalculateItemsFlexBasis(TaitankSize available_size, void* layout_context);
  bool CollectFlexLines(std::vector<FlexLine*>& flex_lines, TaitankSize available_size);
  void DetermineItemsMainAxisSize(std::vector<FlexLine*>& flexLines, FlexLayoutAction layoutAction);
  float DetermineCrossAxisSize(std::vector<FlexLine*>& flexLines, TaitankSize availableSize,
                               FlexLayoutAction layoutAction, void* layoutContext);
  void MainAxisAlignment(std::vector<FlexLine*>& flexLines);
  void CrossAxisAlignment(std::vector<FlexLine*>& flexLines);

  void LayoutFixedItems(TaitankSizeMode measureMode, void* layoutContext);
  void CalculateFixedItemPosition(TaitankNodeRef item, FlexDirection axis);

  void ConvertLayoutResult(float absLeft, float absTop, float scaleFactor);

 public:
  TaitankStyle style_;
  TaitankLayout layout_result_{};

  void* context_;
  std::vector<TaitankNodeRef> children_;
  TaitankNodeRef parent_;
  TaitankMeasureFunction measure_;

  bool is_frozen_{};
  bool is_dirty_{};
  bool has_new_layout_{};
  TaitankDirtiedFunction dirtied_function_;

  // cache layout or measure positions, used if conditions are met
  TaitankLayoutCache layout_cache_;
  // layout result is in initial state or not
  bool in_initail_state_;
  TaitankConfigRef config_ = nullptr;

#ifdef LAYOUT_TIME_ANALYZE
  int fetchCount;
#endif
};

}  // namespace taitank
