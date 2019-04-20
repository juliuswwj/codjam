
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
    
char cm[104][104];

void solve(){
    int C;
    cin >> C;
    vector<int> cs(C);
    rep(c, 0, C) cin >> cs[c];
    if(!cs[0] || !cs[C-1]){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    memset(cm, '.', sizeof(cm));

    int t = 0;
    int m = 0;
    rep(i, 0, C){
        while(!cs[t]) t++;
        cs[t]--;
        if(i == t) continue;
        if(i > t) {
            rep(j, 0, i-t){
                cm[(i-t)-j-1][t+j+1] = '/';
            }
            m = max(m, i-t);
        } else {
            rep(j, 0, t-i){
                cm[j][i+j] = '\\';
            }
            m = max(m, t-i);
        }
    }
    m += 1;

    cout << m << endl;
    rep(i, 0, m){
        cm[i][C] = 0;
        cout << cm[i] << endl;
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
    