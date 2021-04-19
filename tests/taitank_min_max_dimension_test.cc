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

TEST(TAITANK_TEST, max_width) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_max_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, max_height) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 10);
  set_taitank_node_style_max_height(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, min_height) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_min_height(root_child0, 60);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child1, 1);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, min_width) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_min_width(root_child0, 60);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child1, 1);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_min_max) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_min_height(root, 100);
  set_taitank_node_style_max_height(root, 200);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 60);
  set_taitank_node_style_height(root_child0, 60);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_items_min_max) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_min_width(root, 100);
  set_taitank_node_style_max_width(root, 200);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 60);
  set_taitank_node_style_height(root_child0, 60);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, justify_content_overflow_min_max) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_min_height(root, 100);
  set_taitank_node_style_max_height(root, 110);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 50);
  set_taitank_node_style_height(root_child2, 50);
  TaitankNodeInsertChild(root, root_child2, 2);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(110, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(-20, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child2));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(110, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(-20, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child2));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_to_min) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_min_height(root, 100);
  set_taitank_node_style_max_height(root, 500);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_flex_shrink(root_child0, 1);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_in_at_most_container) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_align_items(root, FLEX_ALIGN_START);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root_child0, FLEX_DIRECTION_ROW);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0_child0, 1);
  set_taitank_node_style_flex_basis(root_child0_child0, 0);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_child) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_flex_basis(root_child0, 0);
  set_taitank_node_style_height(root_child0, 100);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_within_constrained_min_max_column) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_min_height(root, 100);
  set_taitank_node_style_max_height(root, 200);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_within_max_width) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root_child0, FLEX_DIRECTION_ROW);
  set_taitank_node_style_max_width(root_child0, 100);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0_child0, 1);
  set_taitank_node_style_height(root_child0_child0, 20);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_within_constrained_max_width) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root_child0, FLEX_DIRECTION_ROW);
  set_taitank_node_style_max_width(root_child0, 300);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0_child0, 1);
  set_taitank_node_style_height(root_child0_child0, 20);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_root_ignored) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root, 1);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_min_height(root, 100);
  set_taitank_node_style_max_height(root, 500);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_flex_basis(root_child0, 200);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child1, 100);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(300, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(300, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_root_minimized) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_min_height(root, 100);
  set_taitank_node_style_max_height(root, 500);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_min_height(root_child0, 100);
  set_taitank_node_style_max_height(root_child0, 500);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0_child0, 1);
  set_taitank_node_style_flex_basis(root_child0_child0, 200);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child1 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child0_child1, 100);
  TaitankNodeInsertChild(root_child0, root_child0_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(300, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(300, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child1));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_top(root_child0_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(300, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(300, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child1));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_top(root_child0_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_height_maximized) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 500);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_min_height(root_child0, 100);
  set_taitank_node_style_max_height(root_child0, 500);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0_child0, 1);
  set_taitank_node_style_flex_basis(root_child0_child0, 200);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child1 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child0_child1, 100);
  TaitankNodeInsertChild(root_child0, root_child0_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(400, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child1));
  ASSERT_FLOAT_EQ(400, get_taitank_node_layout_top(root_child0_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(400, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child1));
  ASSERT_FLOAT_EQ(400, get_taitank_node_layout_top(root_child0_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_within_constrained_min_row) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_min_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_within_constrained_min_column) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_min_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_within_constrained_max_row) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 200);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root_child0, FLEX_DIRECTION_ROW);
  set_taitank_node_style_max_width(root_child0, 100);
  set_taitank_node_style_height(root_child0, 100);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_shrink(root_child0_child0, 1);
  set_taitank_node_style_flex_basis(root_child0_child0, 100);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0_child1, 50);
  TaitankNodeInsertChild(root_child0, root_child0_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child0_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(200, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_grow_within_constrained_max_column) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_max_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_shrink(root_child0, 1);
  set_taitank_node_style_flex_basis(root_child0, 100);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, child_min_max_width_flexing) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_width(root, 120);
  set_taitank_node_style_height(root, 50);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0, 1);
  set_taitank_node_style_flex_basis(root_child0, 0);
  set_taitank_node_style_min_width(root_child0, 60);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child1, 1);
  set_taitank_node_style_flex_basis(root_child1, 60);
  set_taitank_node_style_max_width(root_child1, 20);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(120, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(120, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, min_width_overrides_width) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 50);
  set_taitank_node_style_min_width(root, 100);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, max_width_overrides_width) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 200);
  set_taitank_node_style_max_width(root, 100);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, min_height_overrides_height) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_height(root, 50);
  set_taitank_node_style_min_height(root, 100);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, max_height_overrides_height) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_height(root, 200);
  set_taitank_node_style_max_height(root, 100);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, min_max_percent_no_width_height) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_START);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_min_width(root_child0, 10);
  set_taitank_node_style_max_width(root_child0, 10);
  set_taitank_node_style_min_height(root_child0, 10);
  set_taitank_node_style_max_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}
