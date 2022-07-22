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
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;

    vector<vector<int>> cnt(N+1, vector<int>(26));
    for(int i=0; i<N; i++) {
        for(int j=0; j<26; j++) {
            cnt[i+1][j] = cnt[i][j] + (s[i]-'A' == j);
        }
    }

    int ans = 0;
    for(int i=0; i<Q; i++) {
        int L, R;
        cin >> L >> R;
        L -= 1;

        int c = 0;
        for(int j=0; j<26; j++) {
            if((cnt[R][j] - cnt[L][j]) % 2) c++;
        }
        if(c <= 1) ans++;
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

