#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int zero=0;
        for(int i=0, j=0; i<nums.size(); i++){
            zero+=nums[i]==0?1:0;
            while(j<=i&&zero>k){
                zero-=nums[j++]==0?1:0;
            }
            if(j<=i) ans=max(ans, i-j+1);
        }
        return ans;
    }
};