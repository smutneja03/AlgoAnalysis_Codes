#!/usr/bin/python
#Worst Case Search Time
#Search in an Array, Sorted Array, BST and Balanced BST
#only deals with Ascending order for the 4 data structures
import numpy as np
import matplotlib.pyplot as plt

###
#Plotting that of BST, input in ascending order

x = []
y = []
#Initially printing and plotting the results of array in ascending order
file_handle = open("log_bst_random.txt", "r");

lines = file_handle.read().split('\n');

for pair in lines:
	x_y = pair.split(' ')
	x.append(x_y[0])
	y.append(x_y[1])
	
plt.plot(x, y, label="BST", c="green")
leg = plt.legend()

###
#Plotting that of Balanced BST, input in ascending order

x = []
y = []
#Initially printing and plotting the results of array in ascending order
file_handle = open("log_balanced_bst_random.txt", "r");

lines = file_handle.read().split('\n');

for pair in lines:
	x_y = pair.split(' ')
	x.append(x_y[0])
	y.append(x_y[1])
	
plt.plot(x, y, c="blue", label="BalancedBST", linewidth=2.0)
leg = plt.legend()

###
#Plotting that of Sorted Array, input in ascending order

x = []
y = []
#Initially printing and plotting the results of array in ascending order
file_handle = open("log_sarray.txt",  "r");

lines = file_handle.read().split('\n');

for pair in lines:
	x_y = pair.split(' ')
	x.append(x_y[0])
	y.append(x_y[1])
	
plt.plot(x, y, c="red", label="SortedArray", linewidth=3.0)
leg = plt.legend()

plt.title('Random order')
plt.xlabel('Input')
plt.ylabel('Time')

plt.show()    
