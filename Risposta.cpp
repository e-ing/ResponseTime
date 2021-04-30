// Risposta.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>

#include <iostream>
#include <sstream> 
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


//Abstract_oString& Abstract_oString::operator << (const string str)
//{
////	if( !str.empty() ) 
////		bigBuff.push_back(str);
////	if( !bigBuff.empty() )
////		if( cashBf.empty() )
////		{
////			list<string>::iterator it = bigBuff.begin();
////			cashBf = *it;
////			bigBuff.pop_front();
////			cashBf = PushBuffer(cashBf);
////		}
//	return *this;
//}


class TeddyStr
{
private:
	unsigned int sz;// , pos;
	char* strVulgaris;
	char* str0;
public:
	TeddyStr() : sz(0)
	{
		strVulgaris = new char[1];
		strVulgaris[0] = 0;
		str0 = strVulgaris;
	}

	TeddyStr(const char* str) :
	sz( strlen(str) + 1 )
	{
		strVulgaris = new char[sz + 1];
		for (int i = sz - 1; i >= 0; --i)
			strVulgaris[i] = str[i];
		strVulgaris[sz] = 0;
		str0 = strVulgaris;
	}

	TeddyStr(int val)
	{
		char txV[16];
		_itoa_s(val, txV, 10);
		sz = strlen(txV) + 1;
		strVulgaris = new char[sz + 1];
		for (int i = sz - 1; i >= 0; --i)
			strVulgaris[i] = txV[i];
		strVulgaris[sz] = 0;
		str0 = strVulgaris;
	}

	TeddyStr(unsigned long val) 
	{
		char txV[16];
		_itoa_s(val, txV, 16);
		sz = strlen(txV) + 1;
			strVulgaris = new char[sz + 1];
		for (int i = sz - 1; i >= 0; --i)
			strVulgaris[i] = txV[i];
		strVulgaris[sz] = 0;
		str0 = strVulgaris;
	}

	TeddyStr(double val)
	{
		char txV[32];
		sprintf_s(txV, "%.4f", val);
		sz = strlen(txV) + 1;
		strVulgaris = new char[sz + 1];
		for (int i = sz - 1; i >= 0; --i)
			strVulgaris[i] = txV[i];
		strVulgaris[sz] = 0;
		str0 = strVulgaris;
	}

	TeddyStr(bool val)
	{
		const char TX_TR[] = "TRUE";
		const char TX_FL[] = "FALSE";
		const char* ptr = val ? TX_TR : TX_FL;
		sz = strlen(ptr) + 1;
		strVulgaris = new char[sz + 1];
		for (int i = sz - 1; i >= 0; --i)
			strVulgaris[i] = ptr[i];
		strVulgaris[sz] = 0;
		str0 = strVulgaris;
	}

	TeddyStr(const TeddyStr& any)
	{
		sz = any.sz;
		strVulgaris = new char[sz + 1];
		str0 = strVulgaris;
		for (int i = sz; i >= 0; --i)
			strVulgaris[i] = any.strVulgaris[i];
	}

	TeddyStr& operator = (const TeddyStr& any)
	{
		if (str0 != nullptr)
			delete[] str0;
		sz = any.sz;
		strVulgaris = new char[sz + 1];
		for (int i = sz; i >= 0; --i)
			strVulgaris[i] = any.strVulgaris[i];
		str0 = strVulgaris;
		return *this;
	}
//Discard n elements from the beginning of the string 
	void CutOff ( unsigned int nnn )
	{ 	
		if (sz > 0)
		{
			nnn = (nnn > sz)? sz : nnn;
			sz -= nnn;
			strVulgaris += nnn;
		}
	}
	unsigned int Size() { return sz; }
	bool NotEpty() { return (sz > 0); }
	bool Epty() { return (sz == 0); }
	operator const char* ()
	{
		return strVulgaris;
	}

	~TeddyStr() 
	{
		delete[] str0;
	}
};



//class TeddyStr
//{
//private:
//	unsigned int sz;
//	const char* strVulgaris;
//	vector <char> buff;
//public:
//	TeddyStr() : sz(0), strVulgaris(NULL) { buff.clear(); }
//	TeddyStr(const char* str)
//	{
//		sz = strlen(str) + 1;
//		buff.resize(sz);
//		for (int i = sz - 1; i >= 0; --i)
//			buff[i] = str[i];
//		strVulgaris = buff.data();
//	}
//	//Discard n elements from the beginning of the string 
//	void CutOff(unsigned int n)
//	{
//		vector<char>::iterator it = buff.begin();
//		while ((n-- > 0) && (it != buff.end()))
//		{
//			buff.erase(it);
//			it = buff.begin();
//		}
//		sz = buff.size();
//		strVulgaris = buff.data();
//	}
//	unsigned int Size() { return sz; }
//	bool NotEpty() { return (sz > 0); }
//	bool Epty() { return (sz == 0); }
//	operator const char* ()
//	{
//		return strVulgaris;
//	}
//	//TeddyStr& operator << (const char* str);
//	//TeddyStr& operator << (int);
//	//TeddyStr& operator << (unsigned long);
//	//TeddyStr& operator << (double);
//	//TeddyStr& operator << (bool);
//	~TeddyStr() {}
//};

unsigned int rndR(unsigned int cycles)
{
	unsigned int ret = rand();
	cout << cycles << "---" << endl;
	int i = cycles;
	while (--i > 0)
	{
		ret = rand();
	}
	return ret;
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

	TeddyStr first("1234567890++Hello Word++qwertyuiop");
	cout <<  first << "szFirst = " << first.Size() << endl;
	TeddyStr second(first);
	TeddyStr t3("abc");
	TeddyStr t4("xyz");
	second = t3;
	cout << second << endl;
	t3 = t4 = first;
	cout << t3 << "::" << t4 << "::" << first << endl;
	TeddyStr t5 = second;
	cout << t5 << endl;
	t5 = second = t3;
	TeddyStr tInt(564);
	TeddyStr tFl(9.056);
	TeddyStr tBoo(false);
	cout << tInt << "::" << tFl << "::" << tBoo << endl;
	char cpStr[64];
	char* ptr = cpStr;
	unsigned int cutSz = 0;
	unsigned int rep, temp32;
	cout << "enter any number ";
	cin >> rep;
	while (--rep > 0)
	{
		temp32 = rand();
	}
	rep *= temp32;
	rep &= 0xff;
	cout << second << "szSecond = " << second.Size() << endl;
	while (second.Size() > 0)
	{
		cutSz = rndR(rep) % 5 + 1;
		memcpy(ptr, second, cutSz);
		*(ptr + cutSz) = 0;
		ptr += cutSz;
		second.CutOff(cutSz);
		cout << cpStr << "===" << second << " sz=" << cutSz << endl;
		Sleep(1000);
	}

	first.CutOff(5);
	const char* vlSt = first;
	cout << first << endl;
	cout << vlSt << endl;
	while (true);


	string fS;
	ostringstream ossss ;
	char xStUn[] = "==Hello Word!==";
	char xStUn1[] = "Yes";
	int iUn = 389;
	double zzzz = 3.14;
	fS = xStUn;
	cout <<  fS  << endl;
	ossss << iUn;
	fS = ossss.str();
	cout << fS << endl;


	ossss << zzzz;
	
	fS = xStUn1;
	cout << fS << endl;
	
	bool bbb = false;
	ossss.flush();
	ossss.clear();
	ossss << bbb;
	fS = ossss.str();
	cout << fS << endl;

	while (true);
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

