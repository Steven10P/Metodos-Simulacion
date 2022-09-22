/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;
//BISECCIÓN

double fun(double x){
    return sin(x)/x;
}
const double ErrMax =1e-7;


int main(){
double x;
double a=2, b=4 ,m, fa , fm;
fa=fun(a);
while(b-a > ErrMax){
    m=(b+a)/2; // punto medio del intervalo
    fm=fun(m);
    if(fa*fm < 0) // si no son del mismo signo
        {a=m; fa=fm;} //correr el intervalo de a a m
    else
        b=m; //si son del mismo signo b=m
    
    }
 
 
    cout<< "El creo es "<< (a+b)/2<<endl;

    return 0;
}
