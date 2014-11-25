//lsb: 0-th bit, msb: n-th bit
//get j-th bit
(a & (1 << j)) != 0
//set j-th bit
a |= (1 << j)
//clear j-th bit
a &= ~(1 << j)
//toggle j-th bit
a ^= (1 << j)
//get value of least significant bit set
(a & -a)
//turn on all bits
a = -1
//turn on first n bits (be aware of overflows)
a = (1 << n) - 1
