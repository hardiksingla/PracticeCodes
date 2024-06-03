import pandas as pd
import matplotlib.pyplot as plt

data = {
  "server":["mumbai","delhi","chennai","kolkata","bangalore"],
  "usage":[70,80,90,60,50]
}
df = pd.DataFrame(data)
plt.bar(df["server"],df["usage"],color=["red","blue","pink","violet","green"])
plt.xlabel("server")
plt.ylabel("usage")
plt.title("server usage")
plt.show()