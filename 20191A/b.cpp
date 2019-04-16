
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
    
int main(){
    int T, N, M;
    cin >> T >> N >> M;
    cout.precision(12);
    rep(t, 0, T) {
        int m[7];
        rep(n, 0, 7){
            rep(i, 0, 18) cout << (18-n) << " ";
            cout << endl;
            cout.flush();

            m[n] = 0;
            rep(i, 0, 18) {
                int t;
                cin >> t;
                m[n] += t;
            }
            //fprintf(stderr, "m[n] = %d\n", m[n]);
        }

        int v = m[0];
        while(v <= 1000000){
            int i = 1;
            for(; i<7; i++){
                if(v < m[i]) break;
                if(v % (18-i) != m[i] % (18-i)) break;
            }
            if(i == 7) break;
            v += 18;
        }
        //fprintf(stderr, "-- %d %d\n", t, v);
        cout << v << endl;
        cout.flush();

        cin >> v;
        if(v == -1)break;
    }
    //fprintf(stderr, "exit\n");
    return 0;
}
    