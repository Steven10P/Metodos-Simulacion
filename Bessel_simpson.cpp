#include <iostream>
#include <cmath>

using namespace std;

//Bessel

const double ErrMax =1e-7;


double fun(double x, double alpha, double t){
    return cos(alpha*t-x*sin(t));
}

double IntegralSimpson(double a, double b , int n, double x, double alpha){

    double t, h , suma; int i;
    n*=2; h=(b-a)/n;
    for(suma=0, i=0; i<=n;i++){
        t= a+i*h;
        if (i==0 || i==n){ //si es el primero o el ultimo
            suma+=fun(x, alpha,t);
        }
        else if(i%2==0){ // si es par
            suma+=2*fun(x, alpha,t);
        }
        else
        suma+=4*fun(x, alpha,t); // si es impar a

    }
    return suma*h/3;
}

double Bessel(double alpha, double x){
    double a=0, b=M_PI; int n=50;
    return IntegralSimpson(a,b,n,alpha,x)/M_PI;
}

int main(){
    double alpha=0,x;
    for(x=0;x<=10;x+=0.1)   
    cout<<x<<" "<<Bessel(alpha,x)<<endl;
    return 0;
    
}