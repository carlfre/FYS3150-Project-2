"""Plots for problem 7.
"""
import os
import numpy as np
import matplotlib.pyplot as plt

def read_3_eigenvalues_and_eigenvectors_from_file(filename):
    """Reads values of 3 eigenvalues and eigenvectors from csv-file and returns them"""
    data = np.loadtxt(filename, dtype="float", delimiter=",")
    eigenvalues = data[0, :]
    v1 = data[1:, 0]
    v2 = data[1:, 1]
    v3 = data[1:, 2]
    return eigenvalues, v1, v2, v3

def plot_buckling_beam_solution(file_name):
    """Plots approximated solution to buckling beam problem for parameter lambda (eigenvalue)."""
    #Retrieve data from "data"-folder
    os.chdir("..")
    os.chdir("data")
    eigenvalues, v1, v2, v3 = read_3_eigenvalues_and_eigenvectors_from_file(file_name)
    N = len(v1)
    n = N + 1
    fig, axs = plt.subplots(3, sharex=True, sharey=True)
    fig.suptitle(f"Approximated solution v(x) for N={N}")
    fig.text(0.5, 0.04, "x", ha="center")
    fig.text(0.04, 0.5, "v(x)", va="center", rotation="vertical")
    for i, v_i in enumerate([v1, v2, v3]):
        #add endpoints (v(0) = 0, v(1) = 0)
        solution = np.zeros(n+1)
        solution[1:-1] = v_i
        x = np.linspace(0, 1, n+1)
        axs[i].plot(x, solution, label = f"$\lambda_{i+1}$={eigenvalues[i]:.2f}")
        axs[i].legend()
    #save plots in "plots"-folder
    os.chdir("..")
    os.chdir("plots")
    plt.savefig(f"solution_for_N_equals{N}.pdf")

if __name__ == "__main__":
    file_names = ["3_eigvecs_n_equals_10.csv", "3_eigvecs_n_equals_100.csv"]
    for file in file_names:
        plot_buckling_beam_solution(file)


