#include "c-echo.h"

int main(int argv, char** argc) {
	std::cout << "Count of output: " << count(echo(argv,argc)) << std::endl;
}
