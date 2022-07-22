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

//+debug
template<class T>
ostream& operator<<(ostream& os, const vector<T>& vs) {
    os << "[";
    bool first = true;
    for(auto v: vs) {
        if(!first) os << ", ";
        first = false;
        os << v;
    }
    os << "]";
    return os;
}

template<class T, class V>
ostream& operator<<(ostream& os, const pair<T,V>& p) {
    os << p.first << ":" << p.second;
    return os;
}

template<class T, class V>
ostream& operator<<(ostream& os, const map<T,V>& vs) {
    os << "{";
    bool first = true;
    for(auto v: vs) {
        if(!first) os << ", ";
        first = false;
        os << v;
    }
    os << "}";
    return os;
}

//+gcd
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

//+prime
void getprime(int cnt, vector<int>& prime){
    cnt = (cnt-1)/2;
    prime.pb(2);
    bool* flag = new bool[cnt];
    rep(i, 0, cnt) flag[i] = true;
    rep(i, 0, cnt) {
        int v = i*2+3;
        if(flag[i]) prime.pb(v);
        rep(j, 1, prime.size()){
            int idx = (v*prime[j]-3)/2;
            if(idx >= cnt) break;
            flag[idx] = false;
            if(v%prime[j] == 0) break;
        }
    }
    delete[] flag;
}
void getfactor(int n, map<int, int>& fs){
    while(n % 2 == 0){
        fs[2] += 1;
        n /= 2;
    }
    vector<int> prime;
    prime.pb(2);
    int cnt = (int)sqrt(n)/2 + 1;
    bool* flag = new bool[cnt];
    rep(i, 0, cnt) flag[i] = true;
    rep(i, 0, cnt) {
        int v = i*2+3;
        if(flag[i]){
            while(n % v == 0){
                fs[v] += 1;
                n /= v;
            }
            if(n < v) break;
            prime.pb(v);
        }
        rep(j, 1, prime.size()){
            int idx = (v*prime[j]-3)/2;
            if(idx >= cnt) break;
            flag[idx] = false;
            if(v%prime[j] == 0) break;
        }
    }
    delete[] flag;
    if(n != 1) fs[n] += 1;
}

//+mod
ll pow(ll x, ll p, ll mod) {
    ll ans = 1;
    while (p > 0) {
        if ((p & 1) == 1) ans = ((__int128)ans * x) % mod;
        p >>= 1;
        x = ((__int128)x * x) % mod;
    }
    return ans % mod;
}
ll inv(ll k, ll mod){ // k 乘法逆元
    return pow(k, mod-2, mod);
}

//+comb
struct COMB {
    int n, i;
    ll m;
    COMB(int n, int c) : n(n), i(0), m( (1l<<c)-1 ) { }
    bool next(){
        while(i < n-1) {
            if( ((m >> i) & 3) == 1 ){
                m ^= 3l << i;
                int c = 0;
                rep(j, 0, i) if((m>>j) & 1) c += 1;
                m &= ~((1l << i)-1);
                m |= (1l<<c)-1;
                i = 0;
                return true;
            }
            i += 1;
        }
        return false;
    }
};
ll combcnt(int n, int c) {
    ll sum = 1;
    rep(i, 1, c+1) sum = sum * (n-i+1) / i;
    return sum;
}
double combprob(double P[], int n, int k){
    vector<double> e(k+1);
    e[0] = 1;
    rep(i, 0, n){
        double p = P[i];
        per(j, 1, k+1) e[j] = (1-p)*e[j] + p*e[j-1];
    }
    return e[k];
}


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

//+union
struct UNION {
    vector<int> pre;
    vector<int> rank;

    UNION(int N): pre(N), rank(N, 1){
        rep(n, 0, N) pre[n] = n;
    }

    int find(int x){ // range [0..N-1]
        int r = x;
        while(r != pre[r]) r = pre[r];
        int i = x;
        while(i != r){
            int j = pre[i];
            pre[i] = r;
            i = j;
        }
        return r;
    }

    int join(int x, int y){ // range [0..N-1]
        x = find(x);
        y = find(y);
        if(x == y) return rank[x];
        if(rank[x] > rank[y]){
            pre[y] = x;
            rank[x] += rank[y];
            return rank[x];
        } else {
            pre[x] = y;
            rank[y] += rank[x];
            return rank[y];
        }
    }
};

//+bit
template<typename T=int>
struct BIT {
    int n;
    vector<T> t;

    BIT<T> (int _n): n(_n), t(n+1) { }

    void add(int i, T x){
        while (i <= n){
            t[i] += x;
            i += i & -i;
        }
    }

    T sum(int i){
        T ans = 0;
        while (i > 0){
            ans += t[i];
            i -= i & -i;
        }
        return ans;
    }

    T sum(int i, int j){
        return sum(j) - sum(i - 1);
    }
};

//+segtree
#define segtree_lson  l,m,rt<<1
#define segtree_rson  m+1,r,rt<<1|1
// int T.l, T.r; T.up(const T& a, const T& b); T.down(T& a, T& b); T.update(UT v); T.build(); T.merge(const T& t);
template<typename T, typename UT=int> 
struct SEGTREE {
    vector<T> tree;

    SEGTREE(int N): tree(N*4) { build(1, N); }
    void build(int l, int r, int rt=1){
        auto& t = tree[rt];
        t.l = l;
        t.r = r;
        if(l == r) {
            t.build();
            return;
        }
        int m = (t.l + t.r)/2;
        build(segtree_lson);
        build(segtree_rson);
        t.up(tree[rt<<1], tree[rt<<1|1]);
    }
    void update(UT v, int l, int r, int rt=1){ // range[1..N]
        auto& t = tree[rt];
        if(t.l == l && t.r == r) { t.update(v); return; }
        if(t.l == t.r)return;
        t.down(tree[rt<<1], tree[rt<<1|1]);
        int m = (t.l + t.r)/2;
        if(r <= m) update(v, l, r, rt<<1);
        else if(l > m) update(v, l, r, rt<<1|1);
        else {
            update(v, segtree_lson);
            update(v, segtree_rson);
        }
        t.up(tree[rt<<1], tree[rt<<1|1]);
    }
    void run(T& ret, int l, int r, int rt=1){ // range[1..N]
        auto& t = tree[rt];
        if(l == t.l && r == t.r){
            ret = t;
            return;
        }
        t.down(tree[rt<<1], tree[rt<<1|1]);
        int m = (t.l + t.r)/2;
        if(r <= m) run(ret, l, r, rt<<1);
        else if(l > m) run(ret, l, r, rt<<1|1);
        else {
            T b;
            run(ret, segtree_lson);
            run(b, segtree_rson);
            ret.merge(b);
        }
    }
};

//+matrix
template<typename T=int>
struct MATRIX : vector< vector<T> > {
    T mod;
    MATRIX(int M, int N, T v = 0, T mod = 0) : vector< vector<T> >(M), mod(mod) {
        for(auto& u : *this) u.resize(N, v);
    }
    MATRIX(const MATRIX& t) : vector< vector<T> >( t.size() ), mod(t.mod) {
        rep(i, 0, t.size()){
            (*this)[i].assign( all(t[i]) );
        }
    }
    MATRIX& operator=(const MATRIX& t){
        this->resize(t.size());
        rep(i, 0, t.size()){
            (*this)[i].assign( all(t[i]) );
        }
        return *this;
    }
    MATRIX& operator+=(const MATRIX& t){
        rep(y, 0, t.size())rep(x, 0, t[y].size()){
            (*(this))[y][x] += t[y][x];
        }
        return *this;
    }
    MATRIX operator+(const MATRIX& t) const {
        MATRIX r(*this);
        return r += t;
    }
    MATRIX& operator-=(const MATRIX& t){
        rep(y, 0, t.size())rep(x, 0, t[y].size()){
            (*(this))[y][x] -= t[y][x];
        }
        return *this;
    }
    MATRIX operator-(const MATRIX& t) const {
        MATRIX r(*this);
        return r -= t;
    }
    MATRIX& operator*=(T v){
        rep(y, 0, this->size())rep(x, 0, (*this)[y].size()){
            (*this)[y][x] *= v;
        }
        return *this;
    }
    MATRIX operator*(T v) const {
        MATRIX r(*this);
        return r *= v;
    }
    MATRIX operator*(const MATRIX& t) const {
        MATRIX r(this->size(), t[0].size(), 0, mod);
        rep(y, 0, this->size())rep(x, 0, t.size())rep(z, 0, t[y].size()){
            if(mod) r[y][z] = (r[y][z] + (*this)[y][x]*t[x][z]) % mod;
            else r[y][z] = r[y][z] + (*this)[y][x]*t[x][z];
        }
        return r;
    }
    MATRIX pow(ll v) const {
        MATRIX a(*this);
        MATRIX t(a.size(), a.size(), 0, mod);
        rep(i, 0, a.size()) t[i][i] = 1;
        while(v > 0){
            if(v & 1) t = t * a;
            a = a * a;
            v >>= 1;
        }
        return t;
    }
};



//+bignum
template<int CNTN=500>
struct BigNum {
    const int MAXN = 9999;
    const int DLEN = 4;

	int a[CNTN];    //可以控制大数的位数 
	int len;       //大数长度
	BigNum(): len(0) { memset(a,0,sizeof(a)); }   //构造函数
	BigNum(int b){ //将一个int类型的变量转化为大数
        len = 0;
        memset(a, 0, sizeof(a));
        while(b > MAXN) {
            a[len++] = b % (MAXN + 1);
            b = b / (MAXN + 1);
        }
        if(b) a[len++] = b;
    }
	BigNum(const char* str){     //将一个字符串类型的变量转化为大数
        set(str);
    }
	BigNum(const BigNum & t): len(t.len) {  //拷贝构造函数
        memcpy(a, t.a, sizeof(a));
    }
	BigNum &operator=(const BigNum & t){   //重载赋值运算符，大数之间进行赋值运算
        len = t.len;
        memcpy(a, t.a, sizeof(a));
        return *this;
    }

    BigNum& set(const char* str) {
        int t,k,index,l,i;
        memset(a, 0, sizeof(a));
        l = min(CNTN*DLEN-1, (int)strlen(str));
        len = l / DLEN;
        if(l % DLEN) len++;
        index=0;
        for(i=l-1;i>=0;i-=DLEN){
            t=0;
            k=i-DLEN+1;
            if(k<0) k=0;
            for(int j=k;j<=i;j++) t=t*10+str[j]-'0';
            a[index++]=t;
        }
        return *this;
    }

	BigNum operator+(const BigNum & t) const {   //重载加法运算符，两个大数之间的相加运算 
        BigNum r(*this);
        int mlen = min(CNTN-1, max(len, t.len));
        rep(i, 0, mlen){
            r.a[i] += t.a[i];
            if(r.a[i] > MAXN){
                r.a[i] -= MAXN;
                r.a[i+1] += 1;
            }
        }
        if(r.a[mlen]) mlen += 1;
        r.len = mlen;
        return r;
    }
	BigNum operator-(const BigNum& T) const {   //重载减法运算符，两个大数之间的相减运算 
        int i,j,big;
        bool flag;
        BigNum t1,t2;
        if(*this>T) {
            t1=*this;
            t2=T;
            flag=0;
        } else {
            t1=T;
            t2=*this;
            flag=1;
        }
        big=t1.len;
        for(i = 0 ; i < big ; i++) {
            if(t1.a[i] < t2.a[i]){ 
                j = i + 1; 
                while(t1.a[j] == 0)
                    j++; 
                t1.a[j--]--; 
                while(j > i)
                    t1.a[j--] += MAXN;
                t1.a[i] += MAXN + 1 - t2.a[i]; 
            } 
            else
                t1.a[i] -= t2.a[i];
        }
        t1.len = big;
        while(t1.a[len - 1] == 0 && t1.len > 1) {
            t1.len--; 
            big--;
        }
        if(flag) t1.a[big-1]=0-t1.a[big-1];
        return t1; 
    }
	BigNum operator/(const int& b) const {    //重载除法运算符，大数对一个整数进行相除运算
        BigNum ret; 
        int i,down = 0;   
        for(i = len - 1 ; i >= 0 ; i--)
        { 
            ret.a[i] = (a[i] + down * (MAXN + 1)) / b; 
            down = a[i] + down * (MAXN + 1) - ret.a[i] * b; 
        } 
        ret.len = len; 
        while(ret.a[ret.len - 1] == 0 && ret.len > 1)
            ret.len--; 
        return ret; 
    }
 
	int    operator%(int b) const {    //大数对一个int类型的变量进行取模运算    
        int d=0;
        for (int i = len-1; i>=0; i--) {
            d = ((d * (MAXN+1))% b + a[i]) % b;
        }
        return d;
    }

	BigNum operator*(const BigNum& T) const {   //重载乘法运算符，两个大数之间的相乘运算 
        BigNum ret; 
        int i, j;
        for(i = 0 ; i < len ; i++){ 
            int up = 0;
            for(j = 0; j < T.len; j++){ 
                int temp = a[i] * T.a[j] + ret.a[i + j] + up; 
                if(temp > MAXN) { 
                    int temp1 = temp - temp / (MAXN + 1) * (MAXN + 1); 
                    up = temp / (MAXN + 1); 
                    ret.a[i + j] = temp1;
                } else { 
                    up = 0; 
                    ret.a[i + j] = temp; 
                } 
            }
            if(up != 0) ret.a[i + j] = up; 
        } 
        ret.len = i + j; 
        while(ret.len && ret.a[ret.len-1] == 0) ret.len--; 
        return ret; 
    }

	BigNum pow(int n) const {    //大数的n次方运算
        if(n <= 0)return 1;
        if(n == 1)return *this;
        BigNum t,ret(1);
        int m=n;
        while(m>1) {
            t=*this;
            int i;
            for(i=1;i<<1<=m;i<<=1)t=t*t;
            m-=i;
            ret=ret*t;
            if(m==1)ret=ret*(*this);
        }
        return ret;
    }

    int compare(const BigNum & T) const { //大数和另一个大数的大小比较
        if(len < T.len) return -1;
        if(len > T.len) return 1;
        int idx = len - 1;
        while(idx >= 0 && a[idx] == T.a[idx]) idx--;
        if(idx < 0) return 0;
        return a[idx]<T.a[idx] ? -1 : 1;
    }

	bool   operator>(const BigNum & T) const { 
        return compare(T) > 0;
    }
	bool   operator<(const BigNum & T) const { 
        return compare(T) < 0;
    }
	bool   operator>=(const BigNum & T) const { 
        return compare(T) >= 0;
    }
	bool   operator<=(const BigNum & T) const { 
        return compare(T) <= 0;
    }
	bool   operator==(const BigNum & T) const { 
        return compare(T) == 0;
    }

	friend istream& operator>>(istream& is,  BigNum& t) {   //重载输入运算符
        char str[CNTN*4+1];
        is >> str;
        t.set(str);
        return is;
    }

	friend ostream& operator<<(ostream& out,  BigNum& t){   //重载输出运算符
        if(t.len == 0) {
            out << '0';
            return out;
        }
        out << t.a[t.len-1];
        if(t.len < 2) return out;
        per(i, 0, t.len-1) out << setw(4) << setfill('0') << t.a[i];
        return out;
    }
}; 


//+fib
template<typename T=int>
void fib1(T max, vector<T>& f){
    f.pb(0);
    f.pb(1);
    int last = f.size() - 1;
    while(true){
        f.pb(f[last] + f[last-1]);
        last += 1;
        if(f[last] > max) break;
    }
}
ll fib2(ll n, ll mod){
    MATRIX<ll> P(2, 2, 1, mod);
    P[0][0] = 0;
    P = P.pow(n);
    return P[0][1];
}
int fibf(ll n, int c){
    double s = log10(1.0/sqrt(5)) + (double)n*log10((1.0+sqrt(5))/2.0);
    return (int)(pow(10, s -(int)s + c - 1));
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
