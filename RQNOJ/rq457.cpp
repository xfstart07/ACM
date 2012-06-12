#include<iostream>
using namespace std;

int n,s;
int d,S;
int c[10001];
int main()
{
	scanf("%d%d",&n,&s);
	S=(n-1)*n/2;
	d=S-s;
	if(s>S||s<-S||d%2==1){
		printf("NIE");
		return 0;
	}
	for(int i=2;i<=n;++i)
		c[i]=1;
	int k;
	for(int i=2;i<=n&&d;++i){
		k=(n-i+1)*2;
		if(d>=k){
			c[i]=-1;
			d-=k;
		}
	}
	k=0;
	printf("%d\n",k);
	for(int i=2;i<=n;++i){
		k+=c[i];
		printf("%d\n",k);
	}
	return 0;
}

/*
相邻元素绝对值之差必须为1，所以显然构造出的和最大的序列一定为0,1,2,3,…,N-1，和为(N-1)*N/2，最小和同理为-(N-1)*N/2。于是如果给定的S不在最大值与最小值的区间内，一定无解。

我们先生成一个和最大的序列，0,1,2,3,…,N-1，然后再考虑调整使得满足条件。假设当前的和与S的差为D，可以发现，无论怎样变换序列，D的奇偶性的不改变的。因为无论改变那个元素，都只能从比前一个元素多1变成少1，或者从比前一个元素少1变成多1，调整多个也是一样的，变化量为偶数。所以说，如果初始的D为奇数，则一定不可能有解。

余下来的情况一定为有解的情况了。把序列顺序做差，初始化每项差值都为1，则对应了0,1,2,3,…,N-1。可以发现，修改一个差值从1到-1 会引起后面所有项的值减少2，总的减少量就是后面项的个数*2。这时就可以设计出算法了，从第一个差值开始尝试从1变成-1，更新当前和，直到等于S为止。最后再根据差值序列还原出原序列。时间复杂度为O(N)。
*/