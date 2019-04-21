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