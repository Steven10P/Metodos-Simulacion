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
    return IntegralSimpson(a,b,n,x,alpha)/M_PI;
}

double cerosBiseccion(double a,double b, double alpha){
    double m, fa, fm;
    fa=Bessel(alpha,a); //calculo 1 sola vez f(a)
    while(b-a > ErrMax){
        m=(b+a)/2; // punto medio del intervalo
        fm=Bessel(alpha,m);
        if(fa*fm>0) // si no son del mismo signo
            {a=m; fa=fm;} //correr el intervalo de a a m
        else
            b=m; //si son del mismo signo b=m
    }
    return (a+b)/2;
}
int main(){
    double alpha=0, a=2, b=4;

    cout<<"La función de Bessel tiene un cero en x="<<cerosBiseccion(a,b,alpha)<<endl;
    return 0;
    
}