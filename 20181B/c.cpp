
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
    
int R[102][2];
ll Q[102];
ll D[102];

ll solve(){
    int M;
    cin >> M;
    
    rep(i, 0, M){
        cin >> R[i][0] >> R[i][1];
        R[i][0]--;
        R[i][1]--;
    }
    rep(i, 0, M){
        cin >> Q[i];
    }

    function<bool(int, ll)> get = [&](int r, ll v){
        if(D[r] < 0) return false;
        D[r] -= v;
        if(D[r] >= 0) return true;
        if( get(R[r][0], -D[r]) && get(R[r][1], -D[r]) ) {
            D[r] = 0;
            return true;
        }
        return false;
    };

    ll b = Q[0];
    ll e = 1e12;
    while(e > b+1){
        ll v = (b+e)/2;

        memcpy(D, Q, sizeof(Q));
        if(get(0, v)){
            b = v;
        } else {
            e = v;
        }
    }
    return b;
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
    