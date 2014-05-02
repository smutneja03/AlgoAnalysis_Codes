#!/usr/bin/python
#Worst Case Search Time
#Search in an Array, Sorted Array, BST and Balanced BST
#only deals with Ascending order for the 4 data structures
import numpy as np
import matplotlib.pyplot as plt
import math
x = []
y = []
#Initially printing and plotting the results of array in ascending order
file_handle = open("log_count_best.txt", "r");

lines = file_handle.read().split('\n');

for pair in lines:
	x_y = pair.split(' ')
	x.append(x_y[0])
	y.append(math.log(float(x_y[1]) * 1000))

	
plt.plot(x, y, c="red", label="Count Sort")
leg = plt.legend()
###
#Plotting that of BST, input in ascending order

x = []
y = []
#Initially printing and plotting the results of array in ascending order
file_handle = open("log_heap_best.txt", "r");

lines = file_handle.read().split('\n');

for pair in lines:
	x_y = pair.split(' ')
	x.append(x_y[0])
	y.append(math.log(float(x_y[1]) * 1000))
	
plt.plot(x, y, c="orange", label="Heap Sort")
leg = plt.legend()

###
#Plotting that of Balanced BST, input in ascending order

x = []
y = []
#Initially printing and plotting the results of array in ascending order
file_handle = open("log_insertion_best.txt", "r");

lines = file_handle.read().split('\n');

for pair in lines:
	x_y = pair.split(' ')
	x.append(x_y[0])
	y.append(math.log(float(x_y[1]) * 1000))
	
plt.plot(x, y, c="purple", label="Insertion Sort")
leg = plt.legend()

###
#Plotting that of Sorted Array, input in ascending order

x = []
y = []
#Initially printing and plotting the results of array in ascending order
file_handle = open("log_merge_best.txt",  "r");

lines = file_handle.read().split('\n');

for pair in lines:
	x_y = pair.split(' ')
	x.append(x_y[0])
	y.append(math.log(float(x_y[1]) * 1000))
	
plt.plot(x, y, c="green", label="Merge Sort")
leg = plt.legend()

###
#Plotting that of Sorted Array, input in ascending order

x = []
y = []
#Initially printing and plotting the results of array in ascending order
file_handle = open("log_quick_best.txt",  "r");

lines = file_handle.read().split('\n');

for pair in lines:
	x_y = pair.split(' ')
	x.append(x_y[0])
	y.append(math.log(float(x_y[1]) * 1000))
	
plt.plot(x, y, c="blue", label="Quick Sort")
leg = plt.legend()

plt.title('Best Case Analysis')
plt.xlabel('Input')
plt.ylabel('Time')

plt.show()    
