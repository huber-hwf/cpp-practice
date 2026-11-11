#include<iostream>
using namespace std;
bool isperfect(int x){
    int ans=0;
    for(int i=2; i<=x/i; i++){
        if(x%i==0) ans+=i+x/i;
        if(i==x/i) ans-=i;
    }
    return ans+1==x;
}
int main(){
    for(int i=6; i<=1000; i++){
        if(isperfect(i)) cout<<i<<endl;
    }
    return 0;
}