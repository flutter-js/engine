// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_FML_PLATFORM_DARWIN_MESSAGE_LOOP_DARWIN_H_
#define FLUTTER_FML_PLATFORM_DARWIN_MESSAGE_LOOP_DARWIN_H_

#include <CoreFoundation/CoreFoundation.h>

#include <atomic>

#include "flutter/fml/macros.h"
#include "flutter/fml/message_loop_impl.h"
#include "flutter/fml/platform/darwin/cf_utils.h"

namespace fml {

class MessageLoopDarwin : public MessageLoopImpl {
 private:
  std::atomic_bool running_;
  CFRef<CFRunLoopTimerRef> delayed_wake_timer_;
  CFRef<CFRunLoopRef> loop_;

  MessageLoopDarwin();

  ~MessageLoopDarwin() override;

  void Run() override;

  void Terminate() override;

  void WakeUp(fml::TimePoint time_point) override;

  static void OnTimerFire(CFRunLoopTimerRef timer, MessageLoopDarwin* loop);

  FML_FRIEND_MAKE_REF_COUNTED(MessageLoopDarwin);
  FML_FRIEND_REF_COUNTED_THREAD_SAFE(MessageLoopDarwin);
  FML_DISALLOW_COPY_AND_ASSIGN(MessageLoopDarwin);
};

}  // namespace fml

#endif  // FLUTTER_FML_PLATFORM_DARWIN_MESSAGE_LOOP_DARWIN_H_
