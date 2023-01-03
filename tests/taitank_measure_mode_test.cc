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

struct _MeasureConstraint {
  float width;
  MeasureMode widthMode;
  float height;
  MeasureMode heightMode;
};

struct _MeasureConstraintList {
  uint32_t length;
  struct _MeasureConstraint *constraints;
};

static TaitankSize _measure(TaitankNodeRef node, float width, MeasureMode widthMode, float height,
                            MeasureMode heightMode, void *layoutContext) {
  struct _MeasureConstraintList *constraintList =
      (struct _MeasureConstraintList *)node->GetContext();
  struct _MeasureConstraint *constraints = constraintList->constraints;
  uint32_t currentIndex = constraintList->length;
  (&constraints[currentIndex])->width = width;
  (&constraints[currentIndex])->widthMode = widthMode;
  (&constraints[currentIndex])->height = height;
  (&constraints[currentIndex])->heightMode = heightMode;
  constraintList->length = currentIndex + 1;

  return TaitankSize{
      .width = widthMode == MEASURE_MODE_UNDEFINED ? 10 : width,
      .height = heightMode == MEASURE_MODE_UNDEFINED ? 10 : width,
  };
}

/*TEST(TAITANK_TEST, exactly_measure_stretched_child_column) {
  struct _MeasureConstraintList constraintList = _MeasureConstraintList {
      .length = 0, .constraints = (struct _MeasureConstraint *) malloc(
          10 * sizeof(struct _MeasureConstraint)), };

  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  //  root_child0->SetContext(&constraintList);
  root_child0->SetContext(&constraintList);
  root_child0->measure_ = (_measure);
  //  root_child0->measure_=(_measure);
  InsertChild(root, root_child0, 0);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(1, constraintList.length);

  ASSERT_FLOAT_EQ(100, constraintList.constraints[0].width);
  ASSERT_EQ(MEASURE_MODE_EXACTLY, constraintList.constraints[0].widthMode);

  free(constraintList.constraints);
  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, exactly_measure_stretched_child_row) {
  struct _MeasureConstraintList constraintList = _MeasureConstraintList {
      .length = 0, .constraints = (struct _MeasureConstraint *) malloc(
          10 * sizeof(struct _MeasureConstraint)), };

  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  //  root_child0->SetContext(&constraintList);
  root_child0->SetContext(&constraintList);
  root_child0->measure_ = (_measure);
  InsertChild(root, root_child0, 0);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(1, constraintList.length);

  ASSERT_FLOAT_EQ(100, constraintList.constraints[0].height);
  ASSERT_EQ(MEASURE_MODE_EXACTLY, constraintList.constraints[0].heightMode);

  free(constraintList.constraints);
  NodeFreeRecursive(root);
}*/

TEST(TAITANK_TEST, at_most_main_axis_column) {
  struct _MeasureConstraintList constraintList = _MeasureConstraintList{
      .length = 0,
      .constraints = (struct _MeasureConstraint *)malloc(10 * sizeof(struct _MeasureConstraint)),
  };

  const TaitankNodeRef root = NodeCreate();
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  root_child0->SetContext(&constraintList);
  root_child0->measure_ = (_measure);
  InsertChild(root, root_child0, 0);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(1, constraintList.length);

  ASSERT_FLOAT_EQ(100, constraintList.constraints[0].height);
  ASSERT_EQ(MEASURE_MODE_AT_MOST, constraintList.constraints[0].heightMode);

  free(constraintList.constraints);
  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, at_most_cross_axis_column) {
  struct _MeasureConstraintList constraintList = _MeasureConstraintList{
      .length = 0,
      .constraints = (struct _MeasureConstraint *)malloc(10 * sizeof(struct _MeasureConstraint)),
  };

  const TaitankNodeRef root = NodeCreate();
  SetAlignItems(root, FLEX_ALIGN_START);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  root_child0->SetContext(&constraintList);
  root_child0->measure_ = (_measure);
  InsertChild(root, root_child0, 0);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(1, constraintList.length);

  ASSERT_FLOAT_EQ(100, constraintList.constraints[0].width);
  ASSERT_EQ(MEASURE_MODE_AT_MOST, constraintList.constraints[0].widthMode);

  free(constraintList.constraints);
  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, at_most_main_axis_row) {
  struct _MeasureConstraintList constraintList = _MeasureConstraintList{
      .length = 0,
      .constraints = (struct _MeasureConstraint *)malloc(10 * sizeof(struct _MeasureConstraint)),
  };

  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  root_child0->SetContext(&constraintList);
  root_child0->measure_ = (_measure);
  InsertChild(root, root_child0, 0);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(1, constraintList.length);

  ASSERT_FLOAT_EQ(100, constraintList.constraints[0].width);
  ASSERT_EQ(MEASURE_MODE_AT_MOST, constraintList.constraints[0].widthMode);

  free(constraintList.constraints);
  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, at_most_cross_axis_row) {
  struct _MeasureConstraintList constraintList = _MeasureConstraintList{
      .length = 0,
      .constraints = (struct _MeasureConstraint *)malloc(10 * sizeof(struct _MeasureConstraint)),
  };

  const TaitankNodeRef root = NodeCreate();
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetAlignItems(root, FLEX_ALIGN_START);
  SetWidth(root, 100);
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  root_child0->SetContext(&constraintList);
  root_child0->measure_ = (_measure);
  InsertChild(root, root_child0, 0);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(1, constraintList.length);

  ASSERT_FLOAT_EQ(100, constraintList.constraints[0].height);
  ASSERT_EQ(MEASURE_MODE_AT_MOST, constraintList.constraints[0].heightMode);

  free(constraintList.constraints);
  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_child) {
  struct _MeasureConstraintList constraintList = _MeasureConstraintList{
      .length = 0,
      .constraints = (struct _MeasureConstraint *)malloc(10 * sizeof(struct _MeasureConstraint)),
  };

  const TaitankNodeRef root = NodeCreate();
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  root_child0->SetContext(&constraintList);
  root_child0->measure_ = (_measure);
  InsertChild(root, root_child0, 0);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(2, constraintList.length);

  ASSERT_FLOAT_EQ(100, constraintList.constraints[0].height);
  ASSERT_EQ(MEASURE_MODE_AT_MOST, constraintList.constraints[0].heightMode);

  ASSERT_FLOAT_EQ(100, constraintList.constraints[1].height);
  ASSERT_EQ(MEASURE_MODE_EXACTLY, constraintList.constraints[1].heightMode);

  free(constraintList.constraints);
  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, flex_child_with_flex_basis) {
  struct _MeasureConstraintList constraintList = _MeasureConstraintList{
      .length = 0,
      .constraints = (struct _MeasureConstraint *)malloc(10 * sizeof(struct _MeasureConstraint)),
  };

  const TaitankNodeRef root = NodeCreate();
  SetHeight(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  SetFlexGrow(root_child0, 1);
  SetFlexBasis(root_child0, 0);
  root_child0->SetContext(&constraintList);
  root_child0->measure_ = (_measure);
  InsertChild(root, root_child0, 0);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(1, constraintList.length);

  ASSERT_FLOAT_EQ(100, constraintList.constraints[0].height);
  ASSERT_EQ(MEASURE_MODE_EXACTLY, constraintList.constraints[0].heightMode);

  free(constraintList.constraints);
  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, overflow_scroll_column) {
  struct _MeasureConstraintList constraintList = _MeasureConstraintList{
      .length = 0,
      .constraints = (struct _MeasureConstraint *)malloc(10 * sizeof(struct _MeasureConstraint)),
  };

  const TaitankNodeRef root = NodeCreate();
  SetAlignItems(root, FLEX_ALIGN_START);
  SetOverflow(root, OVERFLOW_SCROLL);
  SetHeight(root, 100);
  SetWidth(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  root_child0->SetContext(&constraintList);
  root_child0->measure_ = (_measure);
  InsertChild(root, root_child0, 0);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(1, constraintList.length);

  ASSERT_FLOAT_EQ(100, constraintList.constraints[0].width);
  ASSERT_EQ(MEASURE_MODE_AT_MOST, constraintList.constraints[0].widthMode);

  ASSERT_TRUE(isUndefined(constraintList.constraints[0].height));
  ASSERT_EQ(MEASURE_MODE_UNDEFINED, constraintList.constraints[0].heightMode);

  free(constraintList.constraints);
  NodeFreeRecursive(root);
}

TEST(TAITANK_TEST, overflow_scroll_row) {
  struct _MeasureConstraintList constraintList = _MeasureConstraintList{
      .length = 0,
      .constraints = (struct _MeasureConstraint *)malloc(10 * sizeof(struct _MeasureConstraint)),
  };

  const TaitankNodeRef root = NodeCreate();
  SetAlignItems(root, FLEX_ALIGN_START);
  SetFlexDirection(root, FLEX_DIRECTION_ROW);
  SetOverflow(root, OVERFLOW_SCROLL);
  SetHeight(root, 100);
  SetWidth(root, 100);

  const TaitankNodeRef root_child0 = NodeCreate();
  root_child0->SetContext(&constraintList);
  root_child0->measure_ = (_measure);
  InsertChild(root, root_child0, 0);

  DoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

  ASSERT_EQ(1, constraintList.length);

  ASSERT_TRUE(isUndefined(constraintList.constraints[0].width));
  ASSERT_EQ(MEASURE_MODE_UNDEFINED, constraintList.constraints[0].widthMode);

  ASSERT_FLOAT_EQ(100, constraintList.constraints[0].height);
  ASSERT_EQ(MEASURE_MODE_AT_MOST, constraintList.constraints[0].heightMode);

  free(constraintList.constraints);
  NodeFreeRecursive(root);
}
