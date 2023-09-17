#include<iostream>
using namespace std;

// cout<<(int)'a'<<endl; // 97
// cout<<(int)'z'<<endl; // 122
// cout<<(int)'A'<<endl; // 65
// cout<<(int)'Z'<<endl; // 90

int main() {
	char c;
	cin>>c;
	int ic=(int)c;
	if (ic>=65 && ic<=90) cout<<1<<endl;
	else if (ic>=97 && ic<=122) cout<<0<<endl;
	else cout<<-1<<endl;
	return 0;
}


#include<iostream>
using namespace std;

int main() {
	char ch;
	cin >> ch;

	if(ch >= 'A' && ch <= 'Z') {
		cout << "1";
	}
	else if(ch >= 'a' && ch <= 'z') {
		cout << "0";
	}
	else {
		cout << "-1";
	}
	
}
