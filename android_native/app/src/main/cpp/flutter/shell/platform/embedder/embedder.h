// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_NATIVE_H
#define FLUTTER_NATIVE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


#if defined(__cplusplus)
extern "C" {
#endif

#ifndef FLUTTER_EXPORT
#define FLUTTER_EXPORT
#endif  // FLUTTER_EXPORT

#define FLUTTER_ENGINE_VERSION 1

typedef enum {
  kSuccess = 0,
  kInvalidLibraryVersion,
  kInvalidArguments,
} FlutterResult;

typedef enum {
  kOpenGL,
  kSoftware,
} FlutterRendererType;

typedef struct _FlutterEngine* FlutterEngine;


FLUTTER_EXPORT
FlutterResult FlutterEngineRun(size_t version,
                               const void* config,
                               const void* args,
                               void* user_data,
                               FlutterEngine* engine_out);

FLUTTER_EXPORT
FlutterResult FlutterEngineShutdown(FlutterEngine engine);

#if defined(__cplusplus)
}  // extern "C"
#endif

#endif