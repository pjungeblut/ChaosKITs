// Bit an Position j auslesen.
(a & (1 << j)) != 0
// Bit an Position j setzen.
a |= (1 << j)
// Bit an Position j löschen.
a &= ~(1 << j)
// Bit an Position j umkehren.
a ^= (1 << j)
// Wert des niedrigsten gesetzten Bits.
(a & -a)
// Setzt alle Bits auf 1.
a = -1
// Setzt die ersten n Bits auf 1. Achtung: Overflows.
a = (1 << n) - 1
// Iteriert über alle Teilmengen einer Bitmaske (außer der leeren Menge).
for (int subset = bitmask; subset > 0; subset = (subset - 1) & bitmask)
// Anzahl der gesetzten Bits.
int __builtin_popcount(unsigned int x);
int __builtin_popcountll(unsigned long long x);
// Anzahl der führenden 0-Bits.
int __builtin_clz(unsigned int x);
int __builtin_clzll(unsigned long long x);
