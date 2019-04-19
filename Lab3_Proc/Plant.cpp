#include "Plant.h"
#include <set>
#include <sstream>

using namespace std;

void InAll(std::ofstream& outfile, ifstream& infile, RingList<Plant>& container)
{
	int watLine = 0;
	string line;
	while (getline(infile, line))
	{
		watLine++;
		Plant object;
		if (GetPlant(outfile, line, object, watLine))
			container.PushBack(object);
	}
	outfile << "_____________" << endl;
}

bool GetPlant(std::ofstream& outfile, string line, Plant& object, int watLine)
{
	try
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
			if (object.t.year<1)
				throw string("Год дерева отрицательный");

			break;

		case Type::bush:
			InBush(stream, object.b);

			if ((1 >object.b.month) || (object.b.month > watIsMonth.size()))
				throw string("Месяц цветения куста считался некорректно");

			break;

		case Type::flower:
			InFlower(stream, object.f);

			if ((1 > object.f.type) || (object.f.type > watIsType.size()))
				outfile << "Тип цветка считался некорректно";

			break;

		default:
			throw string("Тип класса " + to_string(type) + " не существует");
		}

		stream >> s >> object.WIG;
		if (s.length() < MLEN)
			strcpy_s(object.name, s.c_str());
		else
			throw string("Имя класса слишком длинное (нужно менее 20 символов)");

		if ((1 > object.WIG) || (object.WIG > whereItGrows.size()))
			throw string("Местность введена некорректно");

		
	}
	catch (string wrong)
	{
		outfile << wrong<<" ; в строке номер "<<to_string(watLine) << endl;
		return false;
	}
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

void OutName(std::ofstream& outfile, Plant& plant)
{
	outfile << "; Растёт в " << whereItGrows[plant.WIG - 1];
	outfile << " Его название = " << plant.name << " ; ";
	outfile << "Кол-во согласных в названии = " << Amount(plant.name);
	outfile << std::endl;
}