#define _CRT_SECURE_NO_WARNINGS
#include<windows.h>
#include<stdio.h>
#include <math.h>
#include <limits.h>
#include<time.h>
#include<stdlib.h>

//초기 화면을 출력해주는 함수
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

//사용자가 잘못 된 입력을 했을때 예외처리를 위해 키보드버퍼를 비워주는 함수
void clearInputBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {} // 버퍼 비우기
}

//사용자가 게임선택, 만든이 소개 등을 할 수 있도록 선택을 하는 함수
int menu()
{
	int input;//사용자가 입력한 값을 저장하는 변수
	while (1)
	{	
		while (1)
		{

			printf("게임시작 : 1   만든이 소개 : 2   게임 종료 : 0\n");
			printf("\n\n입력 >>");
			int result = scanf("%d", &input);
			system("cls");
			if ((input < 0 || input>4)||result!=1)
			{
				printf("잘못된 입력입니다. 다시 입력해주세요\n");
				clearInputBuffer(); 
				
			}
			else
			{
				break;
			}
		}

		if (input == 2)//사용자가 만든이 보기를 선택한 경우
		{

			if (inform() == 0) continue; // inform에서 돌아가기를 선택했을 때 메뉴를 다시 보여줍니다.
		}
		else if (input == 0)//사용자가 프로그램 종료를 입력한 경우
		{
			printf("프로그램을 종료합니다. 이용해주셔서 감사합니다.");
			Sleep(1000);
			exit(0);
		}
		else
		{
			break;
		}
	}


	return input;
}


//사용자가 카드를 몇장 이용해 진행 할지 선택해주는 함수
int cardchoice()
{
	int n = 0, result;
	while (1)
	{
		printf("곧 마술카드가 시작합니다. !!!\n!!! 집중해 주세요 !!!\n");
		Sleep(1500);
		system("cls");
		printf("몇 장의 카드로 진행하실 건가요?  : ");
		result = scanf("%d", &n);//result 값에 정수를 입력했는지 저장

		if (result != 1 || n < 0) // 정상적으로 정수를 입력받지 않았거나 음수를 입력한 경우
		{
			system("cls");
			printf("잘못된 입력입니다. 다시 입력해주세요\n");
			clearInputBuffer(); // 버퍼 비우기
		}
		else
		{
			break; // 올바른 입력
		}
	}

	return n;//사용자가 선택한 카드의 수를 반환
}


//사용자에게 각 카드의 배정된 숫자를 보여주는 로직
void showcard(unsigned long long max, int n) {//max는 사용자가 선택한 카드의 수에 따라 최대로 나타 낼 수 있는 최댓값 . n은 사용자에게 n번째 카드를 나타내줌
	
	unsigned long long mask = 1ull << n;//1을 왼쪽 쉬프트를 해주며 2진수의 n의 자릿수의 1이 있는 숫자를 mask변수에 저장

	for (unsigned long long i = 0; i < max; i++) {//최댓값까지 i를 통해 반복
		if ((i & mask) != 0) {//i가 저장한 mask와 같다면 출력
			printf("%llu ", i);
		}
	}
}

//사용자에게 부가 정보를 출력해주는 함수
int inform()
{
	int input = 0;
	while (1) {
		printf("만든이 : 홍길동\n");
		printf("소속 : 대학교 컴퓨터공학과\n");
		printf("프로젝트 지도교수 : 기미니 교수님\n");
		printf("\n돌아가기는 1   종료  0");
		printf("\n\n입력 >>");

		int result = scanf("%d", &input);//사용자가 정수를 정확히 입력했는지 확인하기 우ㅏ해 변수에 저장

		if (result != 1 || (input != 0 && input != 1)) // 정상적으로 입력받지 않았거나 입력값이 0 또는 1이 아닌 경우
		{
			system("cls");
			printf("잘못된 입력입니다. 다시 입력해주세요\n");
			clearInputBuffer(); // 버퍼 비우기
		}
		else
		{
			break; // 올바른 입력
		}
	}

	system("cls");
	if (input == 1)
	{
		return 0; // 돌아가기
	}
	else
	{
		printf("프로그램을 종료합니다. 이용해주셔서 감사합니다.");
		Sleep(1000);
		exit(0); // 프로그램 종료
	}
}

//전체적인 게임을 진행해주는 함수
void game()
{
	int re = 0;


	int n = cardchoice();//n= 선택한 카드의 수
	unsigned long long max = 0;
	if (n == 64) {
		max = ULLONG_MAX;
	}
	else
	{
		max = pow(2, n);
	}
	printf("0 ~ %llu의 숫자중 한 숫자를 마음속으로 생각해주세요 !\n", max - 1);


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
	Sleep(1000);
	system("cls");
	for (int j = 0; j < n; j++) {//0부터 사용자가 선택학 n까지에 해당하는 각 카드를 순차적으로 보여줌
		int answer;//사용자가 응답한 답을 변수에 저장
		showcard(max, j);//각 카드를 출력해주는 함수 호출
		printf("\n");
		while (1)
		{


			printf("이 카드에 당신이 생각한 숫자가 있나요? 있으면 1을, 없으면 0을 입력하세요: ");
			int result = scanf("%d", &answer);
			if (result != 1 || (answer != 0 && answer != 1))
			{
				system("cls");
				printf("잘못된 입력입니다. 다시 입력해주세요\n");
				clearInputBuffer(); // 버퍼 비우기
			}
			else
			{
				break; // 올바른 입력
			}
		}


		if (answer == 1)
		{
			re += pow(2, j);//변수에 n-1번째 만큼 제곱해 변수에 더함
		}
		system("cls");
		printf("\n");
	}
	
	printf("결과는.... ");
	printf("3...");
	Sleep(1000);
	printf("2...");
	Sleep(1000);
	printf("1...");
	Sleep(1000);
	system("cls");
	printf("!!! %d !!!", re);
}

int main()
{

	if (intro() == 1)
	{
		
		int choice = menu();
		if (choice == 1)
		{
			game();
		}
		else
		{
			exit(0);
		}
		
		
	}
	else
	{
		return 0;
	}
}