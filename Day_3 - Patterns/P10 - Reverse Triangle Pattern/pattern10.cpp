// Reverse Triangle pattern for value n

// 1
// 2 1
// 3 2 1
// 4 3 2 1

#include<iostream>
using namespace std;

// int main() {
    
//     int n;
//     cout<<"Enter the value of n ";
//     cin>> n;

//     for(int i=1; i<n+1; i++){
//         for(int j=0; j<i; j++){
//             cout<<i-j<<" ";
//         }
//         cout<<endl;
//     }
    
//     return 0;
// }


// --------------------OR-------------------------

int main() {
    
    int n;
    cout<<"Enter the value of n ";
    cin>> n;

    for(int i=0; i<n; i++){
        for(int j=i+1; j>0; j--){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}