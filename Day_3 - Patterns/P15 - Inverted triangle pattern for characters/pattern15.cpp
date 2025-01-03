// Inverted triangle pattern for characters

// A A A A
//   B B B
//     c C
//       D 

#include<iostream>
using namespace std;
 int main() {
    
    int n;
    char ch='A';
    cout<<"Enter the value of n ";
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j<i){
                cout<<"  ";
            }else{
                cout<<ch<<" "; 
            }
            
        }
        cout<<endl;
        ch++;
    }

    return 0;

 }