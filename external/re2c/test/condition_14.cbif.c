/* Generated by re2c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	BSIZE	8192


enum ScanContition {
	EStateNormal,
	EStateComment,
	EStateSkiptoeol,
	EStateString,
};


typedef struct Scanner
{
	FILE			    *fp;
	unsigned char	    *cur, *tok, *lim, *eof;
	unsigned char 	    buffer[BSIZE];
	unsigned char       yych;
	enum ScanContition  cond;
	int                 state;
} Scanner;

size_t fill(Scanner *s, size_t len)
{
	size_t got = ~0, cnt;

	if (!s->eof && s->lim - s->tok < len)
	{
		if (s->tok > s->buffer)
		{
			cnt = s->tok - s->buffer;
			memcpy(s->buffer, s->tok, s->lim - s->tok);
			s->tok -= cnt;
			s->cur -= cnt;
			s->lim -= cnt;
			cnt = &s->buffer[BSIZE] - s->lim;
		}
		else
		{
			cnt = BSIZE;
		}
		if ((got = fread(s->lim, 1, cnt, s->fp)) != cnt)
		{
			s->eof = &s->lim[got];
		}
		s->lim += got;
	}
	if (s->eof && s->cur + len > s->eof)
	{
		return ~0; /* not enough input data */
	}
	return got;
}

size_t init(Scanner *s)
{
	s->cur = s->tok = s->lim = s->buffer;
	s->eof = 0;
	s->cond = EStateNormal;
	s->state = -1;

	return fill(s, 0);
}

void fputl(const char *s, size_t len, FILE *stream)
{
	while(len-- > 0)
	{
		fputc(*s++, stream);
	}
}

void scan(Scanner *s)
{
	s->tok = s->cur;

	if (s->state < 1) {
		if (s->state < 0) {
			goto yy0;
		} else {
			goto yyFillLabel0;
		}
	} else {
		if (s->state < 2) {
			goto yyFillLabel1;
		} else {
			if (s->state < 3) {
				goto yyFillLabel2;
			} else {
				goto yyFillLabel3;
			}
		}
	}
	for(;;)
	{
		s->tok = s->cur;


yy0:
		if (s->cond < 2) {
			if (s->cond < 1) {
				goto yyc_Normal;
			} else {
				goto yyc_Comment;
			}
		} else {
			if (s->cond < 3) {
				goto yyc_Skiptoeol;
			} else {
				goto yyc_String;
			}
		}
/* *********************************** */
yyc_Comment:
		s->state = 0;
		if ((s->lim - s->cur) < 2) if (fill(s, 2) == ~0) break;
yyFillLabel0:
		s->yych = *s->cur;
		if (s->yych != '*') goto yy5;
		++s->cur;
		if ((s->yych = *s->cur) == '/') goto yy6;
yy4:
		continue;
yy5:
		s->yych = *++s->cur;
		goto yy4;
yy6:
		++s->cur;
		s->cond = EStateNormal;
		continue;
/* *********************************** */
yyc_Normal:
		s->state = 1;
		if ((s->lim - s->cur) < 4) if (fill(s, 4) == ~0) break;
yyFillLabel1:
		s->yych = *s->cur;
		if (s->yych <= '\'') {
			if (s->yych == '"') goto yy14;
			if (s->yych <= '&') goto yy16;
			goto yy13;
		} else {
			if (s->yych <= '/') {
				if (s->yych <= '.') goto yy16;
				goto yy12;
			} else {
				if (s->yych != '?') goto yy16;
			}
		}
		s->yych = *(s->tok = ++s->cur);
		if (s->yych == '?') goto yy27;
yy11:
		fputc(s->cur[-1], stdout);
		continue;
yy12:
		s->yych = *++s->cur;
		if (s->yych == '*') goto yy25;
		if (s->yych == '/') goto yy23;
		goto yy11;
yy13:
		s->yych = *(s->tok = ++s->cur);
		if (s->yych == '"') goto yy17;
		if (s->yych == '\\') goto yy19;
		goto yy11;
yy14:
		++s->cur;
		s->cond = EStateString;
		fputc(s->cur[-1], stdout);
		continue;
yy16:
		s->yych = *++s->cur;
		goto yy11;
yy17:
		s->yych = *++s->cur;
		if (s->yych == '\'') goto yy21;
yy18:
		s->cur = s->tok;
		goto yy11;
yy19:
		s->yych = *++s->cur;
		if (s->yych != '"') goto yy18;
		s->yych = *++s->cur;
		if (s->yych != '\'') goto yy18;
yy21:
		++s->cur;
		fputl("'\"'", 3, stdout);
		continue;
yy23:
		++s->cur;
		s->cond = EStateSkiptoeol;
		continue;
yy25:
		++s->cur;
		s->cond = EStateComment;
		continue;
yy27:
		s->yych = *++s->cur;
		switch (s->yych) {
		case '!':	goto yy42;
		case '\'':	goto yy40;
		case '(':	goto yy28;
		case ')':	goto yy30;
		case '-':	goto yy44;
		case '/':	goto yy38;
		case '<':	goto yy32;
		case '=':	goto yy36;
		case '>':	goto yy34;
		default:	goto yy18;
		}
yy28:
		++s->cur;
		fputc('[', stdout);
		continue;
yy30:
		++s->cur;
		fputc(']', stdout);
		continue;
yy32:
		++s->cur;
		fputc('{', stdout);
		continue;
yy34:
		++s->cur;
		fputc('}', stdout);
		continue;
yy36:
		++s->cur;
		fputc('#', stdout);
		continue;
yy38:
		++s->cur;
		fputc('\\', stdout);
		continue;
yy40:
		++s->cur;
		fputc('^', stdout);
		continue;
yy42:
		++s->cur;
		fputc('|', stdout);
		continue;
yy44:
		++s->cur;
		fputc('~', stdout);
		continue;
/* *********************************** */
yyc_Skiptoeol:
		s->state = 2;
		if ((s->lim - s->cur) < 5) if (fill(s, 5) == ~0) break;
yyFillLabel2:
		s->yych = *s->cur;
		if (s->yych <= '\r') {
			if (s->yych == '\n') goto yy52;
			if (s->yych <= '\f') goto yy54;
			goto yy51;
		} else {
			if (s->yych <= '?') {
				if (s->yych <= '>') goto yy54;
			} else {
				if (s->yych == '\\') goto yy50;
				goto yy54;
			}
		}
		s->yych = *(s->tok = ++s->cur);
		if (s->yych == '?') goto yy61;
yy49:
		continue;
yy50:
		s->yych = *(s->tok = ++s->cur);
		if (s->yych == '\n') goto yy59;
		if (s->yych == '\r') goto yy57;
		goto yy49;
yy51:
		s->yych = *++s->cur;
		if (s->yych == '\n') goto yy55;
		goto yy49;
yy52:
		++s->cur;
		s->cond = EStateNormal;
		fputc('\n', stdout);
		continue;
yy54:
		s->yych = *++s->cur;
		goto yy49;
yy55:
		++s->cur;
		s->cond = EStateNormal;
		fputc('\r', stdout);
		fputc('\n', stdout);
		continue;
yy57:
		s->yych = *++s->cur;
		if (s->yych == '\n') goto yy59;
yy58:
		s->cur = s->tok;
		goto yy49;
yy59:
		++s->cur;
		continue;
yy61:
		s->yych = *++s->cur;
		if (s->yych != '/') goto yy58;
		s->yych = *++s->cur;
		if (s->yych == '\n') goto yy64;
		if (s->yych != '\r') goto yy58;
		s->yych = *++s->cur;
		if (s->yych != '\n') goto yy58;
yy64:
		++s->cur;
		continue;
/* *********************************** */
yyc_String:
		s->state = 3;
		if ((s->lim - s->cur) < 2) if (fill(s, 2) == ~0) break;
yyFillLabel3:
		s->yych = *s->cur;
		if (s->yych == '"') goto yy70;
		if (s->yych != '\\') goto yy72;
		++s->cur;
		if ((s->yych = *s->cur) != '\n') goto yy73;
yy69:
		fputc(s->cur[-1], stdout);
		continue;
yy70:
		++s->cur;
		s->cond = EStateNormal;
		fputc(s->cur[-1], stdout);
		continue;
yy72:
		s->yych = *++s->cur;
		goto yy69;
yy73:
		++s->cur;
		fputl((const char*)s->cur-2, 2, stdout);
		continue;

	}
}

int main(int argc, char **argv)
{
	Scanner in;

	if (argc != 2)
	{
		fprintf(stderr, "%s <file>\n", argv[0]);
		return 1;;
	}

	memset((char*) &in, 0, sizeof(in));

	if (!strcmp(argv[1], "-"))
	{
		in.fp = stdin;
	}
	else if ((in.fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Cannot open file '%s'\n", argv[1]);
		return 1;
	}

	if (init(&in) > 0)
	{
 		scan(&in);
 	}

	if (in.fp != stdin)
	{
		fclose(in.fp);
	}
	return 0;
}
