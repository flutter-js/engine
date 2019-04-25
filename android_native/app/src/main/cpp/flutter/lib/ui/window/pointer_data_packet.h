// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_LIB_UI_WINDOW_POINTER_DATA_PACKET_H_
#define FLUTTER_LIB_UI_WINDOW_POINTER_DATA_PACKET_H_

#include <string.h>

#include <vector>

#include "flutter/fml/macros.h"
#include "flutter/lib/ui/window/pointer_data.h"

namespace blink {

class PointerDataPacket {
 public:
  explicit PointerDataPacket(size_t count);
  PointerDataPacket(uint8_t* data, size_t num_bytes);
  ~PointerDataPacket();

  void SetPointerData(size_t i, const PointerData& data);
  const std::vector<uint8_t>& data() const { return data_; }

 private:
  std::vector<uint8_t> data_;

  FML_DISALLOW_COPY_AND_ASSIGN(PointerDataPacket);
};

}  // namespace blink

#endif  // FLUTTER_LIB_UI_WINDOW_POINTER_DATA_PACKET_H_
