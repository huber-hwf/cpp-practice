#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int beautifulBouquet(vector<int>& flowers, int cnt) {
        int ans=0;
        unordered_map<int, int> num;
        for(int i=0, j=0; i<flowers.size(); i++){
            num[flowers[i]]++;
            while(num[flowers[i]]>cnt){
                num[flowers[j++]]--;
            }
            ans+=i-j+1;
        }
        return ans;
    }
};
