#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>

#define EXT_CH 0xffffffe0

void gotoxy(int, int);

int main(void){
	char key;
	int x=0, y=0;

    system("cls");

	while(1){

		key=getch();

		switch(key){
			case 72: /*printf("위로\n");*/ gotoxy(x,--y); printf("*"); break;
			case 77: /*printf("오른쪽으로\n");*/ gotoxy(++x, y); printf("*"); break;
			case 80: /*printf("아래로\n");*/ gotoxy(x, ++y); printf("*"); break;
			case 75: /*printf("왼쪽으로\n");*/ gotoxy(--x, y); printf("*"); break;}

	if(x<=0)
		x=0;
	if(x>50)
		x=50;
	if(y<=0)
		y=0;
	if(y>24)
		y=25;

		if(key==EXT_CH)
			continue;

		if(key=='q')
			break;
	}

	return 0;
}
void gotoxy(int x, int y)
{
	HANDLE h;
	COORD pos;

	h=GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X=x;
	pos.Y=y;

	if(x<=0)
		x=0;
	if(x>50)
		x=50;
	if(y<=0)
		y=0;
	if(y>24)
		y=25;
	SetConsoleCursorPosition(h, pos);
}