#include "bingoboard.h" //����� �ҽ��ڵ忡�� �����Դ�. �� ��� �ȿ� �ִ� ������ ���� �� ������ �Ǵ� ����.  
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BINGONUM_HOLE         -1

static int bingoboard[N_SIZE][N_SIZE]; //2���� �迭�� ������ �����ϱ�  
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


int bingo_countCompletedLine(void) //�� ���� �����, �� ���ϰ��� ������ ���;� �ϴϱ� int �� �������ֱ�.
{
	
}

/*int get_number(void)
{
	int selNum = 0;
	
	do {
		printf("select a number : "); // �ȳ����� ���  
		scanf("%d", $selNum); // ��ȣ �Է� ����  
		fflush(stdin);  //ǥ���Է� ��Ʈ�� ����  
		
		if (bingo_checkNum(selNum) == BINGO_NUMSTATUS_ABSENT)
		{
			printf("%i is not on the board! select other one. \n", selNum);// �Է¹�ȣ�� �߸��Ǿ��ų� �̹� ���� ��ȣ�̸� �߸��Ǿ��ٰ� ���  
			
		}
	}while (selNum <1 || selNum > N_SIZE || bingo_checkNum(selNum) == BINGO_NUMSTATUS_ABSENT)// ����ε� �Է��� �ƴϸ� �ٽ�  
	
	return selNum ;
}

 */
