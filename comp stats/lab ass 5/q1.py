import pandas as pd
import matplotlib.pyplot as plt
from statsmodels.formula.api import ols
import statsmodels.api as sm
from statsmodels.multivariate.manova import MANOVA
from statsmodels.stats.multicomp import pairwise_tukeyhsd
import seaborn as sns
import numpy as np

data = {'Board': ["State" if i == 1 else "Matriculation" if i == 2 else "CBSE" for i in np.random.randint(low=0,high=3,size=(1,20))[0]],
  'Maths': np.random.randint(low=40,high=100,size=(1,20))[0],
  'Python': np.random.randint(low=40,high=100,size=(1,20))[0]
  }
df = pd.DataFrame(data)
print(df)
maov = MANOVA.from_formula('Maths +Python  ~ Board', data=df)

print(maov.mv_test())
reg = ols ('Maths~Board', data = df).fit()
aov_kind = sm.stats.anova_lm(reg, type=2)
print(aov_kind)
reg = ols ('Python~Board', data = df).fit()
aov_optim = sm.stats.anova_lm(reg, type=2)
print(aov_optim)

print(df.groupby('Board').agg({'Maths': ['mean', 'std'], 'Python': ['mean', 'std']}))

plt.figure(figsize=(12, 6))

plt.subplot(1, 2, 1)
sns.boxplot(x='Board', y='Maths', data=df)
plt.title('Maths Score by Board of School')

plt.subplot(1, 2, 2)
sns.boxplot(x='Board', y='Python', data=df)
plt.title('Python Score by Board of School')

plt.tight_layout()
plt.show()