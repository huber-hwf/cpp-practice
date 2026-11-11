#include<iostream>
#include<ctime>
using namespace std;
int main(){
    srand(time(0));
    int target=rand()%100+1;
    while(true){
        int x;
        cin>>x;
        if(x==target){
            cout<<"恭喜你，猜对了！"<<endl;
            break;
        }else if(x<target){
            cout<<"猜小了！"<<endl;
        }else{
            cout<<"猜大了！"<<endl;
        }
    }
    return 0;
}