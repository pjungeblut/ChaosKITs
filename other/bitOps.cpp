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
// Zählt Anzahl der gesetzten Bits.
int numberOfSetBits(int i) {
  i = i - ((i >> 1) & 0x55555555);
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
  return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}
