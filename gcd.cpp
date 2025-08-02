#include<iostream>
using namespace std;

int gcd(int a, int b){
    while(a>0 && b>0){
        if(a>b){
            a=a%b;
        }else{
            b=b%a;
        }
    }
    if(a==0) return b;
    return a;
}

int lcm(int a, int b){
    int gcd2 = gcd(a, b);
    return (a*b)/gcd2;
}
int main(){
    cout<<gcd(20, 28)<<endl;
    return 0;
}