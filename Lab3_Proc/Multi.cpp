#include "Multi.h"

bool OutThereName(std::ofstream& outfile, Plant& plant1, Plant& plant2)
{
	outfile << " Их названия " << plant1.name << " и " << plant2.name << " соответственно";
	outfile << std::endl;
	return true;
}

bool OutTreeTree(std::ofstream& outfile, Tree t1, Tree t2)
{
	outfile << "Это деревья, ";

	outfile << "им по " << t1.year << " и " << t2.year << " лет, ";

	return true;
}

bool OutTreeBush(std::ofstream& outfile, Tree t1, Bush b2)
{
	outfile << "Это дерево и куст, ";

	outfile << "дереву " << t1.year << " лет, а куст цветет в " << watIsMonth[b2.month - 1];

	return true;
}

bool OutBushTree(std::ofstream& outfile, Bush b1, Tree t2)
{
	outfile << "Это куст и дерево ";

	outfile << "куст цветет в " << watIsMonth[b1.month - 1] << ", а дереву" << t2.year << " лет ";

	return true;
}

bool OutBushBush(std::ofstream& outfile, Bush b1, Bush b2)
{
	outfile << "Это кусты, ";

	outfile << "их месяца цветения " << watIsMonth[b1.month - 1] << " и " << watIsMonth[b2.month - 1];

	return true;
}

bool OutTreeFlower(std::ofstream& outfile, Tree t1, Flower f2)
{
	outfile << "Это дерево и цветок, ";

	outfile << "дереву " << t1.year << " лет, а тип цветка " << watIsType[f2.type - 1];

	return true;
}

bool OutBushFlower(std::ofstream& outfile, Bush b1, Flower f2)
{
	outfile << "Это куст и цветок ";

	outfile << "куст цветет в " << watIsMonth[b1.month - 1] << ", а тип цветка" << watIsType[f2.type - 1];

	return true;
}

bool OutFlowerTree(std::ofstream& outfile, Flower f1, Tree t2)
{
	outfile << "Это цветок и дерево ";

	outfile << "тип цветка" << watIsType[f1.type - 1] << ", а дереву" << t2.year << " лет ";

	return true;
}


bool OutFlowerBush(std::ofstream& outfile, Flower f1, Bush b2)
{
	outfile << "Это цветок и куст, ";

	outfile << "тип цветка" << watIsType[f1.type - 1] << ", а куст цветет в " << watIsMonth[b2.month - 1];

	return true;
}

bool OutFlowerFlower(std::ofstream& outfile, Flower f1, Flower f2)
{
	outfile << "Это цветы, ";

	outfile << "тип первого цветка" << watIsType[f1.type - 1] << ", а второго " << watIsType[f2.type - 1];

	return true;
}