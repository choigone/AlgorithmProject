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


void Start_menu()		// ����ȭ�� UI
{
	cout << endl;
	cout << "  �¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢� " << endl;
	cout << "  ��                                                                                                              �� " << endl;
	cout << "  ��                                                                                                  \"��������\"  �� " << endl;
	cout << "  ��                                                                                                              �� " << endl;
	cout << "  ��                                ���      ��  ������ ��     ��     ��  ������                         �� " << endl;
	cout << "  ��                                ����    ��  ��         ��    ���    ��  ��                                 �� " << endl;
	cout << "  ��                                ���  ��  ��  ������  ��  ��  ��  ��   ������                         �� " << endl;
	cout << "  ��                                ���    ���  ��           ���    ���            ��                         �� " << endl;
	cout << "  ��                                ���      ��  ������    ��      ��     ������                         �� " << endl;
	cout << "  ��                                                                                                              �� " << endl;
	cout << "  ��                                                                                                              �� " << endl;
	cout << "  ��      ����   ��       ��      ��  �����  ������ �����  ����   ����  ��      ��    ����      �� " << endl;
	cout << "  ��     ��    ��  ��       ��      ��  ��            ��     ��        ��   ��    ��    ���    ��   ��    ��     �� " << endl;
	cout << "  ��    ��         ��       ��      ��  ��            ��     ��        ��   ��    ��    �� ��   ��  ��            �� " << endl;
	cout << "  ��    ��         ��       ��      ��  �����      ��     �����  ����     ��    ��  ��  ��  ��    ���    �� " << endl;
	cout << "  ��    ��         ��       ��      ��        ��      ��     ��        ��  ��     ��    ��   �� ��  ��      ��    �� " << endl;
	cout << "  ��     ��    ��  ��       ��      ��        ��      ��     ��        ��   ��    ��    ��    ���   ��     ��    �� " << endl;
	cout << "  ��      ����   �����  �����   �����      ��     �����  ��    �� ����  ��      ��    ����      �� " << endl;
	cout << "  ��                                                                                                              �� " << endl;
	cout << "  ��                                                                                                              �� " << endl;
	cout << "  ��                                                                                                              �� " << endl;
	cout << "  ��                                                                                                              �� " << endl;
	cout << "  ��                                             <Enter> Ű���� �˻��ϱ�                                          �� " << endl;
	cout << "  ��                                                                                                              �� " << endl;
	cout << "  ��                                                                                                              �� " << endl;
	cout << "  �¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢� " << endl;
	//���� 26��

	int ch;
	ch = _getch();
	if (ch = 13)//�����Է½�
	{
		system("cls");
		keywordInputPage1();
	}
}

void keywordInputPage1()
{
	cout << endl;
	cout << "  �¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢� " << endl << endl;
	cout << "                                         Ű���� �Է� > "; cin >> a; //Ű���� �Է¹޴��Լ�


}
void keywordInputPage2() {
	cout << endl;
	cout << "  ����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << endl << endl;
}

int keyControl() {
	int key = _getch();

	if (key == 72) { //��
		return UP;
	}
	else if (key == 80) { //��
		return DOWN;
	}
	else if (key == 75) { //��
		return LEFT;
	}
	else if (key == 77) { //��
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
	cout << "1. a" << endl; i++;//Ű���� ���� ��� ��� �Լ�

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
			if (y < 7 + 5)//y�� + ��� ��簳��-1
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
//	if (ch = 13)//�����Է½�
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