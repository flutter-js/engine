// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_FLOW_INSTRUMENTATION_H_
#define FLUTTER_FLOW_INSTRUMENTATION_H_

#include <vector>

#include "flutter/fml/macros.h"
#include "flutter/fml/time/time_delta.h"
#include "flutter/fml/time/time_point.h"
#include "third_party/skia/include/core/SkCanvas.h"

namespace flow {

static const double kOneFrameMS = 1e3 / 60.0;

class Stopwatch {
 public:
  Stopwatch();

  ~Stopwatch();

  const fml::TimeDelta& LastLap() const;

  fml::TimeDelta CurrentLap() const { return fml::TimePoint::Now() - start_; }

  fml::TimeDelta MaxDelta() const;

  void InitVisualizeSurface(const SkRect& rect) const;

  void Visualize(SkCanvas& canvas, const SkRect& rect) const;

  void Start();

  void Stop();

  void SetLapTime(const fml::TimeDelta& delta);

 private:
  fml::TimePoint start_;
  std::vector<fml::TimeDelta> laps_;
  size_t current_sample_;
  // Mutable data cache for performance optimization of the graphs. Prevents
  // expensive redrawing of old data.
  mutable bool cache_dirty_;
  mutable sk_sp<SkSurface> visualize_cache_surface_;
  mutable size_t prev_drawn_sample_index_;

  FML_DISALLOW_COPY_AND_ASSIGN(Stopwatch);
};

class Counter {
 public:
  Counter() : count_(0) {}

  size_t count() const { return count_; }

  void Reset(size_t count = 0) { count_ = count; }

  void Increment(size_t count = 1) { count_ += count; }

 private:
  size_t count_;

  FML_DISALLOW_COPY_AND_ASSIGN(Counter);
};

class CounterValues {
 public:
  CounterValues();

  ~CounterValues();

  void Add(int64_t value);

  void Visualize(SkCanvas& canvas, const SkRect& rect) const;

  int64_t GetCurrentValue() const;

  int64_t GetMaxValue() const;

  int64_t GetMinValue() const;

 private:
  std::vector<int64_t> values_;
  size_t current_sample_;

  FML_DISALLOW_COPY_AND_ASSIGN(CounterValues);
};

}  // namespace flow

#endif  // FLUTTER_FLOW_INSTRUMENTATION_H_
