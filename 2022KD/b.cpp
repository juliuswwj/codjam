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
void calc(vector<int>& A, int N, int K, vector<ll>& sa) {
    vector<ll> sum(N+1);
    for(int i=0; i<N; i++) {
        sum[i+1] = sum[i] + A[i];
    }
    for(int i=1, e=min(N,K); i<=e; i++) {
        ll m = 0;
        for(int j=0; j<=i; j++) {
            m = max(m, sum[N] - (sum[N-i+j] - sum[j]));
        }
        sa[i] = m;
    }
}

ll solve(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    int M;
    cin >> M;
    vector<int> B(M);
    for(int i=0; i<M; i++) cin >> B[i];

    int K;
    cin >> K;

    vector<ll> sa(K+1);
    vector<ll> sb(K+1);

    calc(A, N, K, sa);
    //cout << "sa=" << sa << endl;
    calc(B, M, K, sb);

    ll ans = 0;
    for(int i=0; i<=K; i++) {
        ans = max(ans, sa[i] + sb[K-i]);
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

