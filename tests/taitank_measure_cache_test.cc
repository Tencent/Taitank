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

#include "gtest.h"

using namespace taitank;

static TaitankSize _measureMax(TaitankNodeRef node, float width, MeasureMode widthMode,
                               float height, MeasureMode heightMode, void *layoutContext) {
  int *measureCount = reinterpret_cast<int *>(node->get_context());
  (*measureCount)++;

  return TaitankSize{
      .width = widthMode == MEASURE_MODE_UNDEFINED ? 10 : width,
      .height = heightMode == MEASURE_MODE_UNDEFINED ? 10 : height,
  };
}

static TaitankSize _measureMin(TaitankNodeRef node, float width, MeasureMode widthMode,
                               float height, MeasureMode heightMode, void *layoutContext) {
  int *measureCount = reinterpret_cast<int *>(node->get_context());
  *measureCount = *measureCount + 1;
  return TaitankSize{
      .width =
          widthMode == MEASURE_MODE_UNDEFINED || (widthMode == MEASURE_MODE_AT_MOST && width > 10)
              ? 10
              : width,
      .height = heightMode == MEASURE_MODE_UNDEFINED ||
                        (heightMode == MEASURE_MODE_AT_MOST && height > 10)
                    ? 10
                    : height,
  };
}

static TaitankSize _measure_84_49(TaitankNodeRef node, float width, MeasureMode widthMode,
                                  float height, MeasureMode heightMode, void *layoutContext) {
  int *measureCount = reinterpret_cast<int *>(node->get_context());
  if (measureCount) {
    (*measureCount)++;
  }

  return TaitankSize{
      .width = 84.f,
      .height = 49.f,
  };
}

TEST(TAITANK_TEST, measure_once_single_flexible_child) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_align_items(root, FLEX_ALIGN_START);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  int measureCount = 0;
  root_child0->set_context(&measureCount);
  root_child0->measure_ = (_measureMax);
  set_taitank_node_style_flex_grow(root_child0, 1);
  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(1, measureCount);

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, remeasure_with_same_exact_width_larger_than_needed_height) {
  const TaitankNodeRef root = TaitankNodeCreate();

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  int measureCount = 0;
  root_child0->set_context(&measureCount);
  root_child0->measure_ = (_measureMin);
  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, 100, 100);
  TaitankNodeDoLayout(root, 100, 50);

  ASSERT_EQ(1, measureCount);

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, remeasure_with_same_atmost_width_larger_than_needed_height) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_START);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  int measureCount = 0;
  root_child0->set_context(&measureCount);
  root_child0->measure_ = (_measureMin);
  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, 100, 100);
  TaitankNodeDoLayout(root, 100, 50);

  ASSERT_EQ(1, measureCount);

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, remeasure_with_computed_width_larger_than_needed_height) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_START);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  int measureCount = 0;
  root_child0->set_context(&measureCount);
  root_child0->measure_ = (_measureMin);
  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, 100, 100);
  set_taitank_node_style_align_items(root, FLEX_ALIGN_STRETCH);
  TaitankNodeDoLayout(root, 10, 50);

  ASSERT_EQ(1, measureCount);

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, remeasure_with_atmost_computed_width_undefined_height) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_START);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  int measureCount = 0;
  root_child0->set_context(&measureCount);
  root_child0->measure_ = (_measureMin);
  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, 100, VALUE_UNDEFINED);
  TaitankNodeDoLayout(root, 10, VALUE_UNDEFINED);

  ASSERT_EQ(1, measureCount);

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, remeasure_with_already_measured_value_smaller_but_still_float_equal) {
  int measureCount = 0;

  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 288.f);
  set_taitank_node_style_height(root, 288.f);
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_padding(root_child0, CSS_LEFT, 2.88f);
  set_taitank_node_style_padding(root_child0, CSS_TOP, 2.88f);
  set_taitank_node_style_padding(root_child0, CSS_RIGHT, 2.88f);
  set_taitank_node_style_padding(root_child0, CSS_BOTTOM, 2.88f);
  set_taitank_node_style_flex_direction(root_child0, FLEX_DIRECTION_ROW);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  root_child0_child0->set_context(&measureCount);
  root_child0_child0->measure_ = _measure_84_49;
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  TaitankNodeFreeRecursive(root);

  ASSERT_EQ(1, measureCount);
}
