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
map<int, bool> pcache;
bool palindrome(int a) {
    if(a < 10) return true;
    if(a < 100) return a/10 == a%10;
    if(a < 1000) return a/100 == a%10;

    auto p = pcache.find(a);
    if(p != pcache.end()) return p->second;

    char str[20];
    sprintf(str, "%d", a);
    int n = strlen(str);
    for(int i=0; i<n/2; i++) {
        if(str[i] != str[n-i-1])
            return pcache[a] = false;
    }
    return pcache[a] = true;
}

vector<bool> primes(100005, true);

int solve(){
    int A;
    cin >> A;

    vector<int> factor;
    vector<int> cnt;

    for(int i=2; i<primes.size(); i++) if(primes[i] && A%i==0) {
        int a = A/i;
        int j = 1;
        while(a%i == 0) {
            a = a/i;
            j++;
        }
        factor.push_back(i);
        cnt.push_back(j);
    }

    int ans = 1;
    int n = cnt.size();
    vector<int> idx(n);

    while(true) {
        int i = 0;
        while(i < n && idx[i] == cnt[i]) i++;
        if(i == n) break;
        idx[i]++;
        while(--i >= 0) idx[i] = 0;
        int v = 1;
        for(i=0; i<n; i++) {
            int j = idx[i];
            while(j-- > 0) v*=factor[i];
        }
        if(palindrome(v)) ans++;
    }
    return ans;
}
int main(){
    primes[0] = false;
    primes[1] = false;
    for(int i=2; i<primes.size(); i++) if(primes[i]) for(int j=2; i*j<primes.size(); j++) {
        primes[i*j] = false;
    }

    int T;
    cin >> T;
    cout.precision(12);
    rep(t, 0, T) {
        cout << "Case #" << (t+1) << ": " << solve() << endl;
    }
    return 0;
}

