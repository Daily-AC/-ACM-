//第一道1300的题，太绝望了，学到很多东西 
/*
题目： 求 1≤a<b≤n 时，F (a,b)=lcm (a,b)/gcd (a,b) 为质数的数对个数。

没错，题目就很难理解了，巨复杂，后面的推导更是堪比爱因斯坦 ，还有欧拉筛这个预处理 

1，	对 F 函数进行推导
	F(a,b) = lcm(a,b) / gcd(a,b) 
	       = (a×b / gcd(a,b)) / gcd(a,b) 
	       = a×b / (gcd(a,b)^2) 
2， // 由于题目要求 F(a,b) 的值为质数，质数只有 1 和它本身两个因数
// 将 F 函数拆分为两个因子的乘积
F(a,b) = (a / gcd(a,b)) × (b / gcd(a,b)) 

// 不妨设 a < b，因为 F(a,b) 为质数，所以它的两个因子中必有一个为 1
// 由此可得 a / gcd(a,b) = 1，b / gcd(a,b) = p（p 为某一个质数）

这里说白了呢，就是搞出个最后的公式， gcd(a,b)*p<=n,化简为：gcd(a,b)<=n/p 
								最后要找的就是满足条件的gcd(a,b)，所以直接找n/p即可
								
注意了，重点来了，这里的p是变量，没错，我刚刚发现的新思想：变量交换

start：原本是找满足条件的a，b，然后因变量是最后那个质数p，正常思想是去 遍历所有a，b组合，找满足条件的p 
也就是自变量是a和b，然后因变量是他们求出来的质数p，必爆 

end：优化后的思想是 ，我先把质数p定死，然后看是否有满足条件的a，b，加到ans里面
换句话说，就是自变量是p，因变量是a和b，数对嘛，ab一起的 

比如说，n为4（最大限制就是4了，不能有比4大的） 
		p为2，说明就是找有无a和b可以组成这个p，
	之前公式的推导给了a和b的形式，a=d,b=d*p
    也就是说，b一定是a的某个倍数，在这里，p=2的情况下，可以是a，b=(1,2)或者(2,4)，大于p也可以 
 	    p为3，就是(1,3)，也可以是2,6，但是大于n了就不行 
		 
		 
反正很复杂，还得多写。 
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
//欧拉筛
vector<bool> isprime(1e7,false);
vector<int> primes;

void eulerSieve(){
	
	
	for(int i=2;i<=1e7;i++){
		if(!isprime[i]){
			primes.push_back(i);
		}
		
		for(int j=0;j<primes.size() && i*primes[j]<=1e7;++j){
			isprime[i*primes[j]]=true;
			if(i%primes[j]==0)
			{
				break;
			}
		}
	}

	
}



int main()
{//妈的，欧拉筛写好结果忘记调用了，真傻比 
	eulerSieve();
    int t;cin >> t;
    while (t--) {
       ll n;
       cin>>n;
       ll ans=0;
       //这里要保证：1，i访问整个质数数组,我真服了，当局者迷，这里你是死活看不明白？自嘲 
	   //			 2，&&后面： 最后那个质数到达n就截止，不能超过n，否则n/p就是0了。 
       for(int i=0;i<primes.size() && primes[i]<=n;i++){
       		ans+=n/primes[i];
	   }
       cout<<ans<<endl;
 		
    }

    return 0;
}
