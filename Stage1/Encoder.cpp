#include "pch.h"
#include "Encoder.h"
#define GETBIT(x,pos)   ( ((x) & ( 0x1 << (pos) )) !=0 ) //битовая магия

Encoder::Encoder(std::string in)
{
    Encoder::toUpper(in);
	Encoder::eorr = 0; 
	size_t i;
	size_t len = in.length(); //can be replaced with 3 separate length () calls
	// Check if the string is suitable for alphanumeric coding.
	//If not. We fix the error
	// TODO: If not suitable, implement byte-coding.
	for (size_t j = 0; j < len;j++) {
		if (!strchr(Encoder::sempl, in[j])) {
			Encoder::eorr = 1;
			break;
		}
	}
	if (!Encoder::eorr) {
		for (i = 1; i < len; i += 2) {
			int decBit = Encoder::tab1[in[i - 1]] * 45 + Encoder::tab1[in[i]];
			for (int j = 10; j >= 0; j--) // 2 characters are encoded with 11 bits, we send only 11 valid bits to the array
				Encoder::bitArray.push_back(GETBIT(decBit, j));
		}
		if (i == len) {
			int decBit = Encoder::tab1[in[i - 1]];
			for (int j = 5; j >= 0; j--)  // 1 character is encoded with 6 bits, we send only 6 valid bits to the array
				Encoder::bitArray.push_back(GETBIT(decBit, j));
		}
	}
}

void Encoder::toUpper(std::string &s) {
	for (size_t i = 0; i < s.length(); i++) 
		if (s[i] >= 'a' && s[i] <= 'z') 
			s[i] = s[i] - 32;
	
}

Encoder::~Encoder()
{
}
