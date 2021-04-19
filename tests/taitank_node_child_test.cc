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

TEST(TAITANK_TEST, reset_layout_when_child_removed) {
  const TaitankNodeRef root = TaitankNodeCreate();

  const TaitankNodeRef root_child0 = TaitankNodeCreate();
  set_taitank_node_style_width(root_child0, 100);
  set_taitank_node_style_height(root_child0, 100);
  TaitankNodeInsertChild(root, root_child0, 0);

  TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_EQ(100, get_taitank_node_layout_width(root_child0));
  ASSERT_EQ(100, get_taitank_node_layout_height(root_child0));

  TaitankNodeRemoveChild(root, root_child0);

  ASSERT_EQ(0, get_taitank_node_layout_left(root_child0));
  ASSERT_EQ(0, get_taitank_node_layout_top(root_child0));
  ASSERT_TRUE(isUndefined(get_taitank_node_layout_width(root_child0)));
  ASSERT_TRUE(isUndefined(get_taitank_node_layout_height(root_child0)));

  TaitankNodeFreeRecursive(root);
}
