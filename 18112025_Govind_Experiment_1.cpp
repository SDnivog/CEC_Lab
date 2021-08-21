
//EXPERIMENT NO 1
//NAME : GOVIND DAS JATAV
//ROLL NO . 18112025
//
#include<iostream>
#include<cmath>
    using namespace std;
float firstFxn(float x,float y, float z, float r,float t,float p){
  return (pow(x,3)-z*pow(x,2)-(r*t*pow(x,2)/p)+(y*x)/p-(y*z)/p);
}

float SecounFxn(float x,float y, float z, float r,float t,float p){
  return (3*pow(x,2)-2*z*pow(x,1)-(2*r*t*pow(x,1)/p)+y/p);
}
 int main()
{
  int phase;
  float Tc,Pc,P,T;
  float R=8.31446261815324;
  float a=(27*(Tc*2)*(R*2))/(64*(Pc*2));
  float b=(R*Tc)/(8*Pc);
  float V,V1;
    cout<<"Enter 1 for finding volume of Liquid and 0 for vapor: ,Critical Temp(in K):, Critical Pressure(in Pa):,Pressure(in Pa): ,Temp.(in K):, "<<endl;
   cin>>phase>>Tc>>Pc>>P>>T;

  if(phase==1){
    V=b;
  }else{
    V=(R*T)/P;
  }

while(true){
  V1=V-firstFxn(V,a,b,R,T,P)/SecounFxn(V,a,b,R,T,P);
  if(V==V1){
    break;
  }
  V=V1;
}
cout<<"Molar Volume is : "<<V1;
    return 0;
}
