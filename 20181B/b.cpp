
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
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// ------------------------

struct MNT {
    int m, n, c, s;
};

void solve(){
    int S;
    cin >> S;

    int mlen = 1;
    list<MNT> mnt;
    rep(s, 0, S){
        int d, a, b;
        cin >> d >> a >> b;

        MNT t;
        t.m = d + a;
        t.n = d - b;
        t.c = 1;
        t.s = s;

        for(auto u = mnt.begin(); u != mnt.end(); ){
            if(u->m != t.m && u->n != t.n){
                if(u->c < mlen) u = mnt.erase(u); else u++;
                continue;
            }
            if(u->c + u->s == s){
                u->c += 1;
                mlen = max(mlen, u->c);
            }
            u++;
        }
        mnt.pb(t);
    }

    int c = 0;
    for(auto& u : mnt){
        if(u.c == mlen) c++;
    }
    cout << mlen << " " << c;
}
int main(){
    int T;
    cin >> T;
    cout.precision(12);
    rep(t, 0, T) {
        cout << "Case #" << (t+1) << ": ";
        solve();
        cout << endl;
    }
    return 0;
}
    