#include "Plant.h"
#include "Tree.h"
#include "Bush.h"
#include <set>
#include <sstream>

using namespace std;

void InAll(ifstream& infile, RingList<Plant>& container)
{
	string line;
	while (getline(infile, line))
	{
		Plant object;
		GetFlower(line, object);
		container.PushBack(object);
	}
}

bool GetFlower(string line, Plant& object)
{
	stringstream stream;
	stream.str(line);

	int type;
	stream >> type;
	object.KEY = static_cast<Type> (type - 1);
	string s;

	switch (object.KEY)
	{
	case Type::tree:
		InTree(stream, object.t);
		break;
	case Type::bush:
		InBush(stream, object.b);
		break;
	case Type::flower:
		InFlower(stream, object.f);
		break;
	default:
		return false;
	}
	stream >> s >> object.WIG;
	if (s.length() < MLEN)
		strcpy_s(object.name, s.c_str());

	return true;
}

bool OutAll(std::ofstream& outfile, RingList<Plant>& container, bool filter)
{
	ElementRL<Plant>* it = container.begin();
	
	for (int i = 0; i < container.WatAmount(); i++)
	{
		switch (it->data.KEY)
		{
		case Type::tree:
			OutTree(outfile, it->data.t);
			break;
		case Type::bush:
			if (filter) break;
			OutBush(outfile, it->data.b);
			break;
		case Type::flower:
			if (filter) break;
			OutFlower(outfile, it->data.f);
			break;
		}

		if ((!filter) || (it->data.KEY == Type::tree)) OutName(outfile, it->data);

		it = it->next;
	}

	return true;
}

void Sort(RingList<Plant>& container)
{
	vector<ElementRL<Plant>*> mass;
	ElementRL<Plant>* it = container.begin();
	for (int i = 0; i < container.WatAmount(); i++)
	{
		mass.push_back(it);
		it = it->next;
	}

	QSort(mass, 0, mass.size() - 1);
}

bool QSort(vector<ElementRL<Plant>*>& mass, int l, int r)
{
	if (l >= r) return true;
	int i = l, j = r;
	string p;
	p = mass[(l + r) / 2]->data.name;
	while (true)
	{

		while (Cmp(p, (mass[i]->data.name))) i++;

		while (Cmp((mass[j]->data.name),p)) j--;

		if (i <= j)
		{
			Plant c;
			c = mass[i]->data;
			mass[i]->data = mass[j]->data;
			mass[j]->data = c;

			i++;
			j--;
		}
		if (i > j) break;
	}

	QSort(mass, l, j); //then QuickSort(l, j);
	QSort(mass, i, r); //then QuickSort(i, r);

	return true;
}

bool Cmp(string l, string r)
{
	vector<string> v; v.push_back(l); v.push_back(r);
	vector<int> value;
	for (int i = 0; i < 2; i++)
	{
		value.push_back(Amount(v[i]));
	}

	return (value[0] > value[1]);
}


int Amount(string name)
{
	int all = 0;
	std::vector<char> bad = { 'а', 'о', 'и', 'е', 'ё', 'э', 'ы', 'у', 'ю', 'я' , 'ъ', 'ь', 'ы'}; //Исправил
	std::set<char> consonant;
	for (char ch = 'а'; ch <= 'п'; ch++) consonant.insert(ch);
	for (char ch = 'р'; ch <= 'я'; ch++) consonant.insert(ch);
	for (auto it : bad) consonant.erase(it);

	for (auto it : name)
	{
		if (consonant.count(MyTolower(it)))
			all++;
	}

	return all;
}

char MyTolower(char ch)
{
	if ((ch >= 'А') && (ch <= 'П')) return ch - 'А' + 'а';
	if ((ch >= 'Р') && (ch <= 'Я')) return ch - 'Р' + 'р';
	if (ch == 'Ё') return 'ё';
	return ch;
}

bool OutName(std::ofstream& outfile, Plant& plant)
{
	if ((1 <= plant.WIG) && (plant.WIG <= whereItGrows.size()))
	{
		outfile << "; Растёт в " << whereItGrows[plant.WIG - 1];
	}
	else
	{
		outfile << "; Местность введенна некорректно";
	}

	outfile << " Его название = " << plant.name << " ; ";
	outfile << "Кол-во согласных в названии = " << Amount(plant.name);
	outfile << std::endl;
	return true;
}