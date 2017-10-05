/*
 * Author: johan
 */

// Inlude googletest and googlemock
#include "gmock/gmock.h"
#include "gtest/gtest.h"
//#include <string>

extern "C"
{
  #include "huffman.h"
}

//using namespace std;


JOHANTEST(MyTest, AnotherTest)
{
  std::string file_path = "test.txt";
  const std::string file_path_result = CompressFile(file_path.c_str());
  ASSERT_EQ(file_path, file_path_result);
}


