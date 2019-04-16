
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
    int R, C;
    cin >> R >> C;

    vector< vector<int> > paths(R*C);

    rep(r, 0, R) rep(c, 0, C) rep(rr, 0, R) rep(cc, 0, C) {
        if(r == rr || c == cc || r+c == rr+cc || r-c == rr-cc) continue;
        paths[r*C+c].pb(rr*C+cc);
    }

    vector<int> cur;
    vector<int> res;
    vector<int> was(R*C, 0);
    function<void(int, int)> dfs = [&](int cnt, int v) {
        if(res.size()) return;
        cur.pb(v);
        was[v] = 1;
        if(cnt == R*C) res = cur;
        for(auto u : paths[v]){
            if(!was[u])dfs(cnt+1, u);
        }
        cur.pop_back();
        was[v] = 0;
    };
    rep(i, 0, R*C){
        dfs(1, i);
    }

    if(res.size() == 0){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << "POSSIBLE" << endl;

    for(auto& p : res){
        cout << p/C+1 << " " << p%C+1 << endl;
    }
}

int main(){
    int T;
    cin >> T;
    cout.precision(12);
    rep(t, 0, T) {
        cout << "Case #" << (t+1) << ": ";
        solve();
    }
    return 0;
}
    