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
int apple(int m, int n)
{
    if(m <= 1 || n <= 1) return 1;
    if(m < n) return apple(m, m);
    return apple(m, n-1) + apple(m-n, n);
}
int main(){
    int T;
    cin >> T;
    rep(t, 0, T) {
        int m, n;
        cin >> m >> n;
        cout << apple(m, n) << endl;
    }
    return 0;
}

