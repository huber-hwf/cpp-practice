#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0, cnt=0, left=0;
        for(int right=0; right<nums.size(); right++){
            cnt+=1-nums[right];
            while(cnt>1) cnt-=1-nums[left++];
            ans=max(ans, right-left);
        }
        return ans;
    }
};