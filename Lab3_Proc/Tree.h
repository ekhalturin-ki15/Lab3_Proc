#pragma once

#include <string>
#include <vector>
#include <fstream>

const std::vector<std::string> TwhereItGrows = { "тундре", "пустыни", "степи", "арктике" };

struct Tree
{
	char name[20];
	__int64 year;
	int WIG;
};

void InTree(std::ifstream& infile, Tree& t);

void OutTree(std::ofstream& outfile, Tree t);