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
double solve(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    sort(A.begin(), A.end());

    int L = N-M+1;
    double ans = A[L/2];
    if(L%2 == 0) ans = (ans + A[L/2-1]) / 2;
    for(int i=L; i<N; i++) ans += A[i];
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

