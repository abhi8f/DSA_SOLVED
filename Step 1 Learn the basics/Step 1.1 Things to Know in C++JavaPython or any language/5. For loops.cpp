#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a=1, b=1, n;
	cin>>n;
	if (n<3) {
		cout<<1<<endl;
		return 0;
	}
	n-=2;
	while(n--) b=a+b, a=b-a;
	cout<<b<<endl;
	return 0;
}