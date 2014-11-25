int rotateLeft(int n) { //returns the number of the last survivor (1 based)
	for (int i = 31; i >= 0; i--)
		if (n & (1 << i)) {
			n &= ~(1 << i);
			break;
		}
	n <<= 1; n++; return n;
}