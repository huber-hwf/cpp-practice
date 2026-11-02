#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int n, k;
    // 请在此添加代码，输入n和k，并输出n以内k个素数以及它们的和
    /********** Begin *********/
    while(cin>>n>>k){
        vector<bool> is_prime(n, true);
        is_prime[0]=is_prime[1]=false;
        for(int i=2; i<(n-1)/i; i++){
            if(is_prime[i]){
                for(int j=i*i; j<(n-1); j+=i){
                    is_prime[j]=false;
                }
            }
        }
        long long sum=0;
        for(int i=is_prime.size()-1, num=0; num<k; i--){
            if(is_prime[i]){
                cout<<i<<" ";
                num++;
                sum+=i;
            }
        }
        cout<<sum<<endl;
    }
    /********** End **********/

    return 0;
}