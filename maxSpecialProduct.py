"""Problem Link: https://www.interviewbit.com/problems/maxspprod/

Returns:
	[type] -- [description]
"""

class Stack:
	"""This is the implementation of stack which stores 2 values, number and its index"""
	def __init__(self):
		self.numArray = []
		self.indexArray = []
		self.currentIndex = 0
	
	"""Pushes the given elemnts into stack
	
	Returns:
		None
	"""
	def push(self, num, index):
		self.numArray.append(num)
		self.indexArray.append(index)
		self.currentIndex += 1
	
	"""Pops the top element of array
	
	Returns:
		[tuple] -- [Return tuple with number and index, if stack is not empty, else None]
	"""
	def pop(self):
		if self.currentIndex == 0:
			return None
		self.currentIndex -= 1
		return (self.numArray.pop(), self.indexArray.pop())
	
	"""Return the current top element of stack
	
	Returns:
		[tuple] -- [Return tuple with number and index, if stack is not empty, else None]
	"""
	def getTop(self):
		if self.currentIndex == 0:
			return None
		return (self.numArray[self.currentIndex - 1], self.indexArray[self.currentIndex - 1])

class Solution:
	def getSpecialValuesForEachElement(self, A, traverseRange):
		result = [0] * len(A)
		stack = Stack()
		for i in traverseRange:
			top = stack.getTop()
			# print(i, A[i], top);
			while top and A[i] >= top[0]:
				stack.pop()
				top = stack.getTop()
			if top:
				result[i] = top[1]
			stack.push(A[i], i)
		return result

	# @param A : list of integers
	# @return an integer
	def maxSpecialProduct(self, A):
		length = len(A)
		leftValues = self.getSpecialValuesForEachElement(A, range(length))
		rightValues = self.getSpecialValuesForEachElement(A, range(length-1, -1, -1))
		print('left values', leftValues, rightValues)
		print(max(leftValues[i] * rightValues[i] for i in range(length)))
		return max(leftValues[i] * rightValues[i] for i in range(length))

sol = Solution()
print('Enter the array\n')
arr = [int(x) for x in input().strip().split(', ')]
sol.maxSpecialProduct(arr)