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
    int n;
    vector<int> data;
    vector<bool> lazy;
    
    void update(int i, int l, int r, int b, int e, int h) {
        if(b <= l && r <= e) {
            data[i] += h;
            lazy[i] = true;
            return;
        }
        if(lazy[i]) {
            lazy[i] = false;
            lazy[2*i+2] = lazy[2*i+1] = true;
            data[2*i+2] = data[2*i+1] = data[i];
        }
        int m = l + (r-l)/2;
        if(l <= e && e <= m) update(2*i+1, l, m, b, e, h);
        else if(m+1 <= b && b <= r) update(2*i+2, m+1, r, b, e, h);
        else if(l <= b && e <= r) {
            int mh = query(i, l, r);
            update(2*i+1, l, m, b, e, h);
            update(2*i+2, m+1, r, b, e, h);

        }


        if(b <= m) update(2*i+1, l, m, b, e, h);
        if(e >= m+1) update(2*i+2, m+1, r, b, e, h);
        data[i] = max(data[2*i+1], data[2*i+2]);
    }

    void print(int i, int l, int r) {
        if(l == r) {
            cout << data[i] << ",";
            return;
        }
        int m = l + (r-l)/2;
        print(2*i+1, l, m);
        print(2*i+2, m+1, r);
    }
    
    
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        set<int> pts;
        for(auto& p: positions) {
            pts.insert(p[0]);
            pts.insert(p[0]+p[1]-1);
        }
        vector<int> idx(pts.begin(), pts.end());
        n = idx.size();
        data.resize(n*4);
        lazy.resize(n*4);

        cout << "idx=" << idx << endl;
        
        vector<int> ans;
        for(auto& p: positions) {
            int a = lower_bound(idx.begin(), idx.end(), p[0]) - idx.begin();
            int b = lower_bound(idx.begin(), idx.end(), p[0]+p[1]-1) - idx.begin();
            update(0, 0, n-1, a, b, p[1]);
            ans.push_back(data[0]);

            cout << "[";
            print(0, 0, n-1);
            cout << "]" << endl;
        }
        return ans;
    }
};

int main(int argc, char*argv[]) {
    vector<vector<int>> test = {{9,7},{1,9},{3,1}};
    Solution s;
    auto ans = s.fallingSquares(test);
    cout << "ans=" << ans << endl;
    return 0;
}

