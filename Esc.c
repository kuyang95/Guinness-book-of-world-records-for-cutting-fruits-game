#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#include <string.h>
#include <conio.h> // kbhit()
#pragma comment(lib, "winmm.lib")

#define Third_Run "D:\\2�г� 2�б�\\C����������α׷���\\�⸻ ������Ʈ(��Ż��)\\click.wav"

#define center_x  43;
#define center_y  16; // �߾� ��ǥ��, ��������

int x = 43; y = 16;
void gotoxy(int x, int y);
void makeFence();
void printText(char *t);
void filecpy(FILE *p);
//////////////////////////////////////////////
void main() {
	system("mode con cols=124 lines=42");
	int i;
	int x = 43; // ����ũ��� 0~80
	int y = 16; // ����ũ��� 0~25
	char game[] = "�̻��� �� ver1.0";
	char *res = NULL, *text;
	char str[100];
	char choice;
	FILE *intro1, *intro2, *intro3;

	intro1 = fopen("intro1.txt", "r" );

	if (intro1 == NULL)
		fprintf(stderr, "intro1 ������ �� �� ����");

	intro2 = fopen("intro2.txt", "r");

	if (intro2 == NULL)
		fprintf(stderr, "intro2 ������ �� �� ����");

	gotoxy(x, y);
	printf("%s", game);
	Sleep(3000);

	filecpy(intro1);
	scanf("%c", &choice);
	
	if (choice == 1) {
		filecpy(intro2);
	}

	else if (choice == 2);
		exit(1);



	
		




	system("pause");
}
//////////////////////////////////////////////

void gotoxy(int x, int y) { // ��ǥ�̵� �Լ�
	COORD Pos = { x,y };
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void makeFence() { // ��Ÿ�� ����
	int i;

	gotoxy(0, 0);
	printf("��");
	for (i = 0; i < 120; i++)
		printf("��");

	printf("��");

	for (i = 1; i <= 40; i++) {
		gotoxy(0, i);
		printf("��");
		gotoxy(121, i);
		printf("��");
	}

	gotoxy(0, 40);
	printf("��");
	for (i = 0; i < 120; i++)
		printf("��");

	printf("��");
}
///////////////////////////////
void printText(char *t) {
	x = 43; y = 16;
	gotoxy(x, y);
	int keyhit = 0;
	char *p_char = (char*)malloc(sizeof(t)*sizeof(t[0]));
	int i;
	for (i = 0; i < strlen(t); i++) {
		if (_kbhit() == 1)
			keyhit = 1;

		if(keyhit == 0)
			Sleep(80);

		p_char[i] = t[i];
		if (i>0  && i % 25 == 0) {
			gotoxy(x, ++y);
		}
		printf("%c", p_char[i]);
		}	

	free(p_char);
	}

void filecpy(FILE *p) {
	system("cls");
	x = 43; y = 16;
	gotoxy(x, y);
	char ch;
	char str[100];
	int pass = 0;
	while (1) {
		

		ch = fgetc(p);
		if (ch == EOF)
			break;
		
		if (ch == '*') {
			gotoxy(x, ++y);
			continue;
		}
		else if (ch == 'p') {
			pass = 1;
			continue;
		}


		
		putchar(ch);
		if (pass == 0) {
			PlaySound(TEXT(Third_Run), NULL, SND_ASYNC | 0);
			Sleep(80);
		}
		
	}
	fclose(p);
}




