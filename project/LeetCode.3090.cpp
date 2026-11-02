#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> alpha(26);
        int ans=0, temp=0;
        for(int i=0, j=0; i<s.size(); i++){
            alpha[s[i]-'a']++;
            while(j<i&&alpha[s[i]-'a']>2) alpha[s[j++]-'a']--;
            ans=max(ans, i-j+1);
        }
        return ans;
    }
};