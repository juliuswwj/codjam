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
const ll M = 360*12*10000000000L;
ll INV11;
int ans[4];

bool check(ll A, ll B, ll C) {
    ll t = (__int128)(M+B-A)%M * INV11 % M;
    if((t*719)%M != (M+C-A) % M) return false;
    
    ans[3] = (int)(t % 1000000000L);
    ans[2] = (int)(t / 1000000000L);
    ans[1] = ans[2] / 60;
    ans[0] = ans[1] / 60;
    ans[2] = ans[2] % 60;
    return true;
}

void solve(){
    ll A, B, C;
    cin >> A >> B >> C;
    if(check(A, B, C)) return;
    if(check(A, C, B)) return;
    if(check(B, A, C)) return;
    if(check(B, C, A)) return;
    if(check(C, A, B)) return;
    if(check(C, B, A)) return;
}

int main(){
    for(int i=1; i<11; i++) {
        ll v = i*M+1;
        if(v % 11 == 0) {
            INV11 = v/11;
            break;
        }
    }


    int T;
    cin >> T;
    cout.precision(12);
    rep(t, 0, T) {
        solve();
        cout << "Case #" << (t+1) << ": " << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
    }
    return 0;
}

