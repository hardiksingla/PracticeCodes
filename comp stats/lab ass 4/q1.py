import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import statsmodels.api as sm
from statsmodels.formula.api import ols

data = {
    'Product Sales': [360, 720, 1140, 1500, 1800, 2160, 2280, 2580, 2640, 2940, 3000, 3120, 3240, 2460, 2100],
    'Operational Cost': [471.4, 514.3, 612.9, 642.9, 651.4, 694.3, 771.4, 780.0, 771.4, 750.0, 835.7, 540.0, 784.3, 814.3, 642.9],
    'Ad Frequency': [8, 20, 22, 24, 30, 36, 36, 38, 36, 38, 50, 54, 58, 50, 48]
}

df = pd.DataFrame(data)

X = sm.add_constant(df[['Operational Cost', 'Ad Frequency']])
Y = df['Product Sales']

model = sm.OLS(Y, X).fit()

model_summary = model.summary()

print(model_summary)
