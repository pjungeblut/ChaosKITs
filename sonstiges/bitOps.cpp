[lsb: 0-th bit, msb: n-th bit,]

Get j-th bit:
(a & (1 << j)) != 0

Set j-th bit:
a |= (1 << j)

Clear j-th bit:
a &= ~(1 << j)

Toggle j-th bit:
a ^= (1 << j)

Get value of first set bit:
(a & -a)

Turn on all bits:
a = -1

Turn on first n bits:
a = (1 << n) - 1
