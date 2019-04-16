
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
    int N, L;
    cin >> N >> L;

    int rc = 1;
    rep(i, 1, N){
        double t = i * 100.0 / N;
        t = t - (int)t;
        if(t >= 0.5) {
            rc = i;
            break;
        }
    }

    int remain = N;

    vector<int> C(L);
    rep(l, 0, L){
        cin >> C[l];
        remain -= C[l];
    } 

    if(rc > 1){
        vector< pair<int, int> > req;
        rep(l, 0, L){
            rep(r, 0, remain+1){
                double t = (C[l]+r) * 100.0 / N;
                t = t - (int)t;
                if(t >= 0.5) {
                    if(r > 0) req.pb( mp(r, l) );
                    break;
                }
            }
        }
        sort(all(req));

        for(auto& r : req){
            if(r.fi > remain) break;

            //fprintf(stderr, "req %d %d\n", r.fi, r.se);

            remain -= r.fi;
            C[r.se] += r.fi;
        }
    }

    //fprintf(stderr, "remain %d %d\n", remain, rc);

    int ret = 0;
    rep(l, 0, L){
        ret += (int)(C[l] * 100.0 / N + 0.5);
    }

    while(remain > 0){
        if(remain >= rc){
            ret += (int)(rc * 100.0 / N + 0.5);
            remain -= rc;
        } else {
            ret += (int)(remain * 100.0 / N + 0.5);
            remain = 0;
        }
    }
    return ret;
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
    