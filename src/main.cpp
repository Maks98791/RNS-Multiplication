#include <stdio.h>
#include <iostream>

using namespace std;

#define MODS_NUM 3

int a, b;
//const int baseN[MODS_NUM] = {3,5,7,11,13,17,19,23,29};
//const int baseR[MODS_NUM] = {4,8,8,16,16,32,32,32,32};

const int baseN[MODS_NUM] = {3,5,7};
const int baseR[MODS_NUM] = {4,8,8};

//Needed to convert from rns to positional
int * mod_product;
int * mod_product_inv;
int baseN_product;


int * inverse_multiplicative(const int * baseN, const int * baseR);
int * create_mod_product();
int* inverse_multiplicative(const int * baseN, const int * baseR);
// computing value*R mod N (for input numbers a and b)
int * compute_input_prim(int value, const int * baseR, const int * baseN);
// computing (value1*value2 + (value1*value2 * (inverse_baseN mod baseR) * baseN)) / baseR
int * compute_result_prim(int value1, int value2, const int * baseN, const int * inverse_baseN, const int * baseR);
// computing (value + (value * (inverse_baseN mod baseR) * baseN)) / 128 => where value = result of result 
int * compute_result(int value, const int * baseN, const int * inverse_baseN, const int * baseR);
int convert_from_rns(int * rns);
int rns_montgomery_reduction(int a, int b);


int main()
{
	baseN_product = 1;

	for(int i = 0; i < MODS_NUM; i++)
	{
		baseN_product *= baseN[i];
	}

	mod_product = create_mod_product();
	mod_product_inv = inverse_multiplicative(mod_product, baseN);

	cout << endl << "Input a: ";
	cin >> a;
	cout << endl << "Input b: ";
	cin >> b;
	
	int result = rns_montgomery_reduction(a, b);

	cout << endl << "Result of montgometry reduction is: " << result << endl;

	return (0);
}


int gcdExtended(int a, int b, int * x_out, int * y_out) 
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

int * inverse_multiplicative(const int * baseN, const int * baseR)
{
	int x, y, * invBase;
	invBase = new int[MODS_NUM];

	for(int i = 0; i < MODS_NUM; i++)
	{
		gcdExtended(baseN[i], baseR[i], &x, &y);
		invBase[i] = (x % baseR[i] + baseR[i]) % baseR[i];
	}

	return invBase;
}

// computing value*R mod N (for input numbers a and b)
int * compute_input_prim(int value, const int * baseR, const int * baseN)
{
	int * result = new int[MODS_NUM];

	for(int i=0; i < MODS_NUM; i++)
	{
		int first_step = value * baseR[i];
		int residue = first_step % baseN[i];

		result[i] = residue;
	}

	return result;
}

// computing (value1*value2 + (value1*value2 * (inverse_baseN mod baseR) * baseN)) / baseR
int * compute_result_prim(int * value1, int * value2, const int * baseN, const int * inverse_baseN, const int * baseR)
{
	int * result = new int[MODS_NUM];
	
	for(int i=0; i < MODS_NUM; i++)
	{
		int entries = value1[i] * value2[i];
		int computies = (entries + (entries * (-inverse_baseN[i] % baseR[i])) * baseN[i]) / baseR[i];
		int residue = computies % baseN[i];

		result[i] = residue;
	}

	return result;
}

// computing (value + (value * (inverse_baseN mod baseR) * baseN)) / 128 => where value = result of compute_result_prim
int * compute_result(int * value, const int * baseN, const int * inverse_baseN, const int * baseR)
{
	int * result = new int[MODS_NUM];
	
	for(int i=0; i < MODS_NUM; i++)
	{
		int computies = (value[i] + (value[i] * (-inverse_baseN[i] % baseR[i]) * baseN[i])) / baseR[i];
		int residue = computies % baseN[i];

		result[i] = residue;
	}

	return result;
}

int * create_mod_product()
{
	int * mod_product = new int[MODS_NUM];
	int product;

	for(int i = 0; i < MODS_NUM; i++)
	{
		product = 1;

		for(int j = 0; j < MODS_NUM; j++)
		{
			if(j != i)
			{
				product *= baseN[j];
			}
		}
		
		mod_product[i] = product;
	}

	return mod_product;
}

int convert_from_rns(int rns[MODS_NUM])
{
	int result = 0;
	
	for(int i = 0; i < MODS_NUM; i++)
	{
		result += mod_product[i] * (mod_product_inv[i] % baseN[i]) * rns[i];
	}

	return result % baseN_product;
}

void print_mods_array(int * array){
	for(int i = 0; i < MODS_NUM; i++)
		cout << array[i] << " ";
	cout << endl;
}

int rns_montgomery_reduction(int a, int b)
{
	int * inversed_N = inverse_multiplicative(baseN, baseR);
	int * a_prim = compute_input_prim(a, baseR, baseN);
	print_mods_array(a_prim);
	int * b_prim = compute_input_prim(b, baseR, baseN);
	print_mods_array(b_prim);
	int * result_prim = compute_result_prim(a_prim, b_prim, baseN, inversed_N, baseR);
	print_mods_array(result_prim);
	int * result = compute_result(result_prim, baseN, inversed_N, baseR);
	print_mods_array(result);
	int converted_result = convert_from_rns(result);

	return converted_result;
}


