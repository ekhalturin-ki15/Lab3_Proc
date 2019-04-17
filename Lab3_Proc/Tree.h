#pragma once

#include <string>
#include <vector>
#include <fstream>

struct Tree
{
	__int64 year;
};

void InTree(std::stringstream& stream, Tree& t);
bool OutTree(std::ofstream& outfile, Tree t);
