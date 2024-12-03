"""Given a list [(x1, y1), (x2, y2), ..., (xk, yk)] of (x, y) tuples,
   DividedDifference recursively computes f[x1, x2, ..., xk].
"""
def DividedDifference(coordinateList):
    listLen = len(coordinateList)
    # f[x] = f(x) is the y-value corresponding to x.
    if listLen == 1:
        return coordinateList[0][1]
    # f[x1, x2, ..., xk] is recursively defined by dividing the difference f[x2, ..., xk] - f[x1, ..., x(k-1)]
    # by xk - x1. To evaluate the numerator, we call DividedDifference on appropriate subsets of coordinateList.
    else:
        numerator = DividedDifference(coordinateList[1:]) - DividedDifference(coordinateList[:listLen-1])
        denominator = coordinateList[listLen-1][0] - coordinateList[0][0]
        return numerator/denominator

"""Given coordinateList, a list of points we want our polynomial to interpolate,
   LagrangePolynomialCoefficients returns the coefficients a_i of our Lagrange
   polynomial.
"""
def LagrangePolynomialCoefficients(coordinateList):
    # We keep track of the coefficients using the index k and store the values themselves in coefficientList.
    k = 0
    coefficientList = []
    # Our Lagrange polynomial will be of degree len(coordinateList), which means we will need at most
    # len(coordinateList) coefficients.
    while k < len(coordinateList):
        coordinateSubList = coordinateList[: k + 1]
        # The a_k index is obtained by computing the kth divided difference with x-values
        # x1, x2, ..., xk.
        a_k = DividedDifference(coordinateSubList)
        coefficientList.append(a_k)
        print(f"a_{k} = {a_k}")
        k += 1
    # print(coefficientList)
    return coefficientList