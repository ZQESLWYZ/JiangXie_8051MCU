#include <REGX52.H>

void Delayms(unsigned char time)
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

unsigned char LEDState = 1;

void main(){
	P2 = 0xFF;
	while(1){
		if(P3_1 == 0){
			Delayms(15);
			while(P3_1 == 0);
			Delayms(15);
			
			P2 = ~LEDState;
			LEDState = LEDState << 0x01;
			
			if(LEDState == 0)
				LEDState = 1;
		}
	}
}
