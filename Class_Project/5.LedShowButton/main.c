#include <REGX52.H>

void Delayms(unsigned int time)
{
	unsigned char data i, j;
	while(time--){
		i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);
	}
}


void main(){
	unsigned char LEDState=0;
	while(1){
		if(P3_1 == 0){
			Delayms(15);
			while(P3_1 == 0);
			Delayms(15);
			LEDState++;
			P2 = ~LEDState;
		}
	}
}