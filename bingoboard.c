#include "bingoboard.h" //����� �ҽ��ڵ忡�� �����Դ�. �� ��� �ȿ� �ִ� ������ ���� �� ������ �Ǵ� ����.  
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BINGONUM_HOLE         -1

static int bingoboard[N_SIZE][N_SIZE]; //2���� �迭�� ������ �����ϱ�  
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


void bingo_printboard(void) //�굵 
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


void bingo_inputNum(int sel) //���� �Է� ���� �ʿ��ϴϱ� �Է¿� int, �ٵ� ����� �ʿ� �����ϱ� void. 
{
	bingoboard[numberStatus[sel-1]/N_SIZE][numberStatus[sel-1]%N_SIZE] = BINGONUM_HOLE;	
	
}



int bingo_countCompletedLine(void) // ���� ��� �ϼ��Ƴ�  
{
	int i,j ;
	int cnt = 0;
	int checkBingo;
	
	//check row �࿡ ���ؼ� ������ ��  
	for (i=0;i<N_SIZE;i++){
		checkBingo = 1; //����� �ø��� ����. ��ȣ�� ��������� ����� ������ ����. 
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
 // �밢�� 
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

 
 
 
 
 
 
 
 
 
  

