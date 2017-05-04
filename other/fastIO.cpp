void fastscan(int* number) {
  bool negative = false;
  register int c;
  *number = 0;
  c = getchar();
  while(c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') negative = true, c = getchar();
  for (; c > 47 && c < 58; c = getchar()) *number = *number * 10 + c - 48;
  if (negative) *number *= -1;
}

void printPositive(int n) {
  if (n == 0) return;
  print(n / 10);
  putchar(n % 10 + '0');
}

void fastprint(int n) {
  if(n == 0) { putchar('0'); return; }
  if (n < 0) {
    putchar('-');
    print(-n);
  } else print(n);
}
