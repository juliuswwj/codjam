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
template<typename T, typename WT=int>  // T.u,T.v @ [0, N-1]; T.operator<
WT kruskal(vector<WT>& ret, vector<T>& es)
{
    int N = ret.size();
    rep(i, 0, N) ret[i] = i;

    function<int(int)> find = [&](int x){
        return x == ret[x] ? x : ret[x] = find(ret[x]);
    };
    sort(all(es));
    WT cnt = 0;
    for(auto& e : es){
        int f1 = find(e.u);
        int f2 = find(e.v);
        if(f1 != f2){
            ret[f1] = f2;
            cnt += e.w;
        }
    }
    return cnt;
}

//+main
struct EDGE {
    int u, v, w;

    bool operator<(const EDGE& e){
        return w < e.w;
    }
};

int N;
int solve(){
    vector<EDGE> es;
    rep(n, 0, N*(N-1)/2){
        EDGE e;
        cin >> e.u >> e.v >> e.w;
        e.u -= 1;
        e.v -= 1;
        es.pb(e);
    }

    vector<int> dat(N);
    return kruskal(dat, es);
}
int main(){
    while(cin >> N){
        if(N == 0)break;

        cout << solve() << endl;
    }
    return 0;
}

