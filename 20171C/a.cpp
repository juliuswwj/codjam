//+base
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cctype>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
#include <functional>
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

//+main
struct PSZ {
    ll a, b;
};
double solve(){
    int N, K;
    cin >> N >> K;

    vector<PSZ> psz;
    rep(n, 0, N){
        PSZ s;
        cin >> s.a >> s.b;
        s.b = 2*s.a*s.b;
        s.a = s.a*s.a;
        psz.pb(s);
    }
    sort(all(psz), [&](const PSZ& a, const PSZ& b){
        return a.a < b.a;
    });
    ll m = 0;
    rep(k, K-1, N){
        if(k > 1) sort(&psz[0], &psz[k], [&](const PSZ& a, const PSZ& b){
            return a.b > b.b;
        });
        ll b = psz[k].b;
        rep(i, 0, K-1) b += psz[i].b;
        m = max(m, psz[k].a + b);
    }
    return M_PI * m;
}
int main(){
    int T;
    cin >> T;
    cout.precision(12);
    rep(t, 0, T) {
        cout << "Case #" << (t+1) << ": " << solve() << endl;
    }
    return 0;
}

