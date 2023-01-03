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
  int *dirtiedCount = reinterpret_cast<int *>(node->GetContext());
  (*dirtiedCount)++;
}

TEST(TAITANK_TEST, dirtied) {
  const TaitankNodeRef root = NodeCreate();
  SetAlignItems(root, FLEX_ALIGN_START);
  SetWidth(root, 100);
  SetHeight(root, 100);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  int dirtiedCount = 0;
  root->SetContext(&dirtiedCount);
  root->SetDirtiedFunction(_dirtied);

  ASSERT_EQ(0, dirtiedCount);

  // `_dirtied` MUST be called in case of explicit dirtying.
  root->SetDirty(true);
  ASSERT_EQ(1, dirtiedCount);

  // `_dirtied` MUST be called ONCE.
  root->SetDirty(true);
  ASSERT_EQ(1, dirtiedCount);
}

TEST(TAITANK_TEST, dirtied_propagation) {
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

  int dirtiedCount = 0;
  root->SetContext(&dirtiedCount);
  root->SetDirtiedFunction(_dirtied);

  ASSERT_EQ(0, dirtiedCount);

  // `_dirtied` MUST be called for the first time.
  root_child0->MarkAsDirty();
  ASSERT_EQ(1, dirtiedCount);

  // `_dirtied` must NOT be called for the second time.
  root_child0->MarkAsDirty();
  ASSERT_EQ(1, dirtiedCount);
}

TEST(TAITANK_TEST, dirtied_hierarchy) {
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

  int dirtiedCount = 0;
  root_child0->SetContext(&dirtiedCount);
  root_child0->SetDirtiedFunction(_dirtied);

  ASSERT_EQ(0, dirtiedCount);

  // `_dirtied` must NOT be called for descendants.
  root->MarkAsDirty();
  ASSERT_EQ(0, dirtiedCount);

  // `_dirtied` must NOT be called for the sibling node.
  root_child1->MarkAsDirty();
  ASSERT_EQ(0, dirtiedCount);

  // `_dirtied` MUST be called in case of explicit dirtying.
  root_child0->MarkAsDirty();
  ASSERT_EQ(1, dirtiedCount);
}
