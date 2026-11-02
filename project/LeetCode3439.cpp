#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int l=0, ans=0, temp=0;
        startTime.push_back(eventTime); endTime.push_back(eventTime);
        for(int i=0, j=0; i<startTime.size(); i++){
            if(i>k){
                int c=i-k-1;
                if(c==0) temp-=startTime[c];
                else temp-=startTime[c]-endTime[c-1];
            }
            temp+=startTime[i]-l;
            l=endTime[i];
            if(i>=k) ans=max(ans, temp);
        }
        return ans;
    }
};