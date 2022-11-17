#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingoboard.h"
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
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
	bingo_inputNum(21);

	
	//initialize bingo board 
	
	/*
	while (game is not end)  조건: 게임이 안 끝날 때. 즉 줄 수가 N_BINGO 보다 작음. 
	{
			// bingo board print
		
			// print no. of completed line
		
			// select a number
			
			// update the board status 
	}
	*/
	
	
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
