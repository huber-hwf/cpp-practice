#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        int r=k>0?k+1:n;
        k=abs(k);
        int s=reduce(code.begin()+r-k, code.begin()+r);
        vector<int> ans;
        for(int i=0; i<n; i++){
            ans.push_back(s);
            s+=code[r%n]-code[(r-k)%n];
            r++;
        }
        return ans;
    }
};