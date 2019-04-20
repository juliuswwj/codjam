
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


int N;

int kuhn(vector<vector<int>>& g)
{
    vector<int> link(N, -1);
    vector<int> use(N, 0);

    function<bool(int)> dfs = [&](int v) {
        if(use[v])return false;
        use[v] = 1;
        for(auto t : g[v]){
            if(link[t] == -1 || dfs(link[t])){
                link[t] = v;
                return true;
            }
        }
        return false;
    };

    int ret = 0;
    rep(n, 0, N){
        if( dfs(n) ) ret += 1;
        rep(i, 0, N) use[i] = 0;
    }
    return ret;
}

int solve(){
    cin >> N;

    vector< vector< vector<int> > > gs(2*N+1);
    rep(r, 0, N) {
        rep(c, 0, N) {
            int color;
            cin >> color;

            auto& g = gs[color+N];
            if(g.size() == 0) g.resize(N);
            g[r].pb(c);
        }
    }

    int ret = N*N;
    for(auto& g : gs)if(g.size() > 0){
        ret -= kuhn(g);
    }
    return ret;
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
    