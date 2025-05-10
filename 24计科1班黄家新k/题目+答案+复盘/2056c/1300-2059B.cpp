//题目：给个数字串，可以交换相邻两位，但原来靠右的需要 -1，最大化字符串代表的数字。
//比如，19->81，把9-1后跟前一个1交换 

/*
	我的思路：想到了要让后面大的数到前面来，但是具体想不到怎么操作 
	
	 
题解：
	1，对于每一位，只看其后9位数字，因为最多是9-9=0，再多就减不起了
	2，然后就去遍历每一个数，每次都去找其后9位里，哪一个数放到这个位置后最大，如果有相同，取第一次
	3，最后记得依次交换每个数字 
	
关键思路：知道最多找9个，且知道要找交换后最大的，其他都是附加思路，多写就自然而然会了 

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
