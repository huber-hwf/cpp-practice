#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> map;
        vector<int> set(26,0);
        int num=0, ans=0;
        for(int i=0; i<s.size(); i++){
            if(!(set[s[i]-'a']++)) num++;
            if(i<minSize-1) continue;
            int left=i-minSize+1;
            if(num<=maxLetters){
                int cnt=++map[s.substr(left, minSize)];
                ans=max(ans,cnt);
            }
            if(!--set[s[left]-'a']) num--;
        }
        return ans;
    }
};