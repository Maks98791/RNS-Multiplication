# instruction set
# residue — calculation of a set of r residues mod mi (i.e. the input conversion)
# add_m—modulo addition, and
# mul_m—modulo multiplication
# add – addition
# sub – subtraction
# and – bit-wise AND and
# shr – logical shift right
# comparision, sign detection, etc.

section .data
# deklaracja wartosci A i B w rns
# A = 51,5
A: .long 51.5, 51.5, 20.5, 6.5, 2.5
# B = 70
B: .long 70, 70, 29, 10, 0 

section .text

.global _start

_start:
