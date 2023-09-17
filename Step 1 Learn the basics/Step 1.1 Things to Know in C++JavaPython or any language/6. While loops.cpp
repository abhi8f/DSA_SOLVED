#include<iostream>
using namespace std;

int main() {
	int os=0, es=0, n, ud;
	cin>>n;
	while(n){
		ud=n%10;
		n/=10;
		if (ud%2) os+=ud;
		else es+=ud;
	}
	cout<<es<<" "<<os<<endl;
	
}
