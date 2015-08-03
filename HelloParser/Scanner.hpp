//
// Lexer
//

#pragma once

#include <cstring>

namespace app {

	//! ctor
	template<typename TokenType, typename CharType>
	Scanner<TokenType, CharType>::Scanner(std::istream* in, size_t buf_size)
		: mpStream(in)
		, mpBuffer(nullptr)
		, mpCursor(nullptr)
		, mpLimit(nullptr)
		, mpToken(nullptr)
		, mpMarker(nullptr)
		, mBufferSize(buf_size)
		, mLineno(1)
	{}

	//! dtor
	template<typename TokenType, typename CharType>
	Scanner<TokenType, CharType>::~Scanner()
	{
	}

	//! fill
	template<typename TokenType, typename CharType>
	bool Scanner<TokenType, CharType>::fill(int n)
	{
		// check EOF
		if (mpStream->eof()) {
			if (mpLimit - mpCursor <= 0) {
				return false;
			}
		}

		if (!mpBuffer) {
			// alloc buffer
			mpBuffer = new yyctype[mBufferSize];
			mpCursor = mpLimit = mpToken = mpMarker = mpBuffer;
		}

		const size_t restSize = mpLimit - mpToken;
		if (restSize + n >= mBufferSize) {
			// extend buffer
			mBufferSize *= 2;
			yyctype* newBuffer = new yyctype[mBufferSize];
			memset(newBuffer, 0, sizeof(yyctype) * mBufferSize);
			memcpy(newBuffer, mpToken, restSize);

			mpCursor = newBuffer + (mpCursor - mpToken);
			mpToken = newBuffer;
			mpLimit = newBuffer + restSize;

			delete[] mpBuffer;
			mpBuffer = newBuffer;
		} else {
			// move remained data to head
			memmove(mpBuffer, mpToken, sizeof(yyctype) * restSize);
			mpCursor = mpBuffer + (mpCursor - mpToken);
			mpToken = mpBuffer;
			mpLimit = mpBuffer + restSize;
		}

		// fill to buffer
		const size_t readSize = mBufferSize - restSize;
		mpStream->read(mpLimit, readSize);
		mpLimit += mpStream->gcount();

		return true;
	}

} // namespace app