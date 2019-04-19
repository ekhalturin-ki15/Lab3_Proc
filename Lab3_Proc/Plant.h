#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "RingList.h"
#include "Bush.h"
#include "Tree.h"
#include "Flower.h"

const enum Type { tree, bush, flower };
const int ATYPE = 3;
const std::vector<std::string> whereItGrows = { "тундре", "пустыни", "степи", "арктике" };
const int MLEN = 19;

struct Plant
{
	Type KEY = Type::tree;
	char name[MLEN+1] = "";
	int WIG = 0;
	union
	{
		Bush b;
		Tree t;
		Flower f;
	};
	Plant() {};
	~Plant() {};
	Plant(const Plant& f) {};
	Plant& operator= (const Plant& object)
	{
		WIG = object.WIG;
		KEY = object.KEY;
		strcpy_s(name,object.name);
		switch (object.KEY)
		{
		case Type::tree:
			t = object.t;
			break;
		case Type::bush:
			b = object.b;
			break;
		case Type::flower:
			f = object.f;
			break;
		}
		return *this;
	}


};

void InAll(std::ofstream& outfile, std::ifstream& infile, RingList<Plant>& container);
bool GetPlant(std::ofstream& outfile, string line, Plant& object, int watLine = 0);
bool OutAll(std::ofstream& outfile, RingList<Plant>& container, bool filter = false);

void Sort(RingList<Plant>& container);

bool QSort(std::vector<ElementRL<Plant>*>& mass, int l, int r);

bool Cmp(std::string l, std::string r);

int Amount(std::string name);

void OutName(std::ofstream& outfile, Plant& plant);

char MyTolower(char ch);