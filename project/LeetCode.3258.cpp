#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans=0, min=0;
        int one=0, zero=0;
        for(int i=0, j=0; i<s.size(); i++){
            if(s[i]=='1') one++;
            else zero++;
            min=zero>one?one:zero;
            while(min>k){
                if(s[j++]=='1') one--;
                else zero--;
                min=zero>one?one:zero;
            }
            ans+=i-j+1;
        }
        return ans;
    }
};