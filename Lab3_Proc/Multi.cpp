#include "Multi.h"

void OutTreeTree(std::ofstream& outfile, Tree t1, Tree t2)
{
	outfile << "��� ������� ";

	outfile << "��" << t1.year <<" � " << t2.year << " ���, ";

}

void OutThereName(std::ofstream& outfile, Plant p1, Plant p2)
{
	outfile << "�� ��������: " << p1.name << " � " << p2."\n";
}