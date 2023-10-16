import matplotlib.pyplot as plt

num_pages = []
time_values = []

with open('resultados.txt', 'r') as file:
    for line in file:
        parts = line.strip().split(", ")
        # print(parts)
        # a = parts[0].split(": ")
        num_pages.append(int(parts[0].split(": ")[1]))
        time_values.append(float(parts[1].split(" ")[1]))

plt.plot(num_pages, time_values)
plt.xlabel("Número de Páginas")
plt.ylabel("Tempo")
plt.title("Gráfico de Número de Páginas vs. Tempo")
plt.grid(True)
plt.show()
