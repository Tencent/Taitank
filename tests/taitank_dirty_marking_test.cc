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
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_START);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 20);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 20);
  TaitankNodeInsertChild(root, root_child1, 1);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  set_taitank_node_style_width(root_child0, 20);

  EXPECT_TRUE(root_child0->is_dirty_);
  EXPECT_FALSE(root_child1->is_dirty_);
  EXPECT_TRUE(root->is_dirty_);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  EXPECT_FALSE(root_child0->is_dirty_);
  EXPECT_FALSE(root_child1->is_dirty_);
  EXPECT_FALSE(root->is_dirty_);

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, dirty_propagation_only_if_prop_changed) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_START);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 50);
  set_taitank_node_style_height(root_child0, 20);
  TaitankNodeInsertChild(root, root_child0, 0);

  const TaitankNodeRef root_child1 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child1, 50);
  set_taitank_node_style_height(root_child1, 20);
  TaitankNodeInsertChild(root, root_child1, 1);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  set_taitank_node_style_width(root_child0, 50);

  EXPECT_FALSE(root_child0->is_dirty_);
  EXPECT_FALSE(root_child1->is_dirty_);
  EXPECT_FALSE(root->is_dirty_);

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, dirty_mark_all_children_as_dirty_when_display_changes) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_flex_direction(root, FLEX_DIRECTION_ROW);
  set_taitank_node_style_height(root, 100);

  const TaitankNodeRef child0 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(child0, 1);
  const TaitankNodeRef child1 = TaitankNodeCreate();
  set_taitank_node_style_flex_grow(child1, 1);

  const TaitankNodeRef child1_child0 = TaitankNodeCreate();
  const TaitankNodeRef child1_child0_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(child1_child0_child0, 8);
  set_taitank_node_style_height(child1_child0_child0, 16);

  TaitankNodeInsertChild(child1_child0, child1_child0_child0, 0);

  TaitankNodeInsertChild(child1, child1_child0, 0);
  TaitankNodeInsertChild(root, child0, 0);
  TaitankNodeInsertChild(root, child1, 0);

  set_taitank_node_style_display(child0, DISPLAY_TYPE_FLEX);
  set_taitank_node_style_display(child1, DISPLAY_TYPE_NONE);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(child1_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(child1_child0_child0));

  set_taitank_node_style_display(child0, DISPLAY_TYPE_NONE);
  set_taitank_node_style_display(child1, DISPLAY_TYPE_FLEX);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
  ASSERT_FLOAT_EQ(8, get_taitank_node_layout_width(child1_child0_child0));
  ASSERT_FLOAT_EQ(16, get_taitank_node_layout_height(child1_child0_child0));

  set_taitank_node_style_display(child0, DISPLAY_TYPE_FLEX);
  set_taitank_node_style_display(child1, DISPLAY_TYPE_NONE);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_width(child1_child0_child0));
  ASSERT_FLOAT_EQ(0, get_taitank_node_layout_height(child1_child0_child0));

  set_taitank_node_style_display(child0, DISPLAY_TYPE_NONE);
  set_taitank_node_style_display(child1, DISPLAY_TYPE_FLEX);
  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);
  ASSERT_FLOAT_EQ(8, get_taitank_node_layout_width(child1_child0_child0));
  ASSERT_FLOAT_EQ(16, get_taitank_node_layout_height(child1_child0_child0));

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, dirty_node_only_if_children_are_actually_removed) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_START);
  set_taitank_node_style_width(root, 50);
  set_taitank_node_style_height(root, 50);

  const TaitankNodeRef child0 = TaitankNodeCreate();
  set_taitank_node_style_width(child0, 50);
  set_taitank_node_style_height(child0, 25);
  TaitankNodeInsertChild(root, child0, 0);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  const TaitankNodeRef child1 = TaitankNodeCreate();
  TaitankNodeRemoveChild(root, child1);
  EXPECT_FALSE(root->is_dirty_);
  TaitankNodeFree(child1);

  TaitankNodeRemoveChild(root, child0);
  EXPECT_TRUE(root->is_dirty_);
  TaitankNodeFree(child0);

  TaitankNodeFreeRecursive(root);
}

TEST(TAITANK_TEST, dirty_node_only_if_undefined_values_gets_set_to_undefined) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_width(root, 50);
  set_taitank_node_style_height(root, 50);
  set_taitank_node_style_min_width(root, VALUE_UNDEFINED);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  EXPECT_FALSE(root->is_dirty_);

  set_taitank_node_style_min_width(root, VALUE_UNDEFINED);

  EXPECT_FALSE(root->is_dirty_);

  TaitankNodeFreeRecursive(root);
}
