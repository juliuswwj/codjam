
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
    int D;
    char P[32];
    cin >> D >> P;

    vector<int> ds;
    int sc = 0;
    for(int i = 0; P[i]; i++){
        if(P[i] == 'S') sc += 1; else {
            ds.pb(sc);
            sc = 0;
        }
    }
    ds.pb(sc);

    while( ds.size() > 0 && *ds.rbegin() == 0) ds.pop_back();

    int c = 0;
    int d = 0;
    rep(i, 0, ds.size()){
        d += ds[i] << i;
    }

    while(true){
        if(d <= D) {
            cout << c;
            return;
        }
        if(ds.size() == 1){
            cout << "IMPOSSIBLE";
            return;
        }
        c++;
        ds[ ds.size() - 1 ]--;
        ds[ ds.size() - 2 ]++;
        d -= 1 << (ds.size() - 2);
        if(ds[ ds.size() - 1 ] == 0) ds.pop_back();
    }
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
    