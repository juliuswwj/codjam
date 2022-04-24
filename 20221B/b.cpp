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
int N, P;
long long cal(int p, vector<int>& prods, int e) {
    return prods[P-1]-prods[0] + min(abs(p-prods[0]) + abs(prods[e]-prods[P-1]), abs(p-prods[P-1]) + abs(prods[e]-prods[0]));
}

long long solve(){
    cin >> N >> P;
    vector<vector<int>> customers(N, vector<int>(P));

    for(int i=0; i<N; i++) {
        for(int j=0; j<P; j++) cin >> customers[i][j];
        sort(customers[i].begin(), customers[i].end());
    }

    vector<long long> cnt(P);

    for(int j=0; j<P; j++) cnt[j] = cal(0, customers[0], j);
    for(int i=1; i<N; i++) {
        vector<long long> newcnt(cnt.begin(), cnt.end());
        for(int j=0; j<P; j++) {
            long long v = cnt[0] + cal(customers[i-1][0], customers[i], j);
            for(int k=1; k<P; k++) {
                v = min(v, cnt[k] + cal(customers[i-1][k], customers[i], j));
            }
            newcnt[j] = v;
        }
        cnt.assign(newcnt.begin(), newcnt.end());
    }
    return *min_element(cnt.begin(), cnt.end());
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

