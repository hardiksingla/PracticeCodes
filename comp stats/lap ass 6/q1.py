import pandas as pd
from statsmodels.multivariate.manova import MANOVA
import numpy as np


data ={ 'treatment': ["t1","t1","t1","t1","t1","t2","t2","t2","t3","t3","t3","t3"],
        'x': [6,5,8,4,7,3,1,2,2,5,3,2],
        'x2': [7,9,6,9,9,3,6,3,3,1,1,3]
}
df = pd.DataFrame(data)
print(df)
maov = MANOVA.from_formula('x +x2 ~ treatment', data=df)
print(maov.mv_test())
