// Square pattern for n
// A B C D
// A B C D
// A B C D
// A B C D

#include<iostream>
using namespace std;

int main() {
    
    int n;
    cout<<"Enter the value of n ";
    cin>>n;

    for(int i=0; i<n; i++) {
        char ch = 'A';
        for(int j=0; j<n; j++, ch++) {
            cout<< ch << " ";
        }
        cout<<endl;
    }

    return 0;
}