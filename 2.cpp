// Example: defining the constructor within the class

#include <iostream>
using namespace std;
int n=1;
class student {

   public:
    int rno=temp();
    int temp(){
        return n++;

    }
};

int main() {
    student s,s2;  // constructor gets called automatically when we create the object of the class
    cout<<s2.rno<<endl;
    return 0;
}
