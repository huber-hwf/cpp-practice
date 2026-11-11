#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        unordered_map<int, int> cnt;
        long long ans=0;
        for(int i=0, j=0; i<nums.size(); i++){
            cnt[nums[i]]++;
            int dif;
            if(cnt[nums[i]]==1){
                for(int k=j; k<i; k++){
                    if(k==j) dif=abs(nums[i]-nums[k]);
                    dif=max(dif, abs(nums[i]-nums[k]));
                }
                while(j<i&&dif>2){
                    cnt[nums[j++]]--;
                    if(cnt[nums[j-1]]==0){
                        dif=0;
                        for(int k=j; k<i; k++){
                        dif=max(dif, abs(nums[i]-nums[k]));
                        }
                    }
                }
            }
            cout<<j<<" "<<i<<endl;
            ans+=i-j+1;
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> nums={5, 4, 2, 4};
    s.continuousSubarrays(nums);
    return 0;
}