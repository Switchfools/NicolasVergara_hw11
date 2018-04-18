//
//  NV_gravity.cpp
//  
//
//  Created by Nicolas Felipe Vergara Duran on 18/04/18.
//
#include <iostream>
#include <cstdlib>
using namespace std;
float f(float v,float x, float t){
    return(v);
}
float g(float v,float x, float t){
    double G=10;
    double M=1000;
    return(-(G*M)/(x*x));
}
int main(){
    float k1;
    float k2;
    float k3;
    float k4;
    float p1;
    float p2;
    float p3;
    float p4;
    float h=0.001;
    float min_t = 0;
    float max_t = 1;
    float x_init=100;
    float x_old=x_init;
    float x_new=x_init;
    float t=0;
    float v_old=10;
    float v_new=10;
    int n = (max_t - min_t)/h;
    
    while(x_new>(0.01*x_init)){
        k1=f(v_old,x_old,t);
        k2=f(v_old+((h/2)*k1),x_old+((h/2)*k1),t+h/2);
        k3=f(v_old+((h/2)*k2),x_old+((h/2)*k2),t+h/2);
        k4=f(v_old+((h/2)*k3),x_old+((h/2)*k3),t+h);
        p1=g(v_old,x_old,t);
        p2=g(v_old,x_old+((h/2)*k1),t+h/2);
        p3=g(v_old,x_old+((h/2)*k2),t+h/2);
        p4=g(v_old,x_old+((h/2)*k3),t+h);
        v_new=v_old+((h/6)*(p1+2*p2+2*p3+p4));
        x_new=x_old+((h/6)*(k1+2*k2+2*k3+k4));
        t=t+h;
        cout<<t<<" "<<x_new<<" "<<v_new<<endl;
        v_old=v_new;
        x_old=x_new;
    }
    return 0;
}
