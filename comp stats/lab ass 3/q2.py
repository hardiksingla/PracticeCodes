import matplotlib.pyplot as plt
import pandas as pd
data = {
  "muscle gained":[3,5,10,11,16,19,20],
  "hours exercised":[1,2,3,4,5,6,7]
}
df = pd.DataFrame(data)
plt.scatter(df["muscle gained"],df["hours exercised"])
plt.xlabel("muscle gained")
plt.ylabel("hours exercised")
plt.show()