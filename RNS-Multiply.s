//Mnożenie liczb w acc i acc2

f_mul_m acc, acc2, digits


//Konwersja RNS do MRN

f_mul_m digits, (0,0,0,0,1), acc
f_residue acc, 0, acc
f_mul_m acc, (-1,-1,-1,-1,0), acc
f_add_m acc, digits, acc
f_mul_m acc, (1/m1%m5, 1/m1%m4, 1/m1%m3, 1/m1%m2, 1), digits

f_mul_m digits, (0,0,0,1,0), acc
f_residue acc, 0, acc
f_mul_m acc, (-1,-1,-1,0,0), acc
f_add_m acc, digits, acc
f_mul_m acc, (1/m2%m5, 1/m2%m4, 1/m2%m3, 1, 1), digits

f_mul_m digits, (0,0,1,0,0), acc
f_residue acc, 0, acc
f_mul_m acc, (-1,-1,0,0,0), acc
f_add_m acc, digits, acc
f_mul_m acc, (1/m3%m5, 1/m3%m4, 1, 1, 1), digits

f_mul_m digits, (0,1,0,0,0), acc
f_residue acc, 0, acc
f_mul_m acc, (-1,0,0,0,0), acc
f_add_m acc, digits, acc
f_mul_m acc, (1/m4%m5, 1, 1, 1, 1), digits


//Konwersja MRN do RNS z pominięciem 2 ostatnich modułów

f_mul_m acc, (0,0,0,0,0), acc2

f_mul_m digits, (1,0,0,0,0), acc
f_residue acc, 0, acc
f_add_m acc, acc2, acc2
f_mul_m acc2, (m4,m4,m4,m4,m4), acc2

f_mul_m digits, (0,1,0,0,0), acc
f_residue acc, 0, acc
f_add_m acc, acc2, acc2
f_mul_m acc2, (m3,m3,m3,m3,m3), acc2

f_mul_m digits, (0,0,1,0,0), acc
f_residue acc, 0, acc
f_add_m acc, acc2, acc2
