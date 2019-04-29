//+base
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cctype>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
#include <functional>
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
struct TT {
    int l, r, cnt, add, it;
    void build(){
        cnt = 0;
        add = 0;
        it = l;
    }
    void up(const TT& a, const TT& b){
        cnt = max(a.cnt, b.cnt);
        it = (a.cnt >= b.cnt) ? a.it : b.it;
    }
    void down(TT& a, TT& b){
        if(add){
            a.cnt += add;
            b.cnt += add;
            a.add = add;
            b.add = add;
            add = 0;
        }
    }
    void update(int n){
        cnt += n;
        add += n;
    }

    void merge(const TT& a){
        it = (cnt >= a.cnt) ? it : a.it;
    }
};

void solve(){
    int P, Q;
    cin >> P >> Q;

    SEGTREE<TT> stx(Q+1);
    SEGTREE<TT> sty(Q+1);

    rep(i, 0, P){
        int x, y;
        char dir;
        cin >> x >> y >> dir;
        if(dir == 'N') sty.update(1, y+2, Q+1);
        if(dir == 'E') stx.update(1, x+2, Q+1);
        if(dir == 'W') stx.update(1, 1, x);
        if(dir == 'S') sty.update(1, 1, y);
    }

    TT tx, ty;
    stx.run(tx, 1, Q+1);
    sty.run(ty, 1, Q+1);


    //rep(y, 0, Q)fprintf(stderr, "%d ", sty.tree[y].c);
    //fprintf(stderr, "\n");


    cout << tx.it-1 << " " << ty.it-1;
}

int main(){
    int T;
    cin >> T;
    cout.precision(12);
    rep(t, 0, T) {
        cout << "Case #" << (t+1) << ": ";
        solve();
        cout << endl;
    }
    return 0;
}

