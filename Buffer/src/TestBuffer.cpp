#include "../includes/Buffer.h"

#include <iostream>


int main(int argc, char **argv) {

	Buffer*  buffer;

	const char *const file = "/home/thomas/git/SysProg/Buffer/src/TestFile.txt";
	buffer = new Buffer(file);

	//std::cout << "Hello!" << std::endl;

	int filesize = 20;
	while(filesize > 0)
	std::cout << buffer->nextChar();

}
