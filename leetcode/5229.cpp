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

//+debug
template<class T>
ostream& operator<<(ostream& os, const vector<T>& vs) {
    os << "[";
    bool first = true;
    for(auto v: vs) {
        if(!first) os << ", ";
        first = false;
        os << v;
    }
    os << "]";
    return os;
}

template<class T, class V>
ostream& operator<<(ostream& os, const pair<T,V>& p) {
    os << p.first << ":" << p.second;
    return os;
}

template<class T, class V>
ostream& operator<<(ostream& os, const map<T,V>& vs) {
    os << "{";
    bool first = true;
    for(auto v: vs) {
        if(!first) os << ", ";
        first = false;
        os << v;
    }
    os << "}";
    return os;
}

//+main
class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> sum(n+1);
        int ans1 = 0;
        int ans2 = 0;
        for(int i=0; i<n; i++) {
            sum[i+1] = nums2[i]-nums1[i] + sum[i];
            ans1 += nums1[i];
            ans2 += nums2[i];
        }

        cout << "ans1=" << ans1 << " ans2=" << ans2 << " AA " << sum << endl;
        
        vector<int> hi(n+1);
        hi[n] = sum[n];
        for(int i=n-1; i>=1; i--) {
            hi[i] = max(hi[i+1], sum[i]);
        }

        cout << "hi=" << hi << endl;
        
        int lo = sum[1];
        int m = 0;
        for(int i=2; i<=n; i++) {
            m = max(m, hi[i] - lo);
            if(lo > sum[i]) lo = sum[i];
        }
        return max(ans1+m, ans2+m);
    }
};
int main(){
    vector<int> nums1 = {20,40,20,70,30};
    vector<int> nums2 = {50,20,50,40,20};
    Solution s;
    cout << s.maximumsSplicedArray(nums1, nums2) << endl;
    return 0;
}

