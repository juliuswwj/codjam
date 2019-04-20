
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
    
void solve(){
    int N, D;
    cin >> N;

    vector<int> rcnt(N);
    vector<int> usage(N);

    rep(n, 0, N) {
        cin >> D;
        if(D < 0) exit(1);

        vector<int> req;
        rep(d, 0, D){
            int v;
            cin >> v;
            if(v < 0) exit(1);
            rcnt[v] += 1;
            req.pb(v);
        }
        if(req.size() == 0){
            cout << -1 << endl;
            cout.flush();
            continue;
        }

        int mc = N;
        int mr = -1;
        for(auto r : req)if(!usage[r]){
            if(rcnt[r] < mc){
                mr = r;
                mc = rcnt[r];
            }
        }
        if(mr >= 0) usage[mr] = 1;
        cout << mr << endl;
        cout.flush();
    }
}
int main(){
    int T;
    cin >> T;
    cout.precision(12);
    rep(t, 0, T) {
        solve();
    }
    return 0;
}
    