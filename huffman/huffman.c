/*
 * huffman.c
 *
 *  Created on: Aug 29, 2017
 *      Author: lukas
 */

#include "huffman.h"
#include "huffman_tree.h"
#include <stdio.h>
#include <stdlib.h>

const unsigned long* GetCharFrequencies(const char* file_path)
{
  FILE* file;
  unsigned long* freq_arr;
  int character;

  // Open file.
  file = fopen(file_path, "r");

  if(file == NULL)
  {
      perror("Could not open file.");
      return NULL;
  }

  // Create array for all possible characters.
  freq_arr = (unsigned long int*)calloc(NUM_CHARS, sizeof(unsigned long int));

  // Count the characters.
  while((character = fgetc(file)) != EOF)
  {
      ++freq_arr[character];
  }

  return freq_arr;
}

const char* CompressFile(const char* file_path)
{
  // const unsigned long int* freq_arr = GetCharFrequencies(file_path);

  // const NodePtr tree = CreateTree(freq_arr, NUM_CHARS);

  // CreateCodeWords(Node*);

  // Construct codes

  // Express codes as canoical huffman to make decompression easier.

  // Compress file with codes

  printf("CompressFile: %s\n", file_path);

  return file_path;
}
