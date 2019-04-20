
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
    
ll dp[100008];
int solve(){
    int N;
    int most = 1;

    cin >> N;
    rep(n, 0, N){
        ll m;
        cin >> m;
        if(n == 0){
            dp[0] = m;
            continue;
        }
        dp[n] = 1L<<62;
        per(i, 0, most) if(dp[i] <= m*6) {
            dp[i+1] = min(dp[i+1], dp[i] + m);
            most = max(most, i+2);
        }
        dp[0] = min(dp[0], m);
    }
    return most;
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
    