// ����Լ��� h�ٿ���

#define N_LINE 2
#define N_SIZE 5//��ũ�θ� �����ϴ� ����  
#define BINGO_NUMSTATUS_ABSENT -1//�����忡 Ȯ���� ���� ���ڷ� �����صα� 
#define BINGO_NUMSTATUS_PRESENT 0  
 
void bingo_init(void); //�Լ� ����. ������� ������ void�� ������. 
void bingo_printboard(void); //�굵 
void bingo_inputNum(int sel); //���� �Է� ���� �ʿ��ϴϱ� �Է¿� int, �ٵ� ����� �ʿ� �����ϱ� void. 
int bingo_countCompletedLine(void); //�� ���� �����, �� ���ϰ��� ������ ���;� �ϴϱ� int �� �������ֱ�.
int bingo_checkNum(int selNum);
