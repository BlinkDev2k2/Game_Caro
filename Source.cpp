#include<iostream>
#include<string>
#include<stdio.h>
#include<fstream>
#include<stack>
#include<vector>
#include"Check_BanCo.h"
#include"Graphics.h"
using namespace std;

HANDLE hStdin;
DWORD fdwSaveOldMode;

VOID ErrorExit(const char*) //LPSTR lpszMessage
{
	fprintf(stderr, "%s\n", "BLACKPINK"); //lpszMessage

	// Restore input mode on exit.

	SetConsoleMode(hStdin, fdwSaveOldMode);

	ExitProcess(0);
}

void Menugame(const short int&, const short int&);

struct toado {
	short int x, y;
	char data;
};
typedef struct toado Toado;

void BangThongBao(const short int& row, const short int& col, const short int color)
{
	// ve thanh doc
	unsigned short int r = row * 2;
	unsigned short int c = col * 4.5;
	unsigned short int m = r / 2;
	textcolor(111);
	for (unsigned short int i = 0; i <= r; ++i)
	{
		Sleep(10);
		gotoXY(i, c);
		cout << " ";
		//cout << "\n";
	}

	// ve thanh ngang
	textcolor(2);
	for (unsigned short int j = c + 1; j <= (c + 16); ++j)
	{
		Sleep(13);
		gotoXY(m, j);
		cout << (char)196;
	}

	// ve bang thong ke
	textcolor(219);
	for (unsigned short int i = m - 6; i <= m + 6; ++i)
	{
		Sleep(15);
		gotoXY(i, c + 17);
		if (i == m - 6 || i == m + 6)
			cout << "                                       ";
		else
		{
			cout << "  ";
			gotoXY(i, c + 54);
			cout << "  ";
		}
		//cout << "\n";
	}
	textcolor(7);
}

void BangThongBao_1(const short int& row, const short int& col, const short int color)
{
	// ve thanh doc
	unsigned short int r = row * 2;
	unsigned short int c = col * 4.5;
	unsigned short int m = r / 2;
	textcolor(111);
	for (unsigned short int i = 0; i <= r; ++i)
	{
		gotoXY(i, c);
		cout << " ";
		//cout << "\n";
	}

	// ve thanh ngang
	textcolor(2);
	for (unsigned short int j = c + 1; j <= (c + 16); ++j)
	{
		gotoXY(m, j);
		cout << (char)196;
	}

	// ve bang thong ke
	textcolor(219);
	for (unsigned short int i = m - 6; i <= m + 6; ++i)
	{
		gotoXY(i, c + 17);
		if (i == m - 6 || i == m + 6)
			cout << "                                       ";
		else
		{
			cout << "  ";
			gotoXY(i, c + 54);
			cout << "  ";
		}
		//cout << "\n";
	}
	textcolor(7);
}

void NutNhan(const short int& row, const short int& col)
{
	// ve thanh doc
	unsigned short int c = col * 4.5;
	/*textcolor(111);
	for (unsigned short int i = 0; i <= r; ++i)
	{
		gotoXY(i, c);
		cout << " ";
		cout << "\n";
	}*/
	ShowCur(0);
	// ve thanh ngang
	textcolor(2);
	for (unsigned short int i = 1; i <= 4; ++i)
	{
		for (unsigned short int j = c + 1; j <= (c + 10); ++j)
		{
			Sleep(20);
			if (i == 1)
				gotoXY(row / 7, j);
			else if (i == 2)
				gotoXY(row / 2.5, j);
			else if (i == 3)
				gotoXY(row * 1.6, j);
			else
				gotoXY(row * 1.9, j);
			cout << (char)196;
		}
	}

	// ve nut nhan
	textcolor(112);
	Sleep(50);
	gotoXY(1, c + 11);
	cout << "        ";
	Sleep(50);
	gotoXY(2, c + 11);
	cout << "  Undo  ";
	Sleep(50);
	gotoXY(3, c + 11);
	cout << "        ";

	gotoXY(5, c + 11);
	Sleep(50);
	cout << "        ";
	Sleep(50);
	gotoXY(6, c + 11);
	cout << "  Redo  ";
	Sleep(50);
	gotoXY(7, c + 11);
	cout << "        ";

	gotoXY(26, c + 11);
	Sleep(50);
	cout << "        ";
	Sleep(50);
	gotoXY(27, c + 11);
	cout << "  Save  ";
	gotoXY(28, c + 11);
	Sleep(50);
	cout << "        ";

	gotoXY(31, c + 11);
	Sleep(50);
	cout << "        ";
	gotoXY(32, c + 11);
	Sleep(50);
	cout << "  Exit  ";
	gotoXY(33, c + 11);
	Sleep(50);
	cout << "        ";
	textcolor(7);
}

void NutNhan1(const short int& row, const short int& col, short int click = 0)
{
	unsigned short int c = col * 4.5;
	ShowCur(0);
	// ve nut nhan
	if (click == 0)
		textcolor(112);
	else if (click == 1)
		textcolor(160);
	else if (click == 2)
		textcolor(192);

	gotoXY(1, c + 11);
	cout << "        ";
	gotoXY(2, c + 11);
	cout << "  Undo  ";
	gotoXY(3, c + 11);
	cout << "        ";
	textcolor(7);
}

void NutNhan2(const short int& row, const short int& col, short int click = 0)
{
	// ve thanh doc
	unsigned short int c = col * 4.5;
	ShowCur(0);
	// ve nut nhan
	if (click == 0)
		textcolor(112);
	else if (click == 1)
		textcolor(160);
	else if (click == 2)
		textcolor(192);

	gotoXY(5, c + 11);
	cout << "        ";
	gotoXY(6, c + 11);
	cout << "  Redo  ";
	gotoXY(7, c + 11);
	cout << "        ";
	textcolor(7);
}

void NutNhan3(const short int& row, const short int& col, short int click = 0)
{
	unsigned short int c = col * 4.5;
	ShowCur(0);
	// ve nut nhan
	if (click == 0)
		textcolor(112);
	else if (click == 1)
		textcolor(160);
	else if (click == 2)
		textcolor(192);

	gotoXY(26, c + 11);
	cout << "        ";
	gotoXY(27, c + 11);
	cout << "  Save  ";
	gotoXY(28, c + 11);
	cout << "        ";
	textcolor(7);
}

void NutNhan4(const short int& row, const short int& col, short int click = 0)
{
	unsigned short int c = col * 4.5;
	ShowCur(0);
	// ve nut nhan
	if (click == 0)
		textcolor(112);
	else if (click == 1)
		textcolor(160);
	else if (click == 2)
		textcolor(192);

	gotoXY(31, c + 11);
	cout << "        ";
	gotoXY(32, c + 11);
	cout << "  Exit  ";
	gotoXY(33, c + 11);
	cout << "        ";
	textcolor(7);
}

void Banco_basic(const short int& row, const short int& col, const short int color)
{
	SetColor(color);
	cout << "+";
	for (unsigned short int i = 1; i <= col; ++i)
	{
		cout << "---+";
	}

	for (unsigned short int i = 1; i <= row; ++i)
	{
		cout << "\n|";
		for (unsigned short int i = 1; i <= col; ++i)
		{
			cout << "   |";
		}
		cout << "\n+";
		for (unsigned short int i = 1; i <= col; ++i)
		{
			Sleep(1);
			cout << "---+";
		}
	}
}

void BanCo(const short int& row, const short int& col, const short int color)
{
	SetColor(color);
	cout << (char)218;
	for (unsigned short int i = 1; i < col; ++i)
	{
		cout << (char)196 << (char)196 << (char)196 << (char)194;
	}
	Sleep(1);
	cout << (char)196 << (char)196 << (char)196 << (char)191;

	for (unsigned short int j = 1; j < row; ++j)
	{
		Sleep(1);
		cout << "\n";
		cout << (char)179;
		for (unsigned short int i = 1; i <= col; ++i)
		{
			cout << "   " << (char)179;
		}
		cout << "\n" << (char)195;
		for (unsigned short int i = 1; i < col; ++i)
		{
			cout << (char)196 << (char)196 << (char)196 << (char)197;
		}
		cout << (char)196 << (char)196 << (char)196 << (char)180;
	}

	cout << "\n";
	cout << (char)179;
	for (unsigned short int i = 1; i <= col; ++i)
	{
		cout << "   " << (char)179;
	}

	cout << "\n";
	cout << (char)192;
	for (unsigned short int i = 1; i < col; ++i)
	{
		Sleep(1);
		cout << (char)196 << (char)196 << (char)196 << (char)193;
	}
	cout << (char)196 << (char)196 << (char)196 << (char)217;
}

void BanCo_1(const short int& row, const short int& col, const short int color)
{
	SetColor(color);
	cout << (char)218;
	for (unsigned short int i = 1; i < col; ++i)
	{
		cout << (char)196 << (char)196 << (char)196 << (char)194;
	}
	cout << (char)196 << (char)196 << (char)196 << (char)191;

	for (unsigned short int j = 1; j < row; ++j)
	{
		cout << "\n";
		cout << (char)179;
		for (unsigned short int i = 1; i <= col; ++i)
		{
			cout << "   " << (char)179;
		}
		cout << "\n" << (char)195;
		for (unsigned short int i = 1; i < col; ++i)
		{
			cout << (char)196 << (char)196 << (char)196 << (char)197;
		}
		cout << (char)196 << (char)196 << (char)196 << (char)180;
	}

	cout << "\n";
	cout << (char)179;
	for (unsigned short int i = 1; i <= col; ++i)
	{
		cout << "   " << (char)179;
	}

	cout << "\n";
	cout << (char)192;
	for (unsigned short int i = 1; i < col; ++i)
	{
		cout << (char)196 << (char)196 << (char)196 << (char)193;
	}
	cout << (char)196 << (char)196 << (char)196 << (char)217;
}

void BanCo_2(const short int& row, const short int& col, const short int color, const char a[17][17])
{
	// 191: ┐  192: └   193: ┴   194: ┬  197: ┼   217: ┘   218: ┌   179: │   196: ─   195: ├   180: ┤
	SetColor(color);
	// in ra dong ben tren dau tien
	cout << (char)218;
	for (unsigned short int i = 1; i < col; ++i)
	{
		cout << (char)196 << (char)196 << (char)196 << (char)194;
	}
	cout << (char)196 << (char)196 << (char)196 << (char)191;

	for (unsigned short int j = 1; j < row; ++j)
	{
		cout << "\n";
		cout << (char)179;
		for (unsigned short int i = 1; i <= col; ++i)
		{
			cout << " ";
			if (a[j - 1][i - 1] == 'X')
				textcolor(14);
			else if(a[j-1][i-1] == 'O')
				textcolor(12);
			cout << a[j - 1][i - 1];
			SetColor(color);
			cout << " " << (char)179;
		}
		cout << "\n" << (char)195;
		for (unsigned short int i = 1; i < col; ++i)
		{
			cout << (char)196 << (char)196 << (char)196 << (char)197;
		}
		cout << (char)196 << (char)196 << (char)196 << (char)180;
	}

	cout << "\n";
	cout << (char)179;
	for (unsigned short int i = 1; i <= col; ++i)
	{
		cout << " ";
		if (a[row - 1][i - 1] == 'X')
			textcolor(14);
		else if(a[row - 1][i - 1] == 'O')
			textcolor(12);
		cout << a[row - 1][i - 1];
		SetColor(color);
		cout << " " << (char)179;
	}

	// in ra dong cuoi cung
	cout << "\n";
	cout << (char)192;
	for (unsigned short int i = 1; i < col; ++i)
	{
		cout << (char)196 << (char)196 << (char)196 << (char)193;
	}
	cout << (char)196 << (char)196 << (char)196 << (char)217;
}

short int ToaDoX1(const short int& x)
{
	if (x == 0) return 1;
	else return x * 2 + 1;
}

short int ToaDoY1(const short int& y)
{
	if (y == 0) return 2;
	else return y * 4 + 2;
}

void InCo(char a[17][17], const short int& x, const short int& y, const char& quanco, bool& luotdi, short int& tongoco)
{
	a[x][y] = quanco;
	gotoXY(19, 97);
	cout << "                   ";
	luotdi = luotdi == 1 ? 0 : 1;
	--tongoco;

	// gotoXY den dung vi tri can in quan co
	short int x1, y1;
	// xu ly toa do x y  de gotoXY den vi tri x1 y1 dung
	if (x == 0) x1 = 1;
	else x1 = x * 2 + 1;

	if (y == 0) y1 = 2;
	else y1 = y * 4 + 2;

	gotoXY(x1, y1);

	if (a[x][y] == 'X')
	{
		SetColor(14);
		cout << "X";
	}
	else if (a[x][y] == 'O')
	{
		SetColor(12);
		cout << "O";
	}
}

bool CheckWin(const char a[17][17], const short int& x, const short int& y, const char& quanco, short int toadothang[10], const short int xx = 16)
{
	bool check;
	check = check_ngang(a, x, y, quanco, xx, toadothang);
	if (check)
	{
		return true;
	}
	check = check_doc(a, x, y, quanco, xx, toadothang);
	if (check)
	{
		return true;
	}
	check = check_cheochinh(a, x, y, quanco, xx, toadothang);
	if (check)
	{
		return true;
	}
	check = check_cheophu(a, x, y, quanco, xx, toadothang);
	if (check)
	{
		return true;
	}

	return false;
}

void NhapNhayQuanCo(const char a[17][17], const short int toadothang[10])
{
	short int x, y;
	ShowCur(0);
	for (unsigned short int j = 1; j < 8; ++j)
	{
		for (unsigned short int i = 0; i < 10; i += 2)
		{
			x = toadothang[i];
			y = toadothang[i + 1];

			short int x2, y2;
			if (x == 0) x2 = 1;
			else x2 = x * 2 + 1;

			if (y == 0) y2 = 2;
			else y2 = y * 4 + 2;

			gotoXY(x2, y2);

			if (a[x][y] == 'X')
			{
				cout << " ";
				Sleep(40);
				SetColor(2 + rand() % 14);
				gotoXY(x2, y2);
				cout << "X";
			}
			else
			{
				cout << " ";
				Sleep(40);
				SetColor(2 + rand() % 14);
				gotoXY(x2, y2);
				cout << "O";
			}
		}
	}
	Sleep(300);
	for (unsigned short int i = 0; i < 10; i += 2)
	{
		x = toadothang[i];
		y = toadothang[i + 1];

		short int x2, y2;
		if (x == 0) x2 = 1;
		else x2 = x * 2 + 1;

		if (y == 0) y2 = 2;
		else y2 = y * 4 + 2;

		gotoXY(x2, y2);

		if (a[x][y] == 'X')
		{
			Sleep(40);
			textcolor(372);
			gotoXY(x2, y2);
			cout << "X";
		}
		else
		{
			Sleep(40);
			textcolor(372);
			gotoXY(x2, y2);
			cout << "O";
		}
	}
	textcolor(7);
	Sleep(500);
}

void Introbanco(const short int& row, const short int& col)
{
	ShowCur(1);
	Banco_basic(row, col, 3);
	gotoXY(0, 0);
	ShowCur(0);
	BanCo(row, col, 3);
	BangThongBao(row, col, 119);
	gotoXY(13, 97);
	textcolor(14);
	cout << "Game da san sang";
	gotoXY(15, 97);
	cout << "Game XO Verson Console";
	gotoXY(17, 97);
	cout << "Code by: Hoang Dinh";
	gotoXY(19, 97);
	cout << "Nhan phim bat ky de bat dau choi";
	_getch();

	gotoXY(13, 97);
	cout << "                ";
	gotoXY(15, 97);
	cout << "                      ";
	gotoXY(17, 97);
	cout << "                   ";
	gotoXY(19, 97);
	cout << "                                ";
	XoaManHinh();
}

void Introbanco1(const short int& row, const short int& col)
{
	ShowCur(1);
	Banco_basic(row, col, 3);
	gotoXY(0, 0);
	ShowCur(0);
	BanCo(row, col, 3);
	BangThongBao(row, col, 119);
	gotoXY(13, 97);
	textcolor(14);
	cout << "Game da san sang";
	gotoXY(15, 97);
	cout << "Game XO Verson Console";
	gotoXY(17, 97);
	cout << "Code by: Hoang Dinh";
	gotoXY(19, 97);
	cout << "Nhan phim bat ky de bat dau choi";
	Sleep(200);
}

void IntroGame()
{
	ifstream ifile;
	ifile.open("Caro.txt", ios::in);
	if (!ifile) exit(0);

	unsigned short int x = 1;
	string s;
	SetColor(1 + rand() % 15);
	while (!ifile.eof())
	{
		getline(ifile, s);
		//SetColor(14);
		gotoXY(x++, 35);
		cout << s << endl;
		s.clear();
	}
	ifile.close();

	// ten tac gia
	ifile.open("HoangDinh.txt", ios::in);
	if (!ifile) exit(0);
	--x;
	SetColor(1 + rand() % 15);
	while (!ifile.eof())
	{
		getline(ifile, s);
		//SetColor(15);
		gotoXY(x++, 40);
		cout << s << endl;
		s.clear();
	}
	ifile.close();

	// loading...
	unsigned short int y = 62;

	x = 17; //y = 62;
	// menu chon
	gotoXY(x++, y);
	cout << "Menu";
	gotoXY(x++, y);
	textcolor(30);
	cout << "Start";
	textcolor(12);
	gotoXY(x++, y);
	cout << "Help";
	gotoXY(x++, y);
	cout << "About me";
	gotoXY(x++, y);
	cout << "Exit";
}

void ThongBaoQuanCoWin(const char who)
{
	Sleep(500);
	system("cls");

	ifstream ifile;
	if (who == 'o')
		ifile.open("owin.txt", ios_base::in);
	else if (who == 'x')
		ifile.open("xwin.txt", ios_base::in);
	else
		ifile.open("hoa.txt", ios_base::in);

	if (!ifile) exit(0);

	unsigned short int x = 10;
	string s;
	while (!ifile.eof())
	{
		getline(ifile, s);
		SetColor(1 + rand() % 15);
		gotoXY(x++, 40);
		cout << s << endl;
		Sleep(200);
		s.clear();
	}

	ifile.close();
	Sleep(500);
}

bool Quit_Continue()
{
	ShowCur(0);
	Sleep(100);
	system("cls");
	gotoXY(12, 40);
	cout << "Ban co muon tiep tuc choi";
	gotoXY(14, 42);
	textcolor(30);
	cout << "Continue";
	textcolor(12);
	gotoXY(14, 55);
	cout << "Exit";

	short int luachon = 1;
	short int y = 42;
	char c;
	while (1)
	{
		if (_kbhit())
		{
			c = _getch();
			if (c == 75) // sang trai
			{
				--luachon;
				if (luachon < 1)
					luachon = 2;

				y+=13;
				if (y > 55)
					y = 42;

				textcolor(30);
				if (y == 42)
				{
					gotoXY(14, y);
					cout << "Continue";
					textcolor(12);
					gotoXY(14, 55);
					cout << "Exit";
				}
				else if (y == 55)
				{
					gotoXY(14, y);
					cout << "Exit";
					textcolor(12);
					gotoXY(14, 42);
					cout << "Continue";
				}
			}
			else if (c == 77) // sang phai
			{
				++luachon;
				if (luachon > 2)
					luachon = 1;

				y -= 13;
				if (y < 42)
					y = 55;

				textcolor(30);
				if (y == 42)
				{
					gotoXY(14, y);
					cout << "Continue";
					textcolor(12);
					gotoXY(14, 55);
					cout << "Exit";
				}
				else if (y == 55)
				{
					gotoXY(14, y);
					cout << "Exit";
					textcolor(12);
					gotoXY(14, 42);
					cout << "Continue";
				}
			}
			else if (c == 13)
			{
				if (luachon == 1)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
}

bool check_savegame()
{
	ShowCur(0);
	Sleep(150);
	system("cls");
	gotoXY(12, 40);
	cout << "Ban co muon luu lai game";
	gotoXY(14, 42);
	textcolor(30);
	cout << "Yes";
	textcolor(12);
	gotoXY(14, 55);
	cout << "No";

	short int luachon = 1;
	short int y = 42;
	char c;
	while (1)
	{
		if (_kbhit())
		{
			c = _getch();
			if (c == 75) // sang trai
			{
				--luachon;
				if (luachon < 1)
					luachon = 2;

				y += 13;
				if (y > 55)
					y = 42;

				textcolor(30);
				if (y == 42)
				{
					gotoXY(14, y);
					cout << "Yes";
					textcolor(12);
					gotoXY(14, 55);
					cout << "No";
				}
				else if (y == 55)
				{
					gotoXY(14, y);
					cout << "No";
					textcolor(12);
					gotoXY(14, 42);
					cout << "Yes";
				}
			}
			else if (c == 77) // sang phai
			{
				++luachon;
				if (luachon > 2)
					luachon = 1;

				y -= 13;
				if (y < 42)
					y = 55;

				textcolor(30);
				if (y == 42)
				{
					gotoXY(14, y);
					cout << "Yes";
					textcolor(12);
					gotoXY(14, 55);
					cout << "No";
				}
				else if (y == 55)
				{
					gotoXY(14, y);
					cout << "No";
					textcolor(12);
					gotoXY(14, 42);
					cout << "Yes";
				}
			}
			else if (c == 13)
			{
				if (luachon == 1)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
}

bool check_newgame()
{
	ShowCur(0);
	Sleep(50);
	system("cls");
	gotoXY(12, 40);
	cout << "Ban muon tao game moi hay tai lai ban co da luu";
	gotoXY(14, 42);
	textcolor(30);
	cout << "New Game";
	textcolor(12);
	gotoXY(14, 55);
	cout << "Load Game";

	short int luachon = 1;
	short int y = 42;
	char c;
	while (1)
	{
		if (_kbhit())
		{
			c = _getch();
			if (c == 75) // sang trai
			{
				--luachon;
				if (luachon < 1)
					luachon = 2;

				y += 13;
				if (y > 55)
					y = 42;

				textcolor(30);
				if (y == 42)
				{
					gotoXY(14, y);
					cout << "New Game";
					textcolor(12);
					gotoXY(14, 55);
					cout << "Load Game";
				}
				else if (y == 55)
				{
					gotoXY(14, y);
					cout << "Load Game";
					textcolor(12);
					gotoXY(14, 42);
					cout << "New Game";
				}
			}
			else if (c == 77) // sang phai
			{
				++luachon;
				if (luachon > 2)
					luachon = 1;

				y -= 13;
				if (y < 42)
					y = 55;

				textcolor(30);
				if (y == 42)
				{
					gotoXY(14, y);
					cout << "New Game";
					textcolor(12);
					gotoXY(14, 55);
					cout << "Load Game";
				}
				else if (y == 55)
				{
					gotoXY(14, y);
					cout << "Load Game";
					textcolor(12);
					gotoXY(14, 42);
					cout << "New Game";
				}
			}
			else if (c == 13)
			{
				if (luachon == 1)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
}

bool Chon_XO()
{
	ShowCur(0);
	Sleep(50);
	system("cls");
	gotoXY(12, 40);
	textcolor(10);
	cout << "Ban chon quan co nao";
	gotoXY(14, 42);
	textcolor(400);
	cout << "X";
	textcolor(12);
	gotoXY(14, 55);
	cout << "O";

	short int luachon = 1;
	short int y = 42;
	char c;
	while (1)
	{
		if (_kbhit())
		{
			c = _getch();
			if (c == 75) // sang trai
			{
				--luachon;
				if (luachon < 1)
					luachon = 2;

				y += 13;
				if (y > 55)
					y = 42;

				textcolor(400);
				if (y == 42)
				{
					gotoXY(14, y);
					cout << "X";
					textcolor(12);
					gotoXY(14, 55);
					cout << "O";
				}
				else if (y == 55)
				{
					gotoXY(14, y);
					cout << "O";
					textcolor(12);
					gotoXY(14, 42);
					cout << "X";
				}
			}
			else if (c == 77) // sang phai
			{
				++luachon;
				if (luachon > 2)
					luachon = 1;

				y -= 13;
				if (y < 42)
					y = 55;

				textcolor(30);
				if (y == 42)
				{
					gotoXY(14, y);
					cout << "X";
					textcolor(12);
					gotoXY(14, 55);
					cout << "O";
				}
				else if (y == 55)
				{
					gotoXY(14, y);
					cout << "O";
					textcolor(12);
					gotoXY(14, 42);
					cout << "X";
				}
			}
			else if (c == 13)
			{
				if (luachon == 1)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
}

bool KeyBoardOrMouse()
{
	ShowCur(0);
	Sleep(50);
	system("cls");
	gotoXY(12, 40);
	textcolor(10);
	cout << "Ban chon choi bang chuot hay ban phim";
	gotoXY(14, 42);
	textcolor(400);
	cout << "KeyBoard";
	textcolor(12);
	gotoXY(14, 55);
	cout << "Mouse";

	short int luachon = 1;
	short int y = 42;
	char c;
	while (1)
	{
		if (_kbhit())
		{
			c = _getch();
			if (c == 75) // sang trai
			{
				--luachon;
				if (luachon < 1)
					luachon = 2;

				y += 13;
				if (y > 55)
					y = 42;

				textcolor(400);
				if (y == 42)
				{
					gotoXY(14, y);
					cout << "KeyBoard";
					textcolor(12);
					gotoXY(14, 55);
					cout << "Mouse";
				}
				else if (y == 55)
				{
					gotoXY(14, y);
					cout << "Mouse";
					textcolor(12);
					gotoXY(14, 42);
					cout << "KeyBoard";
				}
			}
			else if (c == 77) // sang phai
			{
				++luachon;
				if (luachon > 2)
					luachon = 1;

				y -= 13;
				if (y < 42)
					y = 55;

				textcolor(30);
				if (y == 42)
				{
					gotoXY(14, y);
					cout << "KeyBoard";
					textcolor(12);
					gotoXY(14, 55);
					cout << "Mouse";
				}
				else if (y == 55)
				{
					gotoXY(14, y);
					cout << "Mouse";
					textcolor(12);
					gotoXY(14, 42);
					cout << "KeyBoard";
				}
			}
			else if (c == 13)
			{
				if (luachon == 1)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
}

bool Undo(stack<Toado>& ud, stack<Toado>& rd, char a[17][17], short int& tongoco)
{
	if (!ud.empty())
	{
		short int u_x = ud.top().x;
		short int u_y = ud.top().y;
		gotoXY(ToaDoX1(u_x), ToaDoY1(u_y));
		cout << " ";
		++tongoco;
		a[u_x][u_y] = ' ';
		rd.push(ud.top());
		ud.pop();
		return true;
	}
	return false;
}

void Redo(char a[17][17], const short int& x, const short int& y, const char& quanco, bool& luotdi, short int& tongoco)
{
	if (a[x][y] == ' ')
	{
		InCo(a, x, y, quanco, luotdi, tongoco);
	}
}

void SaveGame(const char a[17][17], const short int& x, const short int& y, const char& quanco, const bool& luotdi, const short int& tongoco, stack<Toado> ud, stack<Toado> rd)
{
	Sleep(80);
	system("cls");
	ofstream ofile, ofile1;
	string tenfile = "";
	gotoXY(4, 25);
	ShowCur(1);
	cout << "Nhap ten van co can luu lai (ten ko duoc co dau va khoang trang): ";
	cin >> tenfile;

	// lay thoi gian trong may tinh
	time_t t = time(0);
	struct tm localtime;
	localtime_s(&localtime, &t);

	tenfile += "_";
	tenfile += to_string(localtime.tm_mday);
	tenfile += "-";
	tenfile += to_string(localtime.tm_mon + 1);
	tenfile += "-";
	tenfile += to_string(localtime.tm_year + 1900);
	tenfile += "-";
	tenfile += to_string(localtime.tm_hour);
	tenfile += to_string(localtime.tm_min + 1);
	tenfile += to_string(localtime.tm_sec);
	tenfile += ".txt";

	ofile1.open("NameGame.txt", ios_base::app);
	ofile1 << tenfile << endl;
	ofile1.close();

	ofile.open(tenfile, ios_base::out);

	for (unsigned short int i = 0; i < 17; ++i)
	{
		for (unsigned short int j = 0; j < 17; ++j)
		{
			if (a[i][j] == ' ')
				ofile << '?';
			else 
				ofile << a[i][j];
		}
	}
	ofile << "\n";

	ofile << x << " " << y << "\n";

	ofile << quanco << "\n";
	ofile << luotdi << "\n";
	ofile << tongoco << "\n";

	stack<Toado> st;
	Toado td;

	ofile << ud.size() << endl;
	while (!ud.empty())
	{
		td.data = ud.top().data;
		td.x = ud.top().x;
		td.y = ud.top().y;

		st.push(td);
		ud.pop();
	}
	while (!st.empty())
	{
		ofile << st.top().data << " ";
		ofile << st.top().x << " " << st.top().y << "\n";
		st.pop();
	}

	ofile << rd.size() << "\n";
	while (!rd.empty())
	{
		td.data = rd.top().data;
		td.x = rd.top().x;
		td.y = rd.top().y;

		st.push(td);
		rd.pop();
	}
	while (!st.empty())
	{
		ofile << st.top().data << " ";
		ofile << st.top().x << " " << st.top().y << "\n";
		st.pop();
	}

	ofile.close();
}

bool LoadGame(char a[17][17], short int& x, short int& y, char& quanco, bool& luotdi, short int& tongoco, stack<Toado>& ud, stack<Toado>& rd, bool& checkquit)
{
	Sleep(50);
	system("cls");

	vector<string>vt;
	short int dem = 0;
	ifstream ifile, ifile1;
	ifile1.open("NameGame.txt", ios_base::in);
	if (!ifile1)
	{
		checkquit = false;
		return false;
	}

	string s;
	while (!ifile1.eof())
	{
		getline(ifile1, s);
		vt.push_back(s);
	}
	ifile1.close();

	dem = vt.size();
	if (dem == 0) return false;

	vv:
	short int x1 = 6, y1 = 25;
	gotoXY(2, y1 + 3);
	textcolor(30);
	cout << "<- Back";
	gotoXY(4, y1);
	textcolor(11);
	cout << "Chon file game ban da luu";
	textcolor(30);
	for (unsigned short int i = 0; i < dem; ++i)
	{
		gotoXY(x1++, y1);
		if (i > 0) textcolor(12);
		cout << vt[i];
	}

	short int luachon = 0;
	char c;
	while (1)
	{
		if (_kbhit())
		{
			c = _getch();
			x1 = 6, y1 = 25;
			if (c == 72) // len tren
			{
				--luachon;
				if (luachon < 0)
					luachon = dem - 1;

				for (unsigned short int i = 0; i < dem; ++i)
				{
					gotoXY(x1++, y1);
					if (i == luachon) textcolor(30);
					else textcolor(12);
					cout << vt[i];
				}
			}
			else if (c == 80) // xuong duoi
			{
				++luachon;
				if (luachon >= dem)
					luachon = 0;

				for (unsigned short int i = 0; i < dem; ++i)
				{
					gotoXY(x1++, y1);
					if (i == luachon) textcolor(30);
					else textcolor(12);
					cout << vt[i];
				}
			}
			else if (c == 13)
			{
				ifile.open(vt[luachon], ios_base::in);
				if (!ifile)
				{
					Sleep(20);
					system("cls");
					gotoXY(10, 30);
					textcolor(14);
					cout << "File nay khong con ton tai, vui long chon file khac";
					Sleep(150);
					gotoXY(10, 30);
					cout << "                                                   ";
					goto vv;
				}

				char e;
				for (unsigned short int i = 0; i < 17; ++i)
				{
					for (unsigned short int j = 0; j < 17; ++j)
					{
						ifile >> e;
						if (e == '?')
							a[i][j] = ' ';
						else if (e == 'X')
							a[i][j] = 'X';
						else
							a[i][j] = 'O';
					}
				}

				ifile >> x >> y;
				ifile >> quanco >> luotdi >> tongoco;

				short int dem_ur;
				ifile >> dem_ur;
				Toado td;
				for (unsigned short int i = 1; i <= dem_ur; ++i)
				{
					ifile >> td.data >> td.x >> td.y;
					ud.push(td);
				}

				ifile >> dem_ur;
				for (unsigned short int i = 1; i <= dem_ur; ++i)
				{
					ifile >> td.data >> td.x >> td.y;
					rd.push(td);
				}
				ifile.close();
				return true;
			}
			else if (c == 8)
			{
				checkquit = true;
				return false;
			}
		}
	}
}

void ChuyenDoiToaDo(short int& x1, short int& y1, short int& x, short int& y)
{
	x = x1 / 2;
	if (y1 % 2 == 0)
	{
		for (unsigned short int i = 0; i <= 16; ++i)
		{
			if (4 * i + 2 == y1)
			{
				y = i;
				break;
			}
		}
	}
	else
	{
		y = y1 / 4;
	}
}

void Playgame(const short int& row, const short int& col, const bool& chonquanco)
{
//ll:
	short int tongoco = row * col;
	short int x = 8, y = 8;
	bool luotdi;
	if (chonquanco)
		luotdi = 1;
	else
		luotdi = 0;

	char quanco;
	char a[17][17];
	memset(a, ' ', sizeof(a)); // lap day mang bang ' '
	short int toadothang[10];
	stack<Toado> ud, rd;
	

	ShowCur(0);
	BanCo_1(row, col, 3);
	BangThongBao_1(row, col, 119);
	NutNhan(row, col);
	while (true)
	{
		quanco = luotdi == 1 ? 'X' : 'O';
	aa:
		ShowCur(1);
		gotoXY(13, 97);
		if (quanco == 'X')
		{
			textcolor(14);
			cout << "Dung phim a,s,w,d de chon vi ";
			gotoXY(14, 97);
			cout << "tri cho " << quanco;
			gotoXY(16, 97);
			cout << "Nhan phim Backspace: OK";
			gotoXY(19, 97);
			cout << "Nhan phim ESC de thoat game";
			gotoXY(21, 97);
			cout << "U: Undo / R: Redo / Ctrl+S: Save";
		}
		else
		{
			textcolor(14);
			cout << "Dung phim mui ten de chon ";
			gotoXY(14, 97);
			cout << "vi tri cho " << quanco;
			gotoXY(16, 97);
			cout << "Nhan phim Enter: OK";
			gotoXY(19, 97);
			cout << "Nhan phim ESC de thoat game";
			gotoXY(21, 97);
			cout << "U: Undo / R: Redo / Ctrl+S: Save";
		}

		short int x1, y1;
		// xu ly toa do x y  de gotoXY den vi tri x1 y1 dung
		x1 = ToaDoX1(x);
		y1 = ToaDoY1(y);
		gotoXY(x1, y1);

		char c;
		while (true)
		{
			if (_kbhit())
			{
				if (quanco == 'O')
				{
					c = _getch();
					if (c == 75) // sang trai
					{
						if (y > 0)
							--y;
						y1 = ToaDoY1(y);
						gotoXY(x1, y1);
					}
					else if (c == 77) // sang phai
					{
						if (y < 16)
							++y;
						y1 = ToaDoY1(y);
						gotoXY(x1, y1);
					}
					else if (c == 72) // len tren
					{
						if (x > 0)
							--x;
						x1 = ToaDoX1(x);
						gotoXY(x1, y1);
					}
					else if (c == 80) // xuong duoi
					{
						if (x < 16)
							++x;
						x1 = ToaDoX1(x);
						gotoXY(x1, y1);
					}
					else if (c == 13) // enter
					{
						if (a[x][y] == ' ')
						{
							InCo(a, x, y, quanco, luotdi, tongoco);
							Toado td;
							td.x = x;
							td.y = y;
							td.data = 'O';
							ud.push(td);

							if (CheckWin(a, x, y, quanco, toadothang))
							{
								gotoXY(17, 109);
								cout << "O win";
								gotoXY(13, 97);
								cout << "                               ";
								gotoXY(14, 97);
								cout << "            ";
								gotoXY(16, 97);
								cout << "                       ";
								gotoXY(19, 97);
								cout << "                           ";
								gotoXY(20, 97);
								cout << "                   ";
								gotoXY(21, 97);
								cout << "                                ";
								NhapNhayQuanCo(a, toadothang);
								ThongBaoQuanCoWin('o');
								bool quit = Quit_Continue();
								if (quit)
								{
									system("cls");
									//Menugame(row, col);
									bool check_xo = Chon_XO();
									XoaManHinh();
									Playgame(row, col, check_xo);
								}
								else
								{
									system("cls");
									Sleep(500);
									//textcolor(7);
									//exit(0);
									Menugame(row, col);
								}
							}
							else
								if (tongoco == 0)
								{
									gotoXY(17, 109);
									cout << "Hoa";
									gotoXY(13, 97);
									cout << "                              ";
									gotoXY(16, 97);
									cout << "            ";
									gotoXY(19, 97);
									cout << "                           ";
									gotoXY(21, 97);
									cout << "                                ";
									ThongBaoQuanCoWin('h');
									bool quit = Quit_Continue();
									if (quit)
									{
										system("cls");
										//Menugame(row, col);
										bool check_xo = Chon_XO();
										XoaManHinh();
										Playgame(row, col, check_xo);
									}
									else
									{
										system("cls");
										Sleep(500);
										//textcolor(7);
										//exit(0);
										Menugame(row, col);
									}
								}

							gotoXY(13, 97);
							cout << "                              ";
							gotoXY(14, 97);
							cout << "             ";
							gotoXY(16, 97);
							cout << "                        ";
							gotoXY(20, 97);
							cout << "                   ";
							break;
						}
						else
						{
							textcolor(12);
							gotoXY(20, 97);
							cout << "Vi tri da duoc di!!";
							goto aa;
						}
					}
					else if (c == 27)
					{
						NutNhan4(17, 17, 2);
						Sleep(10);
						system("cls");
						bool check = Quit_Continue();
						if (check)
						{
							system("cls");
							BanCo_2(row, col, 3, a);
							BangThongBao(row, col, 119);
							NutNhan(17, 17);
							goto aa;
						}
						else
						{
							Sleep(100);
							system("cls");
							//textcolor(15);
							//exit(0);
							Menugame(row, col);
						}
					}
					else if (c == 117)
					{
						NutNhan1(17, 17, 2);
						Sleep(10);
						if (Undo(ud, rd, a, tongoco))
						{
							luotdi = luotdi == true ? false : true;
							gotoXY(13, 97);
							cout << "                              ";
							gotoXY(14, 97);
							cout << "             ";
							gotoXY(16, 97);
							cout << "                       ";
							x = rd.top().x;
							y = rd.top().y;
							NutNhan1(17, 17);
							break;
						}
						else
						{
							NutNhan1(17, 17);
							goto aa;
						}
					}
					else if (c == 114)
					{
						NutNhan2(17, 17, 2);
						Sleep(10);
						if (!rd.empty())
						{
							short int r_x = rd.top().x;
							short int r_y = rd.top().y;
							char r_d = rd.top().data;
							Redo(a, r_x, r_y, quanco, luotdi, tongoco);
							ud.push(rd.top());
							rd.pop();
							x = ud.top().x;
							y = ud.top().y;
							gotoXY(13, 97);
							cout << "                              ";
							gotoXY(14, 97);
							cout << "             ";
							gotoXY(16, 97);
							cout << "                       ";
							NutNhan2(17, 17);
							break;
						}
						else
						{
							NutNhan2(17, 17);
							goto aa;
						}
					}
					else if (c == 19)
					{
						NutNhan3(17, 17, 2);
						Sleep(10);
						system("cls");
						if (check_savegame())
						{
							SaveGame(a, x, y, 'O', luotdi, tongoco, ud, rd);
							system("cls");
							if (Quit_Continue())
							{
								system("cls");
								BanCo_2(row, col, 3, a);
								BangThongBao(row, col, 119);
								NutNhan(17, 17);
								goto aa;
							}
							else
							{
								Sleep(100);
								system("cls");
								//textcolor(15);
								//exit(0);
								Menugame(row, col);
							}
						}
						else
						{
							system("cls");
							BanCo_2(row, col, 3, a);
							BangThongBao(row, col, 119);
							NutNhan(17, 17);
							goto aa;
						}
					}
				}
				else
				{
					c = _getch();
					if (c == 97)
					{
						if (y > 0)
							--y;
						y1 = ToaDoY1(y);
						gotoXY(x1, y1);
					}
					else if (c == 100)
					{
						if (y < 16)
							++y;
						y1 = ToaDoY1(y);
						gotoXY(x1, y1);
					}
					else if (c == 119)
					{
						if (x > 0)
							--x;
						x1 = ToaDoX1(x);
						gotoXY(x1, y1);
					}
					else if (c == 115)
					{
						if (x < 16)
							++x;
						x1 = ToaDoX1(x);
						gotoXY(x1, y1);
					}
					else if (c == 32)
					{
						if (a[x][y] == ' ')
						{
							InCo(a, x, y, quanco, luotdi, tongoco);
							Toado td;
							td.x = x;
							td.y = y;
							td.data = 'X';
							ud.push(td);

							if (CheckWin(a, x, y, quanco, toadothang))
							{
								gotoXY(17, 109);
								cout << "X win";
								gotoXY(13, 97);
								cout << "                               ";
								gotoXY(14, 97);
								cout << "            ";
								gotoXY(16, 97);
								cout << "                       ";
								gotoXY(19, 97);
								cout << "                           ";
								gotoXY(20, 97);
								cout << "                   ";
								gotoXY(21, 97);
								cout << "                                ";
								NhapNhayQuanCo(a, toadothang);
								ThongBaoQuanCoWin('x');
								bool quit = Quit_Continue();
								if (quit)
								{
									system("cls");
									//Menugame(row, col);
									bool check_xo = Chon_XO();
									XoaManHinh();
									Playgame(row, col, check_xo);
								}
								else
								{
									system("cls");
									Sleep(500);
									//textcolor(7);
									//exit(0);
									Menugame(row, col);
								}
							}
							else
								if (tongoco == 0)
								{
									gotoXY(17, 109);
									cout << "Hoa";
									gotoXY(13, 97);
									cout << "                              ";
									gotoXY(16, 97);
									cout << "            ";
									gotoXY(19, 97);
									cout << "                           ";
									gotoXY(21, 97);
									cout << "                                ";
									ThongBaoQuanCoWin('h');
									bool quit = Quit_Continue();
									if (quit)
									{
										system("cls");
										//Menugame(row, col);
										bool check_xo = Chon_XO();
										XoaManHinh();
										Playgame(row, col, check_xo);
									}
									else
									{
										system("cls");
										Sleep(500);
										//textcolor(7);
										//exit(0);
										Menugame(row, col);
									}
								}

							gotoXY(16, 97);
							cout << "                        ";
							gotoXY(20, 97);
							cout << "                   ";
							break;
						}
						else
						{
							textcolor(12);
							gotoXY(20, 97);
							cout << "Vi tri da duoc di!!";
							goto aa;
						}
					}
					else if (c == 27)
					{
						NutNhan4(17, 17, 2);
						Sleep(10);
						system("cls");
						bool check = Quit_Continue();
						if (check)
						{
							system("cls");
							BanCo_2(row, col, 3, a);
							BangThongBao(row, col, 119);
							NutNhan(17, 17);
							goto aa;
						}
						else
						{
							Sleep(100);
							system("cls");
							//textcolor(15);
							//exit(0);
							Menugame(row, col);
						}
					}
					else if (c == 117)
					{
						NutNhan1(17, 17, 2);
						Sleep(10);
						if (Undo(ud, rd, a, tongoco))
						{
							luotdi = luotdi == true ? false : true;
							gotoXY(13, 97);
							cout << "                              ";
							gotoXY(14, 97);
							cout << "             ";
							gotoXY(16, 97);
							cout << "                       ";
							x = rd.top().x;
							y = rd.top().y;
							NutNhan1(17, 17);
							break;
						}
						else
						{
							NutNhan1(17, 17);
							goto aa;
						}
					}
					else if (c == 114)
					{
						NutNhan2(17, 17, 2);
						Sleep(10);
						if (!rd.empty())
						{
							short int r_x = rd.top().x;
							short int r_y = rd.top().y;
							char r_d = rd.top().data;
							Redo(a, r_x, r_y, quanco, luotdi, tongoco);
							ud.push(rd.top());
							rd.pop();
							gotoXY(13, 97);
							cout << "                              ";
							gotoXY(14, 97);
							cout << "             ";
							gotoXY(16, 97);
							cout << "                       ";
							x = ud.top().x;
							y = ud.top().y;
							NutNhan2(17, 17);
							break;
						}
						else
						{
							NutNhan2(17, 17);
							goto aa;
						}
					}
					else if (c == 19)
					{
						NutNhan3(17, 17, 2);
						Sleep(10);
						system("cls");
						if (check_savegame())
						{
							SaveGame(a, x, y, 'X', luotdi, tongoco, ud, rd);
							system("cls");
							if (Quit_Continue())
							{
								system("cls");
								BanCo_2(row, col, 3, a);
								BangThongBao(row, col, 119);
								NutNhan(17, 17);
								goto aa;
							}
							else
							{
								Sleep(100);
								system("cls");
								//textcolor(15);
								//exit(0);
								Menugame(row, col);
							}
						}
						else
						{
							system("cls");
							BanCo_2(row, col, 3, a);
							BangThongBao(row, col, 119);
							NutNhan(17, 17);
							goto aa;
						}
					}
				}
			}
		}
	}
}

void Playgame2(const short int& row, const short int& col, const bool& chonquanco)
{
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD InputRecord, irInBuf[128];
	DWORD Events, fdwMode, cNumRead, i;

	fdwMode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(hin, fdwMode))
		ErrorExit("SetConsoleMode");

	// Get the standard input handle.
	hStdin = GetStdHandle(STD_INPUT_HANDLE);

	// Enable the window and mouse input events.
	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdin, fdwMode))
		ErrorExit("SetConsoleMode");

	//ll:
	short int tongoco = row * col;
	short int x = 8, y = 8;
	bool luotdi;
	if (chonquanco)
		luotdi = 1;
	else
		luotdi = 0;

	char quanco;
	char a[17][17];
	memset(a, ' ', sizeof(a)); // lap day mang bang ' '
	short int toadothang[10];
	stack<Toado> ud, rd;

	ShowCur(0);
	BanCo_1(row, col, 3);
	BangThongBao_1(row, col, 119);
	NutNhan(row, col);
	while (true)
	{
		quanco = luotdi == 1 ? 'X' : 'O';
	aa:

		fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
		if (!SetConsoleMode(hin, fdwMode))
			ErrorExit("SetConsoleMode");

		//ShowCur(1);
		gotoXY(13, 97);
		if (quanco == 'X')
		{
			textcolor(14);
			cout << "Click chuot trai de chon vi ";
			gotoXY(14, 97);
			cout << "tri cho " << quanco;
			gotoXY(19, 97);
			cout << "Click Exit de thoat game";
		}
		else
		{
			textcolor(14);
			cout << "Click chuot trai de chon vi ";
			gotoXY(14, 97);
			cout << "tri cho " << quanco;
			gotoXY(19, 97);
			cout << "Click Exit de thoat game";
		}

		short int x1, y1;
		// xu ly toa do x y  de gotoXY den vi tri x1 y1 dung
		//x1 = ToaDoX1(x);
		//y1 = ToaDoY1(y);
		//gotoXY(x1, y1);

		char c;

		// Wait for the events.
		if (!ReadConsoleInput(
			hStdin,      // input buffer handle
			irInBuf,     // buffer to read into
			128,         // size of read buffer
			&cNumRead)) // number of records read
			ErrorExit("ReadConsoleInput");

		for (i = 0; i < cNumRead; ++i)
		{
			switch (irInBuf[i].EventType)
			{
			case MOUSE_EVENT: // mouse input
				if (irInBuf[i].Event.MouseEvent.dwEventFlags == 0)
				{
					if (irInBuf[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
					{
						if (quanco == 'O')
						{
							y1 = irInBuf[i].Event.MouseEvent.dwMousePosition.X;
							x1 = irInBuf[i].Event.MouseEvent.dwMousePosition.Y;
							if (x1 >= 0 && x1 <= 34 && y1 >= 0 && y1 <= 68 && x1 % 2 != 0 && y1 % 4 != 0)
							{
								ChuyenDoiToaDo(x1, y1, x, y);
								if (a[x][y] == ' ')
								{
									InCo(a, x, y, quanco, luotdi, tongoco);
									Toado td;
									td.x = x;
									td.y = y;
									td.data = 'O';
									ud.push(td);

									if (CheckWin(a, x, y, quanco, toadothang))
									{
										gotoXY(17, 109);
										cout << "O win";
										gotoXY(13, 97);
										cout << "                               ";
										gotoXY(14, 97);
										cout << "            ";
										//gotoXY(16, 97);
										//cout << "                       ";
										gotoXY(19, 97);
										cout << "                            ";
										gotoXY(20, 97);
										cout << "                   ";
										/*gotoXY(21, 97);
										cout << "                                ";*/
										NhapNhayQuanCo(a, toadothang);
										ThongBaoQuanCoWin('o');
										bool quit = Quit_Continue();
										if (quit)
										{
											system("cls");
											//Menugame(row, col);
											bool check_xo = Chon_XO();
											XoaManHinh();
											Playgame2(row, col, check_xo);
										}
										else
										{
											system("cls");
											Sleep(500);
											//textcolor(7);
											//exit(0);
											Menugame(row, col);
										}
									}
									else
										if (tongoco == 0)
										{
											gotoXY(17, 109);
											cout << "Hoa";
											gotoXY(13, 97);
											cout << "                              ";
											//gotoXY(16, 97);
											//cout << "            ";
											gotoXY(19, 97);
											cout << "                            ";
											/*gotoXY(21, 97);
											cout << "                                ";*/
											ThongBaoQuanCoWin('h');
											bool quit = Quit_Continue();
											if (quit)
											{
												system("cls");
												//Menugame(row, col);
												bool check_xo = Chon_XO();
												XoaManHinh();
												Playgame2(row, col, check_xo);
											}
											else
											{
												system("cls");
												Sleep(500);
												//textcolor(7);
												//exit(0);
												Menugame(row, col);
											}
										}

									gotoXY(13, 97);
									cout << "                              ";
									gotoXY(14, 97);
									cout << "             ";
									//gotoXY(16, 97);
									//cout << "                        ";
									gotoXY(20, 97);
									cout << "                   ";
									break;
								}
								else
								{
									textcolor(12);
									gotoXY(20, 97);
									cout << "Vi tri da duoc di!!";
									goto aa;
								}
							}
							else if ((x >= 1 && x <= 3) && (y >= 87 && y <= 96))
							{
								NutNhan1(17, 17, 2);
								if (Undo(ud, rd, a, tongoco))
								{
									luotdi = luotdi == true ? false : true;
									gotoXY(13, 97);
									cout << "                              ";
									gotoXY(14, 97);
									cout << "             ";
									//gotoXY(16, 97);
									//cout << "                       ";
									x = rd.top().x;
									y = rd.top().y;
									Sleep(10);
									NutNhan1(17, 17);
									break;
								}
								else
								{
									Sleep(10);
									NutNhan1(17, 17);
									goto aa;
								}
							}
							else if ((x >= 5 && x <= 7) && (y >= 87 && y <= 96))
							{
								NutNhan2(17, 17, 2);
								if (!rd.empty())
								{
									short int r_x = rd.top().x;
									short int r_y = rd.top().y;
									char r_d = rd.top().data;
									Redo(a, r_x, r_y, quanco, luotdi, tongoco);
									ud.push(rd.top());
									rd.pop();
									x = ud.top().x;
									y = ud.top().y;
									gotoXY(13, 97);
									cout << "                              ";
									gotoXY(14, 97);
									cout << "             ";
									//gotoXY(16, 97);
									//cout << "                       ";
									Sleep(10);
									NutNhan2(17, 17);
									break;
								}
								else
								{
									Sleep(10);
									NutNhan2(17, 17);
									goto aa;
								}
							}
							else if ((x >= 26 && x <= 28) && (y >= 87 && y <= 96))
							{
								NutNhan3(17, 17, 2);
								Sleep(10);
								system("cls");
								if (check_savegame())
								{
									SaveGame(a, x, y, 'O', luotdi, tongoco, ud, rd);
									system("cls");
									if (Quit_Continue())
									{
										system("cls");
										BanCo_2(row, col, 3, a);
										BangThongBao(row, col, 119);
										NutNhan(row, col);
										goto aa;
									}
									else
									{
										Sleep(100);
										system("cls");
										Menugame(row, col);
									}
								}
								else
								{
									Sleep(100);
									system("cls");
									//textcolor(15);
									//exit(0);
									bool check = Quit_Continue();
									if (check)
									{
										system("cls");
										BanCo_2(row, col, 3, a);
										BangThongBao(row, col, 119);
										NutNhan(row, col);
										goto aa;
									}
									else
									{
										Sleep(100);
										system("cls");
										//textcolor(15);
										//exit(0);
										Menugame(row, col);
									}
								}
							}
							else if ((x >= 31 && x <= 33) && (y >= 87 && y <= 96))
							{
								NutNhan4(17, 17, 2);
								Sleep(10);
								system("cls");
								bool check = Quit_Continue();
								if (check)
								{
									system("cls");
									BanCo_2(row, col, 3, a);
									BangThongBao(row, col, 119);
									NutNhan(row, col);
									goto aa;
								}
								else
								{
									Sleep(100);
									system("cls");
									//textcolor(15);
									//exit(0);
									Menugame(row, col);
								}
							}
							else
							{
								textcolor(12);
								gotoXY(20, 97);
								cout << "Vi tri khong hop le";
								//cout << "x = " << x1 << "  y = " << y1;
								goto aa;
							}
						}
						else if (quanco == 'X')
						{
							y1 = irInBuf[i].Event.MouseEvent.dwMousePosition.X;
							x1 = irInBuf[i].Event.MouseEvent.dwMousePosition.Y;
							if (x1 >= 0 && x1 <= 34 && y1 >= 0 && y1 <= 68 && x1 % 2 != 0 && y1 % 4 != 0)
							{
								ChuyenDoiToaDo(x1, y1, x, y);
								if (a[x][y] == ' ')
								{
									InCo(a, x, y, quanco, luotdi, tongoco);
									Toado td;
									td.x = x;
									td.y = y;
									td.data = 'X';
									ud.push(td);

									if (CheckWin(a, x, y, quanco, toadothang))
									{
										gotoXY(17, 109);
										cout << "X win";
										gotoXY(13, 97);
										cout << "                               ";
										gotoXY(14, 97);
										cout << "            ";
										//gotoXY(16, 97);
										//cout << "                       ";
										gotoXY(19, 97);
										cout << "                            ";
										gotoXY(20, 97);
										cout << "                   ";
										/*gotoXY(21, 97);
										cout << "                                ";*/
										NhapNhayQuanCo(a, toadothang);
										ThongBaoQuanCoWin('x');
										bool quit = Quit_Continue();
										if (quit)
										{
											system("cls");
											//Menugame(row, col);
											bool check_xo = Chon_XO();
											XoaManHinh();
											Playgame2(row, col, check_xo);
										}
										else
										{
											system("cls");
											Sleep(500);
											//textcolor(7);
											//exit(0);
											Menugame(row, col);
										}
									}
									else
										if (tongoco == 0)
										{
											gotoXY(17, 109);
											cout << "Hoa";
											gotoXY(13, 97);
											cout << "                              ";
											//gotoXY(16, 97);
											//cout << "            ";
											gotoXY(19, 97);
											cout << "                            ";
											/*gotoXY(21, 97);
											cout << "                                ";*/
											ThongBaoQuanCoWin('h');
											bool quit = Quit_Continue();
											if (quit)
											{
												system("cls");
												//Menugame(row, col);
												bool check_xo = Chon_XO();
												XoaManHinh();
												Playgame2(row, col, check_xo);
											}
											else
											{
												system("cls");
												Sleep(500);
												//textcolor(7);
												//exit(0);
												Menugame(row, col);
											}
										}

									//gotoXY(16, 97);
									//cout << "                        ";
									gotoXY(20, 97);
									cout << "                   ";
									break;
								}
								else
								{
									textcolor(12);
									gotoXY(20, 97);
									cout << "Vi tri da duoc di!!";
									goto aa;
								}
							}
							else if ((x >= 1 && x <= 3) && (y >= 87 && y <= 96))
							{
								NutNhan1(17, 17, 2);
								if (Undo(ud, rd, a, tongoco))
								{
									luotdi = luotdi == true ? false : true;
									gotoXY(13, 97);
									cout << "                              ";
									gotoXY(14, 97);
									cout << "             ";
									//gotoXY(16, 97);
									//cout << "                       ";
									x = rd.top().x;
									y = rd.top().y;
									Sleep(10);
									NutNhan1(17, 17);
									break;
								}
								else
								{
									Sleep(10);
									NutNhan1(17, 17);
									goto aa;
								}
							}
							else if ((x >= 5 && x <= 7) && (y >= 87 && y <= 96))
							{
								NutNhan2(17, 17, 2);
								if (!rd.empty())
								{
									short int r_x = rd.top().x;
									short int r_y = rd.top().y;
									char r_d = rd.top().data;
									Redo(a, r_x, r_y, quanco, luotdi, tongoco);
									ud.push(rd.top());
									rd.pop();
									x = ud.top().x;
									y = ud.top().y;
									gotoXY(13, 97);
									cout << "                              ";
									gotoXY(14, 97);
									cout << "             ";
									//gotoXY(16, 97);
									//cout << "                       ";
									Sleep(10);
									NutNhan2(17, 17);
									break;
								}
								else
								{
									Sleep(10);
									NutNhan2(17, 17);
									goto aa;
								}
							}
							else if ((x >= 26 && x <= 28) && (y >= 87 && y <= 96))
							{
								NutNhan3(17, 17, 2);
								Sleep(10);
								system("cls");
								if (check_savegame())
								{
									SaveGame(a, x, y, 'O', luotdi, tongoco, ud, rd);
									system("cls");
									if (Quit_Continue())
									{
										system("cls");
										BanCo_2(row, col, 3, a);
										BangThongBao(row, col, 119);
										NutNhan(row, col);
										goto aa;
									}
									else
									{
										Sleep(100);
										system("cls");
										Menugame(row, col);
									}
								}
								else
								{
									Sleep(100);
									system("cls");
									//textcolor(15);
									//exit(0);
									bool check = Quit_Continue();
									if (check)
									{
										system("cls");
										BanCo_2(row, col, 3, a);
										BangThongBao(row, col, 119);
										NutNhan(row, col);
										goto aa;
									}
									else
									{
										Sleep(100);
										system("cls");
										//textcolor(15);
										//exit(0);
										Menugame(row, col);
									}
								}
							}
							else if ((x >= 31 && x <= 33) && (y >= 87 && y <= 96))
							{
								system("cls");
								bool check = Quit_Continue();
								if (check)
								{
									system("cls");
									BanCo_2(row, col, 3, a);
									BangThongBao(row, col, 119);
									NutNhan(row, col);
									goto aa;
								}
								else
								{
									Sleep(100);
									system("cls");
									//textcolor(15);
									//exit(0);
									Menugame(row, col);
								}
							}
							else
							{
								textcolor(12);
								gotoXY(20, 97);
								cout << "Vi tri khong hop le";
								//cout << "x = " << x1 << "  y = " << y1;
								goto aa;
							}
						}
					}
				}
				else if (irInBuf[i].Event.MouseEvent.dwEventFlags == MOUSE_MOVED)
				{
					y = irInBuf[i].Event.MouseEvent.dwMousePosition.X;
					x = irInBuf[i].Event.MouseEvent.dwMousePosition.Y;

					if ((x >= 1 && x <= 3) && (y >= 87 && y <= 96))
						NutNhan1(17, 17, 1);
					else if ((x >= 5 && x <= 7) && (y >= 87 && y <= 96))
						NutNhan2(17, 17, 1);
					else if ((x >= 26 && x <= 28) && (y >= 87 && y <= 96))
						NutNhan3(17, 17, 1);
					else if ((x >= 31 && x <= 33) && (y >= 87 && y <= 96))
						NutNhan4(17, 17, 1);
					else
					{
						NutNhan1(17, 17);
						NutNhan2(17, 17);
						NutNhan3(17, 17);
						NutNhan4(17, 17);
					}
				}
			}
		}
	}
}

void Playgame1(const short int& row, const short int& col)
{
	short int tongoco;
	short int x, y;
	bool luotdi;
	char quanco;
	char a[17][17];
	short int toadothang[10];
	stack<Toado> ud, rd;
	bool checkquit;
	bool checkloadgame = LoadGame(a, x, y, quanco, luotdi, tongoco, ud, rd, checkquit);
	if (!checkloadgame) {
		Sleep(50);
		system("cls");
		gotoXY(10, 40);
		if (!checkquit)
			cout << "Khong co file game nao duoc luu";
		else
			cout << "Dang quay tro lai menu chinh";
		Sleep(800);
		system("cls");
		Menugame(row, col);
	}

	ShowCur(0);
	system("cls");
	Introbanco1(row, col);
	gotoXY(15, 97);
	cout << "                      ";
	gotoXY(17, 97);
	cout << "                   ";
	gotoXY(19, 97);
	cout << "                                ";
	XoaManHinh();
	BanCo_2(row, col, 3, a);
	BangThongBao_1(17, 17, 119);
	NutNhan(row, col);
	while (true)
	{
		quanco = luotdi == 1 ? 'X' : 'O';
	aa:
		ShowCur(1);
		gotoXY(13, 97);
		if (quanco == 'X')
		{
			textcolor(14);
			cout << "Dung phim a,s,w,d de chon vi ";
			gotoXY(14, 97);
			cout << "tri cho " << quanco;
			gotoXY(16, 97);
			cout << "Nhan phim Backspace: OK";
			gotoXY(19, 97);
			cout << "Nhan phim ESC de thoat game";
			gotoXY(21, 97);
			cout << "U: Undo / R: Redo / Ctrl+S: Save";
		}
		else
		{
			textcolor(14);
			cout << "Dung phim mui ten de chon ";
			gotoXY(14, 97);
			cout << "vi tri cho " << quanco;
			gotoXY(16, 97);
			cout << "Nhan phim Enter: OK";
			gotoXY(19, 97);
			cout << "Nhan phim ESC de thoat game";
			gotoXY(21, 97);
			cout << "U: Undo / R: Redo / Ctrl+S: Save";
		}

		short int x1, y1;
		// xu ly toa do x y  de gotoXY den vi tri x1 y1 dung
		x1 = ToaDoX1(x);
		y1 = ToaDoY1(y);
		gotoXY(x1, y1);

		char c;
		while (true)
		{
			if (_kbhit())
			{
				if (quanco == 'O')
				{
					c = _getch();
					if (c == 75) // sang trai
					{
						if (y > 0)
							--y;
						y1 = ToaDoY1(y);
						gotoXY(x1, y1);
					}
					else if (c == 77) // sang phai
					{
						if (y < 16)
							++y;
						y1 = ToaDoY1(y);
						gotoXY(x1, y1);
					}
					else if (c == 72) // len tren
					{
						if (x > 0)
							--x;
						x1 = ToaDoX1(x);
						gotoXY(x1, y1);
					}
					else if (c == 80) // xuong duoi
					{
						if (x < 16)
							++x;
						x1 = ToaDoX1(x);
						gotoXY(x1, y1);
					}
					else if (c == 13) // enter
					{
						if (a[x][y] == ' ')
						{
							InCo(a, x, y, quanco, luotdi, tongoco);
							Toado td;
							td.x = x;
							td.y = y;
							td.data = 'O';
							ud.push(td);

							if (CheckWin(a, x, y, quanco, toadothang))
							{
								gotoXY(17, 109);
								cout << "O win";
								gotoXY(13, 97);
								cout << "                               ";
								gotoXY(14, 97);
								cout << "            ";
								gotoXY(16, 97);
								cout << "                       ";
								gotoXY(19, 97);
								cout << "                            ";
								gotoXY(20, 97);
								cout << "                   ";
								gotoXY(21, 97);
								cout << "                                ";
								NhapNhayQuanCo(a, toadothang);
								ThongBaoQuanCoWin('o');
								bool quit = Quit_Continue();
								if (quit)
								{
									system("cls");
									//Menugame(row, col);
									bool check_xo = Chon_XO();
									XoaManHinh();
									Playgame(row, col, check_xo);
								}
								else
								{
									system("cls");
									Sleep(500);
									//textcolor(7);
									//exit(0);
									Menugame(row, col);
								}
							}
							else
								if (tongoco == 0)
								{
									gotoXY(17, 109);
									cout << "Hoa";
									gotoXY(13, 97);
									cout << "                              ";
									gotoXY(16, 97);
									cout << "            ";
									gotoXY(19, 97);
									cout << "                           ";
									gotoXY(21, 97);
									cout << "                                ";
									ThongBaoQuanCoWin('h');
									bool quit = Quit_Continue();
									if (quit)
									{
										system("cls");
										//Menugame(row, col);
										bool check_xo = Chon_XO();
										XoaManHinh();
										Playgame(row, col, check_xo);
									}
									else
									{
										system("cls");
										Sleep(500);
										//textcolor(7);
										//exit(0);
										Menugame(row, col);
									}
								}

							gotoXY(13, 97);
							cout << "                              ";
							gotoXY(14, 97);
							cout << "             ";
							gotoXY(16, 97);
							cout << "                        ";
							gotoXY(20, 97);
							cout << "                   ";
							break;
						}
						else
						{
							textcolor(12);
							gotoXY(20, 97);
							cout << "Vi tri da duoc di!!";
							goto aa;
						}
					}
					else if (c == 27)
					{
						NutNhan4(17, 17, 2);
						Sleep(10);
						system("cls");
						bool check = Quit_Continue();
						if (check)
						{
							system("cls");
							BanCo_2(row, col, 3, a);
							BangThongBao(row, col, 119);
							NutNhan(17, 17);
							goto aa;
						}
						else
						{
							Sleep(100);
							system("cls");
							//textcolor(15);
							//exit(0);
							Menugame(row, col);
						}
					}
					else if (c == 117)
					{
						NutNhan1(17, 17, 2);
						Sleep(10);
						if (Undo(ud, rd, a, tongoco))
						{
							luotdi = luotdi == true ? false : true;
							gotoXY(13, 97);
							cout << "                              ";
							gotoXY(14, 97);
							cout << "             ";
							gotoXY(16, 97);
							cout << "                       ";
							x = rd.top().x;
							y = rd.top().y;
							NutNhan1(17, 17);
							break;
						}
						else
						{
							NutNhan1(17, 17);
							goto aa;
						}
					}
					else if (c == 114)
					{
						NutNhan2(17, 17, 2);
						Sleep(10);
						if (!rd.empty())
						{
							short int r_x = rd.top().x;
							short int r_y = rd.top().y;
							char r_d = rd.top().data;
							Redo(a, r_x, r_y, quanco, luotdi, tongoco);
							ud.push(rd.top());
							rd.pop();
							x = ud.top().x;
							y = ud.top().y;
							gotoXY(13, 97);
							cout << "                              ";
							gotoXY(14, 97);
							cout << "             ";
							gotoXY(16, 97);
							cout << "                       ";
							NutNhan2(17, 17);
							break;
						}
						else
						{
							NutNhan2(17, 17);
							goto aa;
						}
					}
					else if (c == 19)
					{
						NutNhan3(17, 17, 2);
						Sleep(10);
						system("cls");
						if (check_savegame())
						{
							SaveGame(a, x, y, 'O', luotdi, tongoco, ud, rd);
							system("cls");
							if (Quit_Continue())
							{
								system("cls");
								BanCo_2(row, col, 3, a);
								BangThongBao(row, col, 119);
								NutNhan(17, 17);
								goto aa;
							}
							else
							{
								Sleep(100);
								system("cls");
								//textcolor(15);
								//exit(0);
								Menugame(row, col);
							}
						}
						else
						{
							system("cls");
							BanCo_2(row, col, 3, a);
							BangThongBao(row, col, 119);
							NutNhan(17, 17);
							goto aa;
						}
					}
				}
				else
				{
					c = _getch();
					if (c == 97)
					{
						if (y > 0)
							--y;
						y1 = ToaDoY1(y);
						gotoXY(x1, y1);
					}
					else if (c == 100)
					{
						if (y < 16)
							++y;
						y1 = ToaDoY1(y);
						gotoXY(x1, y1);
					}
					else if (c == 119)
					{
						if (x > 0)
							--x;
						x1 = ToaDoX1(x);
						gotoXY(x1, y1);
					}
					else if (c == 115)
					{
						if (x < 16)
							++x;
						x1 = ToaDoX1(x);
						gotoXY(x1, y1);
					}
					else if (c == 32)
					{
						if (a[x][y] == ' ')
						{
							InCo(a, x, y, quanco, luotdi, tongoco);
							Toado td;
							td.x = x;
							td.y = y;
							td.data = 'X';
							ud.push(td);

							if (CheckWin(a, x, y, quanco, toadothang))
							{
								gotoXY(17, 109);
								cout << "X win";
								gotoXY(13, 97);
								cout << "                               ";
								gotoXY(14, 97);
								cout << "            ";
								gotoXY(16, 97);
								cout << "                       ";
								gotoXY(19, 97);
								cout << "                           ";
								gotoXY(20, 97);
								cout << "                   ";
								gotoXY(21, 97);
								cout << "                                ";
								NhapNhayQuanCo(a, toadothang);
								ThongBaoQuanCoWin('x');
								bool quit = Quit_Continue();
								if (quit)
								{
									system("cls");
									//Menugame(row, col);
									bool check_xo = Chon_XO();
									XoaManHinh();
									Playgame(row, col, check_xo);
								}
								else
								{
									system("cls");
									Sleep(500);
									//textcolor(7);
									//exit(0);
									Menugame(row, col);
								}
							}
							else
								if (tongoco == 0)
								{
									gotoXY(17, 109);
									cout << "Hoa";
									gotoXY(13, 97);
									cout << "                              ";
									gotoXY(16, 97);
									cout << "            ";
									gotoXY(19, 97);
									cout << "                           ";
									gotoXY(21, 97);
									cout << "                                ";
									ThongBaoQuanCoWin('h');
									bool quit = Quit_Continue();
									if (quit)
									{
										system("cls");
										//Menugame(row, col);
										bool check_xo = Chon_XO();
										XoaManHinh();
										Playgame(row, col, check_xo);
									}
									else
									{
										system("cls");
										Sleep(500);
										//textcolor(7);
										//exit(0);
										Menugame(row, col);
									}
								}

							gotoXY(16, 97);
							cout << "                        ";
							gotoXY(20, 97);
							cout << "                   ";
							break;
						}
						else
						{
							textcolor(12);
							gotoXY(20, 97);
							cout << "Vi tri da duoc di!!";
							goto aa;
						}
					}
					else if (c == 27)
					{
						NutNhan4(17, 17, 2);
						Sleep(10);
						system("cls");
						bool check = Quit_Continue();
						if (check)
						{
							system("cls");
							BanCo_2(row, col, 3, a);
							BangThongBao(row, col, 119);
							NutNhan(17, 17);
							goto aa;
						}
						else
						{
							Sleep(100);
							system("cls");
							//textcolor(15);
							//exit(0);
							Menugame(row, col);
						}
					}
					else if (c == 117)
					{
						NutNhan1(17, 17, 2);
						Sleep(10);
						if (Undo(ud, rd, a, tongoco))
						{
							luotdi = luotdi == true ? false : true;
							gotoXY(13, 97);
							cout << "                              ";
							gotoXY(14, 97);
							cout << "             ";
							gotoXY(16, 97);
							cout << "                       ";
							x = rd.top().x;
							y = rd.top().y;
							NutNhan1(17, 17);
							break;
						}
						else
						{
							NutNhan1(17, 17);
							goto aa;
						}
					}
					else if (c == 114)
					{
						NutNhan2(17, 17, 2);
						Sleep(10);
						if (!rd.empty())
						{
							short int r_x = rd.top().x;
							short int r_y = rd.top().y;
							char r_d = rd.top().data;
							Redo(a, r_x, r_y, quanco, luotdi, tongoco);
							ud.push(rd.top());
							rd.pop();
							gotoXY(13, 97);
							cout << "                              ";
							gotoXY(14, 97);
							cout << "             ";
							gotoXY(16, 97);
							cout << "                       ";
							x = ud.top().x;
							y = ud.top().y;
							NutNhan2(17, 17);
							break;
						}
						else
						{
							NutNhan2(17, 17);
							goto aa;
						}
					}
					else if (c == 19)
					{
						NutNhan3(17, 17, 2);
						Sleep(10);
						system("cls");
						if (check_savegame())
						{
							SaveGame(a, x, y, 'X', luotdi, tongoco, ud, rd);
							system("cls");
							if (Quit_Continue())
							{
								system("cls");
								BanCo_2(row, col, 3, a);
								BangThongBao(row, col, 119);
								NutNhan(17, 17);
								goto aa;
							}
							else
							{
								Sleep(100);
								system("cls");
								//textcolor(15);
								//exit(0);
								Menugame(row, col);
							}
						}
						else
						{
							system("cls");
							BanCo_2(row, col, 3, a);
							BangThongBao(row, col, 119);
							NutNhan(17, 17);
							goto aa;
						}
					}
				}
			}
		}
	}
}

void Playgame3(const short int& row, const short int& col)
{
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD InputRecord, irInBuf[128];
	DWORD Events, fdwMode, cNumRead, i;

	fdwMode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(hin, fdwMode))
		ErrorExit("SetConsoleMode");

	// Get the standard input handle.
	hStdin = GetStdHandle(STD_INPUT_HANDLE);

	// Enable the window and mouse input events.
	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdin, fdwMode))
		ErrorExit("SetConsoleMode");

	short int tongoco;
	short int x, y;
	bool luotdi;
	char quanco;
	char a[17][17];
	short int toadothang[10];
	stack<Toado> ud, rd;
	bool checkquit;
	bool checkloadgame = LoadGame(a, x, y, quanco, luotdi, tongoco, ud, rd, checkquit);
	if (!checkloadgame) {
		Sleep(50);
		system("cls");
		gotoXY(10, 40);
		if (!checkquit)
			cout << "Khong co file game nao duoc luu";
		else
			cout << "Dang quay tro lai menu chinh";
		Sleep(700);
		system("cls");
		Menugame(row, col);
	}

	ShowCur(0);
	system("cls");
	Introbanco1(row, col);
	gotoXY(15, 97);
	cout << "                      ";
	gotoXY(17, 97);
	cout << "                   ";
	gotoXY(19, 97);
	cout << "                                ";
	XoaManHinh();
	BanCo_2(row, col, 3, a);
	BangThongBao_1(17, 17, 119);
	NutNhan(row, col);
	while (true)
	{
		quanco = luotdi == 1 ? 'X' : 'O';
	aa:

		fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
		if (!SetConsoleMode(hin, fdwMode))
			ErrorExit("SetConsoleMode");

		//ShowCur(1);
		gotoXY(13, 97);
		if (quanco == 'X')
		{
			textcolor(14);
			cout << "Click chuot trai de chon vi ";
			gotoXY(14, 97);
			cout << "tri cho " << quanco;
			gotoXY(19, 97);
			cout << "Click nut Exit de thoat game";
		}
		else
		{
			textcolor(14);
			cout << "Click chuot trai de chon vi ";
			gotoXY(14, 97);
			cout << "tri cho " << quanco;
			gotoXY(19, 97);
			cout << "Click nut Exit de thoat game";
		}

		short int x1, y1;
		// xu ly toa do x y  de gotoXY den vi tri x1 y1 dung
		//x1 = ToaDoX1(x);
		//y1 = ToaDoY1(y);
		//gotoXY(x1, y1);

		char c;

		// Wait for the events.
		if (!ReadConsoleInput(
			hStdin,      // input buffer handle
			irInBuf,     // buffer to read into
			128,         // size of read buffer
			&cNumRead)) // number of records read
			ErrorExit("ReadConsoleInput");

		for (i = 0; i < cNumRead; ++i)
		{
			switch (irInBuf[i].EventType)
			{
			case MOUSE_EVENT: // mouse input
				if (irInBuf[i].Event.MouseEvent.dwEventFlags == 0)
				{
					if (irInBuf[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
					{
						if (quanco == 'O')
						{
							y1 = irInBuf[i].Event.MouseEvent.dwMousePosition.X;
							x1 = irInBuf[i].Event.MouseEvent.dwMousePosition.Y;
							if (x1 >= 0 && x1 <= 34 && y1 >= 0 && y1 <= 68 && x1 % 2 != 0 && y1 % 4 != 0)
							{
								ChuyenDoiToaDo(x1, y1, x, y);
								if (a[x][y] == ' ')
								{
									InCo(a, x, y, quanco, luotdi, tongoco);
									Toado td;
									td.x = x;
									td.y = y;
									td.data = 'O';
									ud.push(td);

									if (CheckWin(a, x, y, quanco, toadothang))
									{
										gotoXY(17, 109);
										cout << "O win";
										gotoXY(13, 97);
										cout << "                               ";
										gotoXY(14, 97);
										cout << "            ";
										//gotoXY(16, 97);
										//cout << "                       ";
										gotoXY(19, 97);
										cout << "                            ";
										gotoXY(20, 97);
										cout << "                   ";
										/*gotoXY(21, 97);
										cout << "                                ";*/
										NhapNhayQuanCo(a, toadothang);
										ThongBaoQuanCoWin('o');
										bool quit = Quit_Continue();
										if (quit)
										{
											system("cls");
											//Menugame(row, col);
											bool check_xo = Chon_XO();
											XoaManHinh();
											Playgame2(row, col, check_xo);
										}
										else
										{
											system("cls");
											Sleep(500);
											//textcolor(7);
											//exit(0);
											Menugame(row, col);
										}
									}
									else
										if (tongoco == 0)
										{
											gotoXY(17, 109);
											cout << "Hoa";
											gotoXY(13, 97);
											cout << "                              ";
											//gotoXY(16, 97);
											//cout << "            ";
											gotoXY(19, 97);
											cout << "                            ";
											/*gotoXY(21, 97);
											cout << "                                ";*/
											ThongBaoQuanCoWin('h');
											bool quit = Quit_Continue();
											if (quit)
											{
												system("cls");
												//Menugame(row, col);
												bool check_xo = Chon_XO();
												XoaManHinh();
												Playgame2(row, col, check_xo);
											}
											else
											{
												system("cls");
												Sleep(500);
												//textcolor(7);
												//exit(0);
												Menugame(row, col);
											}
										}

									gotoXY(13, 97);
									cout << "                              ";
									gotoXY(14, 97);
									cout << "             ";
									//gotoXY(16, 97);
									//cout << "                        ";
									gotoXY(20, 97);
									cout << "                   ";
									break;
								}
								else
								{
									textcolor(12);
									gotoXY(20, 97);
									cout << "Vi tri da duoc di!!";
									goto aa;
								}
							}
							else if ((x >= 1 && x <= 3) && (y >= 87 && y <= 96))
							{
								NutNhan1(17, 17, 2);
								if (Undo(ud, rd, a, tongoco))
								{
									luotdi = luotdi == true ? false : true;
									gotoXY(13, 97);
									cout << "                              ";
									gotoXY(14, 97);
									cout << "             ";
									//gotoXY(16, 97);
									//cout << "                       ";
									x = rd.top().x;
									y = rd.top().y;
									Sleep(10);
									NutNhan1(17, 17);
									break;
								}
								else
								{
									Sleep(10);
									NutNhan1(17, 17);
									goto aa;
								}
							}
							else if ((x >= 5 && x <= 7) && (y >= 87 && y <= 96))
							{
								NutNhan2(17, 17, 2);
								if (!rd.empty())
								{
									short int r_x = rd.top().x;
									short int r_y = rd.top().y;
									char r_d = rd.top().data;
									Redo(a, r_x, r_y, quanco, luotdi, tongoco);
									ud.push(rd.top());
									rd.pop();
									x = ud.top().x;
									y = ud.top().y;
									gotoXY(13, 97);
									cout << "                              ";
									gotoXY(14, 97);
									cout << "             ";
									//gotoXY(16, 97);
									//cout << "                       ";
									Sleep(10);
									NutNhan2(17, 17);
									break;
								}
								else
								{
									Sleep(10);
									NutNhan2(17, 17);
									goto aa;
								}
							}
							else if ((x >= 26 && x <= 28) && (y >= 87 && y <= 96))
							{
								NutNhan3(17, 17, 2);
								Sleep(10);
								system("cls");
								if (check_savegame())
								{
									SaveGame(a, x, y, 'O', luotdi, tongoco, ud, rd);
									system("cls");
									if (!Quit_Continue())
									{
										system("cls");
										BanCo_2(row, col, 3, a);
										BangThongBao(row, col, 119);
										NutNhan(row, col);
										goto aa;
									}
									else
									{
										Sleep(50);
										system("cls");
										Menugame(row, col);
									}
								}
								else
								{
									Sleep(100);
									system("cls");
									//textcolor(15);
									//exit(0);
									bool check = Quit_Continue();
									if (check)
									{
										system("cls");
										BanCo_2(row, col, 3, a);
										BangThongBao(row, col, 119);
										NutNhan(row, col);
										goto aa;
									}
									else
									{
										Sleep(100);
										system("cls");
										//textcolor(15);
										//exit(0);
										Menugame(row, col);
									}
								}
							}
							else if ((x >= 31 && x <= 33) && (y >= 87 && y <= 96))
							{
								system("cls");
								bool check = Quit_Continue();
								if (check)
								{
									system("cls");
									BanCo_2(row, col, 3, a);
									BangThongBao(row, col, 119);
									NutNhan(row, col);
									goto aa;
								}
								else
								{
									Sleep(100);
									system("cls");
									//textcolor(15);
									//exit(0);
									Menugame(row, col);
								}
							}
							else
							{
								textcolor(12);
								gotoXY(20, 97);
								cout << "Vi tri khong hop le";
								//cout << "x = " << x1 << "  y = " << y1;
								goto aa;
							}
						}
						else if (quanco == 'X')
						{
							y1 = irInBuf[i].Event.MouseEvent.dwMousePosition.X;
							x1 = irInBuf[i].Event.MouseEvent.dwMousePosition.Y;
							if (x1 >= 0 && x1 <= 34 && y1 >= 0 && y1 <= 68 && x1 % 2 != 0 && y1 % 4 != 0)
							{
								ChuyenDoiToaDo(x1, y1, x, y);
								if (a[x][y] == ' ')
								{
									InCo(a, x, y, quanco, luotdi, tongoco);
									Toado td;
									td.x = x;
									td.y = y;
									td.data = 'X';
									ud.push(td);

									if (CheckWin(a, x, y, quanco, toadothang))
									{
										gotoXY(17, 109);
										cout << "X win";
										gotoXY(13, 97);
										cout << "                               ";
										gotoXY(14, 97);
										cout << "            ";
										//gotoXY(16, 97);
										//cout << "                       ";
										gotoXY(19, 97);
										cout << "                            ";
										gotoXY(20, 97);
										cout << "                   ";
										/*gotoXY(21, 97);
										cout << "                                ";*/
										NhapNhayQuanCo(a, toadothang);
										ThongBaoQuanCoWin('x');
										bool quit = Quit_Continue();
										if (quit)
										{
											system("cls");
											//Menugame(row, col);
											bool check_xo = Chon_XO();
											XoaManHinh();
											Playgame2(row, col, check_xo);
										}
										else
										{
											system("cls");
											Sleep(500);
											//textcolor(7);
											//exit(0);
											Menugame(row, col);
										}
									}
									else
										if (tongoco == 0)
										{
											gotoXY(17, 109);
											cout << "Hoa";
											gotoXY(13, 97);
											cout << "                              ";
											//gotoXY(16, 97);
											//cout << "            ";
											gotoXY(19, 97);
											cout << "                            ";
											/*gotoXY(21, 97);
											cout << "                                ";*/
											ThongBaoQuanCoWin('h');
											bool quit = Quit_Continue();
											if (quit)
											{
												system("cls");
												//Menugame(row, col);
												bool check_xo = Chon_XO();
												XoaManHinh();
												Playgame2(row, col, check_xo);
											}
											else
											{
												system("cls");
												Sleep(500);
												//textcolor(7);
												//exit(0);
												Menugame(row, col);
											}
										}

									//gotoXY(16, 97);
									//cout << "                        ";
									gotoXY(20, 97);
									cout << "                   ";
									break;
								}
								else
								{
									textcolor(12);
									gotoXY(20, 97);
									cout << "Vi tri da duoc di!!";
									goto aa;
								}
							}
							else if ((x >= 1 && x <= 3) && (y >= 87 && y <= 96))
							{
								NutNhan1(17, 17, 2);
								if (Undo(ud, rd, a, tongoco))
								{
									luotdi = luotdi == true ? false : true;
									gotoXY(13, 97);
									cout << "                              ";
									gotoXY(14, 97);
									cout << "             ";
									//gotoXY(16, 97);
									//cout << "                       ";
									x = rd.top().x;
									y = rd.top().y;
									Sleep(10);
									NutNhan1(17, 17);
									break;
								}
								else
								{
									Sleep(10);
									NutNhan1(17, 17);
									goto aa;
								}
							}
							else if ((x >= 5 && x <= 7) && (y >= 87 && y <= 96))
							{
								NutNhan2(17, 17, 2);
								if (!rd.empty())
								{
									short int r_x = rd.top().x;
									short int r_y = rd.top().y;
									char r_d = rd.top().data;
									Redo(a, r_x, r_y, quanco, luotdi, tongoco);
									ud.push(rd.top());
									rd.pop();
									x = ud.top().x;
									y = ud.top().y;
									gotoXY(13, 97);
									cout << "                              ";
									gotoXY(14, 97);
									cout << "             ";
									//gotoXY(16, 97);
									//cout << "                       ";
									Sleep(10);
									NutNhan2(17, 17);
									break;
								}
								else
								{
									Sleep(10);
									NutNhan2(17, 17);
									goto aa;
								}
							}
							else if ((x >= 26 && x <= 28) && (y >= 87 && y <= 96))
							{
								NutNhan3(17, 17,2);
								Sleep(10);
								system("cls");
								if (check_savegame())
								{
									SaveGame(a, x, y, 'O', luotdi, tongoco, ud, rd);
									system("cls");
									if (Quit_Continue())
									{
										system("cls");
										BanCo_2(row, col, 3, a);
										BangThongBao(row, col, 119);
										NutNhan(row, col);
										goto aa;
									}
									else
									{
										Sleep(50);
										system("cls");
										Menugame(row, col);
									}
								}
								else
								{
									Sleep(100);
									system("cls");
									//textcolor(15);
									//exit(0);
									bool check = Quit_Continue();
									if (check)
									{
										system("cls");
										BanCo_2(row, col, 3, a);
										BangThongBao(row, col, 119);
										NutNhan(row, col);
										goto aa;
									}
									else
									{
										Sleep(100);
										system("cls");
										//textcolor(15);
										//exit(0);
										Menugame(row, col);
									}
								}
							}
							else if ((x >= 31 && x <= 33) && (y >= 87 && y <= 96))
							{
								NutNhan4(17, 17, 2);
								Sleep(10);
								system("cls");
								bool check = Quit_Continue();
								if (check)
								{
									system("cls");
									BanCo_2(row, col, 3, a);
									BangThongBao(row, col, 119);
									NutNhan(row, col);
									goto aa;
								}
								else
								{
									Sleep(100);
									system("cls");
									//textcolor(15);
									//exit(0);
									Menugame(row, col);
								}
							}
							else
							{
								textcolor(12);
								gotoXY(20, 97);
								cout << "Vi tri khong hop le";
								//cout << "x = " << x1 << "  y = " << y1;
								goto aa;
							}
						}
					}
				}
				else if (irInBuf[i].Event.MouseEvent.dwEventFlags == MOUSE_MOVED)
				{
					y = irInBuf[i].Event.MouseEvent.dwMousePosition.X;
					x = irInBuf[i].Event.MouseEvent.dwMousePosition.Y;

					if ((x >= 1 && x <= 3) && (y >= 87 && y <= 96))
						NutNhan1(17, 17, 1);
					else if ((x >= 5 && x <= 7) && (y >= 87 && y <= 96))
						NutNhan2(17, 17, 1);
					else if ((x >= 26 && x <= 28) && (y >= 87 && y <= 96))
						NutNhan3(17, 17, 1);
					else if ((x >= 31 && x <= 33) && (y >= 87 && y <= 96))
						NutNhan4(17, 17, 1);
					else
					{
						NutNhan1(17, 17);
						NutNhan2(17, 17);
						NutNhan3(17, 17);
						NutNhan4(17, 17);
					}
				}
			}
		}
	}
}

void Menugame(const short int& row, const short int& col)
{
	ShowCur(0);
	// logo game
	ifstream ifile;
	ifile.open("Caro.txt", ios::in);
	if (!ifile) exit(0);

	unsigned short int x = 1;
	string s;
	SetColor(1 + rand() % 15);
	while (!ifile.eof())
	{
		getline(ifile, s);
		gotoXY(x++, 35);
		cout << s << endl;
		Sleep(50);
		s.clear();
	}
	ifile.close();
	
	// ten tac gia
	ifile.open("HoangDinh.txt", ios::in);
	if (!ifile) exit(0);
	--x;
	SetColor(1 + rand() % 15);
	while (!ifile.eof())
	{
		getline(ifile, s);
		gotoXY(x++, 40);
		cout << s << endl;
		Sleep(50);
		s.clear();
	}
	ifile.close();

	//// loading...
	unsigned short int y = 42;
	gotoXY(x, y + 4);
	cout << "Loading . . .";
	
	for (unsigned short int i = 1; i <= 10; ++i)
	{
		//textcolor(300);
		textcolor(16 + rand() % 2985);
		gotoXY(x + 1, y+=4);
		cout << "     ";

		textcolor(3);
		gotoXY(x + 2, y + 3);
		cout << i * 10 << "%";

		Sleep(10 + rand() % 500);

		gotoXY(x + 2, y + 3);
		cout << "    ";
	}
	Sleep(100);

	x = 17; y = 62;
	// menu chon
	gotoXY(x++, y);
	cout << "Menu";
	gotoXY(x++, y);
	textcolor(30);
	cout << "Start";
	textcolor(12);
	gotoXY(x++, y);
	cout << "Help";
	gotoXY(x++, y);
	cout << "About me";
	gotoXY(x++, y);
	cout << "Exit";

ww:
	short int luachon = 1;
	x = 18; 
	char c;
	while (1)
	{
		if (_kbhit())
		{
			c = _getch();
			if (c == 72) // len tren
			{
				--luachon;
				if (luachon < 1)
					luachon = 4;

				--x;
				if (x < 18)
					x = 21;

				textcolor(30);
				if (x == 18)
				{
					gotoXY(x, y);
					cout << "Start";
					textcolor(12);
					gotoXY(x+1, y);
					cout << "Help";
					gotoXY(x+2, y);
					cout << "About me";
					gotoXY(x+3, y);
					cout << "Exit";
				}
				else if (x == 19)
				{
					gotoXY(x, y);
					cout << "Help";
					textcolor(12);
					gotoXY(x-1, y);
					cout << "Start";
					gotoXY(x+1, y);
					cout << "About me";
					gotoXY(x + 2, y);
					cout << "Exit";
				}
				else if (x == 20)
				{
					gotoXY(x, y);
					cout << "About me";
					textcolor(12);
					gotoXY(x-2, y);
					cout << "Start";
					gotoXY(x-1, y);
					cout << "Help";
					gotoXY(x + 1, y);
					cout << "Exit";
				}
				else if (x == 21)
				{
					gotoXY(x, y);
					cout << "Exit";
					textcolor(12);
					gotoXY(x - 3, y);
					cout << "Start";
					gotoXY(x - 2, y);
					cout << "Help";
					gotoXY(x - 1, y);
					cout << "About me";
				}
			}
			else if (c == 80) // xuong duoi
			{
				++luachon;
				if (luachon > 4)
					luachon = 1;

				++x;
				if (x > 21)
					x = 18;

				textcolor(30);
				if (x == 18)
				{
					gotoXY(x, y);
					cout << "Start";
					textcolor(12);
					gotoXY(x + 1, y);
					cout << "Help";
					gotoXY(x + 2, y);
					cout << "About me";
					gotoXY(x + 3, y);
					cout << "Exit";
				}
				else if (x == 19)
				{
					gotoXY(x, y);
					cout << "Help";
					textcolor(12);
					gotoXY(x - 1, y);
					cout << "Start";
					gotoXY(x + 1, y);
					cout << "About me";
					gotoXY(x + 2, y);
					cout << "Exit";
				}
				else if (x == 20)
				{
					gotoXY(x, y);
					cout << "About me";
					textcolor(12);
					gotoXY(x - 2, y);
					cout << "Start";
					gotoXY(x - 1, y);
					cout << "Help";
					gotoXY(x + 1, y);
					cout << "Exit";
				}
				else if (x == 21)
				{
					gotoXY(x, y);
					cout << "Exit";
					textcolor(12);
					gotoXY(x - 3, y);
					cout << "Start";
					gotoXY(x - 2, y);
					cout << "Help";
					gotoXY(x - 1, y);
					cout << "About me";
				}
			}
			else if (c == 13)
			{
				if (luachon == 1)
				{
					bool newgame = check_newgame();
					if (newgame == true)
					{
						bool checkKeyOrMouse = KeyBoardOrMouse();
						bool check_XO = Chon_XO();
						system("cls");
						y = 40;
						gotoXY(9, y + 4);
						cout << "Loading . . .";
						for (unsigned short int i = 1; i <= 10; ++i)
						{
							//textcolor(111);
							textcolor(16 + rand() % 2985);
							gotoXY(10, y += 4);
							cout << "     ";

							textcolor(11);
							gotoXY(11, y + 3);
							cout << i * 10 << "%";

							Sleep(10 + rand() % 500);

							gotoXY(11, y + 3);
							cout << "    ";
						}
						Sleep(90);
						system("cls");
						Introbanco(row, col);
						if(checkKeyOrMouse)
							Playgame(row, col, check_XO);
						else
							Playgame2(row, col, check_XO);
						
					}
					else
					{
						system("cls");
						y = 40;
						gotoXY(9, y + 4);
						cout << "Loading . . .";
						for (unsigned short int i = 1; i <= 10; ++i)
						{
							textcolor(16 + rand() % 2985);
							//textcolor(111);
							gotoXY(10, y += 4);
							cout << "     ";

							textcolor(11);
							gotoXY(11, y + 3);
							cout << i * 10 << "%";

							Sleep(10 + rand() % 500);

							gotoXY(11, y + 3);
							cout << "    ";
						}
						Sleep(90);
						bool checkKeyOrMouse = KeyBoardOrMouse();
						system("cls");
						if(checkKeyOrMouse)
							Playgame1(row, col);
						else
							Playgame3(row, col);
					}
				}
				else if (luachon == 2)
				{
					system("cls");
					textcolor(1 + rand() % 15);
					gotoXY(5, 20);
					cout << "Mode Keyboard:";
					gotoXY(6, 20);
					cout << "Nguoi choi dung cac phim mui ten (up, down, left, right / a, s, w, d) di chuyen con tro";
					gotoXY(7, 20);
					cout << "Sau khi xac dinh duoc toa do can danh quan co nhan phim enter/backspace de xac nhan toa do";
					gotoXY(8, 20);
					cout << "Bam phim u: quay lai 1 buoc";
					gotoXY(9, 20);
					cout << "Bam phim r: khoi phuc 1 buoc vua Undo";
					gotoXY(10, 20);
					cout << "Bam phim Ctrl + S: luu lai tinh trang ban co";
					gotoXY(11, 20);
					cout << "Bam phim ESC: thoat/tam dung game";
					gotoXY(12, 20);
					cout << "Nhan phim back de quay tro lai menu";

					gotoXY(14, 20);
					cout << "Mode Mouse:";
					gotoXY(15, 20);
					cout << "Nguoi choi dung chuot de chon vi tri cho quan co";
					gotoXY(16, 20);
					cout << "Bam nut Undo: quay lai 1 buoc";
					gotoXY(17, 20);
					cout << "Bam nut Redo: khoi phuc 1 buoc vua Undo";
					gotoXY(18, 20);
					cout << "Bam phim Save: luu lai tinh trang ban co";
					gotoXY(19, 20);
					cout << "Bam phim Exit: thoat/tam dung game";
					gotoXY(21, 20);
					cout << "Nhan phim back de quay tro lai menu";

					//textcolor(30);
					textcolor(16 + rand() % 2985);
					gotoXY(3, 50);
					cout << "<- Back";
					textcolor(11);

					while (true)
					{
						if (_kbhit()) {
							c = _getch();
							if (c == 8)
							{
								system("cls");
								IntroGame();
								goto ww;
							}
						}
					}
				}
				else if(luachon == 3)
				{
					system("cls");
					textcolor(1 + rand() % 15);
					gotoXY(10, 20);
					cout << "Game co caro version console code by: Hoang Dinh";
					gotoXY(11, 20);
					cout << "Linkedin: https://www.linkedin.com/in/hoangdinh2k2blink/";
					gotoXY(12, 20);
					cout << "Github: https://github.com/BlinkDev2k2";
					gotoXY(13, 20);
					cout << "Facebook: https://www.facebook.com/profile.php?id=100034509642984";
					gotoXY(15, 20);
					cout << "Nhan phim back de quay tro lai menu";

					//textcolor(30);
					textcolor(16 + rand() % 2985);
					gotoXY(3, 50);
					cout << "<- Back";
					textcolor(11);

					while (true)
					{
						if (_kbhit()) {
							c = _getch();
							if (c == 8)
							{
								system("cls");
								IntroGame();
								goto ww;
							}
						}
					}
				}
				else
				{
					bool check2 = Quit_Continue();
					if (check2)
					{
						system("cls");
						Menugame(row, col);
					}
					else
					{
						system("cls");
						textcolor(15);
						exit(0);
					}
				}
			}
		}
	}
}

int main()
{
	resizeConsole(1250, 700);
	const short int row = 17, col = 17;
	Menugame(row, col);

	return 0;
}