
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
    
char mm[100][100];
int split[100];
int rc[100];

bool solve(){
    int R, C, H, V;
    cin >> R >> C >> H >> V;

    int cc = 0;
    rep(r, 0, R){
        cin >> mm[r];
        rep(c, 0, C)if(mm[r][c] == '@') cc += 1;
    }
    if(cc % ((H+1) * (V+1))) return false;

    int k = cc / (H+1);
    int si = 0;
    rep(r, 0, R){
        rep(c, 0, C)if(mm[r][c] == '@'){
            k -= 1;
        }
        if(k < 0) return false;
        split[r] = si;
        if(k == 0) {
            si += 1;
            k = cc / (H+1);
        }
    }
    /*
    fprintf(stderr, "split=");
    rep(r, 0, R){
        fprintf(stderr, "%d ", split[r]);
    }
    fprintf(stderr, "\n");*/

    memset(rc, 0, sizeof(rc));
    k = cc / (V+1);
    rep(c, 0, C){
        rep(r, 0, R)if(mm[r][c] == '@'){
            rc[ split[r] ] += 1;
            k -= 1;
        }
        if(k < 0) return false;
        if(k == 0) {
            k = cc / (V+1);
            rep(h, 0, H)if(rc[h]*(H+1) != k) return false;
            memset(rc, 0, sizeof(rc));
        }
    }
    return true;
}

int main(){
    int T;
    cin >> T;
    cout.precision(12);
    rep(t, 0, T) {
        cout << "Case #" << (t+1) << ": " << (solve() ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    }
    return 0;
}
    