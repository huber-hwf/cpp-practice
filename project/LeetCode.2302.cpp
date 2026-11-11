#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum=0, ans=0;
        for(int i=0, j=0; i<nums.size(); i++){
            sum+=nums[i];
            long long prod=sum*(i-j+1);
            while(prod>=k){
                sum-=nums[j++];
                prod=sum*(i-j+1);
            }
            ans+=i-j+1;
        }
        return ans;
    }
};