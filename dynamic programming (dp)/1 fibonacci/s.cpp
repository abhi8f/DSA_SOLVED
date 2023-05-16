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
    int previous1=0,previous2=1;
    n--;
    while(n--){
        int temp=previous2;
        previous2=previous1+previous2;
        previous1=temp;
    }
    cout<<previous2<<endl;
}