import numpy as np

# Date senzor (ex: temperatura)
data = np.array([20.1, 20.3, 20.2, 25.0, 20.4, 20.3, 20.2])

# Medie mobila
window = 3
moving_avg = np.convolve(data, np.ones(window)/window, mode='valid')

# Detectie anomalii (Z-score)
mean = np.mean(data)
std = np.std(data)
z_scores = (data - mean) / std

anomalies = data[np.abs(z_scores) > 2]

print("Medie mobila:", np.round(moving_avg, 2))
print("Valori anormale:", anomalies)
