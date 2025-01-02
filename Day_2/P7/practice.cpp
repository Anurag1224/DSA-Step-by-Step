//Print the factorial of a number n

#include<iostream>
using namespace std;

int main(){
    
    int n, fact =1;
    cout<<"Enter the value of n ";
    cin>>n;
    for(int i=n; i>0; i--){
        if(n==0){
            fact = 1;
            break;
        }
        fact*=i;
        
    }
    cout<<"\nFactorial of "<<n<<" is "<< fact;
    return 0;

}