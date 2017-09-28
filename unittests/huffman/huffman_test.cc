/*
 * huffman_test.cc
 *
 *  Created on: Sep 6, 2017
 *      Author: lukas
 */

// Inlude googletest and googlemock
#include "gmock/gmock.h"
#include "gtest/gtest.h"

extern "C"
{
  #include "huffman.h"
}

#include <string>

TEST(HuffmanTest, DummyTest)
{
  std::string file_path = "test.txt";
  const std::string file_path_result = CompressFile(file_path.c_str());
  ASSERT_EQ(file_path, file_path_result);
}


