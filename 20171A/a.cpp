
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

struct RECT {
    int l, r, t, b;
};

struct USAGE {
    int cnt;
    RECT* rc[26];

    USAGE() { cnt = 0; }
};

char cake[26][26];
map<char, RECT> children;

//        fprintf(stderr, #ru "[%d] %d\n", n, u.cnt); \
//        if(cnt0 > 0) fprintf(stderr, "extend0 " #ru " %d " #d " c0=%d n=%d\n", inc, cnt0, n); \

#define extend0(ru, inc, d) { \
    int base = inc > 0 ? 0 : (ru.size() - 1); \
    int n = base; \
    int cnt0 = 0; \
    while(true){ \
        if(n == ((inc > 0) ? ru.size() : -1)) break; \
        USAGE&u = ru[n]; \
        n += inc; \
        if(!u.cnt) { cnt0 += 1; continue; } \
        for(int i = 0; i < u.cnt; i++) { \
            u.rc[i]->d = rect.d; \
        } \
        for(int i = base; cnt0 > 0; i += inc) { \
            ru[i] = u; \
            cnt0 -= 1; \
        } \
        break; \
    } \
}

#define showx(ru) { \
    fprintf(stderr, "showx " #ru " %u [", (unsigned)ru.size()); \
    for(auto& u : ru) fprintf(stderr, "%d ", u.cnt); \
    fprintf(stderr, "]\n"); \
}



void solvepart(RECT rect)
{
    //fprintf(stderr, "solvepart %d,%d,%d,%d\n", rect.l, rect.t, rect.r, rect.b);

    vector<USAGE> rs(rect.b-rect.t+1);
    vector<USAGE> cs(rect.r-rect.l+1);
    for(auto& i : children){
        if(i.se.r < rect.l || i.se.l > rect.r) continue;
        if(i.se.b < rect.t || i.se.t > rect.b) continue;

        //fprintf(stderr, "add %c %d,%d,%d,%d\n", i.fi, i.se.l, i.se.t, i.se.r, i.se.b);

        rep(c, i.se.l, i.se.r+1){
            USAGE& u = cs[c - rect.l];
            u.rc[ u.cnt++ ] = &i.se;
        }
        rep(r, i.se.t, i.se.b+1){
            USAGE& u = rs[r - rect.t];
            u.rc[ u.cnt++ ] = &i.se;
        }
    }
   
    if(rect.l == rect.r){
        RECT* p = NULL;
        rep(i, 0, rs.size()){
            auto& u = rs[i];
            if(u.cnt == 0) {
                if(p) {
                    p->b++;
                    u.rc[u.cnt++] = p;
                }
            }
            else p = u.rc[0];
        }
        p = NULL;
        per(i, 0, rs.size()){
            auto& u = rs[i];
            if(u.cnt == 0) {
                if(p) {
                    p->t--;
                    u.rc[u.cnt++] = p;
                }
            }
            else p = u.rc[0];
        }
        return;
    }

    if(rect.t == rect.b){
        RECT* p = NULL;
        rep(i, 0, cs.size()){
            auto& u = cs[i];
            if(u.cnt == 0) {
                if(p) {
                    p->r++;
                    u.rc[u.cnt++] = p;
                }
            }
            else p = u.rc[0];
        }
        p = NULL;
        per(i, 0, cs.size()){
            auto& u = cs[i];
            if(u.cnt == 0) {
                if(p) {
                    p->l--;
                    u.rc[u.cnt++] = p;
                }
            }
            else p = u.rc[0];
        }
        return;
    }

    //showx(cs);
    extend0(cs, 1, l);
    extend0(cs, -1, r);
    //showx(cs);

    //showx(rs);
    extend0(rs, 1, t);
    extend0(rs, -1, b);
    //showx(rs);

    int idx = 0;
    while(idx < cs.size()){
        auto& u = cs[idx++];
        if(!u.cnt) continue;
        int i = 0;
        for(; i < u.cnt; i++){
            if( u.rc[i]->r >= idx + rect.l ) break;
        }
        if(i == u.cnt) break;
    }
    if(idx < cs.size()){
        //fprintf(stderr, "split cs@%d\n", idx);

        RECT t;
        t.l = rect.l;
        t.r = rect.l + idx - 1;
        t.t = rect.t;
        t.b = rect.b;
        solvepart(t);

        t.l = rect.l + idx;
        t.r = rect.r;
        t.t = rect.t;
        t.b = rect.b;
        solvepart(t);
        return;
    }

    idx = 0;
    while(idx < rs.size()){
        auto& u = rs[idx++];
        if(!u.cnt) continue;
        int i = 0;
        for(; i < u.cnt; i++){
            if( u.rc[i]->b >= idx + rect.t ) break;
        }
        if(i == u.cnt) break;
    }

    if(idx < rs.size()){
        //fprintf(stderr, "split rs@%d\n", idx);

        RECT t;
        t.l = rect.l;
        t.r = rect.r;
        t.t = rect.t;
        t.b = rect.t + idx - 1;
        solvepart(t);

        t.l = rect.l;
        t.r = rect.r;
        t.t = rect.t + idx;
        t.b = rect.b;
        solvepart(t);
    }
}

// recursive version
void solve(){
    int R, C;

    children.clear();
    cin >> R >> C;
    rep(r, 0, R){
        cin >> cake[r];

        cerr << cake[r] << endl;
        
        rep(c, 0, C){
            char ch = cake[r][c];
            if(ch == '?')continue;
            if(children.count(ch)) {
                RECT& child = children[ch];
                if(c > child.r) child.r = c;
                if(r > child.b) child.b = r;
            } else {
                RECT child;
                child.r = child.l = c;
                child.b = child.t = r;
                children[ch] = child;
            }
        }
    }

    RECT rect;
    rect.l = 0;
    rect.r = C - 1;
    rect.t = 0;
    rect.b = R - 1;
    solvepart(rect);
    
    for(auto& i : children){
        rep(r, i.se.t, i.se.b+1){
            rep(c, i.se.l, i.se.r+1){
                cake[r][c] = i.first;
            }
        }
    }
    
    rep(r, 0, R){
        cout << cake[r] << endl;
    }
}


/*
greedy version from Eryx. 
if the input contains 2 same letters, then get error @ testcase
C?A
?C?
?J?

CAA
CCC
JJJ

But we have "No letter appears in more than one cell in the input grid.", so it is right.
*/ 
void solve2(){
    int R, C;

    int lastr = 0;
    cin >> R >> C;
    rep(r, 0, R){
        cin >> cake[r];

        int lastc = 0;
        char lastch = 0;

        rep(c, 0, C) if(cake[r][c] != '?') {
            rep(rr, lastr, r+1) rep(cc, lastc, c+1){
                cake[rr][cc] = cake[r][c];
            }
            lastc = c + 1;
            lastch = cake[r][c];
        }

        if(lastch){
            rep(rr, lastr, r+1) rep(cc, lastc, C){
                cake[rr][cc] = lastch;
            }
            lastr = r+1;
        }
    }

    rep(r, lastr, R){
        rep(c, 0, C){
            cake[r][c] = cake[lastr-1][c];
        }
    }

    rep(r, 0, R){
        cout << cake[r] << endl;
    }
}

int main(){
    int T;
    cin >> T;
    cout.precision(12);
    rep(t, 0, T) {
        cout << "Case #" << (t+1) << ":" << endl;
        solve();
    }
    return 0;
}
    
