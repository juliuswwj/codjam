
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
    
struct CASHIER {
    ll m, s, p;
};

ll solve(){
    int R, B, C;
    cin >> R >> B >> C;

    vector<CASHIER> cs;
    rep(c, 0, C){
        CASHIER cc;
        cin >> cc.m >> cc.s >> cc.p;
        cs.pb(cc);
    }

    ll ta = 0;
    ll tb = 4e18;

    while(tb > ta+1){
        ll t = (tb+ta)/2;
        vector<ll> cap;
        for(auto& c : cs){
            ll m = min(c.m, (t - c.p) / c.s);  // using ll to handle c.s * c.m  !!!! 
            if(m <= 0) continue;
            cap.pb(m);
        }
        sort(cap.begin(), cap.end());
        ll total = 0;
        ll r = R;
        per(i, 0, cap.size()){
            total += cap[i];
            r -= 1;
            if(total >= B) break;
        }
        if(total < B || r < 0){
            ta = t;
        } else {
            tb = t;
        }
    }
    return tb;
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
    