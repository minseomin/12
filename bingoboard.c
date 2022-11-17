#include "bingoboard.h" //헤더를 소스코드에서 가져왔다. 즉 헤더 안에 있는 내용이 여기 다 복붙이 되는 거임.  
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BINGONUM_HOLE         -1

static int bingoboard[N_SIZE][N_SIZE]; //2차원 배열의 빙고보드 생성하기  
static int numberStatus[N_SIZE*N_SIZE];
 
void bingo_init(void)
{
	int i,j;
	int cnt = 1;
	
	for (i=0; i<N_SIZE;i++)
		for (j=0;j<N_SIZE;j++)
		{
			if (cnt == 15)
			{
			bingoboard[i][j] = BINGONUM_HOLE;
			numberStatus[cnt-1] = BINGONUM_HOLE;
			
			cnt++;
			}
		else
		{
			numberStatus[cnt-1] = i*N_SIZE +j;
			bingoboard[i][j] = cnt++;
		}
		printf("\n");
		}
	printf("============================\n\n");
}


void bingo_printboard(void) //얘도 
{
	int i, j;
	
	printf("=======================\n");
	for (i=0;i<N_SIZE;i++) {
		for (j=0;j<N_SIZE;j++) {
			if (bingoboard[i][j] == BINGONUM_HOLE)
				printf("X\t");
			else
				printf("%i\t",bingoboard[i][j]);
		}
	printf("\n");
	}
	printf("====================\n\n");
}

void bingo_inputNum(int sel) //정수 입력 값이 필요하니까 입력에 int, 근데 출력은 필요 없으니까 void. 
{
	bingoboard[numberStatus[sel-1]/N_SIZE][numberStatus[sel-1]%N_SIZE] = BINGONUM_HOLE;	
	
}


int bingo_countCompletedLine(void) //몇 줄이 생겼다, 즉 리턴값은 정수로 나와야 하니까 int 로 정의해주기.
{
	
}

/*int get_number(void)
{
	int selNum = 0;
	
	do {
		printf("select a number : "); // 안내문구 출력  
		scanf("%d", $selNum); // 번호 입력 받음  
		fflush(stdin);  //표준입력 스트림 비우기  
		
		if (bingo_checkNum(selNum) == BINGO_NUMSTATUS_ABSENT)
		{
			printf("%i is not on the board! select other one. \n", selNum);// 입력번호가 잘못되었거나 이미 나온 번호이면 잘못되었다고 출력  
			
		}
	}while (selNum <1 || selNum > N_SIZE || bingo_checkNum(selNum) == BINGO_NUMSTATUS_ABSENT)// 제대로된 입력이 아니면 다시  
	
	return selNum ;
}

 */
