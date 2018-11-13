# ProblemLink: https://www.interviewbit.com/problems/next-permutation/
# @param A : list of integers
# @return the same list of integer after modification
def nextPermutation(self, A):
    length = len(A)
    i = 0
    # find the number where incrementing sequence breaks from right
    for i in xrange(length - 1, 0, -1):
        if A[i] > A[i - 1]:
            break
    # print 'value ', i
    if i == 0:
        return sorted(A)
    numberToBeSwapped = A[i - 1]
    current = i
    # From going to right find the min number which is greater than A[i - 1]
    for k in xrange(i):
        if A[k] < A[current] and A[k] > numberToBeSwapped:
            current = k
    # Swap this min with A[i - 1] and sort the array right to i - 1
    temp = A[current]
    A[current] = A[i - 1]
    A[i - 1] = temp
    return A[0:i] + sorted(A[i:])
