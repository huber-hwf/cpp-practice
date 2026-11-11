#include<iostream>
#include<vector>
#include<new>
using namespace std;
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int num=0;
        int ans=0;
        for(int i=0, j=0; i<s.size(); i++){
            if(i>0&&s[i]==s[i-1])num++;
            int flag=j;
            while(num>1){
                j++;
                if(j>flag&&s[j]==s[j-1]) num--;
            }
            cout<<j<<endl;
            ans=max(ans, i-j+1);
        }
        return ans;
    }
};
int main(){
    string s="0001";
    Solution slt;
    slt.longestSemiRepetitiveSubstring(s);
    return 0;
}