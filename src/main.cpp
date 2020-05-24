#include <stdio.h>
#include <iostream>

using namespace std;

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
	int * invBase = inverse_multiplicative(baseN, baseR);
	for(int i = 0; i < MODS_NUM; i++)
		cout << invBase[i] << " ";
	cout << endl;

	cout << "Input a: ";
	cin >> a;
	cout << endl << "Input b: ";
	cin >> b;
	
	int result = rns_montgomery_reduction(a, b);

	cout << endl << "Result of montgometry reduction is: " << result << endl;

	return (0);
}


int gcdExtended(int a, int b, int *x_out, int *y_out) 
{ 
    if (a == 0) 
    { 
        *x_out = 0, *y_out = 1; 
        return b; 
    } 
  
    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    *x_out = y1 - (b/a) * x1; 
    *y_out = x1; 
  
    return gcd; 
} 

int* inverse_multiplicative(const int * baseN, const int * baseR)
{
	int x, y, * invBase;
	invBase = new int[MODS_NUM];

	for(int i = 0; i < MODS_NUM; i++){
		gcdExtended(baseN[i], baseR[i], &x, &y);
		invBase[i] = (x % baseR[i] + baseR[i]) % baseR[i];
	}

	return invBase;
}


// computing value*R mod N (for input numbers a and b)
int compute_input_prim(int value, const int * baseR, const int * baseN)
{

}

// computing (value1*value2 + (value1*value2 * (inverse_baseN mod baseR) * baseN)) / baseR
int compute_result_prim(int value1, int value2, const int * baseN, const int * inverse_baseN, const int * baseR)
{

}

// computing (value + (value * (inverse_baseN mod baseR) * baseN)) / 128 => where value = result of compute_result_prim
int compute_result(int value, const int * baseN, const int * inverse_baseN, const int * baseR)
{

}

int convert_from_rns(const int rns[MODS_NUM])
{

}

int rns_montgomery_reduction(int a, int b)
{
	int inversed_N[MODS_NUM] = inverse_multiplicative(baseN, baseR);
	int a_prim = compute_input_prim(a, baseR, baseN);
	int b_prim = compute_input_prim(b, baseR, baseN);
	int result_prim = compute_result_prim(a, b, baseN, inversed_N, baseR);
	int result = compute_result(result_prim, baseN, inversed_N, baseR);

	return result;
}


