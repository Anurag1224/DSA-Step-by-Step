// Triangle Pattern for n

// *
// * *
// * * *

#include<iostream>
using namespace std;

int main (){
    
    int n;
    cout<<"Enter the number n ";
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    
    return 0;
}