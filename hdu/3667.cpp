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

//+mcmf
template<typename CT=int>
struct MCMF {
    struct edge {
        int u, v;
        CT c, t, ct;

        edge() {}
        edge(int u, int v, CT c, CT t, CT ct): u(u), v(v), c(c), t(t), ct(ct) {}
    };

    struct node : vector<int> { // index in es
        bool vis;
        CT d;
        int a, p;
    };
    vector<edge> es;
    vector<node> ns;
    int s, t, K;

    MCMF(int N, int K, int s=0, int t=-1) : ns(N+1), s(s), t(t > 0 ? t : N), K(K) {
        add(0, 1, K, 0);
    }
    void add(int u, int v, CT c, CT ct){ // u,v range [1..N]
        int sz = es.size();
        es.pb(edge(u, v, c, 0, ct));
        es.pb(edge(v, u, 0, 0, -ct));
        ns[u].pb(sz);
        ns[v].pb(sz+1);
    }

    bool BellmanFord(int &flow, CT &cost) {
        queue<int> q;
        for(auto& n : ns) {
            n.d = numeric_limits<CT>::max();
            n.vis = false;
        }
        ns[s].d = 0;
        ns[s].a = numeric_limits<int>::max();
        ns[s].p = 0;
        ns[s].vis = true;
        q.push(s);

        while(!q.empty()){
            int u = q.front(); q.pop();
            ns[u].vis = false;
            rep(i, 0, ns[u].size()){
                auto& e = es[ns[u][i]];
                if(e.c > e.t && ns[e.v].d > ns[u].d + e.ct){
                    ns[e.v].d = ns[u].d + e.ct;
                    ns[e.v].a = min(ns[u].a, e.c - e.t);
                    ns[e.v].p = ns[u][i];
                    if(!ns[e.v].vis){
                        ns[e.v].vis = true;
                        q.push(e.v);
                    }
                }
            }
        }
        if(ns[t].d == numeric_limits<CT>::max()) return false;
        flow += ns[t].a;
        cost += ns[t].d * ns[t].a;
        int u = t;
        while(u != s){
            es[ ns[u].p ].t += ns[t].a;
            es[ ns[u].p ^ 1 ].t -= ns[t].a;
            u = es[ ns[u].p ].u;
        }
        return true;
    }

    CT run() {
        int flow = 0;
        CT cost = 0;
        while(BellmanFord(flow, cost));
        return flow == K ? cost : -1;
    }
};

//+main
int main(){
    int N, M, K;
    while( cin >> N >> M >> K ){
        MCMF<int> mcmf(N, K);
        rep(m, 0, M){
            int u, v, a, c;
            cin >> u >> v >> a >> c;

            rep(i, 1, c+1){
                mcmf.add(u, v, 1, a*(2*i-1));
            }
        }

        cout << mcmf.run() << endl;
    }
    return 0;
}

