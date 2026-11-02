#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int cnt[2]={0};
        int i=0, j=0;
        bool flag=false;
        while(nums[i]==0) i++;
        j=i;
        for( ; i<nums.size(); i++){
            cnt[nums[i]]++;
            if(cnt[0]==2) ans=max(ans, i-j-1);
            if(cnt[0]==1) ans=max(ans, i-j);
            while(j<i&&cnt[0]>1){
                cnt[nums[j++]]--;
                flag=true;
            }
            while(flag&&i>=1&&!nums[i-1]){
                if(j<nums.size()-1) j++;
                if(nums[j]||j==nums.size()-1){
                    i=j-1;
                    flag=false;
                    cnt[0]=0;
                    break;
                }
            }
        }
        return (ans!=0)?ans:(j?i-j:(nums[nums.size()-1]?nums.size()-1:0));
    }
};