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
# declaration of A and B in RNS system
# A = 51,5
A: .long 51.5, 51.5, 20.5, 6.5, 2.5
# B = 70
B: .long 70, 70, 29, 10, 0
# declaration of modul base
modul_base: .long 8192, 127, 31, 15, 7

section .text

.global _start

_start:

# checking sign of argument A

# checking sign of argument B

# multiply corresponding numbers

# convert to MRN (mix radix) and establish RF (rounding flag)

# convert to rns skipping last values

# correct result depending on RF
