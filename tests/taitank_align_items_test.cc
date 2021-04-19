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

TEST(TAITANK_TEST, align_items_stretch) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  //  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  //  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  //  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));
  //
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  //  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  //  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_items_center) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 10);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(45, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(45, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_items_flex_start) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_START);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 10);
  set_taitank_node_style_height(root_child0, 10);
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

  //  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  //  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  //  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));
  //
  //  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_left(root_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  //  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  //  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_items_flex_end) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_END);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 10);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  //  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  //  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  //  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));
  //
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  //  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0));
  //  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_items_center_child_with_margin_bigger_than_parent) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 52);
  set_taitank_node_style_height(root, 52);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_align_items(root_child0, FLEX_ALIGN_CENTER);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin(root_child0_child0, CSS_LEFT, 10);
  set_taitank_node_style_margin(root_child0_child0, CSS_RIGHT, 10);
  set_taitank_node_style_width(root_child0_child0, 52);
  set_taitank_node_style_height(root_child0_child0, 52);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(-10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root_child0_child0));

  //  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  //  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_width(root));
  //  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root));
  //
  //  ASSERT_FLOAT_EQ(-10, get_taitank_node_layout_left(root_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  //  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_width(root_child0));
  //  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root_child0));
  //
  //  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  //  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_width(root_child0_child0));
  //  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root_child0_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_items_flex_end_child_with_margin_bigger_than_parent) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 52);
  set_taitank_node_style_height(root, 52);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_align_items(root_child0, FLEX_ALIGN_END);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_margin(root_child0_child0, CSS_LEFT, 10);
  set_taitank_node_style_margin(root_child0_child0, CSS_RIGHT, 10);
  set_taitank_node_style_width(root_child0_child0, 52);
  set_taitank_node_style_height(root_child0_child0, 52);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(-10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root_child0_child0));

  //  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  //  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_width(root));
  //  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root));
  //
  //  ASSERT_FLOAT_EQ(-10, get_taitank_node_layout_left(root_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  //  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_width(root_child0));
  //  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root_child0));
  //
  //  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_left(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  //  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_width(root_child0_child0));
  //  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root_child0_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_items_center_child_without_margin_bigger_than_parent) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 52);
  set_taitank_node_style_height(root, 52);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_align_items(root_child0, FLEX_ALIGN_CENTER);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0_child0, 72);
  set_taitank_node_style_height(root_child0_child0, 72);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(-10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(-10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_height(root_child0_child0));

  //  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  //  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_width(root));
  //  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root));
  //
  //  ASSERT_FLOAT_EQ(-10, get_taitank_node_layout_left(root_child0));
  //  ASSERT_FLOAT_EQ(-10, get_taitank_node_layout_top(root_child0));
  //  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_width(root_child0));
  //  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_height(root_child0));
  //
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  //  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_width(root_child0_child0));
  //  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_height(root_child0_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_items_flex_end_child_without_margin_bigger_than_parent) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root, 52);
  set_taitank_node_style_height(root, 52);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_align_items(root_child0, FLEX_ALIGN_END);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0_child0, 72);
  set_taitank_node_style_height(root_child0_child0, 72);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(-10, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(-10, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_height(root_child0_child0));

  //  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  //  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_width(root));
  //  ASSERT_FLOAT_EQ(52, get_taitank_node_layout_height(root));
  //
  //  ASSERT_FLOAT_EQ(-10, get_taitank_node_layout_left(root_child0));
  //  ASSERT_FLOAT_EQ(-10, get_taitank_node_layout_top(root_child0));
  //  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_width(root_child0));
  //  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_height(root_child0));
  //
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  //  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_width(root_child0_child0));
  //  ASSERT_FLOAT_EQ(72, get_taitank_node_layout_height(root_child0_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_center_should_size_based_on_content) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_CENTER);
  set_taitank_node_style_margin(root, CSS_TOP, 20);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root_child0, FLEX_ALIGN_CENTER);
  set_taitank_node_style_flex_shrink(root_child0, 1);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0_child0, 1);
  set_taitank_node_style_flex_shrink(root_child0_child0, 1);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0_child0_child0, 20);
  set_taitank_node_style_height(root_child0_child0_child0, 20);
  TaitankNodeInsertChild(root_child0_child0, root_child0_child0_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0_child0_child0));

  //  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  //  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root));
  //  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  //  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));
  //
  //  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_left(root_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  //  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child0));
  //  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));
  //
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  //  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child0_child0));
  //  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0_child0));
  //
  //  ASSERT_FLOAT_EQ(0,
  //  get_taitank_node_layout_left(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(0,
  //  get_taitank_node_layout_top(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(20,
  //  get_taitank_node_layout_width(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(20,
  //  get_taitank_node_layout_height(root_child0_child0_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_strech_should_size_based_on_parent) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_margin(root, CSS_TOP, 20);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_justify_content(root_child0, FLEX_ALIGN_CENTER);
  set_taitank_node_style_flex_shrink(root_child0, 1);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0_child0, 1);
  set_taitank_node_style_flex_shrink(root_child0_child0, 1);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0_child0_child0, 20);
  set_taitank_node_style_height(root_child0_child0_child0, 20);
  TaitankNodeInsertChild(root_child0_child0, root_child0_child0_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_width(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0_child0_child0));

  //  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  //  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root));
  //  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  //  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));
  //
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  //  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  //  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0));
  //
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  //  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0_child0));
  //  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child0_child0));
  //
  //  ASSERT_FLOAT_EQ(80,
  //  get_taitank_node_layout_left(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(0,
  //  get_taitank_node_layout_top(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(20,
  //  get_taitank_node_layout_width(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(20,
  //  get_taitank_node_layout_height(root_child0_child0_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_flex_start_with_shrinking_children) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 500);
  set_taitank_node_style_height(root, 500);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_align_items(root_child0, FLEX_ALIGN_START);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0_child0, 1);
  set_taitank_node_style_flex_shrink(root_child0_child0, 1);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0_child0_child0, 1);
  set_taitank_node_style_flex_shrink(root_child0_child0_child0, 1);
  TaitankNodeInsertChild(root_child0_child0, root_child0_child0_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0_child0_child0));

  //  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  //  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_width(root));
  //  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_height(root));
  //
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  //  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_width(root_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0));
  //
  //  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_left(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0_child0));
  //
  //  ASSERT_FLOAT_EQ(0,
  //  get_taitank_node_layout_left(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(0,
  //  get_taitank_node_layout_top(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(0,
  //  get_taitank_node_layout_width(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(0,
  //  get_taitank_node_layout_height(root_child0_child0_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_flex_start_with_stretching_children) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 500);
  set_taitank_node_style_height(root, 500);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0_child0, 1);
  set_taitank_node_style_flex_shrink(root_child0_child0, 1);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0_child0_child0, 1);
  set_taitank_node_style_flex_shrink(root_child0_child0_child0, 1);
  TaitankNodeInsertChild(root_child0_child0, root_child0_child0_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_width(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0_child0_child0));

  //  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  //  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_width(root));
  //  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_height(root));
  //
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  //  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_width(root_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0));
  //
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  //  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_width(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0_child0));
  //
  //  ASSERT_FLOAT_EQ(0,
  //  get_taitank_node_layout_left(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(0,
  //  get_taitank_node_layout_top(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(500,
  //  get_taitank_node_layout_width(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(0,
  //  get_taitank_node_layout_height(root_child0_child0_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_flex_start_with_shrinking_children_with_stretch) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 500);
  set_taitank_node_style_height(root, 500);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_align_items(root_child0, FLEX_ALIGN_START);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0_child0, 1);
  set_taitank_node_style_flex_shrink(root_child0_child0, 1);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child0_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0_child0_child0, 1);
  set_taitank_node_style_flex_shrink(root_child0_child0_child0, 1);
  TaitankNodeInsertChild(root_child0_child0, root_child0_child0_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0_child0_child0));

  //  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,
  //  DIRECTION_RTL);
  //
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  //  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_width(root));
  //  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_height(root));
  //
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  //  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_width(root_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0));
  //
  //  ASSERT_FLOAT_EQ(500, get_taitank_node_layout_left(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child0_child0));
  //  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0_child0));
  //
  //  ASSERT_FLOAT_EQ(0,
  //  get_taitank_node_layout_left(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(0,
  //  get_taitank_node_layout_top(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(0,
  //  get_taitank_node_layout_width(root_child0_child0_child0));
  //  ASSERT_FLOAT_EQ(0,
  //  get_taitank_node_layout_height(root_child0_child0_child0));

  TaitankNodeFreeRecursive(root);
}
