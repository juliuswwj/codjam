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
int grid[260][260];
int solve(){
    memset(grid, 0x70, sizeof(grid));

    int R, C;
    cin >> R >> C;
    queue<pair<int,int>> q;
    int cc = 0;
    for(int r=0; r<R; r++) {
        string str;
        cin >> str;
        for(int c=0; c<C; c++) if(str[c] == '1') {
            q.push({r, c});
            grid[r][c] = cc;
        }
    }

    //cout << "begin " << R << " " << C << endl;

    cc++;
    auto add = [&](int r, int c) {
        if(r < 0 || r >= R) return;
        if(c < 0 || c >= C) return;
        if(grid[r][c] <= cc) return;
        grid[r][c] = cc;
        q.push({r, c});
        //cout << "add " << r << " " << c << endl;
    };

    while(true) {
        int sz = q.size();
        if(!sz) break;
        while(sz-- > 0) {
            auto [r, c] = q.front();
            q.pop();

            add(r-1, c);
            add(r+1, c);
            add(r, c-1);
            add(r, c+1);
        }
        cc++;
    }

    vector<int> cnt(cc);
    for(int r=0; r<R; r++) for(int c=0; c<C; c++) cnt[grid[r][c]]++;

    cc = 0;
    add(lastr, lastc);
    cc++;
    while(true) {
        int sz = q.size();
        if(!sz) break;
        while(sz-- > 0) {
            auto [r, c] = q.front();
            q.pop();

            add(r-1, c);
            add(r+1, c);
            add(r, c-1);
            add(r, c+1);
        }
        cc++;
    }

    int ans = 0;
    for(int r=0; r<R; r++) for(int c=0; c<C; c++) ans = max(ans, grid[r][c]);
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

