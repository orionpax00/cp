#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

using i64=long long;
using vx=vector<i64>;

const i64 MOD=1e9+7;

i64 modpow(i64 b, i64 p, i64 m=MOD) {
    /* Exponentiation by squaring */
    // returns n == b**p (mod m)
    i64 n=1, a=b%m;
    while (p) {
        if (p & 1)
            (n *= a) %= m;

        (a *= a) %= m;
        p >>= 1;
    }
    return n;
}

i64 modinv(i64 a, i64 p=MOD) {
    // returns n == a**-1 (mod p)
    return modpow(a, p-2, p);
}

i64 moddiv(i64 a, i64 b, i64 p=MOD) {
    // returns n == a b**-1 (mod p)
    return a*modpow(b, p-2, p) % p;
}

i64 modsub(i64 a, i64 b, i64 p=MOD) {
    // returns n == a-b (mod p)
    return ((a-b)%p+p) % p;
}

void table_modfact(int n, vx &ftable, int p=1e9+7) {
    // returns {i! mod p; for i in [0, n)}
    ftable.assign(n, 0); ftable[0]=1;

    int ub=min(n, p);
    for (int i=1; i<ub; ++i)
        ftable[i] = (ftable[i-1]*i) % p;
}

void table_modfactinv(int n, vx &itable, i64 factn=-1, i64 p=1e9+7) {
    // returns {i!**-1 mod p; for i in [0, n)}
    itable.assign(n, 0);

    if (n >= p)
        n = p-1;

    if (factn == -1) {
        factn = 1;
        for (int i=1; i<n; ++i)
            factn = (factn*i) % p;
    }
    itable[n-1] = modinv(factn);
    for (int i=n-1; i--;)
        itable[i] = (itable[i+1]*(i+1)) % p;
}

i64 modchoose(i64 n, i64 r, const vx &ftable, const vx &itable, i64 p=MOD) {
    if (n<0 || n<r || r<0) return 0;

    return (ftable[n]*itable[r]%p)*itable[n-r] % p;
}

int main() {
    i64 H, W, A, B;
    scanf("%lld %lld %lld %lld", &H, &W, &A, &B);

    vx ftable; table_modfact(H+W-1, ftable);
    vx itable; table_modfactinv(H+W-1, itable, ftable[H+W-2]);

    i64 res=0;
    for (int i=B; i<W; ++i) {
        i64 former=modchoose(H-A-1+i, i, ftable, itable);
        i64 latter=modchoose(W+A-2-i, A-1, ftable, itable);
        (res += former*latter%MOD) %= MOD;
    }

    printf("%lld\n", res);
    return 0;
}


