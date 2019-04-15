#include "Bush.h"
#include <set>

void InBush(std::ifstream& infile, Bush& b)
{
	infile >> b.month >> b.WIG;
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

	if ((1 <= b.WIG) && (b.WIG <= BwhereItGrows.size()))
	{
		outfile << "; Растёт в " << BwhereItGrows[b.WIG - 1];
	}
	else
	{
		outfile << "; Местность введенна некорректно";
	}

}