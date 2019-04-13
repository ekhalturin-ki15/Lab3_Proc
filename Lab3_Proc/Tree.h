#pragma once

#include <string>
#include <vector>
#include <fstream>

struct Tree
{
	char name[20];
	__int64 year;
};

void InTree(std::ifstream& infile, Tree& t);

void OutTree(std::ofstream& outfile, Tree t);