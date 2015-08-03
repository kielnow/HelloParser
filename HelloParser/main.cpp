//
// Entry point
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "ScannerHLSL.h"

int main()
{
	using namespace app;

	std::ifstream in("test.txt");
	//std::stringstream in(" <<( ))");

	ScannerHLSL scanner(&in);

	YYSTYPE yylval;
	while (const auto token = scanner.scan(yylval))
	{
		std::cout << token << std::endl;
	}

	std::cin.ignore();

	return 0;
}