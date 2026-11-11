#include<iostream>
using namespace std;
long long Fib(int n){
    if(n==1||n==0){
        return n;
    }
    return Fib(n-1)+Fib(n-2);
}
int main(){
    int n;
    cin>>n;
    cout<<Fib(n);
    return 0;
}