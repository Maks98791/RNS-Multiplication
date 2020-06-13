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
# to chyba do wyjebania bo nie zauwazylem ze f_residue samo konwertuje ale na razie zostawiam
# declaration of A and B in RNS system
# A = 51,5
# A: .long 51.5, 51.5, 20.5, 6.5, 2.5
# B = 70
# B: .long 70, 70, 29, 10, 0
# declaration of modul base
# modul_base: .long 8192, 127, 31, 15, 7

.section .bss
# tu beda zapisane nasze liczby jako tablice
# 20 bo jako 5 intów 4 bajtowych
.lcomm A, 20
.lcomm B, 20

section .text

.global _start

_start:

# convert A to rns
f_residue 51.5, (8192, 127, 31, 15, 7), A

# convert B to rns
f_residue 70, (8192, 127, 31, 15, 7), B

# checking sign of argument A
detect_sign acc

# checking sign of argument B
detect_sign acc2

# multiply corresponding numbers

# convert to MRN (mix radix) and establish RF (rounding flag)

# convert to rns skipping last values

# correct result depending on RF
