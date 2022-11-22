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
		printf("select a number : "); // 안내문구 출력  
		scanf("%d", &selNum); // 번호 입력 받음  
		fflush(stdin);  //표준입력 스트림 비우기  
		
		if (selNum <1 || selNum > N_SIZE || bingo_checkNum(selNum) == BINGO_NUMSTATUS_ABSENT)
		{
			printf("%i is not on the board! select other one. \n", selNum);// 입력번호가 잘못되었거나 이미 나온 번호이면 잘못되었다고 출력  
			
		}
	}while (selNum <1 || selNum > N_SIZE || bingo_checkNum(selNum) == BINGO_NUMSTATUS_ABSENT); // 제대로된 입력이 아니면 다시  
	
	return selNum ;
}

int main(int argc, char *argv[]) {
	
	int selNum;
	srand(( unsigned)( time( NULL))); /* 랜덤한 수열 생성*/
	
	//opening 
	printf("============================================\n");
	printf("--------------------------------------------\n");	
	printf("                 BINGO GAME                 \n");	
	printf("--------------------------------------------\n");
	printf("============================================\n\n\n"); /* 미적감각 */ 
	
	//game
	
	bingo_init();
	bingo_printboard();
	selNum = get_number();
	bingo_inputNum(selNum);
	bingo_printboard();
	
	//initialize bingo board 
	bingo_init(); 
	
	 
	
	while (check_gameEnd() == BINGO_RES_UNFINISHED)  조건: 게임이 안 끝날 때. 즉 줄 수가 N_BINGO 보다 작음. 
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
	printf("============================================\n"); /* 미적감각 */
	 
	
		
	return 0;
}



 
 
 /* 

*/

