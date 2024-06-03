import pandas as pd
import matplotlib.pyplot as plt

data={
  "age":[25,30,22,40,35,28,45,50,28,32],
  "ticketFare":[100,150,100,200,150,100,200,100,150,200],
  "p_class":[1,2,1,3,2,1,3,1,2,3]
}

df = pd.DataFrame(data)

plt.figure(figsize=(10, 6))
plt.scatter(df["age"],df["ticketFare"],c=df["p_class"])
plt.colorbar(label='Passenger Class')
plt.xlabel('Age')
plt.ylabel('Ticket Fare')
plt.title('Relationship between Ticket Fare, Age, and Passenger Class')
plt.grid(True)
plt.show()