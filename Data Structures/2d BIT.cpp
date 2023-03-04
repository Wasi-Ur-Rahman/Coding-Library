const int N = 2e3 + 10;

int a[N][N],t[N][N],n,m;

void upd(int x,int y,int v) {
  for (int i = x;i <= n;i += (i & -i)) {
    for (int j = y;j <= m;j += (j & -j)) {
      t[i][j] += v;
    }
  }
}

int query(int x,int y) {
  int s = 0;
  for (int i = x;i;i -= (i & -i)) {
    for (int j = y;j;j -= (j & -j)) {
      s += t[i][j];
    }
  }
  return s;
}
