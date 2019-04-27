//+base
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SIZE(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;

//+matrix
template<typename T=int>
struct MATRIX : vector< vector<T> > {
    T mod;
    MATRIX(int M, int N, T v = 0, T mod = 0) : vector< vector<T> >(M), mod(mod) {
        for(auto& u : *this) u.resize(N, v);
    }
    MATRIX(const MATRIX& t) : vector< vector<T> >( t.size() ), mod(t.mod) {
        rep(i, 0, t.size()){
            (*this)[i].assign( all(t[i]) );
        }
    }
    MATRIX& operator=(const MATRIX& t){
        this->resize(t.size());
        rep(i, 0, t.size()){
            (*this)[i].assign( all(t[i]) );
        }
        return *this;
    }
    MATRIX& operator+=(const MATRIX& t){
        rep(y, 0, t.size())rep(x, 0, t[y].size()){
            (*(this))[y][x] += t[y][x];
        }
        return *this;
    }
    MATRIX operator+(const MATRIX& t) const {
        MATRIX r(*this);
        return r += t;
    }
    MATRIX& operator-=(const MATRIX& t){
        rep(y, 0, t.size())rep(x, 0, t[y].size()){
            (*(this))[y][x] -= t[y][x];
        }
        return *this;
    }
    MATRIX operator-(const MATRIX& t) const {
        MATRIX r(*this);
        return r -= t;
    }
    MATRIX& operator*=(T v){
        rep(y, 0, this->size())rep(x, 0, (*this)[y].size()){
            (*this)[y][x] *= v;
        }
        return *this;
    }
    MATRIX operator*(T v) const {
        MATRIX r(*this);
        return r *= v;
    }
    MATRIX operator*(const MATRIX& t) const {
        MATRIX r(this->size(), t[0].size(), 0, mod);
        rep(y, 0, this->size())rep(x, 0, t.size())rep(z, 0, t[y].size()){
            if(mod) r[y][z] = (r[y][z] + (*this)[y][x]*t[x][z]) % mod;
            else r[y][z] = r[y][z] + (*this)[y][x]*t[x][z];
        }
        return r;
    }
    MATRIX pow(ll v) const {
        MATRIX a(*this);
        MATRIX t(a.size(), a.size(), 0, mod);
        rep(i, 0, a.size()) t[i][i] = 1;
        while(v > 0){
            if(v & 1) t = t * a;
            a = a * a;
            v >>= 1;
        }
        return t;
    }
};

//+fib
template<typename T=int>
void fib1(T max, vector<T>& f){
    f.pb(0);
    f.pb(1);
    int last = f.size() - 1;
    while(true){
        f.pb(f[last] + f[last-1]);
        last += 1;
        if(f[last] > max) break;
    }
}
ll fib2(ll n, ll mod){
    MATRIX<ll> P(2, 2, 1, mod);
    P[0][0] = 0;
    P = P.pow(n);
    return P[0][1];
}
int fibf(ll n, int c){
    double s = log10(1.0/sqrt(5)) + (double)n*log10((1.0+sqrt(5))/2.0);
    return (int)(pow(10, s -(int)s + c - 1));
}

//+main
int main(){
    int n;
    while(cin >> n){
        if(n < 40) { cout << setw(0) << fib2(n, 0) << endl; continue; }
        int e = (int)fib2(n, 10000);
        int b = fibf(n, 4);
        cout << setfill('0') << setw(4) << b << "..." << e << endl;
    }
    return 0;
}

