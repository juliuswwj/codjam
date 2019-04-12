
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define size(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// ------------------------

int main(){
    int T;
    cin >> T;
    rep(t, 0, T) {
        int A, B, N;
        string str;
        
        cin >> A >> B >> N;
        
        A += 1;
        rep(n, 0, N){
            int c = (A+B)/2;
            cout << c << endl;
            cout.flush();
            cin >> str;
            cerr << c << " " << str << endl;
            if(str == "TOO_BIG") B = max(A, c - 1);
            else if(str == "TOO_SMALL") A = min(B, c + 1);
            else break;
        }
    }
    return 0;
}

