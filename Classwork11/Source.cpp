#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include "Header.h"
#include <cstdio>
#include <conio.h>


using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	cout << "Варіант 8" << endl;
	FILE* f = fopen("D:\\ftext.txt", "r");
	char text[1000] = { '\0' };
	fread(text, sizeof(char), 1000, f);
	bool work = true;
	while (work)
	{
		int answer = menu();
		switch (answer)
		{
		case 0:
		{
			cout << text;
			cout << endl;
			system("pause");
			break;
		}
		case 1:
		{
			int queue[3] = { 1,0,2 };
			int first_el[3] = { 0 };
			int last_el[3] = { 0 };
			int i = 0, j = 0;
			while (i <= strlen(text) - 1 && j <= 2)
			{
				if (isalpha(text[i]))
				{
					first_el[j] = i;
					while ((text[i] != '.') && (text[i] != '!') && (text[i] != '?') && (i != strlen(text) - 1)) i++;
					last_el[j] = i;
					j++;
				}
				i++;
			}
			printtext(text, queue, first_el, last_el);
			break;
		}
		case 2:
		{
			work = false;
			break;
		}
		}
	}
	return 0;
}