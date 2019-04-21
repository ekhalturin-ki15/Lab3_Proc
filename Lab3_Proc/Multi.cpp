#include "Multi.h"

void OutTreeTree(std::ofstream& outfile, Tree t1, Tree t2)
{
	outfile << "Это деревья ";

	outfile << "им" << t1.year <<" и " << t2.year << " лет, ";

}

void OutThereName(std::ofstream& outfile, Plant p1, Plant p2)
{
	outfile << "Их название: " << p1.name << " и " << p2."\n";
}