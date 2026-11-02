#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=0, one=0, ans=nums.size();
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1) n++;
        }
        if(n==0) return 0;
        for(int i=0; i<nums.size()+n-1; i++){
            if(nums[i%nums.size()]) one++;
            int left=i-n+1;
            if(left<0) continue;
            ans=min(ans, n-one);
            if(nums[left]) one--;
        }
        return ans;
    }
};