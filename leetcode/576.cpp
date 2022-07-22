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
class Solution {
public:
    int grid[50][50][50];
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int M = 1000000007;
        memset(grid, 0, sizeof(grid));
        
        queue<pair<int, int>> q;
        grid[startRow][startColumn][0] = 1;
        q.push({startRow, startColumn});
        int mv = 1;
        
        auto add = [&](int r, int c, long long v) {
            if(r < 0 || r >= m) return;
            if(c < 0 || c >= n) return;
            if(!grid[r][c][mv]) q.push({r, c});
            grid[r][c][mv] = (grid[r][c][mv] + v) % M;
            printf("add (%d %d) %d +%d\n", r, c, mv, (int)v);
        };
        
        while(mv < maxMove) {
            int sz = q.size();
            if(!sz) break;
            while(sz) {
                auto [r,c] = q.front(); q.pop();
                int v = grid[r][c][mv-1];
                add(r-1, c, v);
                add(r+1, c, v);
                add(r, c-1, v);
                add(r, c+1, v);
                sz--;
            }
            mv += 1;
        }
        long long ans = 0;
        for(int r=0; r<m; r++) {
            for(int i=0; i<maxMove; i++) {
                ans += grid[r][0][i];
                ans += grid[r][n-1][i];
            }
        }
        for(int c=0; c<n; c++) {
            for(int i=0; i<maxMove; i++) {
                ans += grid[0][c][i];
                ans += grid[m-1][c][i];
            }
        }
        return ans % M;
    }
};

int main(){
    Solution s;
    s.findPaths(1, 3, 4, 0, 1);
    return 0;
}

