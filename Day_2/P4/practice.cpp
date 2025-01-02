// Program to print prime nos. between 1 to n

#include<iostream>
using namespace std;

// int main(){

//     int n;
//     bool isPrime=true;
    
//     cout<<"Enter the number ";
//     cin>> n;
//     for(int i=2; i<=(n-1); i++){

//         if(n%i == 0){
//             isPrime = false;
//             break;
//         }
    
//     }
//     if(isPrime == true){
//         cout<< n <<" is prime number";
//     }else{
//         cout<< n << " is not a prime number";
//     }
    
//     return 0;

// }

//          ------------------------Optimised Solution----------------------------

// replace logic of for loop with for(i=2; i*i<=n; i++)
// instead of this for(int i=2; i<=(n-1); i++)

int main(){

    int n;
    bool isPrime=true;
    
    cout<<"Enter the number ";
    cin>> n;
    for(int i=2; i*i<=n; i++){

        if(n%i == 0){
            isPrime = false;
            break;
        }
    
    }
    if(isPrime == true){
        cout<< n <<" is prime number";
    }else{
        cout<< n << " is not a prime number";
    }
    
    return 0;

}