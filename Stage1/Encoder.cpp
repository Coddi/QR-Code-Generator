#include "pch.h"
#include "Encoder.h"
#define GETBIT(x,pos)   ( ((x) & ( 0x1 << (pos) )) !=0 ) //������� �����

Encoder::Encoder(char *in)
{
	size_t i;
	size_t len = strlen(in);
	for (i = 1; i < len; i+=2) {
		int decBit = Encoder::tab1[toupper(in[i-1])]*45 + Encoder::tab1[toupper(in[i])];
		for (int j = 10; j>=0; j--) //2 ������� ���������� 11 ������, � ������ �� ���������� ������ 11 �������������� ���
			Encoder::bitArray.push_back(GETBIT(decBit,j));
	}
	if (i== len) {
		int decBit = Encoder::tab1[toupper(in[i-1])];
		for (int j = 5; j >= 0; j--)  //1 ������ ���������� 6 ������, � ������ �� ���������� ������ 6 �������������� ���
			Encoder::bitArray.push_back(GETBIT(decBit, j));
	}

}


Encoder::~Encoder()
{
}
