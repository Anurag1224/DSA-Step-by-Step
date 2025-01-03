// Reverse Triangle for Characters

// A
// B A
// C B A
// D C B A

#include <iostream>
using namespace std;

int main() {
    
    int n;
    char ch ='A';
    cout<<"Enter the value of n ";
    cin>>n;

    for(int i=0; i<n; i++){
        
        for(int j=0; j<=i; j++){
            cout<<char(ch-j)<<" ";
            
        }
        cout<<endl;
        ch++;
    }
    return 0;
}