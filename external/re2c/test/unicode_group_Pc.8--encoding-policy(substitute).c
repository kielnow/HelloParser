/* Generated by re2c */
#line 1 "unicode_group_Pc.8--encoding-policy(substitute).re"
#include <stdio.h>
#include "utf8.h"
#define YYCTYPE unsigned char
bool scan(const YYCTYPE * start, const YYCTYPE * const limit)
{
	__attribute__((unused)) const YYCTYPE * YYMARKER; // silence compiler warnings when YYMARKER is not used
#	define YYCURSOR start
Pc:
	
#line 13 "<stdout>"
{
	YYCTYPE yych;

	yych = *YYCURSOR;
	switch (yych) {
	case '_':	goto yy4;
	case 0xE2:	goto yy6;
	case 0xEF:	goto yy7;
	default:	goto yy2;
	}
yy2:
	++YYCURSOR;
yy3:
#line 13 "unicode_group_Pc.8--encoding-policy(substitute).re"
	{ return YYCURSOR == limit; }
#line 29 "<stdout>"
yy4:
	++YYCURSOR;
yy5:
#line 12 "unicode_group_Pc.8--encoding-policy(substitute).re"
	{ goto Pc; }
#line 35 "<stdout>"
yy6:
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 0x80:	goto yy11;
	case 0x81:	goto yy13;
	default:	goto yy3;
	}
yy7:
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 0xB8:	goto yy10;
	case 0xB9:	goto yy8;
	case 0xBC:	goto yy11;
	default:	goto yy3;
	}
yy8:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x8D:
	case 0x8E:
	case 0x8F:	goto yy12;
	default:	goto yy9;
	}
yy9:
	YYCURSOR = YYMARKER;
	goto yy3;
yy10:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xB3:
	case 0xB4:	goto yy12;
	default:	goto yy9;
	}
yy11:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xBF:	goto yy12;
	default:	goto yy9;
	}
yy12:
	yych = *++YYCURSOR;
	goto yy5;
yy13:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case 0x80:
	case 0x94:	goto yy12;
	default:	goto yy9;
	}
}
#line 14 "unicode_group_Pc.8--encoding-policy(substitute).re"

}
static const unsigned int chars_Pc [] = {0x5f,0x5f,  0x203f,0x2040,  0x2054,0x2054,  0xfe33,0xfe34,  0xfe4d,0xfe4f,  0xff3f,0xff3f,  0x0,0x0};
static unsigned int encode_utf8 (const unsigned int * ranges, unsigned int ranges_count, unsigned char * s)
{
	unsigned char * const s_start = s;
	for (unsigned int i = 0; i < ranges_count - 2; i += 2)
		for (unsigned int j = ranges[i]; j <= ranges[i + 1]; ++j)
			s += re2c::utf8::rune_to_bytes (s, j);
	re2c::utf8::rune_to_bytes (s, ranges[ranges_count - 1]);
	return s - s_start + 1;
}

int main ()
{
	YYCTYPE * buffer_Pc = new YYCTYPE [44];
	unsigned int buffer_len = encode_utf8 (chars_Pc, sizeof (chars_Pc) / sizeof (unsigned int), buffer_Pc);
	if (!scan (reinterpret_cast<const YYCTYPE *> (buffer_Pc), reinterpret_cast<const YYCTYPE *> (buffer_Pc + buffer_len)))
		printf("test 'Pc' failed\n");
	delete [] buffer_Pc;
	return 0;
}
