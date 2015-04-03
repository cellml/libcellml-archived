/*
Copyright 2015 University of Auckland

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.Some license of other
*/

#include <memory>
#include <iostream>
#include <string>

#include "libcellml/model.h"
#include "libcellml/xml_serialisation.h"

#include "gtest/gtest.h"

//! Test serialisation to XML of empty model.
TEST(XmlSerialisation, simpleXmlOutput) {
  using Model = libcellml::Model;
  using string = std::string;

  std::shared_ptr<Model> m1 = std::make_shared<Model>();

  const string xml = libcellml::createXml(*m1);

  string expectedXml{
R"(<?xml version="1.0" encoding="UTF-8" standalone="no" ?>
<p1:model xmlns:p1="http://www.cellml.org/cellml/1.2#"/>
)"};

  ASSERT_EQ(expectedXml, xml);
}
