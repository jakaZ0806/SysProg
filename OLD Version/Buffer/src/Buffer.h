/*
 * Buffer.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

using namespace std;

#ifndef BUFFER_H_
#define BUFFER_H_

class Buffer {
private:
	int size;
	int fd;
	bool eof;
	char* buffer1;
	char* buffer2;
	char* next;
	void loadCharsFromFile(char*, int);

public:
	Buffer(int, char*);
	virtual ~Buffer();

	char getchar();
	bool haschar();
	void ungetchar();

};

#endif /* BUFFER_H_ */
