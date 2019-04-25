// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "flutter/fml/mapping.h"

namespace fml {

uint8_t* FileMapping::GetMutableMapping() {
  return mutable_mapping_;
}

DataMapping::DataMapping(std::vector<uint8_t> data) :Mapping(), data_(std::move(data)) {}

DataMapping::~DataMapping(){}

size_t DataMapping::GetSize() const {
  return data_.size();
}

const uint8_t* DataMapping::GetMapping() const {
  return data_.data();
}

size_t NonOwnedMapping::GetSize() const {
  return size_;
}

const uint8_t* NonOwnedMapping::GetMapping() const {
  return data_;
}

}  // namespace fml
