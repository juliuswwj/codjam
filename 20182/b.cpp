
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

#define MAX 504

int mm[MAX][MAX];
   
int main(){
    int T;
    cin >> T;
    cout.precision(12);

    memset(mm, 0, sizeof(mm));
    rep(r, 0, 40) rep(c, 0, 40)if(r+c != 0){ // 1+..+39 -> 780
        per(i, 0, MAX-r) per(j, 0, MAX-c){
            mm[i+r][j+c] = max(mm[i+r][j+c], mm[i][j] + 1);
        }
    }

    rep(t, 0, T) {
        int r, c;
        cin >> r >> c;
        cout << "Case #" << (t+1) << ": " << mm[r][c] << endl;
    }
    return 0;
}
    