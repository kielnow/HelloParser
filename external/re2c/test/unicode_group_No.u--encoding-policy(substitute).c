/* Generated by re2c */
#line 1 "unicode_group_No.u--encoding-policy(substitute).re"
#include <stdio.h>

#define YYCTYPE unsigned int
bool scan(const YYCTYPE * start, const YYCTYPE * const limit)
{
	__attribute__((unused)) const YYCTYPE * YYMARKER; // silence compiler warnings when YYMARKER is not used
#	define YYCURSOR start
No:
	
#line 13 "<stdout>"
{
	YYCTYPE yych;

	yych = *YYCURSOR;
	if (yych <= 0x00002CFC) {
		if (yych <= 0x0000137C) {
			if (yych <= 0x00000B77) {
				if (yych <= 0x000000BB) {
					if (yych <= 0x000000B3) {
						if (yych >= 0x000000B2) goto yy4;
					} else {
						if (yych == 0x000000B9) goto yy4;
					}
				} else {
					if (yych <= 0x000009F3) {
						if (yych <= 0x000000BE) goto yy4;
					} else {
						if (yych <= 0x000009F9) goto yy4;
						if (yych >= 0x00000B72) goto yy4;
					}
				}
			} else {
				if (yych <= 0x00000D6F) {
					if (yych <= 0x00000BF2) {
						if (yych >= 0x00000BF0) goto yy4;
					} else {
						if (yych <= 0x00000C77) goto yy2;
						if (yych <= 0x00000C7E) goto yy4;
					}
				} else {
					if (yych <= 0x00000F29) {
						if (yych <= 0x00000D75) goto yy4;
					} else {
						if (yych <= 0x00000F33) goto yy4;
						if (yych >= 0x00001369) goto yy4;
					}
				}
			}
		} else {
			if (yych <= 0x00002089) {
				if (yych <= 0x0000206F) {
					if (yych <= 0x000017F9) {
						if (yych >= 0x000017F0) goto yy4;
					} else {
						if (yych == 0x000019DA) goto yy4;
					}
				} else {
					if (yych <= 0x00002073) {
						if (yych <= 0x00002070) goto yy4;
					} else {
						if (yych <= 0x00002079) goto yy4;
						if (yych >= 0x00002080) goto yy4;
					}
				}
			} else {
				if (yych <= 0x0000245F) {
					if (yych <= 0x0000215F) {
						if (yych >= 0x00002150) goto yy4;
					} else {
						if (yych == 0x00002189) goto yy4;
					}
				} else {
					if (yych <= 0x000024FF) {
						if (yych <= 0x0000249B) goto yy4;
						if (yych >= 0x000024EA) goto yy4;
					} else {
						if (yych <= 0x00002775) goto yy2;
						if (yych <= 0x00002793) goto yy4;
					}
				}
			}
		}
	} else {
		if (yych <= 0x00010323) {
			if (yych <= 0x000032B0) {
				if (yych <= 0x00003229) {
					if (yych <= 0x00003191) {
						if (yych <= 0x00002CFD) goto yy4;
					} else {
						if (yych <= 0x00003195) goto yy4;
						if (yych >= 0x00003220) goto yy4;
					}
				} else {
					if (yych <= 0x0000325F) {
						if (yych >= 0x00003251) goto yy4;
					} else {
						if (yych <= 0x0000327F) goto yy2;
						if (yych <= 0x00003289) goto yy4;
					}
				}
			} else {
				if (yych <= 0x00010133) {
					if (yych <= 0x0000A82F) {
						if (yych <= 0x000032BF) goto yy4;
					} else {
						if (yych <= 0x0000A835) goto yy4;
						if (yych >= 0x00010107) goto yy4;
					}
				} else {
					if (yych <= 0x00010189) {
						if (yych <= 0x00010174) goto yy2;
						if (yych <= 0x00010178) goto yy4;
					} else {
						if (yych <= 0x0001018A) goto yy4;
						if (yych >= 0x00010320) goto yy4;
					}
				}
			}
		} else {
			if (yych <= 0x00010B5F) {
				if (yych <= 0x00010A3F) {
					if (yych <= 0x0001085F) {
						if (yych >= 0x00010858) goto yy4;
					} else {
						if (yych <= 0x00010915) goto yy2;
						if (yych <= 0x0001091B) goto yy4;
					}
				} else {
					if (yych <= 0x00010A7C) {
						if (yych <= 0x00010A47) goto yy4;
					} else {
						if (yych <= 0x00010A7E) goto yy4;
						if (yych >= 0x00010B58) goto yy4;
					}
				}
			} else {
				if (yych <= 0x00011051) {
					if (yych <= 0x00010B7F) {
						if (yych >= 0x00010B78) goto yy4;
					} else {
						if (yych <= 0x00010E5F) goto yy2;
						if (yych <= 0x00010E7E) goto yy4;
					}
				} else {
					if (yych <= 0x0001D371) {
						if (yych <= 0x00011065) goto yy4;
						if (yych >= 0x0001D360) goto yy4;
					} else {
						if (yych <= 0x0001F0FF) goto yy2;
						if (yych <= 0x0001F10A) goto yy4;
					}
				}
			}
		}
	}
yy2:
	++YYCURSOR;
#line 13 "unicode_group_No.u--encoding-policy(substitute).re"
	{ return YYCURSOR == limit; }
#line 163 "<stdout>"
yy4:
	++YYCURSOR;
#line 12 "unicode_group_No.u--encoding-policy(substitute).re"
	{ goto No; }
#line 168 "<stdout>"
}
#line 14 "unicode_group_No.u--encoding-policy(substitute).re"

}
static const unsigned int chars_No [] = {0xb2,0xb3,  0xb9,0xb9,  0xbc,0xbe,  0x9f4,0x9f9,  0xb72,0xb77,  0xbf0,0xbf2,  0xc78,0xc7e,  0xd70,0xd75,  0xf2a,0xf33,  0x1369,0x137c,  0x17f0,0x17f9,  0x19da,0x19da,  0x2070,0x2070,  0x2074,0x2079,  0x2080,0x2089,  0x2150,0x215f,  0x2189,0x2189,  0x2460,0x249b,  0x24ea,0x24ff,  0x2776,0x2793,  0x2cfd,0x2cfd,  0x3192,0x3195,  0x3220,0x3229,  0x3251,0x325f,  0x3280,0x3289,  0x32b1,0x32bf,  0xa830,0xa835,  0x10107,0x10133,  0x10175,0x10178,  0x1018a,0x1018a,  0x10320,0x10323,  0x10858,0x1085f,  0x10916,0x1091b,  0x10a40,0x10a47,  0x10a7d,0x10a7e,  0x10b58,0x10b5f,  0x10b78,0x10b7f,  0x10e60,0x10e7e,  0x11052,0x11065,  0x1d360,0x1d371,  0x1f100,0x1f10a,  0x0,0x0};
static unsigned int encode_utf32 (const unsigned int * ranges, unsigned int ranges_count, unsigned int * s)
{
	unsigned int * const s_start = s;
	for (unsigned int i = 0; i < ranges_count; i += 2)
		for (unsigned int j = ranges[i]; j <= ranges[i + 1]; ++j)
			*s++ = j;
	return s - s_start;
}

int main ()
{
	YYCTYPE * buffer_No = new YYCTYPE [457];
	unsigned int buffer_len = encode_utf32 (chars_No, sizeof (chars_No) / sizeof (unsigned int), buffer_No);
	if (!scan (reinterpret_cast<const YYCTYPE *> (buffer_No), reinterpret_cast<const YYCTYPE *> (buffer_No + buffer_len)))
		printf("test 'No' failed\n");
	delete [] buffer_No;
	return 0;
}
