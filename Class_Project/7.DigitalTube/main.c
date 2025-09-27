#include <REGX52.H>

unsigned char SelectTube[20] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void Delay50ms(void)	//@11.0592MHz
{
	unsigned char data i;

	i = 110;
	while (--i);
}


void Select(unsigned char Location,Num){

	// Ƭѡ
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
	P0 = 0x00;
}

void main(){
	while(1){
		Select(1,1);
		Select(2,3);
		Select(3,1);
		Select(4,4);
		Select(5,5);                              
		Select(6,2);
		Select(7,1);
		Select(8,1);
	}
}


