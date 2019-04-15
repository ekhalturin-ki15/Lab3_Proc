#include "Bush.h"
#include <set>

void InBush(std::ifstream& infile, Bush& b)
{
	infile >> b.month;
}



void OutBush(std::ofstream& outfile, Bush b)
{
	
	outfile << "Это кустарник, ";

	if ((1 <= b.month) && (b.month <= watIsMonth.size()))
	{
		outfile << "месяц цветения - " << watIsMonth[b.month - 1];

	}
	else
	{
		outfile << "месяц цветения считался некорректно";
	}

}