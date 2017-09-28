/*
 * huffman_tree.h
 *
 *  Created on: Sep 18, 2017
 *      Author: lukas
 */

#ifndef HUFFMAN_HUFFMAN_TREE_H_
#define HUFFMAN_HUFFMAN_TREE_H_

#include <stddef.h>

#define NUM_CHARS 256

typedef struct Node
{
  char character;
  unsigned long freq;

  struct Node* left;
  struct Node* right;
} *NodePtr;

NodePtr CreateTree(const unsigned long* freq_arr, int size);

void DeleteTree(NodePtr tree);



#endif /* HUFFMAN_HUFFMAN_TREE_H_ */
