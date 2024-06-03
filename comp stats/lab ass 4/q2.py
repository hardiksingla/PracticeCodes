import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import statsmodels.api as sm
from statsmodels.formula.api import ols

data = {
    'Age_of_House': [10, 5, 15, 8, 20, 3, 12, 7, 9, 6],
    'Neighborhood_Home_Value': [3000000, 3500000, 2800000, 3200000, 2600000, 3800000, 2950000, 3300000, 3100000, 3400000],
    'Distance_to_School': [1.2, 0.8, 2.5, 1.0, 3.0, 0.5, 1.8, 1.3, 1.1, 0.7],
    'Number_of_Parks': [2, 3, 1, 2, 0, 4, 1, 2, 2, 3],
    'Sales_Price': [3500000, 4200000, 2900000, 3800000, 2700000, 4800000, 3100000, 4000000, 3600000, 4100000]
}

df = pd.DataFrame(data)
print(df)
X = df[['Age_of_House','Neighborhood_Home_Value','Distance_to_School','Number_of_Parks']]
Y = df["Sales_Price"]
X = sm.add_constant(X)
fit = sm.OLS(Y,X).fit()
print(fit.summary())

