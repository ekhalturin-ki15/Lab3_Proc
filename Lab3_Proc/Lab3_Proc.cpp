#include <iostream>
#include <fstream>
#include <string>
#include "Multi.h"

const int STAND_AMOUNT_ARG = 3;


int main(int amount, char* param[])
{

	setlocale(LC_ALL, "Russian");

	std::ifstream infile;
	std::ofstream outfile;

	if (amount == STAND_AMOUNT_ARG)
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

	MultiOutAll(outfile, container);
	outfile << "---------------" << std::endl;

	container.Clear();

	std::cout << "Контейнер очищен" << std::endl << "количество объектов: " << container.WatAmount() << std::endl;

	OutAll(outfile, container);

	std::cout << "Финиш" << std::endl;

}