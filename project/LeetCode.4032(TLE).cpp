#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
void prime(int x, unordered_map<int, int> &cnt, int &temp, int mode){
    vector<bool> is_prime(x+1, true);
    is_prime[0]=is_prime[1]=false;
    for(int i=2; i<=x/i; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=x; j+=i){
                is_prime[j]=false;
            }
        }
    }
    switch(mode){
        case 1:{
            for(int i=0; i<is_prime.size(); i++){
                if(is_prime[i]&&x%i==0){
                    cnt[i]++;
                    if(cnt[i]==1) temp++;
                }
            }
            break;
        }
        case 2:{
            for(int i=0; i<is_prime.size(); i++){
                if(is_prime[i]&&x%i==0){
                    cnt[i]--;
                    if(cnt[i]==0){
                        temp--;
                    }
                }
            }
            break;
        }
    }
}
class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int ans=0;
        int temp=0;
        unordered_map<int, int> cnt;
        for(int i=0, j=0; i<nums.size(); i++){
            prime(nums[i], cnt, temp, 1);
            while(j<=i&&temp>k){
                prime(nums[j], cnt, temp, 2);
                j++;
            }
            cout<<i-j+1<<endl;
            ans=max(ans, i-j+1);
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(9);
    arr.push_back(18);
    s.longestSubarray(arr, 4);
    return 0;
}