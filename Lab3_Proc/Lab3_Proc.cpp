#include <iostream>
#include <fstream>
#include <string>
#include "Plant.h"

const int StandartInpAtr = 3;


int main(int amount, char* param[])
{

	setlocale(LC_ALL, "Russian");

	std::ifstream infile;
	std::ofstream outfile;

	if (amount == StandartInpAtr)
	{
		infile.open(param[1]);
		outfile.open(param[2]);
	}
	else
	{
		infile.open("in.txt");
		outfile.open("out.txt");
	}



	std::cout << "Старт" << std::endl;

	RingList<Plant> container;

	InAll(infile, container);

	std::cout << "Данные считаны с файла" << std::endl;

	OutAll(outfile, container);

	std::cout << "Данные выведенны в файл" << std::endl << "количество объектов: " << container.WatAmount() << std::endl;

	container.Clear();

	std::cout << "Контейнер очищен" << std::endl << "количество объектов: " << container.WatAmount() << std::endl;

	OutAll(outfile, container);

	std::cout << "Финиш" << std::endl;

}