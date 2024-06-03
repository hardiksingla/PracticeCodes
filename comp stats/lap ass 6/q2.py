import numpy as np
import pandas as pd
from scipy.cluster.hierarchy import dendrogram, linkage
import matplotlib.pyplot as plt
data=np.array([[0,2,2,7,6,6,6,6,7,9,9],
               [2,0,1,5,4,6,6,6,7,8,9],
               [2,1,0,6,5,6,5,5,6,8,9],
               [7,5,6,0,5,9,9,9,10,8,9],
               [6,4,5,5,0,7,7,7,8,9,9],
               [6,6,6,9,7,0,2,1,5,10,9],
               [6,6,5,9,7,2,0,1,3,10,9],
               [6,6,5,9,7,1,1,0,4,10,9],
               [7,7,6,10,8,5,3,4,0,10,9],
               [9,8,8,8,9,10,10,10,10,0,9],
               [9,9,9,9,9,9,9,9,9,9,0]])
single_linkage=linkage(data,method='single',metric='euclidean')
dendrogram(single_linkage)
plt.title('Single Linkage Dendrogram')
plt.show()
complete_linkage=linkage(data,method='complete',metric='euclidean')
dendrogram(complete_linkage)
plt.title('Complete Linkage Dendrogram')
plt.show()
average_linkage=linkage(data,method='average',metric='euclidean')
dendrogram(average_linkage)
plt.title('Average Linkage Dendrogram')
plt.show()