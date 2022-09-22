/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;
//BISECCIÓN

const double ErrMax =1e-7;

double fun(double x){
    return sin(x)/x;
}

double cerosBiseccion(double a,double b){
    double m, fa, fm;
    fa=fun(a); //calculo 1 sola vez f(a)
    while(b-a > ErrMax){
        m=(b+a)/2; // punto medio del intervalo
        fm=fun(m);
        if(fa*fm>0) // si no son del mismo signo
            {a=m; fa=fm;} //correr el intervalo de a a m
        else
            b=m; //si son del mismo signo b=m
    }
    return (a+b)/2;
}


int main(){

double a=2, b=4 ;

cout<< "El cero es "<< cerosBiseccion(a,b)<<endl;

return 0;
}
