#include <REGX52.H>
#include <INTRINS.H>

void Delayms(int n)	//@11.0592MHz
{
		int i;
		for(i = 0; i < n; i++){
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
		while(1){
				P2 = 0xFE;
				Delayms(50);
				P2 = 0xFF;
				Delayms(50);
		}
}