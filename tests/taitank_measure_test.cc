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
  int *measureCount = reinterpret_cast<int *>(node->get_context());
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
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  int measureCount = 0;

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  root_child0->set_context(&measureCount);
  set_taitank_node_measure_function(root_child0, _measure);
  //  set_taitank_node_measure_function(root_child0, _measure);;
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_flex_shrink(root_child0, 1);
  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(0, measureCount);

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_absolute_child_with_no_constraints) {
  const TaitankNodeRef root = TaitankNodeCreate();

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  TaitankNodeInsertChild(root, root_child0, 0);

  int measureCount = 0;

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_position_type(root_child0_child0, POSITION_TYPE_ABSOLUTE);
  root_child0_child0->set_context(&measureCount);
  set_taitank_node_measure_function(root_child0_child0, _measure);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(1, measureCount);

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, dont_measure_when_min_equals_max) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_START);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  int measureCount = 0;

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  root_child0->set_context(&measureCount);
  set_taitank_node_measure_function(root_child0, _measure);
  //  set_taitank_node_measure_function(root_child0, _measure);;
  set_taitank_node_style_min_width(root_child0, 10);
  set_taitank_node_style_max_width(root_child0, 10);
  set_taitank_node_style_min_height(root_child0, 10);
  set_taitank_node_style_max_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(0, measureCount);
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, dont_measure_when_min_equals_max_percentages) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_START);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  int measureCount = 0;

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  root_child0->set_context(&measureCount);
  set_taitank_node_measure_function(root_child0, _measure);
  //  set_taitank_node_measure_function(root_child0, _measure);;
  set_taitank_node_style_min_width(root_child0, 10);
  set_taitank_node_style_max_width(root_child0, 10);
  set_taitank_node_style_min_height(root_child0, 10);
  set_taitank_node_style_max_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(0, measureCount);
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_nodes_with_margin_auto_and_stretch) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 500);
  set_taitank_node_style_height(root, 500);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_measure_function(root_child0, _measure);
  //  set_taitank_node_measure_function(root_child0, _measure);;
  set_taitank_node_style_margin_auto(root_child0, CSS_LEFT);
  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  EXPECT_EQ(490, get_taitank_node_layout_left(root_child0));
  EXPECT_EQ(0, get_taitank_node_layout_top(root_child0));
  EXPECT_EQ(10, get_taitank_node_layout_width(root_child0));
  EXPECT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, dont_measure_when_min_equals_max_mixed_width_percent) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_START);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  int measureCount = 0;

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  root_child0->set_context(&measureCount);
  //  set_taitank_node_measure_function(root_child0, _measure);;
  set_taitank_node_measure_function(root_child0, _measure);
  set_taitank_node_style_min_width(root_child0, 10);
  set_taitank_node_style_max_width(root_child0, 10);
  set_taitank_node_style_min_height(root_child0, 10);
  set_taitank_node_style_max_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(0, measureCount);
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, dont_measure_when_min_equals_max_mixed_height_percent) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_START);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  int measureCount = 0;

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  root_child0->set_context(&measureCount);
  set_taitank_node_measure_function(root_child0, _measure);
  set_taitank_node_style_min_width(root_child0, 10);
  set_taitank_node_style_max_width(root_child0, 10);
  set_taitank_node_style_min_height(root_child0, 10);
  set_taitank_node_style_max_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(0, measureCount);
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_enough_size_should_be_in_single_line) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_align_self(root_child0, FLEX_ALIGN_START);
  set_taitank_node_measure_function(root_child0, _simulate_wrapping_text);
  //   set_taitank_node_measure_function(root_child0, _simulate_wrapping_text);;

  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(68, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(16, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_not_enough_size_should_wrap) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 55);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_align_self(root_child0, FLEX_ALIGN_START);
  set_taitank_node_measure_function(root_child0, _simulate_wrapping_text);
  //   set_taitank_node_measure_function(root_child0, _simulate_wrapping_text);;
  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(32, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_zero_space_should_grow) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_height(root, 200);
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_COLUMN);
  set_taitank_node_style_flex_grow(root, 0);

  int measureCount = 0;

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root_child0, FLEX_DIRECTION_COLUMN);
  //  set_taitank_node_style_padding(root_child0, YGEdgeAll, 100);

  set_taitank_node_style_padding(root_child0, CSS_LEFT, 100);
  set_taitank_node_style_padding(root_child0, CSS_TOP, 100);
  set_taitank_node_style_padding(root_child0, CSS_RIGHT, 100);
  set_taitank_node_style_padding(root_child0, CSS_BOTTOM, 100);

  root_child0->set_context(&measureCount);
  set_taitank_node_measure_function(root_child0, _measure);

  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, 282, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(282, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_flex_direction_row_and_padding) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_padding(root, CSS_LEFT, 25);
  set_taitank_node_style_padding(root, CSS_TOP, 25);
  set_taitank_node_style_padding(root, CSS_RIGHT, 25);
  set_taitank_node_style_padding(root, CSS_BOTTOM, 25);
  set_taitank_node_style_width(root, 50);
  set_taitank_node_style_height(root, 50);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_measure_function(root_child0, _simulate_wrapping_text);
  //  set_taitank_node_measure_function(root_child0, _simulate_wrapping_text);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 5);
  set_taitank_node_style_height(root_child1, 5);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(75, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(5, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(5, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_flex_direction_column_and_padding) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_margin(root, CSS_TOP, 20);
  //  set_taitank_node_style_padding(root, YGEdgeAll, 25);
  set_taitank_node_style_padding(root, CSS_LEFT, 25);
  set_taitank_node_style_padding(root, CSS_TOP, 25);
  set_taitank_node_style_padding(root, CSS_RIGHT, 25);
  set_taitank_node_style_padding(root, CSS_BOTTOM, 25);
  set_taitank_node_style_width(root, 50);
  set_taitank_node_style_height(root, 50);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  // set_taitank_node_measure_function(root_child0, _simulate_wrapping_text);;
  set_taitank_node_measure_function(root_child0, _simulate_wrapping_text);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 5);
  set_taitank_node_style_height(root_child1, 5);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(32, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(57, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(5, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(5, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_flex_direction_row_no_padding) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_margin(root, CSS_TOP, 20);
  set_taitank_node_style_width(root, 50);
  set_taitank_node_style_height(root, 50);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_measure_function(root_child0, _simulate_wrapping_text);
  // set_taitank_node_measure_function(root_child0, _simulate_wrapping_text);;
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 5);
  set_taitank_node_style_height(root_child1, 5);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(5, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(5, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_flex_direction_row_no_padding_align_items_flexstart) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_margin(root, CSS_TOP, 20);
  set_taitank_node_style_width(root, 50);
  set_taitank_node_style_height(root, 50);
  set_taitank_node_style_align_items(root, FLEX_ALIGN_START);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_measure_function(root_child0, _simulate_wrapping_text);
  //   set_taitank_node_measure_function(root_child0, _simulate_wrapping_text);;
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 5);
  set_taitank_node_style_height(root_child1, 5);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(32, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(5, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(5, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_with_fixed_size) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_margin(root, CSS_TOP, 20);
  //  set_taitank_node_style_padding(root, YGEdgeAll, 25);
  set_taitank_node_style_padding(root, CSS_LEFT, 25);
  set_taitank_node_style_padding(root, CSS_TOP, 25);
  set_taitank_node_style_padding(root, CSS_RIGHT, 25);
  set_taitank_node_style_padding(root, CSS_BOTTOM, 25);
  set_taitank_node_style_width(root, 50);
  set_taitank_node_style_height(root, 50);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_measure_function(root_child0, _simulate_wrapping_text);
  //   set_taitank_node_measure_function(root_child0, _simulate_wrapping_text);;
  set_taitank_node_style_width(root_child0, 10);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 5);
  set_taitank_node_style_height(root_child1, 5);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(35, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(5, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(5, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_with_flex_shrink) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_margin(root, CSS_TOP, 20);
  //  set_taitank_node_style_padding(root, YGEdgeAll, 25);
  set_taitank_node_style_padding(root, CSS_LEFT, 25);
  set_taitank_node_style_padding(root, CSS_TOP, 25);
  set_taitank_node_style_padding(root, CSS_RIGHT, 25);
  set_taitank_node_style_padding(root, CSS_BOTTOM, 25);
  set_taitank_node_style_width(root, 50);
  set_taitank_node_style_height(root, 50);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_measure_function(root_child0, _simulate_wrapping_text);
  set_taitank_node_style_flex_shrink(root_child0, 1);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 5);
  set_taitank_node_style_height(root_child1, 5);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(25, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(5, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(5, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, measure_no_padding) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_margin(root, CSS_TOP, 20);
  set_taitank_node_style_width(root, 50);
  set_taitank_node_style_height(root, 50);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_measure_function(root_child0, _simulate_wrapping_text);
  set_taitank_node_style_flex_shrink(root_child0, 1);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 5);
  set_taitank_node_style_height(root_child1, 5);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(32, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(32, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(5, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(5, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

#if GTEST_HAS_DEATH_TEST
TEST(TAITANK_TEST, cannot_add_child_to_node_with_measure_func) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_measure_function(root, _measure);
  //  set_taitank_node_measure_function(root, _measure);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  ASSERT_FALSE(TaitankNodeInsertChild(root, root_child0, 0));
  TaitankNodeFree(root_child0);
  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, cannot_add_nonnull_measure_func_to_non_leaf_node) {
  const TaitankNodeRef root = TaitankNodeCreate();
  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  TaitankNodeInsertChild(root, root_child0, 0);
  ASSERT_FALSE(set_taitank_node_measure_function(root, _measure));
  TaitankNodeFreeRecursive(root);
}

#endif

TEST(TAITANK_TEST, can_nullify_measure_func_on_any_node) {
  const TaitankNodeRef root = TaitankNodeCreate();
  TaitankNodeInsertChild(root, TaitankNodeCreate(), 0);
  //  root->setMeasureFunc(nullptr);
  set_taitank_node_measure_function(root, nullptr);
  ASSERT_TRUE(root->measure_ == NULL);
  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, cant_call_negative_measure) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_COLUMN);
  set_taitank_node_style_width(root, 50);
  set_taitank_node_style_height(root, 10);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_measure_function(root, _measure_assert_negative);
  //  root_child0->setMeasureFunc(_measure_assert_negative);
  set_taitank_node_style_margin(root_child0, CSS_TOP, 20);
  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, cant_call_negative_measure_horizontal) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_width(root, 10);
  set_taitank_node_style_height(root, 20);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_measure_function(root_child0, _measure_assert_negative);
  //  root_child0->setMeasureFunc(_measure_assert_negative);
  set_taitank_node_style_margin(root_child0, CSS_LEFT, 20);
  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  TaitankNodeFreeRecursive(root);
}

static TaitankSize _measure_90_10(TaitankNodeRef node, float width, MeasureMode widthMode,
                                  float height, MeasureMode heightMode, void *layoutContext) {
  return TaitankSize{
      .width = 90,
      .height = 10,
  };
}

TEST(TAITANK_TEST, percent_with_text_node) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_SPACE_BETWEEN);
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 80);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_measure_function(root_child1, _measure_90_10);
  //  root_child1->setMeasureFunc(_measure_90_10);
  set_taitank_node_style_max_width(root_child1, 50);
  set_taitank_node_style_padding(root_child1, CSS_TOP, 40);
  TaitankNodeInsertChild(root, root_child1, 1);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(15, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}
