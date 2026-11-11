#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
void change(vector<int> &nums, pair<int, int> &dist, int i, int k){
    int highest=nums[i]+k;
    int lowest=nums[i]-k;
    dist.first=dist.first<highest?dist.first:highest;
    dist.second=dist.second>lowest?dist.second:lowest;
}
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size()-1;
        int ans=0;
        pair<int, int> dist={1e9, -1e9};
        sort(nums.begin(), nums.end());
        if(nums[0]==nums[n]) return n+1;
        for(int i=0, j=0; i<=n; i++){
            change(nums, dist, i, k);
            while(j<i&&dist.first<dist.second){
                j++;
                dist.first=nums[j]+k;
            }
            ans=max(ans, i-j+1);
        }
        return ans;
    }
};
int main(){
    Solution slt;
    vector<int> nums={5,57,46};
    slt.maximumBeauty(nums, 15);
    return 0;
}
