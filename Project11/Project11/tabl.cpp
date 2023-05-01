#include "Header.h"
ostream& shapka(ostream& stream)
{
	setlocale(LC_ALL, "rus");
	stream << endl << FinishL << endl;
	stream << "Заказчик";
	stream << setw(13) << "Материал ";
	stream << setw(14) << "Размер(м^3)";
	stream << setw(10) << "Кол-во";
	stream << setw(8) << "Дата";
	stream << setw(15) << "Стоимость";
	stream << setw(8) << "Метка" << endl;
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