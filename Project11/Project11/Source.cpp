#include "Header.h"
char fname[20] = "file1.bin";
int len = sizeof(INFO);
char menu()
{
	setlocale(LC_ALL, "rus");
	cout << endl << "\n\t1-> �������� ������"
		<< endl << "\t2-> ������ ���� �������"
		<< endl << "\t3-> ������ ������ � N �������"
		<< endl << "\t4-> �������� �� ��������"
		<< endl << "\t5-> ����� ������� �� ��������"
		<< endl << "\t6-> ������� ��������� ������"
		<< endl << "\t7-> ������ ����������"
		<< endl << "\t0-> EXIT" << endl;
	char s;
	//cout << "\n\t-> ";
	cin >> s;
	return s;
}
void main()
{
	fstream p(fname, ios::app);
	setlocale(LC_ALL, "rus");
	if (p)
	{
		p.close();
		p.open(fname, ios::in | ios::out| ios::ate | ios::binary);
	}
	int n;
	do
	{
		char s = menu();
		switch (s)
		{
		case '1':
			cout << "������� ���-�� �������: ";
			cin >> n;
			writeNzap(p, n);
			break;
		case '2':
			readAll(p);
			break;
		case '3':
			int nom;
			cout << "\n������� ����� ������: ";
			cin >> nom;
			readN(p, nom);
			break;
		case '4':
			int a;
			int n;
			cout << "\n\t������� �����: ";
			cin >> n;
			a = metkaDel(p, n);
			break;
		case '5':
			UNmetkaDel(p);
			system("cls");
			break;
		case '6':
			Delete(p);
			cout << ("\n\tDone!");
			break;
		case '7':
			spiski(p);
			break;
		case '0':
			p.close();
			exit(0);
		}
	} while (1);
	p.close();
}