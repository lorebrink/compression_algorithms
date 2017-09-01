/*
 * huffman.h
 *
 *  Created on: Aug 29, 2017
 *      Author: lukas
 */

#ifndef HUFFMAN_H_
#define HUFFMAN_H_

#define NUM_CHARS 256

typedef unsigned char byte;

extern const char* CompressFile(const char* file_path);

#endif /* HUFFMAN_H_ */
