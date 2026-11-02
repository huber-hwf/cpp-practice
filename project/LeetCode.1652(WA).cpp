#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans;
        if(k==0){
            ans.resize(code.size());
        }
        long long sum=0;
        long long tosub=0;
        for(int i=0; i<code.size(); i++){
            sum+=code[i];
        }
        for(int i=0; k<0&&i<(2*code.size()-k-1)%code.size(); i++){
            tosub+=code[i];
            int left=i-code.size()+k+1;
            if(left<0) continue;
            ans.push_back(sum-tosub);
            tosub-=code[left];
        }
        if(k<0) return ans;
        for(int i=code.size()-k+1; ans.size()<code.size(); i=(i+1)%code.size()){
            tosub+=code[i];
            if(i==0||ans.size()>0){
                ans.push_back(sum-tosub);
                int left=(i+k+1)%code.size();
                tosub-=code[left];
            }
        }
        return ans;
    }
};