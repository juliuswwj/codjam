
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
    
#define MAX 25
int solve(){
    int R, C;
    char g[MAX][MAX];
    char vis[MAX][MAX];

    cin >> R >> C;
    rep(r, 0, R){
        char line[MAX];
        cin >> line;
        rep(c, 0, C){
            g[r][c] = line[c] == 'B';
        }
    }

    int ans = 0;
    char color[4];

    auto cover = [&](int r, int c){
        list<int> data;
        vis[r][c] = 1;
        data.pb(r*MAX+c);

        int t = 0;
        while(data.size() > 0){
            int xy = *data.begin(); 
            data.pop_front();
            t += 1;

            int y = xy/MAX;
            int x = xy%MAX;

            if(x > 0 && !vis[y][x-1]){
                vis[y][x-1] = 1;
                data.pb(y*MAX + x-1);
            }
            if(x < C-1 && !vis[y][x+1]){
                vis[y][x+1] = 1;
                data.pb(y*MAX + x+1);
            }
            if(y > 0 && !vis[y-1][x]){
                vis[y-1][x] = 1;
                data.pb((y-1)*MAX + x);
            }
            if(y < R-1 && !vis[y+1][x]){
                vis[y+1][x] = 1;
                data.pb((y+1)*MAX + x);
            }
        }
        ans = max(ans, t);
    };

    rep(S, 0, 2){
        rep(i, 0, 1) color[i] = (S>>i)&1;

        bool find = false;
        rep(r, 0, R) rep(c, 0, C) if(g[r][c] == color[0]){
            find = true;
            break;
        }
        if(!find)continue;

        memset(vis, 0, sizeof(vis));
        rep(r, 0, R) rep(c, 0, C) if(g[r][c] != color[0]){
            vis[r][c] = 1;
        }

        rep(r, 0, R) rep(c, 0, C) if(!vis[r][c]){
            cover(r, c);
        }
    }

    rep(x, 1, C-1) rep(S, 1, 3){
        rep(i, 0, 2) color[i] = (S>>i)&1;

        bool find = false;
        rep(r, 0, R) rep(c, 0, C) if(g[r][c] == color[0]){
            find = true;
            break;
        }
        if(!find)continue;

        memset(vis, 0, sizeof(vis));
        rep(r, 0, R) rep(c, 0, C) if(g[r][c] != color[0]){
            vis[r][c] = 1;
        }

        rep(r, 0, R) rep(c, 0, C) if(!vis[r][c]){
            cover(r, c);
        }
    }



    return ans;
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
    