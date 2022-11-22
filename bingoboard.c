#include "bingoboard.h" //헤더를 소스코드에서 가져왔다. 즉 헤더 안에 있는 내용이 여기 다 복붙이 되는 거임.  
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BINGONUM_HOLE         -1

static int bingoboard[N_SIZE][N_SIZE]; //2차원 배열의 빙고보드 생성하기  
static int numberStatus[N_SIZE*N_SIZE];
 
int bingo_checkNum(int selNum)
{
	if (numberStatus[selNum-1] == BINGONUM_HOLE)
		return BINGO_NUMSTATUS_ABSENT;
		
	return BINGO_NUMSTATUS_PRESENT; 
	
}

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



int bingo_countCompletedLine(void) // 빙고 몇개가 완성됐나  
{
	int i,j ;
	int cnt = 0;
	int checkBingo;
	
	//check row 행에 대해서 따지는 거  
	for (i=0;i<N_SIZE;i++){
		checkBingo = 1; //깃발을 올리고 시작. 번호가 살아있으면 깃발을 내리는 거임. 
		for (j=0;j<N_SIZE;j++){
			if (bingoboard[i][j] > 0) {
				checkBingo = 0;
				break;
			}
		}
		if (checkBingo == 1){
		cnt++;
	}

//col 
	for (j=0;j<N_SIZE;j++)
	{
		checkBingo=1;
		
		for (i=0;i<N_SIZE;j++){
			if (bingoboard[i][j] > 0)
			 {
				checkBingo = 0;
				break;
			}
		}
		if (checkBingo == 1)
		cnt++;
	}
	
	return cnt;
	}
 // 대각선 
 	checkBingo=1;
 	for(i=0;i<N_SIZE;i++)
 	{
 		if (bingoBoard[i][j]>0)
 	{
 			checkBingo = 0;
 			break;
	 }
 }

	if(chenkBingo ==1 )
		cnt++;
		
	checkBingo=1;
	for (i=0;i<N_SIZE;i++)
	{
		if (bingoBoard[i][N_SIZE-i-1]>0)
		{
			checkBingo = 0;
			break;
		}
	}
	if (checkBingo ==1 )
	cnt ++;
	
	return cnt;	

 
 
 
 
 
 
 
 
 
  

