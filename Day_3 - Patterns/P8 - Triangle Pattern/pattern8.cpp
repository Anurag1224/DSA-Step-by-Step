//Triangle pattern for value n
// A
// B B
// C C C
// D D D D

#include<iostream>
using namespace std;

int main() {
    
    int n;
    char ch = 'A';
    cout<<"Enter the value of n ";
    cin>> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout<<ch<<" ";
        }
        cout<<endl;
        ch++;
    }
    
    return 0;
}