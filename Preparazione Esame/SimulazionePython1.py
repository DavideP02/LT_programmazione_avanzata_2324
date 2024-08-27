# 1. Trovare il minimo di 
# x^2 + 10 sin x in [-10,10]

# 2. Calcolare \int_0^{2\pi} \sin t \d t

# 3. Interpolazione cubica usando 10 valori equispaziati in [-1,1] di 
# y(x)= \cos x + 1

import numpy as np 
import scipy as sp

## PUNTO 1

x_min = -10
x_max = 10

def f1(t): 
    return t**2 + 10 * np.sin(t)

x_0 = sp.optimize.fminbound(f1, x_min, x_max)
y_0 = f1(x_0);

print("(%s, %s)" % (x_0,y_0))

## PUNTO 2

# Implementazione del metodo dei trapezi

t_min = 0;
t_max = np.pi * 2;
N = 1000;

def quadratura(f, x_min, x_max, N):
    integrale = 0
    passo = (x_max - x_min)/N
    x = x_min
    while x <= x_max - passo:
        integrale += (passo / 2) * (f(x) + f(x+passo))
        x += passo
    return integrale

def f2(t): 
    return np.sin(t)

integrale = quadratura(f2, t_min, t_max, N)
print("Il risultato dell'integrale con il metodo di quadratura dei trapezi è:\n%s" % integrale)

integrale2 = sp.integrate.quad(f2, t_min, t_max)[0]
print(integrale2)

## PUNTO 3

t_min = -1
t_max = 1
N = 10

x = np.linspace(t_min, t_max, num=N, endpoint=True);
y = np.cos(x) + 1

# for i in range(0,1000,1):
#     print("(%s,%s)" % (x[i], y[i]))

x_new = np.linspace(t_min, t_max, num=100*N, endpoint=True);

y_lin = sp.interpolate.interp1d(x, y, kind='cubic')
y_linv = y_lin(x_new)

y_int = sp.interpolate.interp1d(x, y, kind='cubic')
y_intv = y_int(x_new)

import matplotlib.pyplot as plt

plt.plot(x, y, x_new, y_linv, '-', x_new, y_intv, '--')
plt.show()