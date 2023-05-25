// TC: O(n)
// SC: O(1)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    if (n<=1){
        cout<<n<<endl;
        return 0;
    }
    int pre2=0,pre=1;
    n--;
    while(n--){
        int temp=pre;
        pre=pre2+pre;
        pre2=temp;
    }
    cout<<pre<<endl;
}