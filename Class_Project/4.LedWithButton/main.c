#include <REGX52.H>

void Delayms(unsigned int time)	//@11.0592MHz
{
	unsigned char data i, j;
	while(time){
		i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);
		time--;
	}
}


void LedOnOff_with_Button(){
	while(1){
		if(P3_1 == 0 && P3_0 == 0){
			P2_0 = 0;
		}else{
			P2_0 = 1;
		}
	}
}

void LedInvert(){
	P2_0 = 1;
	while(1){
		if (P3_1 == 0){
			// °´¼üÏû¶¶¡ý
			Delayms(5);
			while(P3_1 == 0);
			Delayms(5);
			
			P2_0 = ~P2_0;
		}
	}
}

void main(){
	LedInvert();
}