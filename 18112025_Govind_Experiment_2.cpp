
//EXPERIMENT NO 2
//NAME : GOVIND DAS JATAV
//ROLL NO . 18112025
//
#include<iostream>
#include<math.h>
using namespace std;
float f(float v,float a,float b,float r,float t,float p){
return(pow(v,3)-(r*t*pow(v,2))/p-(b*b*v)-(b*r*t*v)/p+(a*v)/(p*pow(t,0.5))-a*b/(p*pow(t,0.5)));
}
float f1(float v,float a,float b,float r,float t,float p){
return(3*v*v-(2*v*r*t)/p-b*b-(b*r*t)/p+a/(p*pow(t,0.5)));
}
            int main(){
            int s;
            float v,v1,T,P,Tc,Pc,R=8.3144598;
            cout<<"Enter Temperature(in K): ,Enter Pressure(in Pa): , Enter Tc(in K):, Enter Pc(in Pa): "<<endl;
            cin>>T>>P>>Tc>>Pc;
            float a = (0.42748*pow(R,2)*pow(Tc,2.5))/(Pc);
            float b = (0.08664*R*Tc)/(Pc);
            v = b;
            while(1){
                v1 = v-f(v,a,b,R,T,P)/f1(v,a,b,R,T,P);
                if(v1-v<pow(10,-6)&&v1-v>-pow(10,-6))
                {
                    break;
                }
                v=v1;
            }
            cout<<"Molar Volume of liquid phase is : "<<v1<<" m3/mol"<<endl;

            v = R*T/P;
            while(1){
                v1 = v-f(v,a,b,R,T,P)/f1(v,a,b,R,T,P);
                if(v1-v<pow(10,-6)&&v1-v>-pow(10,-6))
                {
                    break;
                }
                v=v1;
            }
            cout<<"Molar Volume of vapour phase is : "<<v1<<" m3/mol"<<endl;;
            return 0;
            }
