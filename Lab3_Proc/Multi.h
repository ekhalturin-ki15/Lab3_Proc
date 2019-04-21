#pragma once

#include "Plant.h"

bool OutTreeTree(std::ofstream& outfile, Tree t1, Tree t2);
bool OutTreeBush(std::ofstream& outfile, Tree t1, Bush b2);
bool OutTreeFlower(std::ofstream& outfile, Tree t1, Flower f2);
bool OutBushTree(std::ofstream& outfile, Bush b1, Tree t2);
bool OutBushBush(std::ofstream& outfile, Bush b1, Bush b2);
bool OutBushFlower(std::ofstream& outfile, Bush b1, Flower f2);
bool OutFlowerTree(std::ofstream& outfile, Flower f1, Tree t2);
bool OutFlowerBush(std::ofstream& outfile, Flower f1, Bush b2);
bool OutFlowerFlower(std::ofstream& outfile, Flower f1, Flower f2);



bool OutThereName(std::ofstream& outfile, Plant& plant1, Plant& plant2);

