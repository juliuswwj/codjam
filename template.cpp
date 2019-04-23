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

//+gcd
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}


//+sam
template<char B='A', int BN=26>
struct SAM {
    struct node {
        int len;
        int next[BN];
        int rt;
        node() : len(0), rt(0){
            memset(next, 0, sizeof(next));
        }
    };
    int ss;
    vector<node> ns;  // valid [1 .. ss]
    SAM() : ss(0) {}
    const node& operator [](int idx){ return ns[idx]; }
    void add(const char* str){
        int ne;
        for(int last = 0; (ne = *str++) != 0; ){
            if(ns.size() < ss+4) ns.resize(ss + BN);
            ns[++ss].len = ns[last].len + 1;
            ne -= B;
            int x = last; last = ss;
            for (; x && !ns[x].next[ne]; x = ns[x].rt) ns[x].next[ne] = ss;
            int y = ns[x].next[ne];
            if (!y)
                ns[x].next[ne] = ss;
            else if (ns[x].len+1 == ns[y].len)
                ns[ss].rt = y;
            else {
                ns[++ss].len = ns[x].len + 1;
                memcpy(ns[ss].next, ns[y].next, sizeof(ns[y].next));
                ns[last].rt = ss, ns[ss].rt = ns[y].rt, ns[y].rt = ss;
                for (;x && ns[x].next[ne] == y; x = ns[x].rt) ns[x].next[ne] = ss;
                if (ns[x].next[ne] == y) ns[x].next[ne] = ss;
            }
        }
    }
    void count(vector<int>& cnt){
        vector<int> tail(ss+1);
        rep(i, 1, ss+1) tail[i] = i;
        int s = ss;
        vector<int> net(2*(ss+1));
        vector<int> sora(2*(ss+1));
        rep(i, 1, ss+1){
            int x = ns[i].rt;
            s++;
            net[tail[x]] = s;
            tail[x] = s;
            sora[s] = i;
        }
        cnt.resize(ss+1);
        function<void(int)> dfs = [&](int x){
            cnt[x] = (x == tail[x]) ? 1 : 0;
            for(int i=x; net[i] != 0; ){
                i = net[i];
                int ne = sora[i];
                if(ne == ns[x].rt) continue;
                dfs(ne);
                cnt[x] += cnt[ne];
            }
        };
        dfs(0);
    }
    void runs(const char* str, function<void(int s, int sum)> cb){
        int s = 0;
        int sum = 0;
        char ch;
        while( (ch = *(str++)) != 0 ){
            ch -= B;
            while(s && !ns[s].next[ch]){ s = ns[s].rt; sum = ns[s].len; }
	        if (ns[s].next[ch]) sum++, s = ns[s].next[ch];
            cb(s, sum);
        }
    }
    int run(const char* str){
        int s = 0;
        char ch;
        while( (ch = *(str++)) != 0 ){
            ch -= B;
	        s = ns[s].next[ch];
            if(s == 0) break;
        }
        return s;
    }
    void show(){
        rep(i, 0, ss+1){
            fprintf(stderr, "ns[%d] = {%d, %d, [%d, %d, %d, %d, %d, %d, %d, %d, %d, %d]}\n", i, ns[i].len, ns[i].rt, 
                ns[i].next[0], ns[i].next[1], ns[i].next[2], ns[i].next[3], ns[i].next[4],
                ns[i].next[5], ns[i].next[6], ns[i].next[7], ns[i].next[8], ns[i].next[9]
                )
            ;
        }
    }
};


//+kruskal
template<typename T, typename WT=int>  // T.u,T.v @ [0, N-1]; T.w; T.operator<
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
    };

    vector<edge> es;
    vector<node> ns;
    int s, t;

    DINIC(int N, int s=0, int t=-1): ns(N), s(s), t(t>0?t:(N-1)) {}
    void add(int u, int v, CT c) { // u,v range [0..N-1]
        int sz = es.size();
        es.pb(edge(u, v, c, 0));
        es.pb(edge(v, u, 0, 0));
        ns[u].pb(sz);
        ns[v].pb(sz+1);
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
                f = dfs(e.v, min(a, e.c - e.t));
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
            flow += dfs(s, numeric_limits<CT>::max());
        }
        return flow;
    }
};

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

//+hungary
struct HUNGARY {
    struct node : vector<int> {
        int linker;
        bool used;

        node() : used(false), linker(-1) {}
    };
    vector<node> ns;

    HUNGARY(int N) : ns(N) {}
    void add(int u, int v){ // range [0..N-1]
        ns[u].pb(v);
        ns[v].pb(u);
    }

    bool dfs(int u)
    {
        for(auto v : ns[u]) if(!ns[v].used) {
            ns[v].used = true;
            if(ns[v].linker<0 || dfs(ns[v].linker)) {
                ns[v].linker = u;
                return true;
            }
        }
        return false;
    }

    int run(){
        int ans = 0;

        rep(u, 0, ns.size()){
            for(auto& v: ns) v.used = false;
            if(dfs(u)) ans++;
        }
        return ans / 2; // 用双向图来模拟无向图，每条边都变成了两条边，求出的匹配也就被复制了，最后需要除2
    }
};

//+tarjan
struct TARJAN {
    struct node : vector<int> {
        int low, dfn, id, u, v;
    };

    vector<node> ns;
    int dfn, scc;
    stack<int> s;

    TARJAN(int N):ns(N), dfn(0), scc(0) {}
    void add(int u, int v){ // range [0..N-1]
        ns[u].pb(v);
    }
    void dfs(int x){
        s.push(x);
        auto& n = ns[x];
        n.dfn = n.low = ++dfn;
        for(auto v : n){
            if(!ns[v].dfn){
                dfs(v);
                n.low = min(n.low, ns[v].low);
            } else if(!ns[v].id) {
                n.low = min(n.low, ns[v].dfn);
            }
        }

        if(n.low == n.dfn){
            scc++;
            while(true){
                int u = s.top(); s.pop();
                ns[u].id = scc;
                if(u == x)break;
            }
        }
    }
    int run(){
        rep(x, 0, ns.size()) if(!ns[x].dfn) dfs(x);
        return scc;
    }
};


//+fib
template<typename T=int>
void fib(T max, vector<T>& f)
{
    f.pb(0);
    f.pb(1);
    int last = f.size() - 1;
    while(true){
        f.pb(f[last] + f[last-1]);
        last += 1;
        if(f[last] > max) break;
    }
}


//+main
int solve(){
    return 0;
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
