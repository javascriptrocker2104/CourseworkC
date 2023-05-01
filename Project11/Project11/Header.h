#include <conio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;
extern int len;
extern char fname[20]; // переменная под наш файл
struct INFO
{
	char name[20];
	char material[20];
	char size[20];
	int kol=0;
	int data[6];
	int price=0;
	char metka[2];
};
int* sortMasPoVoz(int *pr, int k);
int* price(fstream& p,int*pr, char mat[][25], int k);
ostream& FinishL(ostream& stream);
ostream& FinishL2(ostream& stream);
ostream& shapka(ostream& stream);
void write(fstream& p, INFO zap, int num = 0);
void print(INFO zap);
INFO vvod();
void writeNzap(fstream& p, int n);
fstream& read(fstream& p, INFO& zap, int num = 0);
void readAll(fstream& p);
void readN(fstream& p, int N);
int metkaDel(fstream& p, int n);
void UNmetkaDel(fstream& p);
void spiski(fstream& p);
int Delete(fstream& p);
void vivod(fstream& p, int* pr, int k);