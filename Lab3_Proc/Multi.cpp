#include "Multi.h"

bool OutThereName(std::ofstream& outfile, Plant& plant1, Plant& plant2)
{
	outfile << " »х названи€ " << plant1.name << " и " << plant2.name << " соответственно";
	outfile << std::endl;
	return true;
}

bool OutTreeTree(std::ofstream& outfile, Tree t1, Tree t2)
{
	outfile << "Ёто деревь€, ";

	outfile << "им по " << t1.year << " и " << t2.year << " лет, ";

	return true;
}

bool OutTreeBush(std::ofstream& outfile, Tree t1, Bush b2)
{
	outfile << "Ёто дерево и куст, ";

	outfile << "дереву " << t1.year << " лет, а куст цветет в " << watIsMonth[b2.month - 1];

	return true;
}

bool OutBushTree(std::ofstream& outfile, Bush b1, Tree t2)
{
	outfile << "Ёто куст и дерево ";

	outfile << "куст цветет в " << watIsMonth[b1.month - 1] << ", а дереву" << t2.year << " лет ";

	return true;
}

bool OutBushBush(std::ofstream& outfile, Bush b1, Bush b2)
{
	outfile << "Ёто кусты, ";

	outfile << "их мес€ца цветени€ " << watIsMonth[b1.month - 1] << " и " << watIsMonth[b2.month - 1];

	return true;
}