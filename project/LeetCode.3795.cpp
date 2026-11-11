#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        long long sum=0;
        unordered_map<int, int> cnt;
        int ans=nums.size()+1;
        int flag=0;
        for(int i=0, j=0; i<nums.size(); i++){
            cnt[nums[i]]++;
            if(cnt[nums[i]]==1) sum+=nums[i];
            while(sum>=k){
                flag=1;
                if(cnt[nums[j]]==1){
                    if(sum-nums[j]>=k){
                        sum-=nums[j++];
                        cnt[nums[j-1]]--;
                    }
                    else break;
                }else{
                    cnt[nums[j++]]--;
                }
            }
            int s=0;
            for(int k=j; k<=i; k++){
                cout<<nums[k]<<" ";
                s+=nums[k];
            }
            cout<<" --- "<<s<<" --- "<<sum<<endl;
            if(flag) ans=ans<i-j+1?ans:i-j+1;
        }
        return flag?ans:-1;
    }
};
int main(){
    vector<int> nums={57,75,43,52,80,27,18,33,16,75,77,71,10,34};
    Solution s;
    s.minLength(nums, 152);
    return 0;
}