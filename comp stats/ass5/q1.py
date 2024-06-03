import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
from mpl_toolkits.mplot3d import Axes3D
from scipy.stats import multivariate_normal

np.random.seed(0)

mu = np.array([2, 3])
cov_matrix = np.array([[2, 0.5], [0.5, 1]])

N = 100
data = np.random.multivariate_normal(mu, cov_matrix, N)

mean_vector = np.mean(data, axis=0)
centered_data = data - mean_vector

empirical_covariance_matrix = np.cov(centered_data, rowvar=False)
inverse_covariance_matrix = np.linalg.inv(empirical_covariance_matrix)

def mahalanobis(x, mean_vector, inverse_covariance_matrix):
    x_diff = x - mean_vector
    mahalanobis_distance = np.sqrt(np.dot(np.dot(x_diff, inverse_covariance_matrix), x_diff.T))
    return mahalanobis_distance

x = np.array([3, 4])
mahalanobis_distance = mahalanobis(x, mean_vector, inverse_covariance_matrix)

euclidean_distances = np.linalg.norm(data - mean_vector, axis=1)
mahalanobis_distances = np.apply_along_axis(mahalanobis, 1, data, mean_vector, inverse_covariance_matrix)
distances_df = pd.DataFrame({
    'Euclidean Distance': euclidean_distances,
    'Mahalanobis Distance': mahalanobis_distances
})
print(distances_df)

x_range = np.linspace(min(data[:, 0]), max(data[:, 0]), 100)
y_range = np.linspace(min(data[:, 1]), max(data[:, 1]), 100)
x_grid, y_grid = np.meshgrid(x_range, y_range)

pos = np.empty(x_grid.shape + (2,))
pos[:, :, 0] = x_grid
pos[:, :, 1] = y_grid

pdf_values = multivariate_normal.pdf(pos, mean=mean_vector, cov=empirical_covariance_matrix)

fig = plt.figure(figsize=(12, 6))

ax = fig.add_subplot(121, projection='3d')
ax.plot_surface(x_grid, y_grid, pdf_values, cmap='viridis', edgecolor='k')
ax.set_title('Bivariate Distribution Surface Contour')
ax.set_xlabel('X-axis')
ax.set_ylabel('Y-axis')
ax.set_zlabel('Density')

ax = fig.add_subplot(122)
contour = ax.contour(x_grid, y_grid, pdf_values, levels=10, cmap='viridis')
ax.set_title('Contour Plot for Bivariate Distribution')
ax.set_xlabel('X-axis')
ax.set_ylabel('Y-axis')
plt.colorbar(contour, ax=ax, label='Density')

plt.tight_layout()
plt.show()

pdf_values_elliptical = multivariate_normal.pdf(pos, mean=mean_vector, cov=[[2, -0.5], [-0.5, 1]])

fig = plt.figure(figsize=(12, 6))

ax = fig.add_subplot(121, projection='3d')
ax.plot_surface(x_grid, y_grid, pdf_values_elliptical, cmap='viridis', edgecolor='k')
ax.set_title('Elliptical Surface Contour (covariance matrix = [[2, -0.5], [-0.5, 1]])')
ax.set_xlabel('X-axis')
ax.set_ylabel('Y-axis')
ax.set_zlabel('Density')

ax = fig.add_subplot(122)
contour = ax.contour(x_grid, y_grid, pdf_values_elliptical, levels=10, cmap='viridis')
ax.set_title('Contour Plot for Elliptical Surface')
ax.set_xlabel('X-axis')
ax.set_ylabel('Y-axis')
plt.colorbar(contour, ax=ax, label='Density')

plt.tight_layout()
plt.show()

sns.kdeplot(data[:, 0], label='X-axis')
sns.kdeplot(data[:, 1], label='Y-axis')
plt.title('Marginal Distributions')
plt.xlabel('Value')
plt.ylabel('Density')
plt.legend()
plt.grid(True)
plt.show()

x2_condition = 1

mu_x1_given_x2_1 = mean[0] + cov_matrix[0, 1] / cov_matrix[1, 1] * (x2_condition - mean[1])
variance_x1_given_x2_1 = cov_matrix[0, 0] - cov_matrix[0, 1] ** 2 / cov_matrix[1, 1]

mu_x2_given_x1_1 = mean[1] + cov_matrix[0, 1] / cov_matrix[0, 0] * (1 - mean[0])
variance_x2_given_x1_1 = cov_matrix[1, 1] - cov_matrix[0, 1] ** 2 / cov_matrix[0, 0]

print("Conditional Distribution of x1 given x2=1:")
print(f"Mean (𝜇_x1|x2=1): {mu_x1_given_x2_1}")
print(f"Variance (Var(x1|x2=1)): {variance_x1_given_x2_1}")

print("\nConditional Distribution of x2 given x1=1:")
print(f"Mean (𝜇_x2|x1=1): {mu_x2_given_x1_1}")
print(f"Variance (Var(x2|x1=1)): {variance_x2_given_x1_1}")
