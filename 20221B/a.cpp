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
int solve(){
    int N;
    cin >> N;
    vector<int> D(N);
    for(int i=0; i<N; i++) cin >> D[i];

    int b = 0;
    int e = N-1;
    int last = 0;
    int ans = 0;

    while(b <= e) {
        if(D[b] < last) {
            b++;
            continue;
        }
        if(D[e] < last) {
            e--;
            continue;
        }
        
        ans++;
        if(D[b] < D[e]) {
            last = D[b];
            b++;
        } else {
            last = D[e];
            e--;
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

