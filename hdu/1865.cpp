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

    int join(int x, int y){
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

//+main
int main(){
    int N;
    while(cin >> N){
        UNION ut(10000000);
        int m = 1;
        rep(n, 0, N){
            int u, v;
            cin >> u >> v;
            m = max(m, ut.join(u-1, v-1));
        }
        cout << m << endl;
    }
    return 0;
}

