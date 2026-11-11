#include<iostream>
#include<vector>
using namespace std;
bool Need_Update(string s1, string s2){
    if(s1.size()!=s2.size()) return s1.size()>s2.size();
    for(int i=0; i<s1.size(); i++){
        if(s1[i]!=s2[i]) return s1[i]>s2[i];
    }
    return false;
}
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans=s;
        int cnt=0;
        for(int i=0, j=0; i<s.size(); i++){
            cnt+=(s[i]==(int)'1')?1:0;
            cout<<cnt<<" --- ";
            while(j<i&&cnt>=k){
                if(s[j]==(int)'0') j++;
                else if(cnt>k){
                    j++;
                    cnt--;
                }else break;
            }
            string temp=s.substr(j, i-j+1);
            cout<<temp<<" --- "<<cnt<<endl;
            if(cnt==k&&Need_Update(ans, temp)) ans=temp;
        }
        return ans==s&&cnt!=k?"":ans;
    }
};
int main(){
    Solution s;
    string str="1011";
    s.shortestBeautifulSubstring(str, 2);
    return 0;
}