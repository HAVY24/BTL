#include "header.h"
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}

int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
int inputKey()
{
	if (_kbhit()) //true
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}
	return KEY_NONE;
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void box(int x, int y, int w, int h, int t_color)
{

	SetColor(t_color);
	if (h < 2 || w < 2)
		return;
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoXY(ix, y);
		printf("%c", char(196));
		gotoXY(ix, y + h);
		printf("%c", char(196));
	}
	for (int iy = y; iy <= y + h; iy++)
	{
		gotoXY(x, iy);
		printf("%c", char(179));
		gotoXY(x + w, iy);
		printf("%c", char(179));
	}
	gotoXY(x, y);
	printf("%c", char(218));
	gotoXY(x + w, y + h);
	printf("%c", char(217));
	gotoXY(x + w, y);
	printf("%c", char(191));
	gotoXY(x, y + h);
	printf("%c", char(192));
}
void menu_KH_oder()
{
	textcolor(6);

	for (int ix = 0; ix <= 12; ix++)
	{
		gotoXY(ix, 1);
		printf("%c", char(196));
		gotoXY(ix, 1 + 2);
		printf("%c", char(196));
	}
	for (int iy = 1; iy <= 1 +2 ; iy++)
	{
		gotoXY(12, iy);
		printf("%c", char(179));
	}

	gotoXY(12, 1 + 2);
	printf("%c", char(217));
	gotoXY(12, 1);
	printf("%c", char(191));



	gotoXY(1, 2);
	SetColor(15);
	printf("KHACH HANG");
	
	textcolor(6);
	box(50, 1, 20, 2, 6);
	gotoXY(51, 2);
	SetColor(15);
	printf("     Chon Hang     ");

	for (int j = 10; j <= 22; j+=6)
	{

		for (int i = 5; i <= 55; i+=25)
		{
			box(i, j, 20, 3, 6);
		}
	}
	textcolor(15);
	gotoXY(2 , 10 - 1);
	printf("Coffee");
	gotoXY(4, 16 - 1);
	printf("Tra");
	gotoXY(2, 22 - 1);
	printf("Banh Kem");
	//Coffee
	textcolor(14);
	gotoXY(5 + 1, 10 + 2);
	printf("  AMERICANO        ");
	gotoXY(5 + 1, 10 + 2);
	printf("          Gia: 5$  ");
	gotoXY(30 + 1, 10 + 1);
	printf("  CAPPUCCINO       ");
	gotoXY(30 + 1, 11 + 1);
	printf("          Gia: 5$  ");
	gotoXY(55 + 1, 10 + 1);
	printf("  MACCHIATO        ");
	gotoXY(55 + 1, 11 + 1);
	printf("          Gia: 5$  ");

	//Tra
	gotoXY(5 + 1, 16 + 1);
	printf("   Tra Dao         ");
	gotoXY(5 + 1, 16 + 2);
	printf("          Gia: 4$  ");
	gotoXY(30 + 1, 16 + 1);
	printf("   Tra Vai         ");
	gotoXY(30 + 1, 16 + 2);
	printf("          Gia: 4$  ");
	gotoXY(55 + 1, 16 + 1);
	printf("   Tra Buoi        ");
	gotoXY(55 + 1, 16 + 2);
	printf("          Gia: 4$  ");
	//Tra
	gotoXY(5 + 1, 22 + 1);
	printf("   Tiramisu        ");
	gotoXY(5 + 1, 22 + 2);
	printf("          Gia: 2$  ");;
	gotoXY(30 + 1, 22 + 1);
	printf(" Mousse Cacao      ");
	gotoXY(30 + 1, 22 + 2);
	printf("          Gia: 2$  ");
	gotoXY(55 + 1, 22 + 1);
	printf(" Pho Mai Ca Phe    ");
	gotoXY(55 + 1, 22 + 2);
	printf("          Gia: 2$  ");
	
	// Gio Hang
	box(80, 7, 35, 20, 15); 
	gotoXY(90, 8); 
	textcolor(15); 
	printf("GIO HANG CUA BAN");
	gotoXY(87, 9);
	for (int i = 0; i < 22; i++) {
		textcolor(11);	
		printf("%c", char(196));
	}
	gotoXY(82, 10);
	printf("TEN SAN PHAM |  SO LUONG  |  GIA");

	//Total
		textcolor(15);
	gotoXY(82, 25);
	for (int i = 0; i < 32; i++) {
		printf("%c", char(196));
	}
	gotoXY(102, 26);
	printf("Tong: ");

	//Esc
	gotoXY(1, 5);
	textcolor(15);
	printf("NHAN");
	textcolor(6);
	printf(" ESC ");
	textcolor(15);
	printf("DE QUAY LAI");
	//Enter
	gotoXY(1, 6);
	textcolor(15);
	printf("NHAN");
	textcolor(6);
	printf(" ENTER ");
	textcolor(15);
	printf("DE CHON HANG");
}

