//
// Lexer for HLSL
//

#include <cstdio>
#include <iostream>
#include <cstdint>
#include "ScannerHLSL.h"

namespace app {

	int ScannerHLSL::scan(YYSTYPE& yylval)
	{
/*!re2c
		re2c:define:YYCTYPE = "unsigned char";
		re2c:define:YYCURSOR = mpCursor;
		re2c:define:YYMARKER = mpMarker;
		re2c:define:YYLIMIT = mpLimit;
		re2c:define:YYFILL:naked = 1;
		re2c:define:YYFILL@len = #;
		re2c:define:YYFILL = "if (!fill(#)) { return 0; }";
		re2c:yyfill:enable = 1;
		re2c:indent:top = 2;

		UTF8_BOM		= "\xEF\xBB\xBF";
		WHITESPACE		= [ \t\f]+;
		EOL				= "\r" | "\n" | "\r\n";
		ANY_CHARACTER	= [^];

*/

		for (;;) {
			mpToken = mpCursor;
/*!re2c
			UTF8_BOM		{ printf("UTF-8 BOM\n"); continue; }

			" "				{ printf("white space\n"); continue; }
			"("				{ return LeftParen; }
			")"				{ return RightParen; }

			"<<"			{ return LeftShift; }

			WHITESPACE		{ continue; }
			EOL				{ printf("new line: %d\n", ++mLineno); continue; }

			ANY_CHARACTER
			{
				printf("unexpected character: '%c'(0x%02X)\n", *mpToken, (uint8_t)*mpToken);
				continue;
			}

*/
		}
	}

} // namespace app