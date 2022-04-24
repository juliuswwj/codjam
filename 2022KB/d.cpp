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
vector<vector<int>> DIRS = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
char DIRSTRING[] = "ESWN";
string solve(){
    int R, C;
    cin >> R >> C;

    string A[400];
    for(int i=0; i<R; i++) {
        string b;
        cin >> b;
        for(int j=0; j<b.length(); j++) {
            A[i*2].push_back(b[j]);
            A[i*2].push_back(b[j]);
            A[i*2+1].push_back(b[j]);
            A[i*2+1].push_back(b[j]);
        }
    }
    R*=2;
    C*=2;

    string ans;
    int r = 0;
    int c = 0;
    A[r][c] = '!';

    while(true) {
        int nr, nc;
        bool ok = false;
        for(int d=0; d<4; d++) {
            nr = r + DIRS[d][0];
            nc = c + DIRS[d][1];
            if(nr >= 0 && nr < R && nc >= 0 && nc < C && A[nr][nc] == '*') {
                ok = true;
                ans.push_back(DIRSTRING[d]);
                break;
            }
        }
        if(!ok) break;
        r = nr;
        c = nc;
        A[r][c] = '!';
    }
    for(r=0; r<R; r++) for(c=0; c<C; c++) if(A[r][c] == '*') return "IMPOSSIBLE";
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

