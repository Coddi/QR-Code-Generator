// Stage1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Encoder.h"

int main()
{
	//Строка для теста. Верный вывод должен быть 0110000101101111000110011000
	//количество бит в выводе 28
	char test[] = "hElLo";
	Encoder En(test);
	for (auto B : En.bitArray) std::cout << B << ' ';
	std::cout << std::endl <<"Количество бит: "<< En.bitArray.size();

}
