#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> cnt;
        int ans=0, kind=0;
        for(int i=0, j=0; i<fruits.size(); i++){
            if(!cnt[fruits[i]]) kind++;
            cnt[fruits[i]]++;
            while(kind>2){
                if(!--cnt[fruits[j++]]) kind--;
            }
            ans=max(ans, i-j+1);
        }
        return ans;
    }
};