#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int a[20005]={0},b[20005]={0},c[20005]={0};
    //������루�ͼӷ�һ�� ��������i��1��ʼ�� 
    for(int i=1;i<=s1.size();i++) a[i]=s1[s1.size()-i]-'0';
    for(int i=1;i<=s2.size();i++) b[i]=s2[s2.size()-i]-'0';
    //���� ��λ 
    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++) c[i+j-1]+=a[i]*b[j];
    }
    int len=s1.size()+s2.size();
    for(int i=1;i<len;i++){
        if(c[i]>9){
            c[i+1]+=c[i]/10;
            c[i]=c[i]%10;
        }
    }
    //�ж�λ����λ�����ᳬ����������λ��֮�ͣ� 
    while(c[len]==0&&len>1) len--;
    //������� 
    for(int i=len;i>=1;i--) cout<<c[i];
    
    return 0;
}
