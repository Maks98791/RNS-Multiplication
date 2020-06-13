# instruction set
# residue — calculation of a set of r residues mod mi (i.e. the input conversion)
# add_m—modulo addition, and
# mul_m—modulo multiplication
# add – addition
# sub – subtraction
# and – bit-wise AND and
# shr – logical shift right
# comparision, sign detection, etc.

# accumulators: acc, acc2

# when typing acc_m1, we refers to the first value of accumulator

section .data
m1=7, m2=15, m3=31, m4=127, m5=8192

.section .bss
# tu beda zapisane nasze liczby jako tablice
# 20 bo jako 5 intów 4 bajtowych
.lcomm A, 20
.lcomm B, 20

section .text

.global _start

_start:

# convert A to rns
f_residue 51.5, (m1, m2, m3, m4, m5), A

# convert B to rns
f_residue 70, (m1, m2, m3, m4, m5), B

# multiply corresponding numbers
f_mul_m acc, acc2, acc

# convert to MRN (mix radix) and establish RF (rounding flag)
mov acc_m1, acc2_m1
sub acc, acc_m1, acc
f_mul_m acc, (0, 1/m1%m2, 1/m1%m3, 1/m1%m4, 1/m1%m5), acc

mov acc_m2, acc2_m2
sub acc, acc_m2, acc
f_mul_m acc, (0, 0, 1/m2%m3, 1/m2%m4, 1/m2%m5), acc

mov acc_m3, acc2_m3
sub acc, acc_m3, acc
f_mul_m acc, (0, 0, 0, 1/m3%m4, 1/m3%m5), acc

mov acc_m4, ac2_m4
sub acc, acc_m4, acc
f_mul_m acc, (0, 0, 0, 0, 1/m4%m5), acc

mov acc_m5, acc2_m5
sub acc, acc_m5, acc
f_mul_m acc, (0, 0, 0, 0, 0), acc

# convert to rns skipping last values
f_add_m acc2_m5, acc, acc
f_mul_m acc, m4, acc

f_add_m acc2_m4, acc, acc
f_mul_m acc, m3, acc

f_add_m acc2_m3, acc, acc
