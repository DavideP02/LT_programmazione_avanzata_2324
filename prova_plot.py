import matplotlib.pyplot as plt # libreria per i grafici, lavora con COPPIE DI PUNTI
import numpy as np

# x = [[1,23], [2, 24], [5, 12]]
# x_convertito = np.zeros(len(x))

# for i in range(len(x)):
#     x_convertito[i] = x[i][0] + x[i][1]/24

# y = [12, 13, 14]

# data = ["giorno 1, 23:00", "giorno 2, 24:00", "giorno 5, 12:00"]

# plt.plot(x_convertito, y, data)
# plt.show()

date = {"giorno 1, 23:00": 1+23/24, "giorno 2, 24:00": 3, "giorno 5, 12:00", 5.5}
plt.plot(date, y)
plt.plot