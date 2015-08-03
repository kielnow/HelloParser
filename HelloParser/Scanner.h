//
// Lexer
//

#pragma once

#include <istream>

namespace app {

	struct YYSTYPE
	{
	};

	template<typename TokenType, typename CharType>
	class Scanner
	{
	public:
		typedef typename CharType yyctype;
		typedef typename TokenType token_type;

		Scanner(std::istream* in, size_t buf_size = 1024);
		virtual ~Scanner();

		virtual bool fill(int n);
		virtual int scan(YYSTYPE& yylval) = 0;

	protected:
		std::istream* mpStream;

		yyctype* mpBuffer;
		yyctype* mpCursor;
		yyctype* mpLimit;
		yyctype* mpToken;
		yyctype* mpMarker;
		size_t mBufferSize;
		size_t mLineno;
	};

} // namespace app

#include "Scanner.hpp"