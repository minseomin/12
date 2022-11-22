#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingoboard.h"

#define BINGO_RES_UNFINISHED -1
#define BINGO_RES_FINISHED 0

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

 int check_gameEnd(void) {
 	int res = BINGO_RES_UNFINISHED;
 	if (bingo_countCompletedLine() >= N_LINE)
 	res = BINGO_RES_FINISHED;
 	
 	return res; } 
 	
int get_number(void)
{
	int selNum = 0;
	
	do {
		printf("select a number : "); // �ȳ����� ���  
		scanf("%d", &selNum); // ��ȣ �Է� ����  
		fflush(stdin);  //ǥ���Է� ��Ʈ�� ����  
		
		if (selNum <1 || selNum > N_SIZE || bingo_checkNum(selNum) == BINGO_NUMSTATUS_ABSENT)
		{
			printf("%i is not on the board! select other one. \n", selNum);// �Է¹�ȣ�� �߸��Ǿ��ų� �̹� ���� ��ȣ�̸� �߸��Ǿ��ٰ� ���  
			
		}
	}while (selNum <1 || selNum > N_SIZE || bingo_checkNum(selNum) == BINGO_NUMSTATUS_ABSENT); // ����ε� �Է��� �ƴϸ� �ٽ�  
	
	return selNum ;
}

int main(int argc, char *argv[]) {
	
	int selNum;
	srand(( unsigned)( time( NULL))); /* ������ ���� ����*/
	
	//opening 
	printf("============================================\n");
	printf("--------------------------------------------\n");	
	printf("                 BINGO GAME                 \n");	
	printf("--------------------------------------------\n");
	printf("============================================\n\n\n"); /* �������� */ 
	
	//game
	
	bingo_init();
	bingo_printboard();
	selNum = get_number();
	bingo_inputNum(selNum);
	bingo_printboard();
	
	//initialize bingo board 
	bingo_init(); 
	
	 
	
	while (check_gameEnd() == BINGO_RES_UNFINISHED)  ����: ������ �� ���� ��. �� �� ���� N_BINGO ���� ����. 
	{
		// bingo board print
		bingo_printboard(); 
	
		// print no. of completed line
		printf("No. of completed line : %i\n", bingo_countCompletedLind());
		
		// select a number
		selNum = get_number();	
		
		// update the board status 
		bingo_inputNum(selNum);
	}
	
	
	//ending
	printf("\n\n\n\n\n\n\n");
	printf("============================================\n");
	printf("********************************************\n");
	printf("        !!!!!!!CONGRATULATION!!!!!!!        \n"); 
	printf("                  BINGO!!!!                 \n");
	printf("                ! YOU WIN !                 \n");
	printf("********************************************\n");
	printf("============================================\n"); /* �������� */
	 
	
		
	return 0;
}



 
 
 /* 

*/

