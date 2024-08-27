## 1. Data la list [6,4,1,-5,8,7]
#### a. ordinarla
#### b. aggiungere gli elementi 9 e 2
#### c. inserire dopo 4 l'elemento -3
#### d. aggiungere l'elemento -8
#### e. creare una nuova lista con i numeri >= 5

lista = [6, 4, -5, 1, 8, 7]
lista.sort()
print(lista)


lista.append(9)
lista.append(2)
print(lista)

for i in range(0,len(lista)):
    if lista[i] == 4:
        i_di_quattro = i + 1
        break

lista.insert(i_di_quattro, -3)
print(lista)

lista.append(-8)
print(lista)

lista_cinque = []
for i in range(0,len(lista)):
    if lista[i] >= 5:
        lista_cinque.append(lista[i])

print(lista_cinque)

## 2. disegnare la funzione x^2+exp(x) in [-2,2] e trovarne il minimo

import numpy as np
import scipy as sp
import matplotlib.pyplot as plt

def f(t): 
    return t**2 + np.exp(t)

t_min = -2
t_max = 2
N = 1000

x = np.linspace(t_min, t_max, num=N, endpoint=True)
y = f(x)

pt_min = sp.optimize.fminbound(f, t_min, t_max)
print("Il punto di minimo è %s" % pt_min)
minimo = f(pt_min)
print("Il minimo della funzione è %s" % minimo)

plt.plot(x,y,'-', pt_min, minimo, 'o')
plt.show()
