# 3. Usare le curve-fit (optimize) per trovare modello lineare, quadratico, cubico per i dati
x = [1,1.5,2.5,3,5,6.5]
y = [0,0.8,0.7,0.9,0.5,0.3]

import numpy as np
import scipy as sp
import matplotlib.pyplot as plt

def linear(x,a,b): 
    return a*x + b 

def quadratic(x,a,b,c): 
    return a * x**2 + b * x + c

def cubic(x,a,b,c,d): 
    return a * x**3 + b * x**2 + c * x + d

linear_curve_fit, error1 = sp.optimize.curve_fit(linear, x, y)

quadratic_curve_fit, error2 = sp.optimize.curve_fit(quadratic, x, y)

cubic_curve_fit, error3 = sp.optimize.curve_fit(cubic, x, y)

poly_coeff = np.polyfit(x,y,5)
def poly_fit(x,a,b,c,d,e,f): 
    return a * x**5 + b * x**4 + c * x**3 + d * x**2 + e * x + f

N = 1000
grid_x = np.linspace(x[0]-1, x[len(x)-1]+1, num=N, endpoint=True)

y_linear = linear(grid_x, linear_curve_fit[0], linear_curve_fit[1])

y_quad = quadratic(grid_x, quadratic_curve_fit[0], quadratic_curve_fit[1], quadratic_curve_fit[2])

y_cubic = cubic(grid_x, cubic_curve_fit[0], cubic_curve_fit[1], cubic_curve_fit[2], cubic_curve_fit[3])

y_inter = poly_fit(grid_x, poly_coeff[0], poly_coeff[1],poly_coeff[2],poly_coeff[3],poly_coeff[4],poly_coeff[5])

plt.plot(x,y,'o', grid_x, y_linear, '-', grid_x, y_quad, '-', grid_x, y_cubic, '-', grid_x, y_inter, '-')
plt.legend(['data', 'lineare', 'quadratica', 'cubica', 'interpolazione'])
plt.show()


# 4. Considerare il dizionario
D = {"aa":0, "ab":1, "ac":2, "ad":3}
## a. Usare i comandi "len", "keys", "values"
## b. Cambiare il valore associato alla chiave "ac" in 5

print("La lunghezza del dizionario D è %d" % len(D))
print("Le chiavi del dizionario sono ", D.keys())
print("I valori del dizionario sono ", D.values())

D["ac"] = 5
print(D)