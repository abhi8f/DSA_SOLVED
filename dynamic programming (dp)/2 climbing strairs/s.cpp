// TC: O(n)
// SC: O(1)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    if (n<=2){
        cout<<n<<endl;
        return 0;
    }
    int previous1=1,previous2=2;
    n-=2;
    while(n--){
        int temp=previous2;
        previous2=previous1+previous2;
        previous1=temp;
    }
    cout<<previous2<<endl;
}