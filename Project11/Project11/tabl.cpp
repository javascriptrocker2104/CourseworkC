#include "Header.h"
ostream& shapka(ostream& stream)
{
	setlocale(LC_ALL, "rus");
	stream << endl << FinishL << endl;
	stream << "��������";
	stream << setw(13) << "�������� ";
	stream << setw(14) << "������(�^3)";
	stream << setw(10) << "���-��";
	stream << setw(8) << "����";
	stream << setw(15) << "���������";
	stream << setw(8) << "�����" << endl;
	stream << endl << FinishL;
	return stream;
}
ostream& FinishL(ostream& stream)
{
	stream << setfill('-') << setw(100) << '|' << setfill(' ');
	return stream;
}
ostream& FinishL2(ostream& stream)
{
	stream << setfill('-') << setw(100) << '|' << setfill(' ');
	return stream;
}