
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

int mcnt[8] = {0, 1, 1, 2, 1, 2, 2, 3};

void solve(){
    int A;
    cin >> A;

    //fprintf(stderr, "TTTT @%d\n", A);

    A = (A-7)/3;

    char mm[80];
    memset(mm, 0, sizeof(mm));

    int I;
    int J;
    rep(i, 0, 1000){
        I = 10;
        J = -1;
        rep(n, 0, A+1){
            int c = mcnt[mm[n]] + mcnt[mm[n+1]] + mcnt[mm[n+2]];
            if(c < I){
                I = c;
                J = n;
            }
        }

        //fprintf(stderr, ">%d ", J+11);

        cout << "11 " << (J+11) << endl;
        cout.flush();

        cin >> I;
        if(I < 0)exit(1);
        cin >> J;
        if(J < 0)exit(1);

        //fprintf(stderr, "<%d %d %d\n", i, I, J);

        if(I == 0 && J == 0) break;

        mm[J-10] |= 1 << (I-10);
    }
}
int main(){
    int T;
    cin >> T;
    cout.precision(12);
    rep(t, 0, T) {
        solve();
    }
    return 0;
}
    