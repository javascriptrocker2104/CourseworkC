#include "Header.h"
#include <string.h>
void writeNzap(fstream& p, int n) // записать n-ое кол-во записей
{
	p.clear();
	p.seekg(0, ios::end); //запись в конец
	for (int i = 0; i < n; i++)
	{
		INFO zap;
		zap = vvod();
		write(p, zap);
	}
}
void write(fstream& p, INFO zap, int num)
{
	p.clear(); //очистка потока
	if (num)
		p.seekg((num - 1) * len, ios::beg);
	p.write((char*)&zap, len);
	if (!p)
	{
	cout<<"Error write";
	exit (0);
	}
}
INFO vvod()
{
	INFO zap;
	setlocale(LC_ALL, "rus");
	cout << endl << "¬ведите заказчика\t";
	cin >> zap.name;
	cout << endl << "¬ведите материал\t";
	cin >> zap.material;
	cout << endl << "¬ведите размер в м^3:\t";
	cin >> zap.size;
	cout << endl << "¬ведите кол-во:\t";
	cin >> zap.kol;
	cout << endl << "¬ведите дату:\t";
	for (int i = 0; i < 3; i++)
	{
		cin >> zap.data[i];
	}
	cout << endl << "¬ведите стоимость:\t";
	cin >> zap.price;
	strcpy_s(zap.metka, "+");
	return zap;
}
fstream& read(fstream& p, INFO& zap, int num)
{
	p.clear(); //очистка потока
	if (num) //позиционирование
		p.seekg((num - 1) * len, ios::beg);
	p.read((char*)&zap, len);
	if (!p&&!p.eof())
	{
	cout << "\n\tError read";
	exit(0);
	}
	return p;
}
void print(INFO zap)
{
	cout << endl << setw(5)<< zap.name << setw(2) << ' ';
	cout << setw(13) << zap.material << setw(2) << ' ';
	cout << setw(8) << zap.size << setw(2) << ' ';
	cout << setw(10) << zap.kol << setw(2) << ' ';
	cout << setw(5);
	for (int i = 0; i < 2; i++)
	{
		cout  << zap.data[i] << ".";
	}
	cout << zap.data[2];
	cout << setw(10) << zap.price;
	cout << setw(10) << zap.metka;
}
void readAll(fstream& p)
{
	p.clear();
	p.seekg(0, ios::beg);
	INFO zap; // куда читать
	cout << shapka;
	while (read(p, zap))
		print(zap);
	cout << endl << FinishL;
}
void readN(fstream& p, int N)
{
	p.clear();
	p.seekg(0, ios::beg);
	INFO zap; // куда читать
	if (read(p, zap, N))
	{
		cout << shapka;
		print(zap);
		cout << endl << FinishL;
	}
	else
		cout << endl << "“акой записи нет";
}
void UNmetkaDel(fstream& p)
{
	p.clear();
	INFO zap;
	p.seekp(0, ios::beg);
	for (int i = 1; read(p, zap, i); i++)
	{
		if (strcmp(zap.metka, "-") == 0)
		{
			strcpy_s(zap.metka, "+");
			write(p, zap, i);
		}
	}
}
int metkaDel(fstream& p, int n)
{
		p.clear();
		INFO zap;
		p.seekp(0, ios::beg);
		int kol = 0;
		if(read(p, zap, n))
		{
				strcpy_s(zap.metka, "-");
				write(p, zap, n);
				kol++;
		}
		return kol;
}
int Delete(fstream& p)
{
	fstream p1("temp.txt", ios::app);
	p.clear();
	INFO zap;
	p.seekp(0, ios::beg);
	int kol = 0;
	for (int i = 1; read(p, zap, i); i++)
	{
		if (strcmp(zap.metka, "+") == 0)
		{
			write(p1, zap);
			kol++;
		}
	}
	p.close();
	p1.close();
	remove(fname);
	rename("temp.txt", fname);
	p.open(fname, ios::in | ios::out | ios::ate);
	return kol;
}
void spiski(fstream& p)
{
	INFO zap;
	int f, k = 1;
	char mat[25][25];
	p.clear();
	p.seekg(0, ios::beg);
	for (int i = 1; read(p, zap, i); i++)
	{
		f = 0;
		if (i == 1) strcpy_s(mat[i - 1], zap.material);
		else {
			p.seekg(0, ios::beg);
			for (int j = 0; j < k; j++)
				if (strcmp(mat[j], zap.material) == 0)f = 1;
			if (f == 0) {
				strcpy_s(mat[k], zap.material); 
				k++;
			}
		}
	}
	int* pr = new int[k];
	pr = price(p, pr,mat, k);
	pr=sortMasPoVoz(pr, k);
	vivod(p, pr, k);
}
int* sortMasPoVoz(int *pr, int k)// —ортирует массив по возрастанию
{
		int tmp = 0;
		for (int i = 0; i < k; i++) 
			for (int j = (k - 1); j >= (i + 1); j--) 
				if (pr[j] < pr[j - 1]) {
					tmp = pr[j];
					pr[j] = pr[j - 1];
					pr[j - 1] = tmp;
				}
		return pr;
}
void vivod(fstream& p, int* pr, int k)
{
	cout << endl << "—писки заказчиков:" << endl;
	for (int z = 0; z < k; z++)
	{
		INFO zap;
		p.seekg(0, ios::beg);
		for (int i = 1; read(p, zap, i); i++)
			if (zap.price == pr[z])
				print(zap);
	}
	cout << endl << FinishL2;
}
int* price(fstream& p,int *pr, char mat[][25], int k)
{
	INFO zap;
	for (int j = 0; j < k; j++)
	{
		int min = 1000;
		p.seekg(0, ios::beg);
		for (int i = 1; read(p, zap, i); i++)
		{
			if (strcmp(mat[j], zap.material) == 0)
				if (min > zap.kol)
					min = zap.kol;
		}
		for (int i = 1; read(p, zap, i); i++)
			if (strcmp(mat[j], zap.material) == 0)
				if (zap.kol == min)
				{
					pr[j] = zap.price;
				}
	}
	return pr;
}
