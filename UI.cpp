#include "UI.h"

using namespace std;

#define LEFT 75
#define UP 72
#define DOWN 80
#define RIGHT 77
#define SUBMIT 13

int a;


void gotoxy(int x, int y)
{
	COORD coord = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//void move(char key)
//{
//	switch (key)
//	{
//	case LEFT: printf(">"); x--; break;
//	case RIGHT: printf(">"); x++; break;
//	case UP: printf(">"); y--; break;
//	case DOWN: printf(">"); y++; break;
//	}
//}


void Start_menu()		// 메인화면 UI
{
	cout << endl;
	cout << "  ◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈ " << endl;
	cout << "  ◈                                                                                                              ◈ " << endl;
	cout << "  ◈                                                                                                  \"최정예팀\"  ◈ " << endl;
	cout << "  ◈                                                                                                              ◈ " << endl;
	cout << "  ◈                                ■■      ■  ■■■■■ ■     ■     ■  ■■■■■                         ◈ " << endl;
	cout << "  ◈                                ■■■    ■  ■         ■    ■■    ■  ■                                 ◈ " << endl;
	cout << "  ◈                                ■■  ■  ■  ■■■■■  ■  ■  ■  ■   ■■■■■                         ◈ " << endl;
	cout << "  ◈                                ■■    ■■  ■           ■■    ■■            ■                         ◈ " << endl;
	cout << "  ◈                                ■■      ■  ■■■■■    ■      ■     ■■■■■                         ◈ " << endl;
	cout << "  ◈                                                                                                              ◈ " << endl;
	cout << "  ◈                                                                                                              ◈ " << endl;
	cout << "  ◈      ■■■   ■       ■      ■  ■■■■  ■■■■■ ■■■■  ■■■   ■■■  ■      ■    ■■■      ◈ " << endl;
	cout << "  ◈     ■    ■  ■       ■      ■  ■            ■     ■        ■   ■    ■    ■■    ■   ■    ■     ◈ " << endl;
	cout << "  ◈    ■         ■       ■      ■  ■            ■     ■        ■   ■    ■    ■ ■   ■  ■            ◈ " << endl;
	cout << "  ◈    ■         ■       ■      ■  ■■■■      ■     ■■■■  ■■■     ■    ■  ■  ■  ■    ■■    ◈ " << endl;
	cout << "  ◈    ■         ■       ■      ■        ■      ■     ■        ■  ■     ■    ■   ■ ■  ■      ■    ◈ " << endl;
	cout << "  ◈     ■    ■  ■       ■      ■        ■      ■     ■        ■   ■    ■    ■    ■■   ■     ■    ◈ " << endl;
	cout << "  ◈      ■■■   ■■■■  ■■■■   ■■■■      ■     ■■■■  ■    ■ ■■■  ■      ■    ■■■      ◈ " << endl;
	cout << "  ◈                                                                                                              ◈ " << endl;
	cout << "  ◈                                                                                                              ◈ " << endl;
	cout << "  ◈                                                                                                              ◈ " << endl;
	cout << "  ◈                                                                                                              ◈ " << endl;
	cout << "  ◈                                             <Enter> 키워드 검색하기                                          ◈ " << endl;
	cout << "  ◈                                                                                                              ◈ " << endl;
	cout << "  ◈                                                                                                              ◈ " << endl;
	cout << "  ◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈ " << endl;
	//세로 26개

	int ch;
	ch = _getch();
	if (ch = 13)//엔터입력시
	{
		system("cls");
		keywordInputPage1();
	}
}

void keywordInputPage1()
{
	cout << endl;
	cout << "  ◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈◈ " << endl << endl;
	cout << "                                         키워드 입력 > "; cin >> a; //키워드 입력받는함수


}
void keywordInputPage2() {
	cout << endl;
	cout << "  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl << endl;
}

int keyControl() {
	int key = _getch();

	if (key == 72) { //상
		return UP;
	}
	else if (key == 80) { //하
		return DOWN;
	}
	else if (key == 75) { //좌
		return LEFT;
	}
	else if (key == 77) { //우
		return RIGHT;
	}
	else if (key == 13) {
		return SUBMIT;
	}
}
int menuDraw() {
	int key;
	int x = 4;
	int y = 7;
	int i = 0;

	gotoxy(x, y + i);
	cout << "1. a" << endl; i++;//키워드 포함 기사 출력 함수

	gotoxy(x, y + i);
	cout << "2. b" << endl; i++;

	gotoxy(x, y + i);
	cout << "3. c" << endl; i++;

	gotoxy(x, y + i);
	cout << "4. d" << endl; i++;

	gotoxy(x, y + i);
	cout << "5. e" << endl; i++;

	gotoxy(x, y + i);
	cout << "6. f" << endl;

	while (1)
	{
		int n = keyControl();
		switch (n) {
		case UP:
		{
			if (y > 7)
			{
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << ">";
			}
			break;
		}
		case DOWN:
		{
			if (y < 7 + 5)//y값 + 출력 기사개수-1
			{
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";
			}
			break;
		}
		case SUBMIT:
		{
			return y - 6;
		}

		}
	}
}

//void main()
//{
//	Start_menu();
//	int ch;
//	ch = _getch();
//	if (ch = 13)//엔터입력시
//	{
//		system("cls");
//		keywordInputPage();
//	}
//
//	int menuCode = menuDraw();
//	cout << endl << endl << endl << endl;
//	cout << menuCode;
//
//	system("pause");
//	
//}