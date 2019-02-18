#include "pch.h"
#include "Encoder.h"
#define GETBIT(x,pos)   ( ((x) & ( 0x1 << (pos) )) !=0 ) //������� �����

Encoder::Encoder(char *in)
{
	Encoder::eorr = 0;
	size_t i;
	size_t len = strlen(in);
	for (size_t j = 0; j < len;j++) {
		if (!strchr(Encoder::sempl, toupper(char(in + j)))) {
			Encoder::eorr = 1;
			break;
		}
	}
	if (!Encoder::eorr) {
		for (i = 1; i < len; i += 2) {
			int decBit = Encoder::tab1[toupper(in[i - 1])] * 45 + Encoder::tab1[toupper(in[i])];
			for (int j = 10; j >= 0; j--) //2 ������� ���������� 11 ������, � ������ �� ���������� ������ 11 �������������� ���
				Encoder::bitArray.push_back(GETBIT(decBit, j));
		}
		if (i == len) {
			int decBit = Encoder::tab1[toupper(in[i - 1])];
			for (int j = 5; j >= 0; j--)  //1 ������ ���������� 6 ������, � ������ �� ���������� ������ 6 �������������� ���
				Encoder::bitArray.push_back(GETBIT(decBit, j));
		}
	}
}


Encoder::~Encoder()
{
}
