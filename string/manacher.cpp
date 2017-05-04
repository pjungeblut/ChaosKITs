char input[MAX_N];
char s[2 * MAX_N + 1];
int longest[2 * MAX_N + 1];

void setDots() {
  s[0] = '.';
  int j = 1;
  for (int i = 0; i < (int)strlen(input); i++) {
    s[j++] = input[i];
    s[j++] = '.';
  }
  s[j] = '\0';
}

void manacher() {
  int center = 0, last = 0, n = strlen(s);
  memset(longest, 0, sizeof(longest));

  for (int i = 1; i < n - 1; i++) {
    int i2 = 2 * center - i;
    longest[i] = (last > i) ? min(last - i, longest[i2]) : 0;
    while (i + longest[i] + 1 < n && i - longest[i] - 1 >= 0 &&
        s[i + longest[i] + 1] == s[i - longest[i] - 1]) longest[i]++;
    if (i + longest[i] > last) {
      center = i;
      last = i + longest[i];
    }
  }
  for (int i = 0; i < n; i++) longest[i] = 2 * longest[i] + 1;
}
