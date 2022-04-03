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
class Solution {
public:
    bool validp(const string& s, bool r) {
        int i = 0;
        int j = s.length()-1;
        while(i < j) {
            if(s[i] == s[j]) {
                i++;
                j--;
                continue;
            }
            if(r) {
                if(j == i+1) return true;
                if(s[i] == s[j-1] && validp(s.substr(i+1, j-i-2), false)) return true;
                if(s[i+1] == s[j] && validp(s.substr(i+2, j-i-2), false)) return true;
            }
            return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        return validp(s, true);
    }
};

int main(){
    Solution s;
    string str;
    while(cin >> str) {
        cout << str << " " << s.validPalindrome(str) << endl;
    }
    return 0;
}

