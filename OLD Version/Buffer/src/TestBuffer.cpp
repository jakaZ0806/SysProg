#include "Buffer.h"

using namespace std;


int main(int argc, char **argv) {

	Buffer*  buffer;

	buffer = new Buffer(1024, "/home/thomas/workspace/SysProgTemplate_V11/Buffer/src/input.txt");

	cout << buffer->haschar() << endl;
	cout << buffer->getchar() << endl;

	while (buffer->haschar()) {
		cout << buffer->getchar();
	}

	cout << endl;

	buffer->ungetchar();
	buffer->ungetchar();
	buffer->ungetchar();
	while (buffer->haschar()) {
			cout << buffer->getchar();
		}

	cout << endl;

}
