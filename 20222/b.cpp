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

//+main
const int M = 101;
bool g[M][M];
int  miss[M];

int solve(){
    int R;
    cin >> R;
    return miss[R]*4;
}
int main(){
    int T;
    cin >> T;
    cout.precision(12);

    memset(g, 0, sizeof(g));
    memset(miss, 0, sizeof(miss));
    g[0][0] = true;
    for(int r=1; r<M; r++) {
        for(int x=0; x<=r; x++) {
            int y = round(sqrt(r*r-x*x));
            g[y][x] = true;
            g[x][y] = true;
        }
    }
    for(int r=1; r<M; r++) {
        int c = 0;
        for(int x=0; x<=r; x++) for(int y=0; y<=r; y++) {
            if(round(sqrt(x*x + y*y)) <= r && !g[y][x]) c++;
        }
        miss[r] = c;
    }

    rep(t, 0, T) {
        cout << "Case #" << (t+1) << ": " << solve() << endl;
    }
    return 0;
}

