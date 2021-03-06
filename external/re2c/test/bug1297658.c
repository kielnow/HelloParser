/* Generated by re2c */
#line 1 "bug1297658.re"
#include <string.h>
#include <stdlib.h>
#include <iostream>

struct Scanner
{
	Scanner(char *_inp)
		: inp(_inp), buf(NULL), ptr(NULL), len(0), siz(strlen(_inp)), line(0)
	{
		fill(0);
		cur = buf;
	}
	
	void fill(size_t n)
	{
		n++;
		buf = (char*)realloc(buf, len + n + 1);
		if ((len += n) > siz)
		{
			len = siz;
		}
		memcpy(buf, inp, len);
		buf[len] = '\0';
		lim = buf + len;
		eof = buf + siz - 1;
	}

	char    *inp;
	char    *cur;
	char    *buf;
	char    *ptr;
	char    *lim;
	char    *eof;
	size_t  len;
	size_t  siz;
	size_t  line;
};

enum What
{
	UNEXPECTED,
	FCON,
	EOI
};

#define	YYCTYPE		char
#define	YYCURSOR	s.cur
#define	YYLIMIT		s.lim
#define	YYMARKER	s.ptr
#define	YYFILL(n)	s.fill(n)
#define RET(n)      return (n)

int scan(Scanner &s)
{
std:


#line 61 "<stdout>"
{
	YYCTYPE yych;

	if ((YYLIMIT - YYCURSOR) < 4) YYFILL(4);
	yych = *YYCURSOR;
	switch (yych) {
	case '\n':	goto yy6;
	case '.':	goto yy4;
	case '0':	goto yy2;
	default:	goto yy8;
	}
yy2:
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '.':	goto yy11;
	case '0':	goto yy12;
	default:	goto yy3;
	}
yy3:
#line 74 "bug1297658.re"
	{
		RET(UNEXPECTED);
	}
#line 85 "<stdout>"
yy4:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case 'L':	goto yy10;
	case 'e':	goto yy9;
	default:	goto yy5;
	}
yy5:
#line 61 "bug1297658.re"
	{
		RET(FCON);
	}
#line 98 "<stdout>"
yy6:
	++YYCURSOR;
#line 66 "bug1297658.re"
	{
		s.line++;
		if(1||s.cur == s.eof) RET(EOI);
		goto std;
	}
#line 107 "<stdout>"
yy8:
	yych = *++YYCURSOR;
	goto yy3;
yy9:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'L':	goto yy10;
	default:	goto yy5;
	}
yy10:
	yych = *++YYCURSOR;
	goto yy5;
yy11:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'L':	goto yy10;
	case 'e':	goto yy15;
	default:	goto yy5;
	}
yy12:
	++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 3) YYFILL(3);
	yych = *YYCURSOR;
	switch (yych) {
	case '.':	goto yy11;
	case '0':	goto yy12;
	default:	goto yy14;
	}
yy14:
	YYCURSOR = YYMARKER;
	goto yy3;
yy15:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case 'L':	goto yy10;
	default:	goto yy5;
	}
}
#line 77 "bug1297658.re"

}

int main(int,char**)
{
	Scanner s("\n0.eL\n00.eL\n");
	
	std::cout << "RES(2): " << scan(s) << std::endl;
	std::cout << "RES(1): " << scan(s) << std::endl;
	std::cout << "RES(2): " << scan(s) << std::endl;
	std::cout << "RES(1): " << scan(s) << std::endl;
	std::cout << "RES(2): " << scan(s) << std::endl;
	std::cout << "RES(0): " << scan(s) << std::endl;
}
