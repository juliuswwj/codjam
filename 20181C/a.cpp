
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

char s[16];    
const char* solve(){
    int N, L;
    cin >> N >> L;

    vector<ll> ss;
    rep(n, 0, N) {
        cin >> s;
        ll v = 0;
        ll m = 1;
        for(int i=0; s[i]; i++){
            v += (s[i]- 'A') * m;
            m *= 26;
        }
        ss.pb(v);
    }
    sort(all(ss));

    ll m = 26;
    rep(l, 1, L){
        rep(i, 0, N) rep(j, 0, N) if(i != j){
            ll v = ss[i]%m + (ss[j]/m)*m;
            if(! binary_search(all(ss), v) ){
                rep(k, 0, L){
                    s[k] = 'A' + v%26;
                    v /= 26;
                }
                s[L] = 0;
                return s;
            }
        }
        m *= 26;
    }
    return "-";
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
    