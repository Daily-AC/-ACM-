#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
void beford(string in,string after){
	if(in.size()==0) return ;
	
    char boot=after[after.size()-1];
    int index=in.find(boot);
    cout<<boot;
    beford(in.substr(0,index),after.substr(0,index));
    beford(in.substr(index+1),after.substr(index,in.size()-index-1));
	
}
int main(){
    string inord,aftord;
    cin>>inord;cin>>aftord;//∂¡»Î
    beford(inord,aftord);cout<<endl;
    return 0;
}
