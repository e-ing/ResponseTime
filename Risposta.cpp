// Risposta.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cwchar>
#include <ctime>


using namespace std;


static void NormalText(const char* str = NULL)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 0x07);
	if (NULL != str)
	{
		cout << str;
	}
}

static void SetTextColor(unsigned char txtClr, const char* str = NULL)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, txtClr);
	if (NULL != str)
	{
		cout << str;
		NormalText();
	}
}

static void HighLiteText(const char* str = NULL)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 0x0E);
	if (NULL != str)
	{
		cout << str;
		NormalText();
	}
}

static void BlueText(const char* str = NULL)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
	if (NULL != str)
	{
		cout << str;
		NormalText();
	}
}



void SetXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int _tmain(int argc, _TCHAR* argv[])
{
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//CONSOLE_FONT_INFOEX fontInfo;
	//GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo); // Получить текущий шрифт

	//	// Поменять какие-то параметры
	////wcsncpy(L"Arial Cyr", fontInfo.FaceName, LF_FACESIZE);  // Имя
	//fontInfo.dwFontSize.X = 24; // Размер (в логических единицах)
	//fontInfo.dwFontSize.Y = 24; // Размер (в логических единицах)

	//SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo); // Установить новый
	clock_t t1 = clock(); 
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 10;                   // Width of each character in the font
	cfi.dwFontSize.Y = 24;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	//std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	//std::cout << "Font: Consolas, Size: 24\n";
	SetXY(2,2);
	unsigned int rnX, rnY, rnZ, rnTot ;
	cout << "Hello Word!";
	SetXY(5,4);
	Sleep(1000);
	system("color 85" );
	cout << "are you readY (Y/N)" <<  (char) 7;
	char ready = 'N';
	while(ready != 'Y')
		cin >> ready;
	Sleep(1000);
	clock_t t2 = clock();
	rnX = (t2 - t1 + .0)/ CLOCKS_PER_SEC;
	rnY = (int) t2;
	rnZ =  int (100.0 * ((double) t1 - (double) (int) t1) );
	rnTot = rnZ + (rnY % 255) + rnX * 29;
	for(int i = rnTot; i > 0; --i)
		rnY = rand();

	char temp;
	unsigned char txtColor, bkColor;
	unsigned int rnd;
	unsigned char x, y, symb, inSymb;
	//FILETIME ft;
 //   SYSTEMTIME st;
 //   GetSystemTimeAsFileTime(&ft);
 //   cout << ft.dwLowDateTime << "\n";
 //   GetSystemTime(&st);
 //   cout << st.wMinute <<":"<< st.wSecond <<":"<< st.wMilliseconds << "\n";
 //   GetSystemTimeAsFileTime(&ft);
 //   cout << ft.dwLowDateTime << "\n";
	
	double  totalTime;
	char anotherTime = 'y';
	unsigned int cnt;
	while ( (anotherTime == 'y') || (anotherTime == 'Y') )
	{
		totalTime = 0.0;
		for (int i=0; i < 16; ++i)
		{	
			inSymb = 0;
			cnt = 0;
			x = rand()%72;
			y = rand()%18 + 1;
			SetXY(x, y);
			rnd = rand() + rnX + rnY;
			symb = rnd % (127 - 48) + 48;
			
			bkColor = (symb & 7) ;//txtColor ^ 0xf;
			txtColor = (rnd & 6);// | 8;
			if (txtColor == bkColor)
			{
				txtColor = 0xf;
				bkColor = 0;
			}
			else
				txtColor |= 8;
			SetTextColor(txtColor |  (bkColor << 4));		
			t1 = clock();
			while (inSymb != symb)
			{
				cout << " " << symb;
				cin >> inSymb;
				SetXY((++x) % 75 , y);
				cout << inSymb;
				++cnt;
			}
			t2 = clock();
			cout << (char) 7;
			SetXY(72, 0);
			totalTime += (t2 - t1 + .0)/ CLOCKS_PER_SEC; 
			cout << totalTime  << endl;
			SetXY((x - 2 * cnt) % 75, y);
			for (int j = 3 + 2 * cnt; j > 0; --j)
			{
				cout << " ";
				Sleep(j * 40);
			}
			Sleep(500 + rand() % 2000);
		}
		cout << "un'altra volta? (Y/N)";
		cin >> anotherTime;
	}
	return 0;
}

