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

//+main
struct ST {
    int l, r;
    ll sum, add;

    ST() : sum(0), add(0) {}
    
    void build(){
        cin >> sum;
    }
    void update(int v){
        add += v;
        sum += v * (r - l + 1);
    }
    void up(const ST& a, const ST& b){
        sum = a.sum + b.sum;
    }
    void down(ST& a, ST& b){
        if(!add)return;
        int m = r - l + 1;
        a.add += add;
        b.add += add;
        a.sum += add * (m - (m>>1));
        b.sum += add * (m>>1);
        add = 0;
    }
    void merge(const ST& a){
        sum += a.sum;
    }
};
int main(){
    int N, M;
    while( cin >> N >> M ) {
        SEGTREE<ST> st(N);
        while(M--){
            char ch[2];
            cin >> ch;

            int a, b, c;
            if(ch[0] == 'Q'){
                cin >> a >> b;
                ST ret;
                st.run(ret, a, b);
                cout << ret.sum << endl;
            } else {
                cin >> a >> b >> c;
                st.update(c, a, b);
            }
        }
    }
    return 0;
}

