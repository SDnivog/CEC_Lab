phase = float(input('If the volume to be fount out for liquid phase enter one : '))
Tc = float(input('Enter the critical temp. in Kelvin : '))
Pc = float(input('Enter the critical pressure in Pa :'))
P = float(input('Enter the Volume of pressure in Pa :'))
T = float(input('Enter the value of temp. in Kelvin : '))
R = 8.31446261815324
a = (27*(Tc**2)*(R**2))/(64*(Pc**2))
b = (R*Tc)/(8*Pc)
def MyFunction(f,Df,e,max_iter):
    if phase == 1:
        X0 = b
    else:
            X0 = ((R*T)/P)
            xn = X0
            for n in range(0,max_iter):
                fxn = f(xn)
                if abs(fxn)<e:
                    print('No solution found after',n,'Titrations. ')
                Dfxn = Df(xn)
                if Dfxn == 0:
                     print('No solution found, zero derivative .')
                     return None 
            xn = xn - fxn/Dfxn
    print('No solution found , Exceeded maximum titrations .')
    print('Molar Volume = ' , xn)
    print('Compressibility factor z = ', (P*xn)/(R*T))
    return None

p = (b+((R*T)/P))
q = a/P
r = (a*b)/P
f = lambda x: x**3 - (p*(x**2)) + q*x - r  # Cubic form of van der waal equation
Df = lambda x: 3*(x**2) - (2*p*x) + q 

Value = MyFunction(f,Df,1e-6,10)
print(Value)

            
    