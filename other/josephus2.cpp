int rotateLeft(int n) { // Der letzte Überlebende, 1-basiert.
	for (int i = 31; i >= 0; i--)
		if (n & (1 << i)) {
			n &= ~(1 << i);
			break;
		}
	n <<= 1; n++; return n;
}
