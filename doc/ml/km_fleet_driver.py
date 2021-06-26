
import numpy as np
import pandas as pd
from sklearn.cluster import KMeans
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt

### For the purposes of this example, we store feature data from our
### dataframe `df`, in the `f1` and `f2` arrays. We combine this into
### a feature matrix `X` before entering it into the algorithm.
'''
https://www.datascience.com/blog/introduction-to-k-means-clustering-algorithm-learn-data-science-tutorials
'''

df = pd.read_csv('data_1024.csv',sep='\t')
f1 = df['Distance_Feature'].values
f2 = df['Speeding_Feature'].values

X=np.matrix(zip(f1,f2))
kmeans = KMeans(n_clusters=2).fit(X)
classified_data = kmeans.labels_
#copy dataframe (may be memory intensive but just for illustration)
df_processed = df.copy()
df_processed['Cluster Class'] = pd.Series(classified_data, index=df_processed.index)
print kmeans.cluster_centers_
#copy dataframe (may be memory intensive but just for illustration)

labels = kmeans.labels_
plt.clf()
fig = plt.figure(1, figsize=(4, 3))
ax = Axes3D(fig, rect=[0, 0, .95, 1], elev=48, azim=134)
ax.scatter(X[:,0],X[:,1],c=labels.astype(np.float))
ax.scatter(X[:,0],X[:,1],c=labels.astype(np.float))
ax.w_xaxis.set_ticklabels([])
ax.w_yaxis.set_ticklabels([])
ax.set_xlabel('Distance_Feature')
ax.set_ylabel('Speeding_Feature')
plt.show()

