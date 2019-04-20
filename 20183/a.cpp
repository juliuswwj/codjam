
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
    int N, MR, MC;
    cin >> N;

    vector< PII > ms;

    MR = 0;
    MC = 0;
    rep(n, 0, N){
        int R, C;
        cin >> R >> C;
        ms.pb( mp(R, C) );
        MR = max(MR, R);
        MC = max(MC, C);
    }

    int mt = 1e9;
    rep(r, 0, MR+1) rep(c, 0, MC+1){
        vector< PII > m;
        m.assign( all(ms) );

        int t = 0;
        while(true){
            bool move = false;
            int nr = r;
            int nc = c;
            rep(n, 0, N){
                auto& u = m[n];
                if(!move) move = u.fi != nr || u.se != nc;
                if(u.fi > nr) u.fi -= 1;
                if(u.fi < nr) u.fi += 1;
                if(u.se > nc) u.se -= 1;
                if(u.se < nc) u.se += 1;
                nr = u.fi;
                nc = u.se;
            }
            if(!move) break;
            t += 1;
        }
        mt = min(mt, t);
    }
    return mt;
}


int solve2(){
    int N;
    cin >> N;

    vector< PII > ms;

    int r[2], c[2];
    rep(n, 0, N){
        int R, C;
        cin >> R >> C;
        if(n == 0){
            r[0] = r[1] = R;
            c[0] = c[1] = C;
        } else {
            r[0] = min(r[0], R);
            r[1] = max(r[1], R);
            c[0] = min(c[0], C);
            c[1] = max(c[1], C);
        }
    }

    return max((r[1]-r[0]+1)/2,  (c[1]-c[0]+1)/2);
}

int main(){
    int T;
    cin >> T;
    cout.precision(12);
    rep(t, 0, T) {
        cout << "Case #" << (t+1) << ": " << solve2() << endl;
    }
    return 0;
}
    