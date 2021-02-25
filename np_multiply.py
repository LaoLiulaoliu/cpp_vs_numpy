#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Author: Liu Dan 

import numpy as np
import time
import numba
from numba import jit

def process(func):
    t = time.time()
    func()

    print(time.time() - t)

def fill_np():
    vector_size = 100000000
    vector = np.zeros(vector_size)
    for i in range(vector_size):
        vector[i] = 1

def vector_product_np():
    vector_size = 100000000
    vector1 = np.zeros(vector_size)
    vector1.fill(0.01)
    vector2 = np.zeros(vector_size)
    vector2.fill(0.2)
    s = np.inner(vector1, vector2)

def matrix_multiply_py():
	matrix1_rownum = 2000
	matrix1_colnum = 50000
	matrix1_size = matrix1_rownum * matrix1_colnum
	vector1 = np.zeros(matrix1_size)
	vector1.fill(0.01)

	matrix2_rownum = matrix1_colnum
	matrix2_colnum = matrix1_rownum
	matrix2_size = matrix2_rownum * matrix2_colnum
	vector2 = np.zeros(matrix2_size)
	vector2.fill(0.02)

	vector1=vector1.reshape(matrix1_rownum,matrix1_colnum)
	vector2=vector2.reshape(matrix2_rownum,matrix2_colnum)
	vector3=np.dot(vector1,vector2)

@jit(nopython=True)
def matrix_multiply_py():
	matrix1_rownum = 2000
	matrix1_colnum = 50000
	matrix1_size = matrix1_rownum * matrix1_colnum
	vector1 = []
	for i in range(matrix1_size):
		vector1.append(0.1)

	matrix2_rownum = matrix1_colnum
	matrix2_colnum = matrix1_rownum
	matrix2_size = matrix2_rownum * matrix2_colnum
	vector2 = []
	for i in range(matrix2_size):
		vector2.append(0.1)

	matrix3_size = matrix1_rownum * matrix2_colnum
	vector3 = []
	for i in range(matrix3_size):
		vector3.append(0.1)

	for row in range(matrix1_rownum):
		for col in range(matrix2_colnum):
			for i in range(matrix1_colnum):
				vector3[row*matrix2_colnum+col] += vector1[row*matrix1_colnum+i] * vector2[i*matrix2_colnum+col]


process(matrix_multiply_py)
