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

TEST(TAITANK_TEST, dirty_propagation) {
  const TaitankNodeRef root = NodeCreate();
  SetAlignItems(root, FLEX_ALIGN_START);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 50);
  SetHeight(root_child0, 20);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 50);
  SetHeight(root_child1, 20);
  InsertChild(root, root_child1, 1);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  SetWidth(root_child0, 20);

  EXPECT_TRUE(root_child0->is_dirty_);
  EXPECT_FALSE(root_child1->is_dirty_);
  EXPECT_TRUE(root->is_dirty_);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  EXPECT_FALSE(root_child0->is_dirty_);
  EXPECT_FALSE(root_child1->is_dirty_);
  EXPECT_FALSE(root->is_dirty_);

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, dirty_propagation_only_if_prop_changed) {
  const TaitankNodeRef root = NodeCreate();
  SetAlignItems(root, FLEX_ALIGN_START);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetWidth(root_child0, 50);
  SetHeight(root_child0, 20);
  InsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = NodeCreate();
  SetWidth(root_child1, 50);
  SetHeight(root_child1, 20);
  InsertChild(root, root_child1, 1);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  SetWidth(root_child0, 50);

  EXPECT_FALSE(root_child0->is_dirty_);
  EXPECT_FALSE(root_child1->is_dirty_);
  EXPECT_FALSE(root->is_dirty_);

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, dirty_mark_all_children_as_dirty_when_display_changes) {
  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetHeight(root, 100);

  const TaitankNodeRef child0 = NodeCreate();
  SetFlexGrow(child0, 1);
  const TaitankNodeRef child1 = NodeCreate();
  SetFlexGrow(child1, 1);

  const TaitankNodeRef child1_child0 = NodeCreate();
  const TaitankNodeRef child1_child0_child0 = NodeCreate();
  SetWidth(child1_child0_child0, 8);
  SetHeight(child1_child0_child0, 16);

  InsertChild(child1_child0, child1_child0_child0, 0);

  InsertChild(child1, child1_child0, 0);
  InsertChild(root, child0, 0);
  InsertChild(root, child1, 0);

  SetDisplay(child0, DISPLAY_TYPE_FLEX);
  SetDisplay(child1, DISPLAY_TYPE_NONE);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
  ASSERT_FLOAT_EQ(0, GetWidth(child1_child0_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(child1_child0_child0));

  SetDisplay(child0, DISPLAY_TYPE_NONE);
  SetDisplay(child1, DISPLAY_TYPE_FLEX);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
  ASSERT_FLOAT_EQ(8, GetWidth(child1_child0_child0));
  ASSERT_FLOAT_EQ(16, GetHeight(child1_child0_child0));

  SetDisplay(child0, DISPLAY_TYPE_FLEX);
  SetDisplay(child1, DISPLAY_TYPE_NONE);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
  ASSERT_FLOAT_EQ(0, GetWidth(child1_child0_child0));
  ASSERT_FLOAT_EQ(0, GetHeight(child1_child0_child0));

  SetDisplay(child0, DISPLAY_TYPE_NONE);
  SetDisplay(child1, DISPLAY_TYPE_FLEX);
  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
  ASSERT_FLOAT_EQ(8, GetWidth(child1_child0_child0));
  ASSERT_FLOAT_EQ(16, GetHeight(child1_child0_child0));

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, dirty_node_only_if_children_are_actually_removed) {
  const TaitankNodeRef root = NodeCreate();
  SetAlignItems(root, FLEX_ALIGN_START);
  SetWidth(root, 50);
  SetHeight(root, 50);

  const TaitankNodeRef child0 = NodeCreate();
  SetWidth(child0, 50);
  SetHeight(child0, 25);
  InsertChild(root, child0, 0);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  const TaitankNodeRef child1 = NodeCreate();
  RemoveChild(root, child1);
  EXPECT_FALSE(root->is_dirty_);
  NodeFree(child1);

  RemoveChild(root, child0);
  EXPECT_TRUE(root->is_dirty_);
  NodeFree(child0);

  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, dirty_node_only_if_undefined_values_gets_set_to_undefined) {
  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 50);
  SetHeight(root, 50);
  SetMinWidth(root, VALUE_UNDEFINED);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  EXPECT_FALSE(root->is_dirty_);

  SetMinWidth(root, VALUE_UNDEFINED);

  EXPECT_FALSE(root->is_dirty_);

  NodeFreeRecursive(root);
}
