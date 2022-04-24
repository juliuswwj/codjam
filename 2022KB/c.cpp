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

//+main
int solve(){
    int N, D;
    cin >> N >> D;
    
    vector<int> V(N);
    for(int i=0; i<N; i++) cin >> V[i];

    //cout << "N=" << N << " D=" << D << " V=" << V << endl;
    vector<vector<map<int, int>>> dp(N, vector<map<int, int>>(N));
    function<int(int,int,int)> cal = [&](int b, int e, int off) {
        off = off%D;
        while(b <= e && (V[b]+off)%D == 0) b++;
        while(b <= e && (V[e]+off)%D == 0) e--;
        if(b > e) return 0;

        auto& ddp = dp[b][e];
        auto p = ddp.find(off);
        if(p != ddp.end()) return p->second;

        int t = (V[b]+off)%D;
        int ans = t+cal(b, e, off+D-t);
        t = D-t;
        ans = min(ans, t+cal(b, e, off+t));

        t = (V[e]+off)%D;
        ans = min(ans, t+cal(b, e, off+D-t));
        t = D-t;
        ans = min(ans, t+cal(b, e, off+t));
        return ddp[off] = ans;
    };
    return cal(0, N-1, 0);
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

