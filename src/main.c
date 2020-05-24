#include <stdio.h>

#define MODS_NUM 9
int a, b;
const int baseN[MODS_NUM] = {3,5,7,11,13,17,19,23,29};
const int baseR[MODS_NUM] = {4,8,8,16,16,32,32,32,32};

int* inverse_multiplicative(const int * baseN, const int * baseR);
// computing value*R mod N (for input numbers a and b)
int compute_input_prim(int value, const int * baseR, const int * baseN);
// computing (value1*value2 + (value1*value2 * (inverse_baseN mod baseR) * baseN)) / baseR
int compute_result_prim(int value1, int value2, const int * baseN, const int * inverse_baseN, const int * baseR);
// computing (value + (value * (inverse_baseN mod baseR) * baseN)) / 128 => where value = result of result 
int compute_result(int value, const int * baseN, const int * inverse_baseN, const int * baseR);
int convert_from_rns(const int rns[MODS_NUM]);
int rns_montgomery_reduction(int a, int b);


int main()
{
	cout << "Input a: ";
	cin >> a;
	cout << endl << "Input b: ";
	cin >> b;
	
	int result = rns_montgomery_reduction(a, b);

	cout << endl << Result of montgometry reduction is: << result << endl;

	return (0);
}


int* inverse_multiplicative(const int * baseN, const int * baseR)
{

}

// computing value*R mod N (for input numbers a and b)
int compute_input_prim(int value, const int * baseR, const int * baseN)
{

}

// computing (value1*value2 + (value1*value2 * (inverse_baseN mod baseR) * baseN)) / baseR
int compute_result_prim(int value1, int value2, const int * baseN, const int * inverse_baseN, const int * baseR)
{

}

// computing (value + (value * (inverse_baseN mod baseR) * baseN)) / 128 => where value = result of result 
int compute_result(int value, const int * baseN, const int * inverse_baseN, const int * baseR)
{

}

int convert_from_rns(const int rns[MODS_NUM])
{

}

int rns_montgomery_reduction(int a, int b)
{

}


