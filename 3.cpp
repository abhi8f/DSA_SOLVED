// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;

int isPalindrome(string A) {
    int i=0, j=A.size()-1;
    while(i<j){
        char a=tolower(A[i]), b=tolower(A[j]);
        if (!(isalpha(a) || isdigit(a))) i++;
        else if (!(isalpha(b) || isdigit(b))) j--;
        else if (a!=b) {
            cout<<i<<" "<<j<<endl;
            cout<<a<<" "<<b<<endl;
            return 0;
        }
        else i++, j--;
    }
    return 1;
}

int main(){
    cout<<isPalindrome("A man, a plan, a canal: Panama")<<endl;
    return 0;
}