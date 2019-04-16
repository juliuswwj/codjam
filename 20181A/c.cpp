
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

struct COOKIE {
    double a, b, c;

    bool operator<(const COOKIE& t){
        if(a != t.a) return a < t.a;
        return b < t.b;
    }
};

double solve(){
    int N, P;

    vector<COOKIE> cookies;

    cin >> N >> P;
    rep(n, 0, N) {
        int w, h;
        cin >> w >> h;

        COOKIE c;
        c.a = (w+h)*2;
        c.b = c.a+2*min(w, h);
        c.c = c.a+2*sqrt(w*w+h*h);
        cookies.pb(c);

        //fprintf(stderr, "cookie %lf %lf %lf\n", c.a, c.b, c.c);
    }

    vector< pair<double, double> > may;

    for(auto& c : cookies) {
        vector< pair<double, double> > nm;

        if(may.size() == 0){
            nm.pb( mp(c.a, c.a) );
            nm.pb( mp(c.b, c.c) );

        } else {
            for(auto& m : may){
                if(m.fi + c.a > P)break;
                nm.pb( mp(m.fi + c.a, m.se + c.a) );
                if(m.fi + c.b > P)continue;
                nm.pb( mp(m.fi + c.b, m.se + c.c) );
            }
        }
        sort(nm.begin(), nm.end());

        // merge
        may.clear();
        for(auto& m : nm){
            bool push = true;
            per(i, 0, may.size()){
                if(may[i].se < m.fi) break;
                if(may[i].fi > m.se) continue;
                if(may[i].fi <= m.fi){
                    if(may[i].se < m.se)may[i].se = m.se;
                } else {
                    if(may[i].se <= m.se) may[i] = m;
                    else may[i].fi = m.fi;
                }
                push = false;
                break;
            }
            if(push) may.pb( m );
        }
    }
    double last = 0;
    for(auto& m : may){
        //fprintf(stderr, "may %lf %lf\n", m.fi, m.se);

        if(m.fi > P) break;
        if(m.se >= P) {
            last = P;
            break;
        }
        last = m.se;
    }
    return last;
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
    