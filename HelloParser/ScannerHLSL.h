//
// Lexer for HLSL
//

#pragma once

#include "Scanner.h"

namespace app {

	enum Token
	{
		LeftParen = 1,
		RightParen = 2,
		LeftShift = 3,
	};

	class ScannerHLSL : public Scanner<Token, char>
	{
	public:
		ScannerHLSL(std::istream* in, size_t buf_size = 1024) : Scanner(in, buf_size) {}

		~ScannerHLSL(){}

		int scan(YYSTYPE& yylval) override;
	};

} // namespace app