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

static void _dirtied(TaitankNodeRef node) {
  int *dirtiedCount = reinterpret_cast<int *>(node->get_context());
  (*dirtiedCount)++;
}

TEST(TAITANK_TEST, dirtied) {
  const TaitankNodeRef root = TaitankNodeCreate();
  set_taitank_node_style_align_items(root, FLEX_ALIGN_START);
  set_taitank_node_style_width(root, 100);
  set_taitank_node_style_height(root, 100);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  int dirtiedCount = 0;
  root->set_context(&dirtiedCount);
  root->set_dirtied_function(_dirtied);

  ASSERT_EQ(0, dirtiedCount);

  // `_dirtied` MUST be called in case of explicit dirtying.
  root->set_dirty(true);
  ASSERT_EQ(1, dirtiedCount);

  // `_dirtied` MUST be called ONCE.
  root->set_dirty(true);
  ASSERT_EQ(1, dirtiedCount);
}

TEST(TAITANK_TEST, dirtied_propagation) {
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

  int dirtiedCount = 0;
  root->set_context(&dirtiedCount);
  root->set_dirtied_function(_dirtied);

  ASSERT_EQ(0, dirtiedCount);

  // `_dirtied` MUST be called for the first time.
  root_child0->markAsDirty();
  ASSERT_EQ(1, dirtiedCount);

  // `_dirtied` must NOT be called for the second time.
  root_child0->markAsDirty();
  ASSERT_EQ(1, dirtiedCount);
}

TEST(TAITANK_TEST, dirtied_hierarchy) {
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

  int dirtiedCount = 0;
  root_child0->set_context(&dirtiedCount);
  root_child0->set_dirtied_function(_dirtied);

  ASSERT_EQ(0, dirtiedCount);

  // `_dirtied` must NOT be called for descendants.
  root->markAsDirty();
  ASSERT_EQ(0, dirtiedCount);

  // `_dirtied` must NOT be called for the sibling node.
  root_child1->markAsDirty();
  ASSERT_EQ(0, dirtiedCount);

  // `_dirtied` MUST be called in case of explicit dirtying.
  root_child0->markAsDirty();
  ASSERT_EQ(1, dirtiedCount);
}
