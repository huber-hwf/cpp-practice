#include<iostream>
using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        long long sub=1;
        long long pow=2;
        long long toremove=0;
        while(n){
            if(n%2==1)
            sub*=pow;
            pow*=pow;
            n/=2;
        }
        sub-=1;
        int a=0, b=0, c=0;
        for(int i=0, j=0; i<s.size(); i++){
            switch(s[i]){
                case 'a': a++; break;
                case 'b': b++; break;
                case 'c': c++; break;
            }
            while(a&&b&&c){
                switch(s[j++]){
                case 'a': a--; break;
                case 'b': b--; break;
                case 'c': c--; break;
                }
            }
            toremove+=i-j+1;
        }
        return sub-toremove;
    }
};
int main(){
    Solution s;
    string str="abcabc";
    s.numberOfSubstrings();
}
