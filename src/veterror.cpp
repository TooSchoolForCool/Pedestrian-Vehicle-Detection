#include "error.h"

using namespace std;

void error(string msg)
{
	cerr << msg << ": " << strerror(errno) << endl;
	exit(1);
}
