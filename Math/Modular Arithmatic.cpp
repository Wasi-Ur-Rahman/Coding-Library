ll mulMod (ll a, ll b, ll M) { 
  a %= M, b %= M; 
  if(M <= 1000000009) return a * b % M; 
  ll res = 0;
  while(a > 0) {
    a %= M, b %= M; 
    if (a & 1) { 
      res += b; 
      if (res >= M) res -= M;
    } 
    a >>= 1; b <<= 1; b %= M;
    if (b >= M) b -= M;
  } 
  return res;
}


ll bigMod(ll p, ll q, ll M) { 
  ll ans = 1;
  while(q) { 
    if(q & 1) ans = mulMod(ans, p, M); 
    p = mulMod(p, p, M); 
    q>>=1;
  } 
  return ans % M;
}


ll inverseMod(ll p, ll M) { 
  return bigMod(p, M - 2, M);
}

inline int add(int a, int b, int mod) {a += b ; return a >= mod ? a - mod : a ;}
inline int sub(int a, int b, int mod) {a -= b ; return a < 0 ? a + mod : a ;}
inline int mul(int a, int b, int mod) {return (int)a * b % mod ;}
