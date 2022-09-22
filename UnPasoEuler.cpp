#include <iostream>
#include <cmath>

using namespace std;

double f(double  t, double  x){
  return x;
}

const double ErrMax=1e-7;

double UnpasoEuler(double & t,double & x, double dt){
    double dx;
    dx=dt*f(t,x);
    dt+=dt; dx+=dx;
}

int main(){
  double t,x; double dt=0.1;
  for(t=0,x=0; t<2+dt/2; ){
  cout<<t <<" "<<x<<" "<<endl;
  UnpasoEuler(t,x,dt);
    }
  return 0;
}
