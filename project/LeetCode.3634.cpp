#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans=1e6;
        long long minvalue=nums[0];
        for(int i=0, j=0; i<nums.size(); i++){
            while(j<i&&nums[i]>k*minvalue) minvalue=nums[++j];
            ans=ans<=nums.size()-i+j-1?ans:nums.size()-i+j-1;
        }
        return ans;
    }
};