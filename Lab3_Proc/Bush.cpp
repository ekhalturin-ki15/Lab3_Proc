﻿#include "Bush.h"
#include <set>

void InBush(std::ifstream& infile, Bush& b)
{
	std::string s;
	infile >> b.month >> s >> b.WIG;
	if (s.length() < 20)
		strcpy_s(b.name, s.c_str());
}



void OutBush(std::ofstream& outfile, Bush b)
{
	outfile << "Кол-во согласных в названии = " << BushAmount(b) << " ; ";

	outfile << "Это кустарник, ";

	if ((1 <= b.month) && (b.month <= watIsMonth.size()))
	{
		outfile << "месяц цветения - " << watIsMonth[b.month - 1];

	}
	else
	{
		outfile << "месяц цветения считался некорректно";
	}

	outfile << ", Его название: " << b.name << " ";
	if ((1 <= b.WIG) && (b.WIG <= BwhereItGrows.size()))
	{
		outfile << "; Растёт в " << BwhereItGrows[b.WIG - 1];
	}
	else
	{
		outfile << "; Местность введенна некорректно";
	}
	outfile << std::endl;

}

int BushAmount(Bush b)
{
	int all = 0;
	std::set<char> gl = { 'а', 'о', 'и', 'е', 'ё', 'э', 'ы', 'у', 'ю', 'я' };
	std::string name = b.name;

	for (auto it : name)
		if (!gl.count(tolower(it)))
			all++;

	return all;
}