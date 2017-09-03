/*
 * main.c
 *
 *  Created on: Aug 30, 2017
 *      Author: lukas
 */

#include "huffman.h"
#include <stdio.h>

int main()
{
  const char* compressed_file = CompressFile("test.txt");

  printf("Compressed file: %s\n", compressed_file);

  return 0;
}


