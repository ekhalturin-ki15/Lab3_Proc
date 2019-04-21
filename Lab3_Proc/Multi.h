#pragma once

#include "Plant.h"

bool OutTreeTree(std::ofstream& outfile, Tree t1, Tree t2);
bool OutTreeBush(std::ofstream& outfile, Tree t1, Bush b2);
bool OutBushTree(std::ofstream& outfile, Bush b1, Tree t2);
bool OutBushBush(std::ofstream& outfile, Bush b1, Bush b2);

bool OutThereName(std::ofstream& outfile, Plant& plant1, Plant& plant2);

