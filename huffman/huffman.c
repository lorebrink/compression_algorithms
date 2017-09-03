/*
 * huffman.c
 *
 *  Created on: Aug 29, 2017
 *      Author: lukas
 */

#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
  byte character;
  unsigned long frequency;

  struct TreeNode* left;
  struct TreeNode* right;
} Node;

const Node* GetCharFrequencies(const char* file_path)
{
  FILE* file;
  Node* node_arr;
  int character;

  // Open file.
  file = fopen(file_path, "r");

  if(file == NULL)
  {
      perror("Could not open file.");
      return NULL;
  }

  // Create array for all possible characters.
  node_arr = (Node*)calloc(NUM_CHARS,sizeof(Node));

  // Count the characters.
  while((character = fgetc(file)) != EOF)
  {
      node_arr[character].frequency++;
  }

  return node_arr;
}

int CompareNodes(const void* elem_1, const void* elem_2)
{
  // Node have equal frequencies.
  int comp = 0;
  const Node* node_1 = (const Node*)elem_1;
  const Node* node_2 = (const Node*)elem_2;

  if(node_1->frequency < node_2->frequency)
  {
      // Means that node_1 goes before node_2.
      comp = -1;
  }
  else if(node_1->frequency > node_2->frequency)
  {
      // Means that node_1 goes after node_2.
      comp = 1;
  }

  return comp;
}

const Node* ConstructTree(const Node* node_arr)
{
  // Sort in ascending order.
  qsort((void*)node_arr, NUM_CHARS, sizeof(Node), CompareNodes);

  // Get the two lowest byte frequencies and make an internal node.



  return node_arr;
}

void CompressFile(void)
{
  //const Node* node_arr = GetCharFrequencies(file_path);

  //const Node* tree = ConstructTree(node_arr);

  // Construct codes

  // Express codes as canoical huffman to make decompression easier.

  // Compress file with codes

  printf("CompressFile!\n");

  // return file_path;
}


