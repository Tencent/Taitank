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

#include "taitank_util.h"

namespace taitank {
#ifdef ANDROID
#  include <android/log.h>
void TaitankLog(LogLevel level, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int androidLevel = LogLevelDebug;
  switch (level) {
    case LogLevelInfo:
      androidLevel = ANDROID_LOG_INFO;
      break;
    case LogLevelVerbose:
      androidLevel = ANDROID_LOG_VERBOSE;
      break;
    case LogLevelDebug:
      androidLevel = ANDROID_LOG_DEBUG;
      break;
    case LogLevelWarn:
      androidLevel = ANDROID_LOG_WARN;
      break;
    case LogLevelError:
      androidLevel = ANDROID_LOG_ERROR;
      break;
    case LogLevelFatal:
      androidLevel = ANDROID_LOG_FATAL;
      break;
    default:
      break;
  }
  __android_log_vprint(androidLevel, "TaitankLayout", format, args);
  va_end(args);
}
#else
void TaitankLog(LogLevel level, const char *format, ...) {
  va_list args;
  va_start(args, format);
  if (level >= LogLevelError) {
    vfprintf(stderr, format, args);
  } else {
    vprintf(format, args);
  }
  va_end(args);
}
#endif

bool FloatIsEqual(const float a, const float b) {
  if (isUndefined(a)) {
    return isUndefined(b);
  }
  if (isUndefined(b)) {
    return isUndefined(a);
  }
  return fabs(a - b) < 0.0001f;
}

bool DoubleIsEqual(const double a, const double b) {
  if (isUndefined(a)) {
    return isUndefined(b);
  }
  if (isUndefined(b)) {
    return isUndefined(a);
  }
  return fabs(a - b) < 0.0002;
}

bool FloatIsEqualInScale(float a, float b, const float scale) {
  if (isUndefined(a)) {
    return isUndefined(b);
  }
  if (isUndefined(b)) {
    return isUndefined(a);
  }
  a = PixelRound(a, scale);
  b = PixelRound(b, scale);
  return fabs(a - b) < 0.0001f;
}

bool SizeIsEqual(const TaitankSize a, const TaitankSize b) {
  return FloatIsEqual(a.width, b.width) && FloatIsEqual(a.height, b.height);
}

bool SizeIsEqualInScale(const TaitankSize a, const TaitankSize b, const float scale) {
  return FloatIsEqualInScale(a.width, b.width, scale) &&
         FloatIsEqualInScale(a.height, b.height, scale);
}

float RoundValueToPixelGrid(double value, double scaleFactor, const bool forceCeil, const bool forceFloor) {
  double scaleValue = value * scaleFactor;
  double fractial = fmod(scaleValue, 1.0);
  if (fractial < 0) {
    ++fractial;
  }

  if (DoubleIsEqual(fractial, 0)) {
    // First we check if the value is already rounded
    scaleValue = scaleValue - fractial;
  } else if (DoubleIsEqual(fractial, 1.0)) {
    scaleValue = scaleValue - fractial + 1.0;
  } else if (forceCeil) {
    // Next we check if we need to use forced rounding
    scaleValue = scaleValue - fractial + 1.0;
  } else if (forceFloor) {
    scaleValue = scaleValue - fractial;
  } else {
    // Finally we just round the value
    scaleValue = scaleValue - fractial +
      (fractial > 0.5 || DoubleIsEqual(fractial, 0.5) ? 1.0 : 0.0);
  }
  return static_cast<float>(scaleValue / scaleFactor);
}
}  // namespace taitank
