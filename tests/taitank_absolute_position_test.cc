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

TEST(TAITANK_TEST, absolute_layout_width_height_start_top) {
  const TaitankNodeRef root = NodeCreate();

  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetPositionType(root_child0, POSITION_TYPE_ABSOLUTE);
  SetPosition(root_child0, CSS_START, 10);
  SetPosition(root_child0, CSS_TOP, 10);
  SetWidth(root_child0, 10);
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(10, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(80, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_width_height_end_bottom) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetPositionType(root_child0, POSITION_TYPE_ABSOLUTE);
  SetPosition(root_child0, CSS_END, 10);
  SetPosition(root_child0, CSS_BOTTOM, 10);
  SetWidth(root_child0, 10);
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(80, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(80, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(10, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(80, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_start_top_end_bottom) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetPositionType(root_child0, POSITION_TYPE_ABSOLUTE);
  SetPosition(root_child0, CSS_LEFT, 10);
  SetPosition(root_child0, CSS_TOP, 10);
  SetPosition(root_child0, CSS_RIGHT, 10);
  SetPosition(root_child0, CSS_BOTTOM, 10);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(10, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, GetTop(root_child0));
  ASSERT_FLOAT_EQ(80, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(10, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, GetTop(root_child0));
  ASSERT_FLOAT_EQ(80, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(80, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_width_height_start_top_end_bottom) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetPositionType(root_child0, POSITION_TYPE_ABSOLUTE);
  SetPosition(root_child0, CSS_LEFT, 10);
  SetPosition(root_child0, CSS_TOP, 10);
  SetPosition(root_child0, CSS_RIGHT, 10);
  SetPosition(root_child0, CSS_BOTTOM, 10);
  SetWidth(root_child0, 10);
  SetHeight(root_child0, 10);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(10, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(80, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, GetTop(root_child0));
  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, do_not_clamp_height_of_absolute_node_to_height_of_its_overflow_hidden_parent) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetOverflow(root, OVERFLOW_HIDDEN);
  SetWidth(root, 50);
  SetHeight(root, 50);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetPositionType(root_child0, POSITION_TYPE_ABSOLUTE);
  SetPosition(root_child0, CSS_START, 0);
  SetPosition(root_child0, CSS_TOP, 0);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child0_child0 = NodeCreate();
  SetWidth(root_child0_child0, 100);
  SetHeight(root_child0_child0, 100);
  InsertChild(root_child0, root_child0_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(50, GetWidth(root));
  ASSERT_FLOAT_EQ(50, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(50, GetWidth(root));
  ASSERT_FLOAT_EQ(50, GetHeight(root));

  ASSERT_FLOAT_EQ(-50, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0_child0));
  ASSERT_FLOAT_EQ(100, GetWidth(root_child0_child0));
  ASSERT_FLOAT_EQ(100, GetHeight(root_child0_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_within_border) {
  const TaitankNodeRef root = NodeCreate();
  SetMargin(root, CSS_LEFT, 10);
  SetMargin(root, CSS_TOP, 10);
  SetMargin(root, CSS_RIGHT, 10);
  SetMargin(root, CSS_BOTTOM, 10);
  SetPadding(root, CSS_LEFT, 10);
  SetPadding(root, CSS_TOP, 10);
  SetPadding(root, CSS_RIGHT, 10);
  SetPadding(root, CSS_BOTTOM, 10);
  SetBorder(root, CSS_LEFT, 10);
  SetBorder(root, CSS_TOP, 10);
  SetBorder(root, CSS_RIGHT, 10);
  SetBorder(root, CSS_BOTTOM, 10);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetPositionType(root_child0, POSITION_TYPE_ABSOLUTE);
  SetPosition(root_child0, CSS_LEFT, 0);
  SetPosition(root_child0, CSS_TOP, 0);
  SetWidth(root_child0, 50);
  SetHeight(root_child0, 50);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetPositionType(root_child1, POSITION_TYPE_ABSOLUTE);
  SetPosition(root_child1, CSS_RIGHT, 0);
  SetPosition(root_child1, CSS_BOTTOM, 0);
  SetWidth(root_child1, 50);
  SetHeight(root_child1, 50);
  InsertChild(root, root_child1, 1);

  const TaitankNodeRef root_child2 = NodeCreate();
  SetPositionType(root_child2, POSITION_TYPE_ABSOLUTE);
  SetPosition(root_child2, CSS_LEFT, 0);
  SetPosition(root_child2, CSS_TOP, 0);
  SetMargin(root_child2, CSS_LEFT, 10);
  SetMargin(root_child2, CSS_TOP, 10);
  SetMargin(root_child2, CSS_RIGHT, 10);
  SetMargin(root_child2, CSS_BOTTOM, 10);
  SetWidth(root_child2, 50);
  SetHeight(root_child2, 50);
  InsertChild(root, root_child2, 2);

  const TaitankNodeRef root_child3 = NodeCreate();
  SetPositionType(root_child3, POSITION_TYPE_ABSOLUTE);
  SetPosition(root_child3, CSS_RIGHT, 0);
  SetPosition(root_child3, CSS_BOTTOM, 0);
  SetMargin(root_child3, CSS_LEFT, 10);
  SetMargin(root_child3, CSS_TOP, 10);
  SetMargin(root_child3, CSS_RIGHT, 10);
  SetMargin(root_child3, CSS_BOTTOM, 10);
  SetWidth(root_child3, 50);
  SetHeight(root_child3, 50);
  InsertChild(root, root_child3, 3);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(10, GetLeft(root));
  ASSERT_FLOAT_EQ(10, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(10, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(40, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(40, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(20, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(20, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(30, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child3));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(10, GetLeft(root));
  ASSERT_FLOAT_EQ(10, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(10, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, GetTop(root_child0));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child0));

  ASSERT_FLOAT_EQ(40, GetLeft(root_child1));
  ASSERT_FLOAT_EQ(40, GetTop(root_child1));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child1));

  ASSERT_FLOAT_EQ(20, GetLeft(root_child2));
  ASSERT_FLOAT_EQ(20, GetTop(root_child2));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child2));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child2));

  ASSERT_FLOAT_EQ(30, GetLeft(root_child3));
  ASSERT_FLOAT_EQ(30, GetTop(root_child3));
  ASSERT_FLOAT_EQ(50, GetWidth(root_child3));
  ASSERT_FLOAT_EQ(50, GetHeight(root_child3));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_align_items_and_justify_content_center) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_CENTER);
  SetAlignItems(root, FLEX_ALIGN_CENTER);
  SetFlexGrow(root, 1);
  SetWidth(root, 110);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetPositionType(root_child0, POSITION_TYPE_ABSOLUTE);
  SetWidth(root_child0, 60);
  SetHeight(root_child0, 40);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(110, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(25, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(30, GetTop(root_child0));
  ASSERT_FLOAT_EQ(60, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(110, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(25, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(30, GetTop(root_child0));
  ASSERT_FLOAT_EQ(60, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_align_items_and_justify_content_flex_end) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_END);
  SetAlignItems(root, FLEX_ALIGN_END);
  SetFlexGrow(root, 1);
  SetWidth(root, 110);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetPositionType(root_child0, POSITION_TYPE_ABSOLUTE);
  SetWidth(root_child0, 60);
  SetHeight(root_child0, 40);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(110, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(60, GetTop(root_child0));
  ASSERT_FLOAT_EQ(60, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(110, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(60, GetTop(root_child0));
  ASSERT_FLOAT_EQ(60, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_justify_content_center) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_CENTER);
  SetFlexGrow(root, 1);
  SetWidth(root, 110);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetPositionType(root_child0, POSITION_TYPE_ABSOLUTE);
  SetWidth(root_child0, 60);
  SetHeight(root_child0, 40);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(110, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(30, GetTop(root_child0));
  ASSERT_FLOAT_EQ(60, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(110, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(50, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(30, GetTop(root_child0));
  ASSERT_FLOAT_EQ(60, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_align_items_center) {
  const TaitankNodeRef root = NodeCreate();
  SetAlignItems(root, FLEX_ALIGN_CENTER);
  SetFlexGrow(root, 1);
  SetWidth(root, 110);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetPositionType(root_child0, POSITION_TYPE_ABSOLUTE);
  SetWidth(root_child0, 60);
  SetHeight(root_child0, 40);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(110, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(25, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(60, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(110, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(25, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(60, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_align_items_center_on_child_only) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexGrow(root, 1);
  SetWidth(root, 110);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetAlignSelf(root_child0, FLEX_ALIGN_CENTER);
  SetPositionType(root_child0, POSITION_TYPE_ABSOLUTE);
  SetWidth(root_child0, 60);
  SetHeight(root_child0, 40);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(110, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(25, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(60, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(110, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(25, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(60, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_align_items_and_justify_content_center_and_top_position) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_CENTER);
  SetAlignItems(root, FLEX_ALIGN_CENTER);
  SetFlexGrow(root, 1);
  SetWidth(root, 110);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetPositionType(root_child0, POSITION_TYPE_ABSOLUTE);
  SetPosition(root_child0, CSS_TOP, 10);
  SetWidth(root_child0, 60);
  SetHeight(root_child0, 40);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(110, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(25, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, GetTop(root_child0));
  ASSERT_FLOAT_EQ(60, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(110, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(25, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(10, GetTop(root_child0));
  ASSERT_FLOAT_EQ(60, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_align_items_and_justify_content_center_and_bottom_position) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_CENTER);
  SetAlignItems(root, FLEX_ALIGN_CENTER);
  SetFlexGrow(root, 1);
  SetWidth(root, 110);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetPositionType(root_child0, POSITION_TYPE_ABSOLUTE);
  SetPosition(root_child0, CSS_BOTTOM, 10);
  SetWidth(root_child0, 60);
  SetHeight(root_child0, 40);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(110, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(25, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(50, GetTop(root_child0));
  ASSERT_FLOAT_EQ(60, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(110, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(25, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(50, GetTop(root_child0));
  ASSERT_FLOAT_EQ(60, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_align_items_and_justify_content_center_and_left_position) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_CENTER);
  SetAlignItems(root, FLEX_ALIGN_CENTER);
  SetFlexGrow(root, 1);
  SetWidth(root, 110);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetPositionType(root_child0, POSITION_TYPE_ABSOLUTE);
  SetPosition(root_child0, CSS_LEFT, 5);
  SetWidth(root_child0, 60);
  SetHeight(root_child0, 40);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(110, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(5, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(30, GetTop(root_child0));
  ASSERT_FLOAT_EQ(60, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(110, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(5, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(30, GetTop(root_child0));
  ASSERT_FLOAT_EQ(60, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0));
  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_align_items_and_justify_content_center_and_right_position) {
  const TaitankNodeRef root = NodeCreate();
  SetJustifyContent(root, FLEX_ALIGN_CENTER);
  SetAlignItems(root, FLEX_ALIGN_CENTER);
  SetFlexGrow(root, 1);
  SetWidth(root, 110);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetPositionType(root_child0, POSITION_TYPE_ABSOLUTE);
  SetPosition(root_child0, CSS_RIGHT, 5);
  SetWidth(root_child0, 60);
  SetHeight(root_child0, 40);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(110, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(45, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(30, GetTop(root_child0));
  ASSERT_FLOAT_EQ(60, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(110, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(45, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(30, GetTop(root_child0));
  ASSERT_FLOAT_EQ(60, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(40, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, position_root_with_rtl_should_position_withoutdirection) {
  const TaitankNodeRef root = NodeCreate();
  SetPosition(root, CSS_LEFT, 72);
  SetWidth(root, 52);
  SetHeight(root, 52);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(72, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(52, GetWidth(root));
  ASSERT_FLOAT_EQ(52, GetHeight(root));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(72, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(52, GetWidth(root));
  ASSERT_FLOAT_EQ(52, GetHeight(root));

  NodeFreeRecursive(root);
}

// TEST(TAITANK_TEST, absolute_layout_percentage_bottom_based_on_parent_height)
// {
//
//
//  const TaitankNodeRef root = NodeCreate();
//  SetWidth(root, 100);
//  SetHeight(root, 200);
//
//  const TaitankNodeRef root_child0 = NodeCreate();
//  SetPositionType(root_child0, POSITION_TYPE_ABSOLUTE);
//  SetPositionPercent(root_child0, CSS_TOP, 50);
//  SetWidth(root_child0, 10);
//  SetHeight(root_child0, 10);
//  InsertChild(root, root_child0, 0);
//
//  const TaitankNodeRef root_child1 = NodeCreate();
//  SetPositionType(root_child1, POSITION_TYPE_ABSOLUTE);
//  SetPositionPercent(root_child1, CSS_BOTTOM, 50);
//  SetWidth(root_child1, 10);
//  SetHeight(root_child1, 10);
//  InsertChild(root, root_child1, 1);
//
//  const TaitankNodeRef root_child2 = NodeCreate();
//  SetPositionType(root_child2, POSITION_TYPE_ABSOLUTE);
//  SetPositionPercent(root_child2, CSS_TOP, 10);
//  SetPositionPercent(root_child2, CSS_BOTTOM, 10);
//  SetWidth(root_child2, 10);
//  InsertChild(root, root_child2, 2);
//   DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
//
//  ASSERT_FLOAT_EQ(0, GetLeft(root));
//  ASSERT_FLOAT_EQ(0, GetTop(root));
//  ASSERT_FLOAT_EQ(100, GetWidth(root));
//  ASSERT_FLOAT_EQ(200, GetHeight(root));
//
//  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
//  ASSERT_FLOAT_EQ(100, GetTop(root_child0));
//  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
//  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));
//
//  ASSERT_FLOAT_EQ(0, GetLeft(root_child1));
//  ASSERT_FLOAT_EQ(90, GetTop(root_child1));
//  ASSERT_FLOAT_EQ(10, GetWidth(root_child1));
//  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));
//
//  ASSERT_FLOAT_EQ(0, GetLeft(root_child2));
//  ASSERT_FLOAT_EQ(20, GetTop(root_child2));
//  ASSERT_FLOAT_EQ(10, GetWidth(root_child2));
//  ASSERT_FLOAT_EQ(160, GetHeight(root_child2));
//
//  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED,);
//
//  ASSERT_FLOAT_EQ(0, GetLeft(root));
//  ASSERT_FLOAT_EQ(0, GetTop(root));
//  ASSERT_FLOAT_EQ(100, GetWidth(root));
//  ASSERT_FLOAT_EQ(200, GetHeight(root));
//
//  ASSERT_FLOAT_EQ(90, GetLeft(root_child0));
//  ASSERT_FLOAT_EQ(100, GetTop(root_child0));
//  ASSERT_FLOAT_EQ(10, GetWidth(root_child0));
//  ASSERT_FLOAT_EQ(10, GetHeight(root_child0));
//
//  ASSERT_FLOAT_EQ(90, GetLeft(root_child1));
//  ASSERT_FLOAT_EQ(90, GetTop(root_child1));
//  ASSERT_FLOAT_EQ(10, GetWidth(root_child1));
//  ASSERT_FLOAT_EQ(10, GetHeight(root_child1));
//
//  ASSERT_FLOAT_EQ(90, GetLeft(root_child2));
//  ASSERT_FLOAT_EQ(20, GetTop(root_child2));
//  ASSERT_FLOAT_EQ(10, GetWidth(root_child2));
//  ASSERT_FLOAT_EQ(160, GetHeight(root_child2));
//
//  NodeFreeRecursive(root);
//
//
//}

TEST(TAITANK_TEST, absolute_layout_in_wrap_reverse_column_container) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexWrap(root, FLEX_WRAP_REVERSE);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetPositionType(root_child0, POSITION_TYPE_ABSOLUTE);
  SetWidth(root_child0, 20);
  SetHeight(root_child0, 20);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(80, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_in_wrap_reverse_row_container) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetFlexWrap(root, FLEX_WRAP_REVERSE);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetPositionType(root_child0, POSITION_TYPE_ABSOLUTE);
  SetWidth(root_child0, 20);
  SetHeight(root_child0, 20);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(80, GetTop(root_child0));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(80, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(80, GetTop(root_child0));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_in_wrap_reverse_column_container_flex_end) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexWrap(root, FLEX_WRAP_REVERSE);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetAlignSelf(root_child0, FLEX_ALIGN_END);
  SetPositionType(root_child0, POSITION_TYPE_ABSOLUTE);
  SetWidth(root_child0, 20);
  SetHeight(root_child0, 20);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(80, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, absolute_layout_in_wrap_reverse_row_container_flex_end) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetFlexWrap(root, FLEX_WRAP_REVERSE);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetAlignSelf(root_child0, FLEX_ALIGN_END);
  SetPositionType(root_child0, POSITION_TYPE_ABSOLUTE);
  SetWidth(root_child0, 20);
  SetHeight(root_child0, 20);
  InsertChild(root, root_child0, 0);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(0, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_RTL);

  ASSERT_FLOAT_EQ(0, GetLeft(root));
  ASSERT_FLOAT_EQ(0, GetTop(root));
  ASSERT_FLOAT_EQ(100, GetWidth(root));
  ASSERT_FLOAT_EQ(100, GetHeight(root));

  ASSERT_FLOAT_EQ(80, GetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, GetTop(root_child0));
  ASSERT_FLOAT_EQ(20, GetWidth(root_child0));
  ASSERT_FLOAT_EQ(20, GetHeight(root_child0));

  NodeFreeRecursive(root);
}
