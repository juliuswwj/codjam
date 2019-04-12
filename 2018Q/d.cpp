
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
    

#define EPS  1e-8

double cal(double a, double b)
{
    return 2*a + sqrt(1 - 4*a*a);
}

void solve(){
    double A;
    cin >> A;

    double ma = 0.25*sqrt(2);
    //cout << "ma " << ma << endl;

    double a = 0;
    double b = ma;
    rep(i, 0, 50){
        double c = (a+b)/2;
        double t = cal(c, 0);
        //cout << c << " " << t-A << endl;
        if(t < A - EPS){
            a = c;
            continue;
        }
        if(t > A + EPS){
            b = c;
            continue;
        }
        break;
    }

    cout << sqrt(0.25 - a*a) << " " << a << " " << 0 << endl;
    cout << -a << " " << sqrt(0.25 - a*a) << " " << 0 << endl;
    cout << 0 << " " << 0 << " " << 0.5 << endl; 

}
int main(){
    int T;
    cin >> T;
    cout.precision(12);
    rep(t, 0, T) {
        cout << "Case #" << (t+1) << ":" << endl;
        solve();
    }
    return 0;
}
    