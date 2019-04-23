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

//+dinic
template<typename CT=int>
struct DINIC {
    struct edge {
        int u, v;
        CT c, t;

        edge() {}
        edge(int u, int v, CT c, CT t): u(u), v(v), c(c), t(t) {}
    };

    struct node : vector<int> { // index in es
        bool vis;  // used by BFS
        int d, cur; // distance of s->i / current edge idx

        node() {}
        node(int N): vector<int>(N) {}
    };

    vector<edge> es;
    vector<node> ns;
    int s, t;

    DINIC(int N, int s, int t): ns(N, N), s(s), t(t) {}
    void add(int u, int v, CT c) {
        int sz = es.size();
        es.pb(edge(u, v, c, 0));
        es.pb(edge(v, u, 0, 0));
        ns[u][v] = sz;
        ns[v][u] = sz+1;
    }

    bool bfs(){
        for(auto&n : ns) n.vis = false;
        queue<int> q;
        q.push(s);
        ns[s].d = 0;
        ns[s].vis = true;
        while(!q.empty()){
            int x = q.front(); q.pop();
            rep(i, 0, ns[x].size()){
                auto& e = es[ ns[x][i] ];
                if(!ns[e.v].vis && e.c > e.t){
                    ns[e.v].vis = true;
                    ns[e.v].d = ns[x].d + 1;
                    q.push(e.v);
                }
            }
        }
        return ns[t].vis;
    }

    CT dfs(int x, CT a) {
        if(x == t || a == 0) return a;
        CT flow = 0;
        int& i = ns[x].cur;
        while(i < ns[x].size()){
            auto& e = es[ ns[x][i] ];
            if(ns[x].d+1 == ns[e.v].d){
                CT f = e.c - e.t;
                if(f > a && a >= 0)f = a;
                f = dfs(e.v, f);
                if(f > 0){
                    e.t += f;
                    es[ns[x][i]^1].t -= f;
                    flow += f;
                    a -= f;
                    if(a == 0)break;
                }
            }
            i += 1;
        }
        return flow;
    }

    CT run(){
        CT flow = 0;
        while(bfs()){
            for(auto&n : ns) n.cur = 0;
            flow += dfs(s, -1);
        }
        return flow;
    }
};

//+main
int solve(){
    int N, M;
    cin >> N >> M;

    DINIC<int> dinic(N, 0, N-1);
    rep(m, 0, M){
        int u, v, c;
        cin >> u >> v >> c;
        dinic.add(u-1, v-1, c);
    }
    return dinic.run();
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

