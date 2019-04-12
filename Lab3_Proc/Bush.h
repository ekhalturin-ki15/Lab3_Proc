#pragma once

#include <string>
#include <vector>
#include <fstream>

const std::vector<std::string> watIsMonth = { "€нварь", "февраль", "март", "апрель", "май","июнь", "июль", "август", "сент€брь", "окт€брь", "но€брь", "декабрь" };

struct Bush
{
	char name[20];
	int month;
};

void InBush(std::ifstream& infile, Bush& b);
void OutBush(std::ofstream& outfile, Bush b);