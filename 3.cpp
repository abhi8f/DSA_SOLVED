// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;



int main(){
    int *p;
    *p=5;
    p=&*p;
    cout<<p<<endl;
    cout<<sizeof(p)<<endl;
    cout<<*p<<endl;
    cout<<sizeof(*p)<<endl;
    return 0;
}