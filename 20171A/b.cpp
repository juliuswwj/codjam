
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

int solve(){
    int N, P;
    cin >> N >> P;

    vector<int> R(N);
    rep(n, 0, N) cin >> R[n];

    typedef list< pair<int, int> > RRR;
    vector<RRR> rs;

    rep(n, 0, N){
        RRR rrr;
        rep(p, 0, P){
            int t;
            cin >> t;
            int a = (int)floor(t / 0.9 / R[n]);
            int b = (int)ceil(t / 1.1 / R[n]);
            if(a >= b) rrr.pb( mp(b, a) );
        }

        rrr.sort();
        rs.pb(rrr);
    }

    // greedy match
    int c = 0;
    while(true){
        int a = 0;
        int b = 10000000;
        int i = 0;
        int mi = 0;
        int mb = b;
        for(auto& rrr : rs){
            if( rrr.size() == 0 ) {
                a = -1;
                b = -1;
                break;
            }

            auto t = rrr.begin();
            if(t->fi <= b && t->se >= a){
                a = max(a, t->fi);
                b = min(b, t->se);
            } else {
                b = -1;
            }
            if(mb > t->se){
                mb = t->se;
                mi = i;
            }
            i++;
        }
        if(a < 0 && b < 0)break;
        if(b < 0){ // no intersection, remove lowest upper
            rs[mi].erase( rs[mi].begin() );
            continue;
        }
        // find one
        c += 1;
        for(auto& rrr : rs){
            rrr.erase(rrr.begin());
        }
    }
    return c;
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
    