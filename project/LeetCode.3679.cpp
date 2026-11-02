#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int ans=0;
        unordered_map<int, int> cnt;
        vector<char> kept(arrivals.size(), 0);
        for(int i=0; i<arrivals.size(); i++){
            int c=cnt[arrivals[i]];
            if(c<m){
                cnt[arrivals[i]]++;
                kept[i]=1;
            }
            else ans++;
            if(i>w-2&&kept[i-w+1]==1){
                cnt[arrivals[i-w+1]]--;
            }
        }
        return ans;
    }
};