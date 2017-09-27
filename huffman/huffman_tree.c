/*
 * huffman_tree.c
 *
 *  Created on: Sep 18, 2017
 *      Author: lukas
 */

#include "huffman_tree.h"

// ****** TREE GLOBALS ******
// 2^k - 1, where k is level of the tree
#define MAX_NUM_NODES 511

// ****** PRIORITY QUEUE GLOBALS ******
typedef struct
{
  NodePtr tree[MAX_NUM_NODES];
  int size;
} Heap;

// ************************************
// PRIORITY QUEUE
// ************************************
int GetParentIndex(int index)
{
  return ((index + 1) / 2) - 1;
}

int GetLeftLeaf(int index)
{
  return 2 * (index + 1) - 1;
}

int GetRightLeaf(int index)
{
  return GetLeftLeaf(index) + 1;
}

unsigned long GetParentValue(Heap* heap, int index)
{
  return heap->tree[GetParentIndex(index)]->freq;
}

void SwapNodes(Heap* heap, int index_1, int index_2)
{
  NodePtr node_tmp;
  node_tmp = heap->tree[index_1];
  SetNode(heap, heap->tree[index_2], index_1);
  heap->tree[index_2] = node_tmp;
}

void MinHeapify(Heap* heap, int index)
{
  int left_index, right_index, smallest;

  left_index = GetLeftLeaf(index);
  right_index = GetRightLeaf(index);

  if(left_index < heap->size && heap->tree[left_index] < heap->tree[index])
  {
    smallest = left_index;
  }
  else
  {
    smallest = index;
  }

  if(right_index < heap->size && heap->tree[right_index] < heap->tree[smallest])
  {
    smallest = right_index;
  }

  if(smallest != index)
  {
    SwapNodes(heap, index, smallest);
    MinHeapify(heap, index);
  }
}

int QueueInsert(Heap* heap, NodePtr node)
{
  int index, parent_index;
  NodePtr tree;
  
  // NOTE: the index begins at 1 but the array indexes from 0.
  index = heap->size++;
  heap->tree[index] = node;
  while(index > 0 &&  GetParentValue(heap, index) > heap->tree[index]->freq)
  {
    parent_index = GetParentIndex(index);
    SwapNodes(heap, index, parent_index);
    index = parent_index;
  }
}

NodePtr QueuePop(Heap* heap)
{
  NodePtr min_node;

  if(heap->size < 1)
  {
    return NULL;
  }

  min_node = heap->tree[0];
  heap->tree[0] = heap->tree[heap->size];
  --heap->size;

  // Rearrange tree so it conforms with min heap specs.
  MinHeapify(heap, 0);

  return min_node;
}

// ************************************
// Huffman tree
// ************************************

NodePtr InitNodes()
{
  return (Heap*)calloc(MAX_NUM_NODES , sizeof(struct Node));
}

NodePtr CreateNode(NodePtr node_arr, unsigned long int freq, char character, NodePtr left, NodePtr right)
{
  int index;
  static int num_nodes = 0;
  
  index = num_nodes++;
  NodePtr node = &node_arr[index];

  node->freq = freq;
  node->character = character;
  node->left = left;
  node->right = right;

  return node;
}

const NodePtr CreateTree(const unsigned long* freq_arr, int size)
{
  int i;
  NodePtr min_1, min_2, node_arr;

  node_arr = InitNodes();

  Heap heap = {
    .tree = {0},
    .size = 0,
  };
  

  // Populate Priority queue
  for(i = 0; i < size; ++i)
  {
    if(freq_arr[i] != 0)
    {
      QueueInsert(&heap, CreateNode(node_arr, freq_arr[i], i, NULL, NULL));
    }
  }

  // Build tree.
  while(heap.size > 1)
  {
    min_1 = QueuePop(&heap);
    min_2 = QueuePop(&heap);

    NodePtr new_node = CreateNode(node_arr, min_1->freq + min_2->freq, 0, min_1, min_2);
    QueueInsert(&heap, new_node);
  }
  
  // The root node of the tree.
  return heap.tree[0];
}


