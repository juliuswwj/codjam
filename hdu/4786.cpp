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

//+kruskal
template<typename T>
int kruskal(vector<int>& ret, vector<T>& es)
{
    int N = ret.size();
    rep(i, 0, N) ret[i] = i;

    function<int(int)> find = [&](int x){
        return x == ret[x] ? x : ret[x] = find(ret[x]);
    };
    sort(all(es));
    int cnt = 0;
    for(auto& e : es){
        int f1 = find(e.u);
        int f2 = find(e.v);
        if(f1 != f2){
            ret[f1] = f2;
            cnt += 1;
        }
    }
    return cnt;
}

//+main
bool solve(){
    int N, M;
    cin >> N >> M;

    struct EDGE {
        int u, v, c;
        bool operator<(const EDGE& t){
            return c < t.c;
        }
    };
    vector<EDGE> es;
    rep(m, 0, M){
        EDGE e;
        cin >> e.u >> e.v >> e.c;
        e.u -= 1;
        e.v -= 1;
        es.pb(e);
    }

    auto cal = [&](int c) {
        vector<EDGE> nes;
        for(auto& e: es) if(e.c != c) {
            nes.pb(e);
        }
        vector<int> ret(N);
        return kruskal(ret, nes);
    };

    int k = cal(2);
    if(k != N-1) return false; // determin spanning tree existance

    int mx = cal(0);
    int mn = N-1-cal(1);

    int a = 0;
    int b = 1;
    while(true){
        int c = a + b;
        if(c > mx) break;
        if(c >= mn) return true;
        a = b;
        b = c;
    }
    return false;
}
int main(){
    int T;
    cin >> T;
    cout.precision(12);
    rep(t, 0, T) {
        cout << "Case #" << (t+1) << ": " << (solve() ? "Yes" : "No") << endl;
    }
    return 0;
}

