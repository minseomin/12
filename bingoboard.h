// 헤더함수라서 h붙여놈

#define N_LINE 2
#define N_SIZE 5//메크로를 정의하는 문법  
#define BINGO_NUMSTATUS_ABSENT -1//빙고보드에 확실히 없는 숫자로 정의해두기 
#define BINGO_NUMSTATUS_PRESENT 0  
 
void bingo_init(void); //함수 정의. 입출력이 없도록 void로 정의함. 
void bingo_printboard(void); //얘도 
void bingo_inputNum(int sel); //정수 입력 값이 필요하니까 입력에 int, 근데 출력은 필요 없으니까 void. 
int bingo_countCompletedLine(void); //몇 줄이 생겼다, 즉 리턴값은 정수로 나와야 하니까 int 로 정의해주기.
int bingo_checkNum(int selNum);
