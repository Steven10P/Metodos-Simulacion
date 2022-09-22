#include <iostream>
#include <cmath>
 using namespace std;
//Constantes globales
const double GM=1.0;
//Declaración de clases
class Cuerpo;
//  Interfaz de clase  Cuerpo .h
class Cuerpo{
private :
    double x,y,Vx,Vy,Fx,Fy,m,R;
public:
    void Inicie(double x0,double y0,double Vx0,double Vy0,double m0,double R0); // Declaración de clase
    //Funciones o metodps
    void CalculeFuerza(void);
    void Muevase(double dt);
    double Getx(void){return x;}
    double Gety(void){return y;}
 };
void Cuerpo::Inicie(double x0,double y0,double Vx0,double Vy0,double m0,double R0){ // :: indica q pertenece a la clase cuerpo
    x=x0 ;y=y0; Vx=Vx0; Vy=Vy0; m=m0, R=R0;
}
void Cuerpo::CalculeFuerza(void){ 
    double aux= GM*m*pow(x*x+y*y,-1.5);
    Fx=-aux*x;Fy=-aux*y;
    }
void Cuerpo::Muevase(double dt){ 
    x += Vx*dt;      y+=Vy*dt;
    Vx += Fx/m *dt ; Vy+=Fy/m * dt;   
}
//   Funciones Globales
int main(){
    Cuerpo Balon;//sol, jupiter,  //Instaciar o Ejemplares
    double t , dt=0.01;
    double r=10 , m0=1;
    double omega, V0, T;
    omega = sqrt(GM/(r*r*r)) ; 
    V0= omega*r ;
    T= 2*M_PI/omega;
    //----Inicie(x0,y0,Vx0,Vy0,m0,R0)
    Balon.Inicie(r,0,0,V0,m0,0.5); 
    for (t=0; t<=1.1*T.5;t+=dt){
        cout<<Balon.Getx()<<" "<<Balon.Gety()<<endl;
        Balon.CalculeFuerza();
        Balon.Muevase(dt);
    } 


    return 0;
 }
 