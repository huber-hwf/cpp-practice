#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> cnt;
        long long ans=0 ,sum=0;
        for(int i=0, j=0; i<nums.size(); i++){
            cnt[nums[i]]++;
            sum+=nums[i];
            while(cnt[nums[i]]>1){
                cnt[nums[j]]--;
                sum-=nums[j++];
            }
            ans=max(ans, sum);
        }
        return ans;
    }
};