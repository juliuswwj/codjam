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

//+main
struct POINT {
    int x, y;
};
int N;
vector<POINT> pts;

double dist(int i, int j)
{
    int x = pts[i].x-pts[j].x;
    int y = pts[i].y-pts[j].y;
    return x*x + y*y;
}

bool check(double r){
    r = r*r*4;

    TARJAN t(2*N);
    for(int i=0; i<2*N-2; i+=2) for(int j=i+2; j<2*N; j+=2){
        if(dist(i, j)<r)t.add(i, j+1), t.add(j, i+1);
        if(dist(i, j+1)<r)t.add(i, j), t.add(j+1, i+1);
        if(dist(i+1, j)<r)t.add(i+1, j+1), t.add(j, i);
        if(dist(i+1, j+1)<r)t.add(i+1, j), t.add(j+1, i);
    }
    t.run();
    for(int i=0; i<2*N; i+=2)if(t.ns[i].id == t.ns[i+1].id) return false;
    return true;
}

int main(){
    cout.precision(12);
    while(cin >> N){
        pts.clear();
        rep(i, 0, N){
            POINT p1, p2;
            cin >> p1.x >> p1.y >> p2.x >> p2.y;
            pts.pb(p1);
            pts.pb(p2);
        }

        double a = 0;
        double b = 2e5;
        while(b - a > 1e-10){
            double c = (b+a) / 2;
            if(check(c))
                a = c;
            else
                b = c;
        }
        cout << a << endl;
    }
    return 0;
}

