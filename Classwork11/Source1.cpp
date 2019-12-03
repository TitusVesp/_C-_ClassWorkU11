#include <iostream>
#include <windows.h>
#include "Header.h"
#include <cstdio>
#include <conio.h>

using namespace std;

int menu()
{
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 3) % 3;
		if (key == 0) cout << "-> Вивести текст на екран." << endl;
		else  cout << "   Вивести текст на екран." << endl;
		if (key == 1) cout << "-> Виділити 2,1,3 текст на екран." << endl;
		else  cout << "   Виділити 2,1,3 текст на екран." << endl;
		if (key == 2) cout << "-> Вийти з програми." << endl;
		else  cout << "   Вийти з програми." << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void printtext(char text[1000], int queue[3], int first_el[3], int last_el[3])
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j < strlen(text); j++)
		{
			if (first_el[ queue[i] ] <= j && j <= last_el[ queue[i] ])
			{
				SetColor(4, 0);
				cout << text[j];
			}
			else
			{
				SetColor(7, 0);
				cout << text[j];
			}
		}
		cout << endl;
		SetColor(7, 0);
		system("pause");
		system("cls");
	}
}