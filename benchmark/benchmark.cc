/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * The source code in this file may have been modified by THL A29 Limited ("Tencent Modifications").
 * All Tencent Modifications are Copyright (C) 2021 THL A29 Limited.
 * 
 */

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "taitank.h"

using namespace taitank;

#define NUM_REPETITIONS 1000

#define TAITANKBENCHMARKS(BLOCK)           \
  int main(int argc, char const *argv[]) { \
    clock_t __start;                       \
    clock_t __endTimes[NUM_REPETITIONS];   \
    { BLOCK }                              \
    return 0;                              \
  }

#define TAITANKBENCHMARK(NAME, BLOCK)                    \
  __start = clock();                                     \
  for (uint32_t __i = 0; __i < NUM_REPETITIONS; __i++) { \
    {BLOCK} __endTimes[__i] = clock();                   \
  }                                                      \
  __printBenchmarkResult(NAME, __start, __endTimes);

static int __compareDoubles(const void *a, const void *b) {
  double arg1 = *(const double *)a;
  double arg2 = *(const double *)b;

  if (arg1 < arg2) {
    return -1;
  }

  if (arg1 > arg2) {
    return 1;
  }

  return 0;
}

static void __printBenchmarkResult(char *name, clock_t start, clock_t *endTimes) {
  double timesInMs[NUM_REPETITIONS];
  double mean = 0;
  clock_t lastEnd = start;
  for (uint32_t i = 0; i < NUM_REPETITIONS; i++) {
    timesInMs[i] = (endTimes[i] - lastEnd) / static_cast<double>(CLOCKS_PER_SEC) * 1000;
    lastEnd = endTimes[i];
    mean += timesInMs[i];
  }
  mean /= NUM_REPETITIONS;

  qsort(timesInMs, NUM_REPETITIONS, sizeof(double), __compareDoubles);
  double median = timesInMs[NUM_REPETITIONS / 2];

  double variance = 0;
  for (uint32_t i = 0; i < NUM_REPETITIONS; i++) {
    variance += pow(timesInMs[i] - mean, 2);
  }
  variance /= NUM_REPETITIONS;
  double stddev = sqrt(variance);

  printf("%s: median: %lf ms, stddev: %lf ms\n", name, median, stddev);
}

static TaitankSize _measure(TaitankNodeRef node, float width, MeasureMode widthMode, float height,
                            MeasureMode heightMode, void *layoutContext) {
  return (TaitankSize){
      .width = widthMode == MEASURE_MODE_UNDEFINED ? 10 : width,
      .height = heightMode == MEASURE_MODE_UNDEFINED ? 10 : width,
  };
}

TAITANKBENCHMARKS({
  TAITANKBENCHMARK("Stack with flex", {
    const TaitankNodeRef root = TaitankNodeCreate();
    set_taitank_node_style_width(root, 100);
    set_taitank_node_style_height(root, 100);

    for (uint32_t i = 0; i < 10; i++) {
      const TaitankNodeRef child = TaitankNodeCreate();
      set_taitank_node_measure_function(child, _measure);
      set_taitank_node_style_flex(child, 1);
      TaitankNodeInsertChild(root, child, 0);
    }

    TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_LTR);
    TaitankNodeFreeRecursive(root);
  });

  TAITANKBENCHMARK("Align stretch in undefined axis", {
    const TaitankNodeRef root = TaitankNodeCreate();

    for (uint32_t i = 0; i < 10; i++) {
      const TaitankNodeRef child = TaitankNodeCreate();
      set_taitank_node_style_height(child, 20);
      set_taitank_node_measure_function(child, _measure);
      TaitankNodeInsertChild(root, child, 0);
    }

    TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_LTR);
    TaitankNodeFreeRecursive(root);
  });

  TAITANKBENCHMARK("Nested flex", {
    const TaitankNodeRef root = TaitankNodeCreate();

    for (uint32_t i = 0; i < 10; i++) {
      const TaitankNodeRef child = TaitankNodeCreate();
      set_taitank_node_style_flex(child, 1);
      TaitankNodeInsertChild(root, child, 0);

      for (uint32_t ii = 0; ii < 10; ii++) {
        const TaitankNodeRef grandChild = TaitankNodeCreate();
        set_taitank_node_measure_function(grandChild, _measure);
        set_taitank_node_style_flex(grandChild, 1);
        TaitankNodeInsertChild(child, grandChild, 0);
      }
    }

    TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_LTR);
    TaitankNodeFreeRecursive(root);
  });

  TAITANKBENCHMARK("Huge nested layout", {
    const TaitankNodeRef root = TaitankNodeCreate();

    for (uint32_t i = 0; i < 10; i++) {
      const TaitankNodeRef child = TaitankNodeCreate();
      set_taitank_node_style_flex_grow(child, 1);
      set_taitank_node_style_width(child, 10);
      set_taitank_node_style_height(child, 10);
      TaitankNodeInsertChild(root, child, 0);

      for (uint32_t ii = 0; ii < 10; ii++) {
        const TaitankNodeRef grandChild = TaitankNodeCreate();
        set_taitank_node_style_flex_direction(grandChild, FLEX_DIRECTION_ROW);
        set_taitank_node_style_flex_grow(grandChild, 1);
        set_taitank_node_style_width(grandChild, 10);
        set_taitank_node_style_height(grandChild, 10);
        TaitankNodeInsertChild(child, grandChild, 0);

        for (uint32_t iii = 0; iii < 10; iii++) {
          const TaitankNodeRef grandGrandChild = TaitankNodeCreate();
          set_taitank_node_style_flex_grow(grandGrandChild, 1);
          set_taitank_node_style_width(grandGrandChild, 10);
          set_taitank_node_style_height(grandGrandChild, 10);
          TaitankNodeInsertChild(grandChild, grandGrandChild, 0);

          for (uint32_t iiii = 0; iiii < 10; iiii++) {
            const TaitankNodeRef grandGrandGrandChild = TaitankNodeCreate();
            set_taitank_node_style_flex_direction(grandGrandGrandChild, FLEX_DIRECTION_ROW);
            set_taitank_node_style_flex_grow(grandGrandGrandChild, 1);
            set_taitank_node_style_width(grandGrandGrandChild, 10);
            set_taitank_node_style_height(grandGrandGrandChild, 10);
            TaitankNodeInsertChild(grandGrandChild, grandGrandGrandChild, 0);
          }
        }
      }
    }

    TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_LTR);
    TaitankNodeFreeRecursive(root);
  });

  // added by ianwang(honwsn@gmail.com) ,for no style test that will cost more
  // time then the previous test case.
  TAITANKBENCHMARK("Huge nested layout, no style width & height", {
    const TaitankNodeRef root = TaitankNodeCreate();

    for (uint32_t i = 0; i < 10; i++) {
      const TaitankNodeRef child = TaitankNodeCreate();
      set_taitank_node_style_flex_grow(child, 1);
      //      set_taitank_node_style_width(child, 10);
      //      set_taitank_node_style_height(child, 10);
      TaitankNodeInsertChild(root, child, 0);

      for (uint32_t ii = 0; ii < 10; ii++) {
        const TaitankNodeRef grandChild = TaitankNodeCreate();
        set_taitank_node_style_flex_direction(grandChild, FLEX_DIRECTION_ROW);
        set_taitank_node_style_flex_grow(grandChild, 1);
        //        set_taitank_node_style_width(grandChild, 10);
        //        set_taitank_node_style_height(grandChild, 10);
        TaitankNodeInsertChild(child, grandChild, 0);

        for (uint32_t iii = 0; iii < 10; iii++) {
          const TaitankNodeRef grandGrandChild = TaitankNodeCreate();
          set_taitank_node_style_flex_grow(grandGrandChild, 1);
          //          set_taitank_node_style_width(grandGrandChild, 10);
          //          set_taitank_node_style_height(grandGrandChild, 10);
          TaitankNodeInsertChild(grandChild, grandGrandChild, 0);

          for (uint32_t iiii = 0; iiii < 10; iiii++) {
            const TaitankNodeRef grandGrandGrandChild = TaitankNodeCreate();
            set_taitank_node_style_flex_direction(grandGrandGrandChild, FLEX_DIRECTION_ROW);
            set_taitank_node_style_flex_grow(grandGrandGrandChild, 1);
            set_taitank_node_style_width(grandGrandGrandChild, 10);
            set_taitank_node_style_height(grandGrandGrandChild, 10);
            TaitankNodeInsertChild(grandGrandChild, grandGrandGrandChild, 0);
          }
        }
      }
    }

    TaitankNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DIRECTION_LTR);
    TaitankNodeFreeRecursive(root);
  });
});
