#include <iostream>
#include <vector>
using namespace std;

int main()
{
	/********* Begin *********/
	//定义变量
    vector<int> sb;
    int sum=0;
    //逐个输入ISBN13编码
    for(int i=0; i<12; i++){
        int x;
        cin>>x;
        sum+=i%2==0?x:x*3;
        if(i>2) sb.push_back(x);
    }
    int final;
    cin>>final;
    if((10-sum%10)%10!=final) cout<<"Error"<<endl;
    else{
        int i, j;//不能写成for(int i=0, j=10, sum=0)，这样全局变量会被遮蔽， sum在循环结束后值不会发生变化
        for(i=0, j=10, sum=0; i<sb.size(); i++, j--){
            sum+=sb[i]*j;
        }
        cout<<sum<<endl;
        sb.push_back((11-sum%11)%11==1?'x':(11-sum%11)%11);
        for(int i=0; i<sb.size(); i++){
            if(i==sb.size()-1){
                if(sb[i]=='x') cout<<'x'<<endl;
                else cout<<sb[i]<<endl;
                break;
            }
            cout<<sb[i];
        }
    }
    return 0;
}