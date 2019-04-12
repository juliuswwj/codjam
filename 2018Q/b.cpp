
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
    int N;
    cin >> N;
    vector<int> a, b;
    rep(i, 0, N){
        int v;
        cin >> v;
        if(i % 2) b.pb(v); else a.pb(v);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int v = -1;
    rep(i, 0, N){
        int nv = i%2 ? b[i/2] : a[i/2];
        if(v > nv){
            cout << i-1;
            return;
        }
        v = nv;
    }
    cout << "OK";
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
    