#include <REGX52.H>
#include <INTRINS.H>

void Delayms(int n)	//@11.0592MHz
{
		int i;
		for(i = 0; i < n - 25; i++){
				unsigned char data i, j;
				_nop_();
				_nop_();
				_nop_();
				i = 11;
				j = 190;
				do
				{
					while (--j);
				} while (--i);
    }
}

void main(){
		P2 = 0xFF;
		Delayms(50);
		P2 = 0xFE;
		Delayms(50);
		P2 = 0xFD;
		Delayms(50);
		P2 = 0xFB;
		Delayms(50);
		P2 = 0xF7;
		Delayms(50);
		P2 = 0xEF;
		Delayms(50);
		P2 = 0xDF;
		Delayms(50);
		P2 = 0xBF;
		Delayms(50);
		P2 = 0x7F;
		Delayms(50);
}