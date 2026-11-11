#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long long sum=0;
        int ans=nums.size()+1;
        int flag=0;
        for(int i=0, j=0; i<nums.size(); i++){
            sum+=nums[i];
            while(sum>=target){
                flag=1;
                if(sum-nums[j]>=target){
                    sum-=nums[j++];
                }else break;
            }
            if(flag) ans=i-j+1<ans?i-j+1:ans;
        }
        return ans==nums.size()+1?0:ans;
    }
};