#include <REGX52.H>

unsigned char SelectTube[20] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void Delay(int time)	//@11.0592MHz
{
	while(time--){
		unsigned char data i, j;

		i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);
	}
}

void Select(unsigned char Location,Num){

	switch(Location){
		case 1: P2_4=1;P2_3=1;P2_2=1;break;
		case 2: P2_4=1;P2_3=1;P2_2=0;break;
		case 3: P2_4=1;P2_3=0;P2_2=1;break;
		case 4: P2_4=1;P2_3=0;P2_2=0;break;
		case 5: P2_4=0;P2_3=1;P2_2=1;break;
		case 6: P2_4=0;P2_3=1;P2_2=0;break;
		case 7: P2_4=0;P2_3=0;P2_2=1;break;
		case 8: P2_4=0;P2_3=0;P2_2=0;break;
	}
	
	P0 = SelectTube[Num];            
	// P0 = 0x00;
}

unsigned char scanning(){
	// 扫描第一列
	P1 = 0xFF;
	P1_3 = 0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);return 1;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);return 5;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);return 9;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);return 13;}
	
	// 扫描第二列
	P1 = 0xFF;
	P1_2 = 0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);return 2;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);return 6;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);return 10;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);return 14;}
	
	// 扫描第三列
	P1 = 0xFF;
	P1_1 = 0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);return 3;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);return 7;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);return 11;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);return 15;}

	// 扫描第四列
	P1 = 0xFF;
	P1_0 = 0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);return 4;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);return 8;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);return 12;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);return 16;}
	
	return 0;
}

void main(){
	while(1){
		unsigned char keynum = scanning();
		if(keynum){
			Select(1, keynum);
		}
	}
}


