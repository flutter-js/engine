// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_SHELL_COMMON_THREAD_HOST_H_
#define FLUTTER_SHELL_COMMON_THREAD_HOST_H_

#include <memory>

#include "flutter/fml/macros.h"
#include "flutter/fml/thread.h"

namespace shell {

struct ThreadHost {
  enum Type {
    Platform = 1 << 0,
    UI = 1 << 1,
    GPU = 1 << 2,
    IO = 1 << 3,
  };

  std::unique_ptr<fml::Thread> platform_thread;
  std::unique_ptr<fml::Thread> ui_thread;
  std::unique_ptr<fml::Thread> gpu_thread;
  std::unique_ptr<fml::Thread> io_thread;

  ThreadHost();

  ThreadHost(ThreadHost&&);

  ThreadHost& operator=(ThreadHost&&) = default;

  ThreadHost(std::string name_prefix, uint64_t type_mask);

  ~ThreadHost();

  void Reset();
};

}  // namespace shell

#endif  // FLUTTER_SHELL_COMMON_THREAD_HOST_H_
