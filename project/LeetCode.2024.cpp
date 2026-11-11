#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        vector<int> TF(2);
        int ans=0;
        for(int i=0, j=0; i<answerKey.size(); i++){
            answerKey[i]=='T'?TF[0]++:TF[1]++;
            int min=TF[0]<TF[1]?TF[0]:TF[1];
            while(TF[0]!=0&&TF[1]!=0&&min>k){
                answerKey[j++]>'F'?TF[0]--:TF[1]--;
                min=TF[0]<TF[1]?TF[0]:TF[1];
            }
            ans=max(ans, i-j+1);
        }
        return ans;
    }
};