import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from scipy.stats import multivariate_normal

# Set random seed for reproducibility
np.random.seed(42)

# Task 1: Sample dataset from bivariate normal distribution
mean = np.array([2, 3])
covariance_matrix = np.array([[2, 0.5], [0.5, 1]])
dataset = np.random.multivariate_normal(mean, covariance_matrix, 100)

# Task 2: Compute mean vector and center X
mean_estimate = np.mean(dataset, axis=0)
centered_data = dataset - mean_estimate

# Task 3: Compute empirical covariance matrix
covariance_matrix_estimate = np.cov(centered_data, rowvar=False, bias=True)

# Task 4: Compute the inverse of the covariance matrix
covariance_matrix_inverse = np.linalg.inv(covariance_matrix_estimate)

# Task 5: Mahalanobis distance function
def mahalanobis(x, mean, covariance_inverse):
    diff = x - mean
    return np.sqrt(np.dot(np.dot(diff, covariance_inverse), diff))

# Task 6: Compute Mahalanobis and Euclidean distances
mahalanobis_distances = np.apply_along_axis(lambda x: mahalanobis(x, mean_estimate, covariance_matrix_inverse), axis=1, arr=dataset)
euclidean_distances = np.linalg.norm(centered_data, axis=1)

# Task 7: Surface contour for the bivariate distribution
x, y = np.meshgrid(np.linspace(-2, 6, 100), np.linspace(0, 6, 100))
pos = np.dstack((x, y))
rv = multivariate_normal(mean, covariance_matrix)

# Task 8: Compare with different covariance matrix
covariance_matrix_alternate = np.array([[2, -0.5], [-0.5, 1]])
rv_alternate = multivariate_normal(mean, covariance_matrix_alternate)

# Task 9: Marginal distribution
marginal_x1 = np.random.normal(mean[0], np.sqrt(covariance_matrix[0, 0]), 100)
marginal_x2 = np.random.normal(mean[1], np.sqrt(covariance_matrix[1, 1]), 100)

# Task 10: Conditional distribution
conditional_x1_given_x2_1 = multivariate_normal(mean[0] + covariance_matrix[0, 1]/covariance_matrix[1, 1] * (1 - mean[1]), covariance_matrix[0, 0] - covariance_matrix[0, 1]**2/covariance_matrix[1, 1])
conditional_x2_given_x1_1 = multivariate_normal(mean[1] + covariance_matrix[0, 1]/covariance_matrix[0, 0] * (1 - mean[0]), covariance_matrix[1, 1] - covariance_matrix[0, 1]**2/covariance_matrix[0, 0])

# Print values
print("Task 1: Sampled Dataset\n", dataset)
print("\nTask 2: Mean Estimate\n", mean_estimate)
print("\nTask 3: Covariance Matrix Estimate\n", covariance_matrix_estimate)
print("\nTask 4: Inverse of Covariance Matrix\n", covariance_matrix_inverse)
print("\nTask 6: Mahalanobis Distances\n", mahalanobis_distances)
print("\nTask 7: Bivariate Distribution Contour\n", rv.pdf(pos))  
print("\nTask 8: Bivariate Distribution Contour (Alternate Covariance)\n", rv_alternate.pdf(pos))
print("\nTask 9: Marginal Distributions\nMarginal X1:\n", marginal_x1, "\nMarginal X2:\n", marginal_x2)
print("\nTask 10: Conditional Distributions\nConditional X1 given X2=1:\n", conditional_x1_given_x2_1.rvs(100), "\nConditional X2 given X1=1:\n", conditional_x2_given_x1_1.rvs(100))
