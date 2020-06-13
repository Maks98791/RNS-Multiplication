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
a: .float 3.5
b: .float 4.5

section .text

.global _start

_start:
