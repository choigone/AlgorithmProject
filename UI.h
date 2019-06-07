#ifndef __UI_H__
#define __UI_H__

#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <vector>

#define col GetStdHandle(STD_OUTPUT_HANDLE)
#define RED SetConsoleTextAttribute( col, 0x000c);  
#define BLUE SetConsoleTextAttribute(col, 0x000b);
#define GOLD SetConsoleTextAttribute(col, 0x000e);
#define GREEN SetConsoleTextAttribute(col, 0x000a); 
#define WHITE SetConsoleTextAttribute(col, 0x000f);


void Start_menu(void);
void keywordInputPage1();
void keywordInputPage2();

//int ch;
//void P_admin(void);
//void P_stat(void);

#endif