/*
 * huffman.h
 *
 *  Created on: Aug 29, 2017
 *      Author: lukas
 */

#ifndef HUFFMAN_H_
#define HUFFMAN_H_

#define SIZE_OF_ARRAY(x)  (sizeof(x) / sizeof((x)[0]))

extern const char* compress_file(const char* file_path);

#endif /* HUFFMAN_H_ */
