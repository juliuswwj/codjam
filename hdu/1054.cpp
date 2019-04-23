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

//+main
int main(){
    int n, k, u, v;
    while(scanf("%d", &n) != EOF){
        HUNGARY ht(n);
        rep(i, 0, n){
            if( scanf("%d:(%d)", &u, &k) == EOF) break;
            while(k--){
                if( scanf("%d", &v) == EOF) break;
                ht.add(u, v);
            }
        }
        cout << ht.run() << endl;
    }
    return 0;
}

