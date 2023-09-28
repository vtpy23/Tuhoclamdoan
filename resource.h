#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

// Hàm thay ??i kích c? c?a khung cmd v?i tham s? truy?n vào là chi?u cao, chi?u r?ng.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Hàm d?ch chuy?n con tr? ??n t?a ?? x, y.
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

// Hàm l?y Key t? bàn phím
/* GetAsyncKeyState(VK_ESCAPE) => b?t s? ki?n phím Esc */

// Hàm t? vi?t
void ToMau(int x, int y, char* a, int color) // x, y là t?a ?? con tr? c?n nh?y ??n ?? vi?t, a là chu?i c?n truy?n vào, color là màu truy?n vào.
{
	gotoxy(x, y);
	textcolor(color);
	cout << a;
	textcolor(7);
}

void box(int x, int y, int w, int h, int a)
{
	if (h <= 1 || w <= 1) return;
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoxy(ix, y); textcolor(a);
		cout << char(196);
		gotoxy(ix, y + h); textcolor(a);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++)
	{
		gotoxy(x, iy); textcolor(a);
		cout << char(179);
		gotoxy(x + w, iy); textcolor(a);
		cout << char(179);
	}
	gotoxy(x, y); textcolor(a); cout << char(218);
	gotoxy(x + w, y); textcolor(a); cout << char(191);
	gotoxy(x, y + h); textcolor(a); cout << char(192);
	gotoxy(x + w, y + h); textcolor(a); cout << char(217);
}

void hinhnen(int x, int y)
{
	int ix, iy;
	for (iy = 0; iy < y; iy++)
	{
		for (ix = 0; ix < x; ix++)
		{
			textcolor(255);
			printf(" ");
		}
	}
}

void abt()
{
	hinhnen(120, 30);
	box(36, 13, 52, 14, 246);
	gotoxy(59, 13); printf(" ABOUT ");
	gotoxy(47, 16); printf(" DO AN GAME CO CARO - NHOM IV");
	gotoxy(44, 18); printf("_MSSV_                   _HO VA TEN_");
	gotoxy(43, 19); printf("23122031               NGUYEN HUY HOANG");
	gotoxy(43, 20); printf("23122042              TRAN TA QUANG MINH");
	gotoxy(43, 21); printf("23122043                 NGUYEN BA NAM");
	gotoxy(43, 22); printf("23122056                 LAM HOANG VU");
	gotoxy(43, 24); printf("GV HUONG DAN: THAY TRUONG TOAN THINH");
	gotoxy(60, 26); printf("BACK");
}

void hlp()
{
	hinhnen(120, 30);
	box(36, 13, 52, 16, 246);
	gotoxy(58, 13); printf("HUONG DAN");
	gotoxy(41, 15); printf("1. BAN CO VOI KINH THUOC 16x16.");
	gotoxy(41, 18); printf("2. SU DUNG: PHIM W A S D DE DI CHUYEN");
	gotoxy(53, 19); printf("PHIM ENTER DE DANH DAU.");
	gotoxy(41, 21); printf("3. KHI CO 5 QUAN CO X HOAC O LIEN TIEP THEO");
	gotoxy(44, 22); printf("CHIEU DOC, NGANG, CHEO SE KET THUC.");
	gotoxy(41, 24); printf("4. AP DUNG LUAT CHAN HAI DAU TRONG CO CARO.");
	gotoxy(47, 26); printf("YOU CAN DO IT. GOOD LUCK!!!");
	gotoxy(60, 28); printf("BACK");
}