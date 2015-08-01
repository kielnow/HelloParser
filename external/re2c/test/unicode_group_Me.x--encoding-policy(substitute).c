/* Generated by re2c */
#line 1 "unicode_group_Me.x--encoding-policy(substitute).re"
#include <stdio.h>
#include "utf16.h"
#define YYCTYPE unsigned short
bool scan(const YYCTYPE * start, const YYCTYPE * const limit)
{
	__attribute__((unused)) const YYCTYPE * YYMARKER; // silence compiler warnings when YYMARKER is not used
#	define YYCURSOR start
Me:
	
#line 13 "<stdout>"
{
	YYCTYPE yych;

	yych = *YYCURSOR;
	if (yych <= 0x20E0) {
		if (yych <= 0x0487) goto yy2;
		if (yych <= 0x0489) goto yy4;
		if (yych >= 0x20DD) goto yy4;
	} else {
		if (yych <= 0x20E4) {
			if (yych >= 0x20E2) goto yy4;
		} else {
			if (yych <= 0xA66F) goto yy2;
			if (yych <= 0xA672) goto yy4;
		}
	}
yy2:
	++YYCURSOR;
#line 13 "unicode_group_Me.x--encoding-policy(substitute).re"
	{ return YYCURSOR == limit; }
#line 34 "<stdout>"
yy4:
	++YYCURSOR;
#line 12 "unicode_group_Me.x--encoding-policy(substitute).re"
	{ goto Me; }
#line 39 "<stdout>"
}
#line 14 "unicode_group_Me.x--encoding-policy(substitute).re"

}
static const unsigned int chars_Me [] = {0x488,0x489,  0x20dd,0x20e0,  0x20e2,0x20e4,  0xa670,0xa672,  0x0,0x0};
static unsigned int encode_utf16 (const unsigned int * ranges, unsigned int ranges_count, unsigned short * s)
{
	unsigned short * const s_start = s;
	for (unsigned int i = 0; i < ranges_count; i += 2)
		for (unsigned int j = ranges[i]; j <= ranges[i + 1]; ++j)
		{
			if (j <= re2c::utf16::MAX_1WORD_RUNE)
				*s++ = j;
			else
			{
				*s++ = re2c::utf16::lead_surr(j);
				*s++ = re2c::utf16::trail_surr(j);
			}
		}
	return s - s_start;
}

int main ()
{
	YYCTYPE * buffer_Me = new YYCTYPE [26];
	unsigned int buffer_len = encode_utf16 (chars_Me, sizeof (chars_Me) / sizeof (unsigned int), buffer_Me);
	if (!scan (reinterpret_cast<const YYCTYPE *> (buffer_Me), reinterpret_cast<const YYCTYPE *> (buffer_Me + buffer_len)))
		printf("test 'Me' failed\n");
	delete [] buffer_Me;
	return 0;
}
