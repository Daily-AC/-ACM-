//��Ŀ���������ִ������Խ���������λ����ԭ�����ҵ���Ҫ -1������ַ�����������֡�
//���磬19->81����9-1���ǰһ��1���� 

/*
	�ҵ�˼·���뵽��Ҫ�ú���������ǰ���������Ǿ����벻����ô���� 
	
	 
��⣺
	1������ÿһλ��ֻ�����9λ���֣���Ϊ�����9-9=0���ٶ�ͼ�������
	2��Ȼ���ȥ����ÿһ������ÿ�ζ�ȥ�����9λ���һ�����ŵ����λ�ú�����������ͬ��ȡ��һ��
	3�����ǵ����ν���ÿ������ 
	
�ؼ�˼·��֪�������9������֪��Ҫ�ҽ��������ģ��������Ǹ���˼·����д����Ȼ��Ȼ���� 

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int t;cin >> t;
    while (t--) {
        string s;
        cin>>s;
        s=" "+s;
        for(int i=1;i<=s.size();i++){
        	int nows=s[i]-'0';
        	int index=i;
        	for(int j=1;j<=9 && j+i<=s.size();j++){
        		if(nows<s[i+j]-'0'-j){
        			nows=s[i+j]-'0'-j;
        			index=i+j;
				}
				
			}
			if(index==i){
				continue;
			}
			for(int j=index;j>i;j--){
				swap(s[j],s[j-1]);
			}
			s[i]=nows+'0';

		}
		for(int i=1;i<=s.size();i++){
			cout<<s[i];
		}
		cout<<endl;
		
		
    }

    return 0;
}
