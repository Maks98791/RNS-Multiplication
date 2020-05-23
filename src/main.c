#include <stdio.h>

#define MODS_NUM 4
const unsigned char base[MODS_NUM] = {3, 7, 15, 31};
const unsigned char inverse_base[MODS_NUM];

void convert_to_rns(int value, unsigned char rns_out[MODS_NUM]);
long long convert_from_rns(unsigned char rns[MODS_NUM]);
unsigned char fast_mod(int value, unsigned char mod);
int inverse_multiplicative(int value, int mod);
long long rns_multiply(unsigned char aRns[MODS_NUM], unsigned char bRns[MODS_NUM]);
long long rns_multiply(int a, int b);


int main()
{
	return (0);
}


long long rns_multiply(int a, int b){
	char aRns[MODS_NUM], bRns[MODS_NUM];
	convert_to_rns(a,aRns);
	convert_to_rns(b,bRns);
	rns_multiply(aRns, bRns); //Wynik mnożenia zapisany jest w aRns
	return convert_from_rns(aRns);
}

void convert_to_rns(int value, unsigned char rns_out[MODS_NUM]){
	for(char i = 0; i < MODS_NUM; i++)
		rns_out[i] = fast_mod(value, base[i]);
}

long long convert_from_rns(unsigned char rns[MODS_NUM]){

}


