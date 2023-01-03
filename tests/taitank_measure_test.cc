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

static TaitankSize _measure(TaitankNodeRef node, float width, MeasureMode widthMode, float height,
                            MeasureMode heightMode, void *layoutContext) {
  int *measureCount = reinterpret_cast<int *>(node->GetContext());
  if (measureCount) {
    (*measureCount)++;
  }

  return TaitankSize{
      .width = 10,
      .height = 10,
  };
}

static TaitankSize _simulate_wrapping_text(TaitankNodeRef node, float width, MeasureMode widthMode,
                                           float height, MeasureMode heightMode,
                                           void *layoutContext) {
  if (widthMode == MEASURE_MODE_UNDEFINED || width >= 68) {
    return TaitankSize{.width = 68, .height = 16};
  }

  return TaitankSize{
      .width = 50,
      .height = 32,
  };
}

static TaitankSize _measure_assert_negative(TaitankNodeRef node, float width, MeasureMode widthMode,
                                            float height, MeasureMode heightMode,
                                            void *layoutContext) {
  EXPECT_GE(width, 0);
  EXPECT_GE(height, 0);

  return TaitankSize{
      .width = 0,
      .height = 0,
  };
}

TEST(TAITANK_TEST, dont_measure_single_grow_shrink_child) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 100);
  SetHeight(root, 100);

  int measureCount = 0;

  const TaitankNodeRef root_child0 = NodeCreate();
  root_child0->SetContext(&measureCount);
  SetMeasureFunction(root_child0, _measure);
  //  SetMeasureFunction(root_child0, _measure);;
  SetFlexGrow(root_child0, 1);
  SetFlexShrink(root_child0, 1);
  InsertChild(root, root_child0, 0);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(0, measureCount);

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_absolute_child_with_no_constraints) {
  const TaitankNodeRef root = NodeCreate();

  const TaitankNodeRef root_child0 = NodeCreate();
  InsertChild(root, root_child0, 0);

  int measureCount = 0;

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetPositionType(root_child0_child0, POSITION_TYPE_ABSOLUTE);
  root_child0_child0->SetContext(&measureCount);
  SetMeasureFunction(root_child0_child0, _measure);
  InsertChild(root_child0, root_child0_child0, 0);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(1, measureCount);

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, dont_measure_when_min_equals_max) {
  const TaitankNodeRef root = NodeCreate();
  SetAlignItems(root, FLEX_ALIGN_START);
  SetWidth(root, 100);
  SetHeight(root, 100);

  int measureCount = 0;

  const TaitankNodeRef root_child0 = NodeCreate();
  root_child0->SetContext(&measureCount);
  SetMeasureFunction(root_child0, _measure);
  //  SetMeasureFunction(root_child0, _measure);;
  SetMinWidth(root_child0, 10);
  SetMaxWidth(root_child0, 10);
  SetMinHeight(root_child0, 10);
  SetMaxHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(0, measureCount);
  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, dont_measure_when_min_equals_max_percentages) {
  const TaitankNodeRef root = NodeCreate();
  SetAlignItems(root, FLEX_ALIGN_START);
  SetWidth(root, 100);
  SetHeight(root, 100);

  int measureCount = 0;

  const TaitankNodeRef root_child0 = NodeCreate();
  root_child0->SetContext(&measureCount);
  SetMeasureFunction(root_child0, _measure);
  //  SetMeasureFunction(root_child0, _measure);;
  SetMinWidth(root_child0, 10);
  SetMaxWidth(root_child0, 10);
  SetMinHeight(root_child0, 10);
  SetMaxHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(0, measureCount);
  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_nodes_with_margin_auto_and_stretch) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 500);
  SetHeight(root, 500);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetMeasureFunction(root_child0, _measure);
  //  SetMeasureFunction(root_child0, _measure);;
  SetMarginAuto(root_child0, CSS_LEFT);
  InsertChild(root, root_child0, 0);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  EXPECT_EQ(490, GetLeft(root_child0));
  EXPECT_EQ(0, GetTop(root_child0));
  EXPECT_EQ(10, GetWidth(root_child0));
  EXPECT_EQ(10, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, dont_measure_when_min_equals_max_mixed_width_percent) {
  const TaitankNodeRef root = NodeCreate();
  SetAlignItems(root, FLEX_ALIGN_START);
  SetWidth(root, 100);
  SetHeight(root, 100);

  int measureCount = 0;

  const TaitankNodeRef root_child0 = NodeCreate();
  root_child0->SetContext(&measureCount);
  //  SetMeasureFunction(root_child0, _measure);;
  SetMeasureFunction(root_child0, _measure);
  SetMinWidth(root_child0, 10);
  SetMaxWidth(root_child0, 10);
  SetMinHeight(root_child0, 10);
  SetMaxHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(0, measureCount);
  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, dont_measure_when_min_equals_max_mixed_height_percent) {
  const TaitankNodeRef root = NodeCreate();
  SetAlignItems(root, FLEX_ALIGN_START);
  SetWidth(root, 100);
  SetHeight(root, 100);

  int measureCount = 0;

  const TaitankNodeRef root_child0 = NodeCreate();
  root_child0->SetContext(&measureCount);
  SetMeasureFunction(root_child0, _measure);
  SetMinWidth(root_child0, 10);
  SetMaxWidth(root_child0, 10);
  SetMinHeight(root_child0, 10);
  SetMaxHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(0, measureCount);
  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_enough_size_should_be_in_single_line) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetAlignSelf(root_child0, FLEX_ALIGN_START);
  SetMeasureFunction(root_child0, _simulate_wrapping_text);
  //   SetMeasureFunction(root_child0, _simulate_wrapping_text);;

  InsertChild(root, root_child0, 0);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(68, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(16, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_not_enough_size_should_wrap) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 55);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetAlignSelf(root_child0, FLEX_ALIGN_START);
  SetMeasureFunction(root_child0, _simulate_wrapping_text);
  //   SetMeasureFunction(root_child0, _simulate_wrapping_text);;
  InsertChild(root, root_child0, 0);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(32, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_zero_space_should_grow) {
  const TaitankNodeRef root = NodeCreate();
  SetHeight(root, 200);
  SetFlexDirection(root, FLEX_DIRECTION_COLUMN);
  SetFlexGrow(root, 0);

  int measureCount = 0;

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexDirection(root_child0, FLEX_DIRECTION_COLUMN);
  //  SetPadding(root_child0, YGEdgeAll, 100);

  SetPadding(root_child0, CSS_LEFT, 100);
  SetPadding(root_child0, CSS_TOP, 100);
  SetPadding(root_child0, CSS_RIGHT, 100);
  SetPadding(root_child0, CSS_BOTTOM, 100);

  root_child0->SetContext(&measureCount);
  SetMeasureFunction(root_child0, _measure);

  InsertChild(root, root_child0, 0);

  DoLayout(root, 282, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(282, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_flex_direction_row_and_padding) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetPadding(root, CSS_LEFT, 25);
  SetPadding(root, CSS_TOP, 25);
  SetPadding(root, CSS_RIGHT, 25);
  SetPadding(root, CSS_BOTTOM, 25);
  SetWidth(root, 50);
  SetHeight(root, 50);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetMeasureFunction(root_child0, _simulate_wrapping_text);
  //  SetMeasureFunction(root_child0, _simulate_wrapping_text);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 5);
  SetHeight(root_child1, 5);
  InsertChild(root, root_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(50, GetWidth(root));
  ASSERT_FLOAT_EQ(50, GetHeight(root));

  ASSERT_FLOAT_EQ(25, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(25, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(75, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(25, GetTop(root_child1));
  ASSERT_FLOAT_EQ(5, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(5, GetHeight(root_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_flex_direction_column_and_padding) {
  const TaitankNodeRef root = NodeCreate();
  SetMargin(root, CSS_TOP, 20);
  //  SetPadding(root, YGEdgeAll, 25);
  SetPadding(root, CSS_LEFT, 25);
  SetPadding(root, CSS_TOP, 25);
  SetPadding(root, CSS_RIGHT, 25);
  SetPadding(root, CSS_BOTTOM, 25);
  SetWidth(root, 50);
  SetHeight(root, 50);

  const TaitankNodeRef root_child0 = NodeCreate();
  // SetMeasureFunction(root_child0, _simulate_wrapping_text);;
  SetMeasureFunction(root_child0, _simulate_wrapping_text);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 5);
  SetHeight(root_child1, 5);
  InsertChild(root, root_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(20, GetTop(root));
  ASSERT_FLOAT_EQ(50, GetWidth(root));
  ASSERT_FLOAT_EQ(50, GetHeight(root));

  ASSERT_FLOAT_EQ(25, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(25, GetTop(root_child0));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(32, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(25, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(57, GetTop(root_child1));
  ASSERT_FLOAT_EQ(5, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(5, GetHeight(root_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_flex_direction_row_no_padding) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetMargin(root, CSS_TOP, 20);
  SetWidth(root, 50);
  SetHeight(root, 50);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetMeasureFunction(root_child0, _simulate_wrapping_text);
  // SetMeasureFunction(root_child0, _simulate_wrapping_text);;
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 5);
  SetHeight(root_child1, 5);
  InsertChild(root, root_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(20, GetTop(root));
  ASSERT_FLOAT_EQ(50, GetWidth(root));
  ASSERT_FLOAT_EQ(50, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(5, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(5, GetHeight(root_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_flex_direction_row_no_padding_align_items_flexstart) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetMargin(root, CSS_TOP, 20);
  SetWidth(root, 50);
  SetHeight(root, 50);
  SetAlignItems(root, FLEX_ALIGN_START);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetMeasureFunction(root_child0, _simulate_wrapping_text);
  //   SetMeasureFunction(root_child0, _simulate_wrapping_text);;
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 5);
  SetHeight(root_child1, 5);
  InsertChild(root, root_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(20, GetTop(root));
  ASSERT_FLOAT_EQ(50, GetWidth(root));
  ASSERT_FLOAT_EQ(50, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(32, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, GetTop(root_child1));
  ASSERT_FLOAT_EQ(5, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(5, GetHeight(root_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_with_fixed_size) {
  const TaitankNodeRef root = NodeCreate();
  SetMargin(root, CSS_TOP, 20);
  //  SetPadding(root, YGEdgeAll, 25);
  SetPadding(root, CSS_LEFT, 25);
  SetPadding(root, CSS_TOP, 25);
  SetPadding(root, CSS_RIGHT, 25);
  SetPadding(root, CSS_BOTTOM, 25);
  SetWidth(root, 50);
  SetHeight(root, 50);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetMeasureFunction(root_child0, _simulate_wrapping_text);
  //   SetMeasureFunction(root_child0, _simulate_wrapping_text);;
  SetWidth(root_child0, 10);
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 5);
  SetHeight(root_child1, 5);
  InsertChild(root, root_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(20, GetTop(root));
  ASSERT_FLOAT_EQ(50, GetWidth(root));
  ASSERT_FLOAT_EQ(50, GetHeight(root));

  ASSERT_FLOAT_EQ(25, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(25, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(25, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(35, GetTop(root_child1));
  ASSERT_FLOAT_EQ(5, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(5, GetHeight(root_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_with_flex_shrink) {
  const TaitankNodeRef root = NodeCreate();
  SetMargin(root, CSS_TOP, 20);
  //  SetPadding(root, YGEdgeAll, 25);
  SetPadding(root, CSS_LEFT, 25);
  SetPadding(root, CSS_TOP, 25);
  SetPadding(root, CSS_RIGHT, 25);
  SetPadding(root, CSS_BOTTOM, 25);
  SetWidth(root, 50);
  SetHeight(root, 50);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetMeasureFunction(root_child0, _simulate_wrapping_text);
  SetFlexShrink(root_child0, 1);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 5);
  SetHeight(root_child1, 5);
  InsertChild(root, root_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(20, GetTop(root));
  ASSERT_FLOAT_EQ(50, GetWidth(root));
  ASSERT_FLOAT_EQ(50, GetHeight(root));

  ASSERT_FLOAT_EQ(25, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(25, GetTop(root_child0));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(25, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(25, GetTop(root_child1));
  ASSERT_FLOAT_EQ(5, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(5, GetHeight(root_child1));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_no_padding) {
  const TaitankNodeRef root = NodeCreate();
  SetMargin(root, CSS_TOP, 20);
  SetWidth(root, 50);
  SetHeight(root, 50);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetMeasureFunction(root_child0, _simulate_wrapping_text);
  SetFlexShrink(root_child0, 1);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 5);
  SetHeight(root_child1, 5);
  InsertChild(root, root_child1, 1);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(20, GetTop(root));
  ASSERT_FLOAT_EQ(50, GetWidth(root));
  ASSERT_FLOAT_EQ(50, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(32, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(32, GetTop(root_child1));
  ASSERT_FLOAT_EQ(5, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(5, GetHeight(root_child1));

  NodeFreeRecursive(root);
}

#if GTEST_HAS_DEATH_TEST
TEST(TAITANK_TEST, cannot_add_child_to_node_with_measure_func) {
  const TaitankNodeRef root = NodeCreate();
  SetMeasureFunction(root, _measure);
  //  SetMeasureFunction(root, _measure);

  const TaitankNodeRef root_child0 = NodeCreate();
  ASSERT_FALSE(InsertChild(root, root_child0, 0));
  NodeFree(root_child0);
  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, cannot_add_nonnull_measure_func_to_non_leaf_node) {
  const TaitankNodeRef root = NodeCreate();
  const TaitankNodeRef root_child0 = NodeCreate();
  InsertChild(root, root_child0, 0);
  ASSERT_FALSE(SetMeasureFunction(root, _measure));
  NodeFreeRecursive(root);
}

#endif

TEST(TAITANK_TEST, can_nullify_measure_func_on_any_node) {
  const TaitankNodeRef root = NodeCreate();
  InsertChild(root, NodeCreate(), 0);
  //  root->setMeasureFunc(nullptr);
  SetMeasureFunction(root, nullptr);
  ASSERT_TRUE(root->measure_ == NULL);
  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, cant_call_negative_measure) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_COLUMN);
  SetWidth(root, 50);
  SetHeight(root, 10);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetMeasureFunction(root, _measure_assert_negative);
  //  root_child0->setMeasureFunc(_measure_assert_negative);
  SetMargin(root_child0, CSS_TOP, 20);
  InsertChild(root, root_child0, 0);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, cant_call_negative_measure_horizontal) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetWidth(root, 10);
  SetHeight(root, 20);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetMeasureFunction(root_child0, _measure_assert_negative);
  //  root_child0->setMeasureFunc(_measure_assert_negative);
  SetMargin(root_child0, CSS_LEFT, 20);
  InsertChild(root, root_child0, 0);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  NodeFreeRecursive(root);
}

static TaitankSize _measure_90_10(TaitankNodeRef node, float width, MeasureMode widthMode,
                                  float height, MeasureMode heightMode, void *layoutContext) {
  return TaitankSize{
      .width = 90,
      .height = 10,
  };
}

TEST(TAITANK_TEST, percent_with_text_node) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetJustifyContent(root, FLEX_ALIGN_SPACE_BETWEEN);
  SetAlignItems(root, FLEX_ALIGN_CENTER);
  SetWidth(root, 100);
  SetHeight(root, 80);

  const TaitankNodeRef root_child0 = NodeCreate();
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetMeasureFunction(root_child1, _measure_90_10);
  //  root_child1->setMeasureFunc(_measure_90_10);
  SetMaxWidth(root_child1, 50);
  SetPadding(root_child1, CSS_TOP, 40);
  InsertChild(root, root_child1, 1);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(80, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(40, GetTop(root_child0));
  ASSERT_FLOAT_EQ(0, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(15, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child1));

  NodeFreeRecursive(root);
}
