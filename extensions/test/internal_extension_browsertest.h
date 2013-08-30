// Copyright (c) 2013 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef XWALK_EXTENSIONS_TEST_INTERNAL_EXTENSION_BROWSERTEST_H_
#define XWALK_EXTENSIONS_TEST_INTERNAL_EXTENSION_BROWSERTEST_H_

#include <utility>
#include <string>
#include <vector>
#include "xwalk/extensions/browser/xwalk_extension_internal.h"

using xwalk::extensions::XWalkExtensionFunctionHandler;
using xwalk::extensions::XWalkExtensionFunctionInfo;

class TestExtension : public xwalk::extensions::XWalkInternalExtension {
 public:
  TestExtension();

  virtual const char* GetJavaScriptAPI() OVERRIDE;

  virtual xwalk::extensions::XWalkExtensionInstance* CreateInstance() OVERRIDE;
};

class TestExtensionInstance
    : public xwalk::extensions::XWalkInternalExtensionInstance {
 public:
  typedef std::vector<std::pair<std::string, int> > Database;

  TestExtensionInstance();

  Database* database() { return &database_; }

 private:
  void OnClearDatabase(const XWalkExtensionFunctionInfo& info);
  void OnAddPerson(const XWalkExtensionFunctionInfo& info);
  void OnAddPersonObject(const XWalkExtensionFunctionInfo& info);
  void OnGetAllPersons(const XWalkExtensionFunctionInfo& info);
  void OnGetPersonAge(const XWalkExtensionFunctionInfo& info);

  std::vector<std::pair<std::string, int> > database_;
};

#endif  // XWALK_EXTENSIONS_TEST_INTERNAL_EXTENSION_BROWSERTEST_H_
