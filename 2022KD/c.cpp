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
    int N;
    cin >> N;
    vector<int> S(N);
    for(int i=0; i<N; i++) cin >> S[i];

    int M;
    cin >> M;
    unordered_map<int, vector<int>> K;
    
    for(int i=0; i<M; i++) {
        int v;
        cin >> v;
        K[v].push_back(i);
    }

    vector<int> dp(M);
    int ans = 0;
    for(int i=1; i<N; i++) {
        if(S[i] == S[i-1]) continue;
        auto& opos = K[S[i-1]];
        ans = INT_MAX;
        for(auto a : K[S[i]]) {
            int v = INT_MAX;
            for(auto b: opos) {
                v = min(v, dp[b]+abs(a-b));
            }
            dp[a] = v;
            ans = min(ans, v);
        }
    }
    return ans;
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

