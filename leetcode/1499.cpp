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
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int i = 0;
        int j = 0;
        
        map<int, int> mc;
        int ans = INT_MIN;
        while(i < n-1) {
            if(i < j && points[j][0]-points[i][0] <= k) {
                ans = max(ans, mc.rbegin()->first + points[i][1]-points[i][0]);
                cout << "i=" << i << " j=" << j << " ans=" << ans << endl;
            }
            
            if(j < n-1 && (points[j+1][0]-points[i][0] <= k || i == j)) {
                j++;
                int v = points[j][0]+points[j][1];
                mc[v]++;
                cout << "i=" << i << " j=" << j << " mc=" << mc << endl;
                continue;
            }
            i++;
            int v = points[i][0]+points[i][1];
            if(--mc[v] == 0)mc.erase(v);

            cout << "i=" << i << " j=" << j << " mc=" << mc << endl;
        }
        return ans;
    }
};

int main(){
    //vector<vector<int>> test = {{1,3},{2,0},{5,10},{6,-10}};
    vector<vector<int>> test = {{0,0},{3,0},{9,2}};
    Solution s;
    s.findMaxValueOfEquation(test, 3);
    return 0;
}

