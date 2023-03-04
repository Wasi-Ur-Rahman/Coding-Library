int GCD(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a < b) swap(a, b);
  return GCD(a % b, b);
}
