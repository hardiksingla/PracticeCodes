import pandas as pd
import numpy as np
sample_data = input("enter sample data: ")
sample_data = eval(sample_data)
df = pd.DataFrame(sample_data)
print(df)

# {'name': ['Anu', 'Bima', 'Katherine', 'Joe', 'Abi', 'Michael', 'Vinu', 'Binu', 'Kevin','Jona'],'score': [15.5, 9, 16.5, np.nan, 9, 20, 17.5, np.nan, 8, 19],'attempts': [1, 3, 2, 3, 2, 3, 1, 1, 2, 1],'qualify': ['yes', 'no', 'yes', 'no', 'no', 'yes', 'yes', 'no', 'no', 'yes']}
print(df[(df['score']>=15) & (df['score']<=20)]) 

print(df[(df['score']>=15) & (df['attempts']<=2)])


