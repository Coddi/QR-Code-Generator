#include "pch.h"
#include "Encoder.h"
#define GETBIT(x,pos)   ( ((x) & ( 0x1 << (pos) )) !=0 ) //������� �����

Encoder::Encoder(std::string in)
{
    Encoder::toUpper(in);
	Encoder::eorr = 0; 
	size_t i;
	size_t len = in.length(); //����� ��������, �� 3 ��������� ������ length()
	//��������, �������� �� ������ ��� ��������-��������� �����������.
	//���� ���. ��������� ������
	//TODO: ���� �� ��������, ����������� ���������� �����������
	for (size_t j = 0; j < len;j++) {
		if (!strchr(Encoder::sempl, in[j])) {
			Encoder::eorr = 1;
			break;
		}
	}
	if (!Encoder::eorr) {
		for (i = 1; i < len; i += 2) {
			int decBit = Encoder::tab1[in[i - 1]] * 45 + Encoder::tab1[in[i]];
			for (int j = 10; j >= 0; j--) //2 ������� ���������� 11 ������, � ������ �� ���������� ������ 11 �������������� ���
				Encoder::bitArray.push_back(GETBIT(decBit, j));
		}
		if (i == len) {
			int decBit = Encoder::tab1[in[i - 1]];
			for (int j = 5; j >= 0; j--)  //1 ������ ���������� 6 ������, � ������ �� ���������� ������ 6 �������������� ���
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
