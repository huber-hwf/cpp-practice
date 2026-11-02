#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans=0;
        int cost=0;
        for(int i=0, j=0; i<s.size(); i++){
            cost+=abs(s[i]-t[i]);
            while(j<=i&&cost>maxCost) cost-=abs(s[j]-t[j++]);
            if(j<=i) ans=max(ans, i-j+1);
        }
        return ans;
    }
};