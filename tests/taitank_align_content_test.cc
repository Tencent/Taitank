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

TEST(TAITANK_TEST, align_content_flex_start) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_width(root, 130);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 50);
  set_taitank_node_style_height(root_child2, 10);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child3, 50);
  set_taitank_node_style_height(root_child3, 10);
  TaitankNodeInsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child4, 50);
  set_taitank_node_style_height(root_child4, 10);
  TaitankNodeInsertChild(root, root_child4, 4);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(130, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child4));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_flex_start_without_height_on_children) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 50);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child3, 50);
  set_taitank_node_style_height(root_child3, 10);
  TaitankNodeInsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child4, 50);
  TaitankNodeInsertChild(root, root_child4, 4);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child4));

  TaitankNodeFreeRecursive(root);
}
//
// TEST(TAITANK_TEST, align_content_flex_start_with_flex) {
//
//
//  const TaitankNodeRef root = TaitankNodeCreate();
//  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
//  set_taitank_node_style_width(root, 100);
//  set_taitank_node_style_height(root, 120);
//
//  const TaitankNodeRef root_child0 = TaitankNodeCreate();
//  set_taitank_node_style_flex_grow(root_child0, 1);
//  set_taitank_node_style_flex_basis_percent(root_child0, 0);
//  set_taitank_node_style_width(root_child0, 50);
//  TaitankNodeInsertChild(root, root_child0, 0);
//
//  const TaitankNodeRef root_child1 = TaitankNodeCreate();
//  set_taitank_node_style_flex_grow(root_child1, 1);
//  set_taitank_node_style_flex_basis_percent(root_child1, 0);
//  set_taitank_node_style_width(root_child1, 50);
//  set_taitank_node_style_height(root_child1, 10);
//  TaitankNodeInsertChild(root, root_child1, 1);
//
//  const TaitankNodeRef root_child2 = TaitankNodeCreate();
//  set_taitank_node_style_width(root_child2, 50);
//  TaitankNodeInsertChild(root, root_child2, 2);
//
//  const TaitankNodeRef root_child3 = TaitankNodeCreate();
//  set_taitank_node_style_flex_grow(root_child3, 1);
//  set_taitank_node_style_flex_shrink(root_child3, 1);
//  set_taitank_node_style_flex_basis_percent(root_child3, 0);
//  set_taitank_node_style_width(root_child3, 50);
//  TaitankNodeInsertChild(root, root_child3, 3);
//
//  const TaitankNodeRef root_child4 = TaitankNodeCreate();
//  set_taitank_node_style_width(root_child4, 50);
//  TaitankNodeInsertChild(root, root_child4, 4);
//   TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
//
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
//  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
//  ASSERT_FLOAT_EQ(120, get_taitank_node_layout_height(root));
//
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
//  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0));
//
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
//  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_top(root_child1));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
//  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child1));
//
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
//  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child2));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child2));
//
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child3));
//  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child3));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
//  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child3));
//
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child4));
//  ASSERT_FLOAT_EQ(120, get_taitank_node_layout_top(root_child4));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child4));
//
//  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);
//
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
//  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
//  ASSERT_FLOAT_EQ(120, get_taitank_node_layout_height(root));
//
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child0));
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
//  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0));
//
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
//  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_top(root_child1));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
//  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child1));
//
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child2));
//  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child2));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child2));
//
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child3));
//  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child3));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
//  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child3));
//
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child4));
//  ASSERT_FLOAT_EQ(120, get_taitank_node_layout_top(root_child4));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child4));
//
//  TaitankNodeFreeRecursive(root);
//
//
//}

TEST(TAITANK_TEST, align_content_flex_end) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_content(root, FLEX_ALIGN_END);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 50);
  set_taitank_node_style_height(root_child2, 10);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child3, 50);
  set_taitank_node_style_height(root_child3, 10);
  TaitankNodeInsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child4, 50);
  set_taitank_node_style_height(root_child4, 10);
  TaitankNodeInsertChild(root, root_child4, 4);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child4));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child4));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_stretch) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_content(root, FLEX_ALIGN_STRETCH);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_width(root, 150);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 50);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child3, 50);
  TaitankNodeInsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child4, 50);
  TaitankNodeInsertChild(root, root_child4, 4);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child4));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child4));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_spacebetween) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_align_content(root, FLEX_ALIGN_SPACE_BETWEEN);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_width(root, 130);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 50);
  set_taitank_node_style_height(root_child2, 10);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child3, 50);
  set_taitank_node_style_height(root_child3, 10);
  TaitankNodeInsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child4, 50);
  set_taitank_node_style_height(root_child4, 10);
  TaitankNodeInsertChild(root, root_child4, 4);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(130, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(45, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(45, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child4));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(130, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(45, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(30, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(45, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child4));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_spacearound) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_align_content(root, FLEX_ALIGN_SPACE_AROUND);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_width(root, 140);
  set_taitank_node_style_height(root, 120);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 10);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 10);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 50);
  set_taitank_node_style_height(root_child2, 10);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child3, 50);
  set_taitank_node_style_height(root_child3, 10);
  TaitankNodeInsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child4, 50);
  set_taitank_node_style_height(root_child4, 10);
  TaitankNodeInsertChild(root, root_child4, 4);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(140, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(120, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(15, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(15, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(55, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(55, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(95, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child4));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(140, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(120, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(15, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(15, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(55, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(55, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(95, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child4));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_stretch_row) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_align_content(root, FLEX_ALIGN_STRETCH);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_width(root, 150);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 50);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child3, 50);
  TaitankNodeInsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child4, 50);
  TaitankNodeInsertChild(root, root_child4, 4);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child4));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child4));

  TaitankNodeFreeRecursive(root);
}
//
// TEST(TAITANK_TEST, align_content_stretch_row_with_children) {
//
//
//  const TaitankNodeRef root = TaitankNodeCreate();
//  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
//  set_taitank_node_style_align_content(root, FLEX_ALIGN_STRETCH);
//  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
//  set_taitank_node_style_width(root, 150);
//  set_taitank_node_style_height(root, 100);
//
//  const TaitankNodeRef root_child0 = TaitankNodeCreate();
//  set_taitank_node_style_width(root_child0, 50);
//  TaitankNodeInsertChild(root, root_child0, 0);
//
//  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
//  set_taitank_node_style_flex_grow(root_child0_child0, 1);
//  set_taitank_node_style_flex_shrink(root_child0_child0, 1);
//  set_taitank_node_style_flex_basis_percent(root_child0_child0, 0);
//  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);
//
//  const TaitankNodeRef root_child1 = TaitankNodeCreate();
//  set_taitank_node_style_width(root_child1, 50);
//  TaitankNodeInsertChild(root, root_child1, 1);
//
//  const TaitankNodeRef root_child2 = TaitankNodeCreate();
//  set_taitank_node_style_width(root_child2, 50);
//  TaitankNodeInsertChild(root, root_child2, 2);
//
//  const TaitankNodeRef root_child3 = TaitankNodeCreate();
//  set_taitank_node_style_width(root_child3, 50);
//  TaitankNodeInsertChild(root, root_child3, 3);
//
//  const TaitankNodeRef root_child4 = TaitankNodeCreate();
//  set_taitank_node_style_width(root_child4, 50);
//  TaitankNodeInsertChild(root, root_child4, 4);
//   TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
//
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
//  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
//  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));
//
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));
//
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0_child0));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0_child0));
//
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));
//
//  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child2));
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child2));
//
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child3));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child3));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child3));
//
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child4));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child4));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child4));
//
//  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);
//
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
//  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
//  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));
//
//  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child0));
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));
//
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0_child0));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0_child0));
//
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));
//
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
//  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child2));
//
//  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child3));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child3));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child3));
//
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child4));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child4));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
//  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child4));
//
//  TaitankNodeFreeRecursive(root);
//
//
//}

TEST(TAITANK_TEST, align_content_stretch_row_with_flex) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_align_content(root, FLEX_ALIGN_STRETCH);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_width(root, 150);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child1, 1);
  set_taitank_node_style_flex_shrink(root_child1, 1);
  //  set_taitank_node_style_flex_basis_percent(root_child1, 0);
  set_taitank_node_style_flex_basis(root_child1, 0);
  set_taitank_node_style_width(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 50);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child3, 1);
  set_taitank_node_style_flex_shrink(root_child3, 1);
  //  set_taitank_node_style_flex_basis_percent(root_child3, 0);
  set_taitank_node_style_flex_basis(root_child3, 0);
  set_taitank_node_style_width(root_child3, 50);
  TaitankNodeInsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child4, 50);
  TaitankNodeInsertChild(root, root_child4, 4);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child4));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child4));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_stretch_row_with_flex_no_shrink) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_align_content(root, FLEX_ALIGN_STRETCH);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_width(root, 150);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child1, 1);
  set_taitank_node_style_flex_shrink(root_child1, 1);
  // set_taitank_node_style_flex_basis_percent(root_child1, 0);
  set_taitank_node_style_flex_basis(root_child1, 0);
  set_taitank_node_style_width(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 50);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child3, 1);
  // set_taitank_node_style_flex_basis_percent(root_child3, 0);
  set_taitank_node_style_flex_basis(root_child3, 0);
  set_taitank_node_style_width(root_child3, 50);
  TaitankNodeInsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child4, 50);
  TaitankNodeInsertChild(root, root_child4, 4);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child4));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child4));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_stretch_row_with_margin) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_align_content(root, FLEX_ALIGN_STRETCH);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_width(root, 150);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_margin(root_child1, CSS_LEFT, 10);
  set_taitank_node_style_margin(root_child1, CSS_TOP, 10);
  set_taitank_node_style_margin(root_child1, CSS_RIGHT, 10);
  set_taitank_node_style_margin(root_child1, CSS_BOTTOM, 10);
  set_taitank_node_style_width(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 50);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_margin(root_child3, CSS_LEFT, 10);
  set_taitank_node_style_margin(root_child3, CSS_TOP, 10);
  set_taitank_node_style_margin(root_child3, CSS_RIGHT, 10);
  set_taitank_node_style_margin(root_child3, CSS_BOTTOM, 10);
  set_taitank_node_style_width(root_child3, 50);
  TaitankNodeInsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child4, 50);
  TaitankNodeInsertChild(root, root_child4, 4);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child4));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(40, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child4));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_stretch_row_with_padding) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_align_content(root, FLEX_ALIGN_STRETCH);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_width(root, 150);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_padding(root_child1, CSS_LEFT, 10);
  set_taitank_node_style_padding(root_child1, CSS_TOP, 10);
  set_taitank_node_style_padding(root_child1, CSS_RIGHT, 10);
  set_taitank_node_style_padding(root_child1, CSS_BOTTOM, 10);
  set_taitank_node_style_width(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 50);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_padding(root_child3, CSS_LEFT, 10);
  set_taitank_node_style_padding(root_child3, CSS_TOP, 10);
  set_taitank_node_style_padding(root_child3, CSS_RIGHT, 10);
  set_taitank_node_style_padding(root_child3, CSS_BOTTOM, 10);
  set_taitank_node_style_width(root_child3, 50);
  TaitankNodeInsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child4, 50);
  TaitankNodeInsertChild(root, root_child4, 4);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child4));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child4));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_stretch_row_with_single_row) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_align_content(root, FLEX_ALIGN_STRETCH);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_width(root, 150);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
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
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child1));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_stretch_row_with_fixed_height) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_align_content(root, FLEX_ALIGN_STRETCH);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_width(root, 150);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 60);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 50);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child3, 50);
  TaitankNodeInsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child4, 50);
  TaitankNodeInsertChild(root, root_child4, 4);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child4));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(60, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(80, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child4));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_stretch_row_with_max_height) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_align_content(root, FLEX_ALIGN_STRETCH);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_width(root, 150);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_max_height(root_child1, 20);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 50);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child3, 50);
  TaitankNodeInsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child4, 50);
  TaitankNodeInsertChild(root, root_child4, 4);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child4));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(20, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child4));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_stretch_row_with_min_height) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_align_content(root, FLEX_ALIGN_STRETCH);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_width(root, 150);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_min_height(root_child1, 80);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child2, 50);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child3, 50);
  TaitankNodeInsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child4, 50);
  TaitankNodeInsertChild(root, root_child4, 4);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child4));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child4));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_stretch_column) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_content(root, FLEX_ALIGN_STRETCH);
  set_taitank_node_style_flex_wrap(root, FLEX_WRAP);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 150);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child0, 50);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child0_child0, 1);
  set_taitank_node_style_flex_shrink(root_child0_child0, 1);
  // set_taitank_node_style_flex_basis_percent(root_child0_child0, 0);
  set_taitank_node_style_flex_basis(root_child0_child0, 0);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(root_child1, 1);
  set_taitank_node_style_flex_shrink(root_child1, 1);
  // set_taitank_node_style_flex_basis_percent(root_child1, 0);
  set_taitank_node_style_flex_basis(root_child1, 0);
  set_taitank_node_style_height(root_child1, 50);
  TaitankNodeInsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child2, 50);
  TaitankNodeInsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child3, 50);
  TaitankNodeInsertChild(root, root_child3, 3);

  const TaitankNodeRef root_child4 = TaitankNodeCreate();
  set_taitank_node_style_height(root_child4, 50);
  TaitankNodeInsertChild(root, root_child4, 4);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child4));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(150, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child0_child0));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child1));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child1));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(root_child1));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_top(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child2));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child2));

  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_left(root_child3));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_top(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child3));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child3));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child4));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_width(root_child4));
  ASSERT_FLOAT_EQ(50, get_taitank_node_layout_height(root_child4));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, align_content_stretch_is_not_overriding_align_items) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_content(root, FLEX_ALIGN_STRETCH);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root_child0, FLEX_DIRECTION_ROW);
  set_taitank_node_style_align_content(root_child0, FLEX_ALIGN_STRETCH);
  set_taitank_node_style_align_items(root_child0, FLEX_ALIGN_CENTER);
  set_taitank_node_style_width(root_child0, 100);
  set_taitank_node_style_height(root_child0, 100);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_align_content(root_child0_child0, FLEX_ALIGN_STRETCH);
  set_taitank_node_style_width(root_child0_child0, 10);
  set_taitank_node_style_height(root_child0_child0, 10);
  TaitankNodeInsertChild(root_child0, root_child0_child0, 0);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(45, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0_child0));

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root));

  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_FLOAT_EQ(100, get_taitank_node_layout_height(root_child0));

  ASSERT_FLOAT_EQ(90, get_taitank_node_layout_left(root_child0_child0));
  ASSERT_FLOAT_EQ(45, get_taitank_node_layout_top(root_child0_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_width(root_child0_child0));
  ASSERT_FLOAT_EQ(10, get_taitank_node_layout_height(root_child0_child0));

  TaitankNodeFreeRecursive(root);
}
