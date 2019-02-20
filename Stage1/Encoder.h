#pragma once
#include <vector>
#include <map>
#include <cctype>    
#include <string.h>
class Encoder
{
public:
	Encoder(std::string in);
	~Encoder();
	//0 - if there are no errors.
	//Other values - there are errors
	int eorr;
	std::vector<bool> bitArray;
private:
	// convert the string to upper case
	void toUpper(std::string &s); 
	//List of valid characters
	char sempl[46] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:";
	//List of valid characters and their codes
	std::map<char, int> tab1 = { {'0',0},
								{'1',1},
								{'2',2},
								{'3',3},
								{'4',4},
								{'5',5},
								{'6',6},
								{'7',7},
								{'8',8},
								{'9',9},
								{'A',10},
								{'B',11},
								{'C',12},
								{'D',13},
								{'E',14},
								{'F',15},
								{'G',16},
								{'H',17},
								{'I',18},
								{'J',19},
								{'K',20},
								{'L',21},
								{'M',22},
								{'N',23},
								{'O',24},
								{'P',25},
								{'Q',26},
								{'R',27},
								{'S',28},
								{'T',29},
								{'U',30},
								{'V',31},
								{'W',32},
								{'X',33},
								{'Y',34},
								{'Z',35},
								{' ',36},
								{'$',37},
								{'%',38},
								{'*',39},
								{'+',40},
								{'-',41},
								{'.',42},
								{'/',43},
								{':',44} };
};

