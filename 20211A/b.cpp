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
ll solve(){
    int M;
    cin >> M;
    vector<int> nums(M);
    vector<int> count(M);

    // max(sum) could be 499*(10**17)
    // since 499**8 > 499*(10**17), so we assume the max sum of group2 is 499*8 = 3992

    ll sum = 0;
    for(int i=0; i<M; i++) {
        ll n;
        cin >> nums[i] >> n;
        sum += nums[i]*n;
        count[i] = (int)min((ll)3992/nums[i], n);
        // 1
        if(i == M-1 && sum == nums[i]*2) return nums[i];
    }

    // search all factors of [sum-3992, sum]
    ll e = sum-3992;
    if(e < 1) e = 1;
    for(ll v=sum-1; v>e; v--) {
        ll t = v;
        int a = 0;
        for(int i=0; i<M && t>=nums[i]; i++) {
            int c = 0;
            while(t%nums[i]==0 && c<count[i]) {
                t /= nums[i];
                a += nums[i];
                c++;
            }
        }
        if(t == 1 && a+v == sum) return v;
    }
    return 0;
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

