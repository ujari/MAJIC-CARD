#define _CRT_SECURE_NO_WARNINGS
#include<windows.h>
#include<stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <ctype.h>

int intro()
{
	printf("\t\t┌────────────────────────┐\n");
	printf("\t\t│                        │\n");
	printf("\t\t│                        │\n");
	printf("\t\t│                        │\n");
	printf("\t\t│마술카드에 오신 여러분을│ \n\t\t│\t환영합니다.      │ \n");
	printf("\t\t│                        │\n");
	printf("\t\t│   엔터를 눌러주세요.   │\n");
	printf("\t\t│                        │\n");
	printf("\t\t│                        │\n");
	printf("\t\t│                        │\n");
	printf("\t\t└────────────────────────┘\n");

	int i;
	i = getchar();
	if (i == '\n') {
		system("cls"); //콘솔화면 지우기
		return 1;
	}
	
}

void clearInputBuffer() {
	while (getchar() != '\n');
}

int cardchoice()
{
	int n=0;
	
	printf("몇장의 카드로 진행하실 건가요? (3장 이상의 카드가 필요합니다.) : ");
	scanf("%d", &n);
	
	return n;
}

void bit(int max,int n)
{
	for (int i = 0; i < max; i++)
	{
		if ((i >> n & 1) == 1) {
			printf("%d\n", i);
		}
	}
}

int main()
{
	if (intro() == 1)
	{


		int re = 0;
		int cho;
		int n = cardchoice();//n= 선택한 카드의 수
		int max = pow(2, n);//선택할 수 있는 최대 값 = 0 ~ max-1

		printf("0 ~ %d의 숫자중 한 숫자를 마음속으로 생각해주세요 !\n", max - 1);
		Sleep(1000);
		printf("5...");
		Sleep(1000);
		printf("4...");
		Sleep(1000);
		printf("3...");
		Sleep(1000);
		printf("2...");
		Sleep(1000);
		printf("1...");

		////////////////////////////////////////////
		for (int j = 0; j < n; j++) {
			system("cls");
			bit(max,j);
			printf("이 숫자들 중 원하시는 숫자가 있으면 1 아니면 0을 눌러주세요");
			scanf("%d", &cho);
			if (cho == 1)
			{
				re += pow(2, j);
			}
			printf("\n");
		}


		printf("결과는.... %d", re);
	}
	else
	{
		return 0;
	}
}