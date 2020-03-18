/*
 * @Author: Sanjay Zhong 
 * @Date: 2020-03-18 23:18:58 
 * @Last Modified by:   Sanjay Zhong 
 * @Last Modified time: 2020-03-18 23:18:58 
 */
#ifndef __READ_H__
#define __READ_H__

size_t readn(int fd, void *buffer, size_t size);
size_t read_message(int fd, char *buffer, size_t length);

#endif