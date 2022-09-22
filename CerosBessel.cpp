#include <iostream>
#include <cmath>

using namespace std;

//Bessel

const double ErrMax =1e-7;

double fun(double x){
    return sin(x);
}

double IntegralSimpson(double a, double b , int n){

    double x, h , suma; int i;
    n*=2; h=(b-a)/n;
    for(suma=0, i=0; i<=n;i++){
        x= a+i*h;
        if (i==0 || i==n){ //si es el primero o el ultimo
            suma+=fun(x);
        }
        else if(i%2==0){ // si es par
            suma+=2*fun(x);
        }
        else
            suma+=4*fun(x); // si es impar a
    
    }
    return suma*h/3;

}
int main(){
    double a=0, b=M_PI/2; int n=50;
    cout<<"la integral calculada pso Simpson es " << IntegralSimpson(a,b,n) <<endl;
    return 0;

}

