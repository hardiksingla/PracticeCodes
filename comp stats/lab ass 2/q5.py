import pandas as pd
import numpy as np

df = pd.DataFrame({'Name': ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'],
                  "marks": np.random.randint(low=40,high=100,size=(1,10))[0],
                  "gender":["male" if i == 1 else "female" for i in np.random.randint(low=0,high=2,size=(1,10))[0]],
                  "age": np.random.randint(low=18,high=25,size=(1,10))[0],
                  "height": np.random.randint(low=150,high=190,size=(1,10))[0],
                  "weight": np.random.randint(low=50,high=100,size=(1,10))[0],
                  "attempts": np.random.randint(low=0,high=2,size=(1,10))[0],
                  "qualify": ["yes" if i == 1 else "no" for i in np.random.randint(low=0,high=2,size=(1,10))[0]]})
print(df)
print(df.iloc[:,[1,2]])
print(df.dtypes)
print(f"max value of marks: {df['marks'].max()} min value of marks: {df['marks'].min()} sum of marks: {df['marks'].sum()} mean of marks: {df['marks'].mean()} ")
df.insert(2,"new_col",np.nan)
print(df)
print("no of nan in 5th col: ",df.isnull().sum(axis=0)[4])