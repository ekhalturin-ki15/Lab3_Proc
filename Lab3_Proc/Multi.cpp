#include "Multi.h"

bool OutThereName(std::ofstream& outfile, Plant& plant1, Plant& plant2)
{
	outfile << " �� �������� " << plant1.name << " � " << plant2.name << " ��������������";
	outfile << std::endl;
	return true;
}

bool OutTreeTree(std::ofstream& outfile, Tree t1, Tree t2)
{
	outfile << "��� �������, ";

	outfile << "�� �� " << t1.year << " � " << t2.year << " ���, ";

	return true;
}

bool OutTreeBush(std::ofstream& outfile, Tree t1, Bush b2)
{
	outfile << "��� ������ � ����, ";

	outfile << "������ " << t1.year << " ���, � ���� ������ � " << watIsMonth[b2.month - 1];

	return true;
}

bool OutBushTree(std::ofstream& outfile, Bush b1, Tree t2)
{
	outfile << "��� ���� � ������ ";

	outfile << "���� ������ � " << watIsMonth[b1.month - 1] << ", � ������" << t2.year << " ��� ";

	return true;
}

bool OutBushBush(std::ofstream& outfile, Bush b1, Bush b2)
{
	outfile << "��� �����, ";

	outfile << "�� ������ �������� " << watIsMonth[b1.month - 1] << " � " << watIsMonth[b2.month - 1];

	return true;
}

bool OutTreeFlower(std::ofstream& outfile, Tree t1, Flower f2)
{
	outfile << "��� ������ � ������, ";

	outfile << "������ " << t1.year << " ���, � ��� ������ " << watIsType[f2.type - 1];

	return true;
}

bool OutBushFlower(std::ofstream& outfile, Bush b1, Flower f2)
{
	outfile << "��� ���� � ������ ";

	outfile << "���� ������ � " << watIsMonth[b1.month - 1] << ", � ��� ������" << watIsType[f2.type - 1];

	return true;
}

bool OutFlowerTree(std::ofstream& outfile, Flower f1, Tree t2)
{
	outfile << "��� ������ � ������ ";

	outfile << "��� ������" << watIsType[f1.type - 1] << ", � ������" << t2.year << " ��� ";

	return true;
}


bool OutFlowerBush(std::ofstream& outfile, Flower f1, Bush b2)
{
	outfile << "��� ������ � ����, ";

	outfile << "��� ������" << watIsType[f1.type - 1] << ", � ���� ������ � " << watIsMonth[b2.month - 1];

	return true;
}

bool OutFlowerFlower(std::ofstream& outfile, Flower f1, Flower f2)
{
	outfile << "��� �����, ";

	outfile << "��� ������� ������" << watIsType[f1.type - 1] << ", � ������� " << watIsType[f2.type - 1];

	return true;
}