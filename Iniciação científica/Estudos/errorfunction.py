import random 
import numpy as np

features = np.array([1, 2, 3, 5, 6, 7])
labels = np.array([155, 197, 244, 356, 407, 448])

def square_trick(base_price, price_per_room, num_rooms, price, learning_rate):
    predicted_price = base_price + price_per_room*num_rooms
    base_price += learning_rate*(price - predicted_price)
    price_per_room += learning_rate*num_rooms*(price - predicted_price)
    return price_per_room, base_price

#root mean square error function
def rmse(labels, predictions):
    n = len(labels)
    differences = np.subtract(labels, predictions)
    return np.sqrt(1.0/n*(np.dot(differences, differences)))

def linear_regression(features, labels, learning_rate=0.01, epochs=1000):
    price_per_room = random.random()
    base_price = random.random()
    errors = []
    for i in range(epochs):
        predictions = features[0]*price_per_room + base_price
        errors.append(rmse(labels, predictions))
        i = random.randint(0, len(features)-1)
        num_rooms = features[i]
        price = labels[i]
        price_per_room, base_price = square_trick(base_price, price_per_room, num_rooms, price, learning_rate=learning_rate)
    return price_per_room, base_price

price_per_room, base_price = linear_regression(features, labels, learning_rate=0.01, epochs=10000)
print('Preço por quarto: {}\nPreço base: {}'.format(price_per_room, base_price))
