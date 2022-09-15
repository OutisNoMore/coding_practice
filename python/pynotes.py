# Numpy
## Large, multi-dim arrays, with high level math functions
## faster than lists

# Scipy
## built on numpy, has a lot of methods to process data
## Use for engineering, ...

import pandas
import numpy

# initialize array of 0
numpyZero = numpy.zeros(5)

# initialize array of 1
numpyOne = numpy.ones(5)

# convert list to numpy
listToNumpy = numpy.array([1, 2, 3])

#?z.shape # ? returns help doc for function
print(numpyZero.shape) # returns width, length
print(numpyZero[numpyZero < 3]) # creates list of numbers less than 3
print(numpyZero[numpyZero == 0]) # everything equal to 0

# Pandas
## Data analysis using numpy, more specialized for data science
## Data analytics
## Data frames - 2D, size-mutable, heterogenous data, like an excel file or database
### Axis 0 = rows, Axis 1 = columns
## Series = 1D array/numpy - only Axis 0/ one column

srsA = pandas.Series([1, 2, 3, 4, 5])
srsB = pandas.Series(['A', 'B', 'C', 'D', 'E'])

dataFrame = pandas.DataFrame({'a': srsA, 'b': srsB})
print("---Data----")
print(dataFrame)
print("---Data at 2, b---")
print(dataFrame.loc[2, 'b']) # row 2 column b
print("--First 3 rows---")
print(dataFrame.head(3))
print("---Describe data---")
print(dataFrame.describe())
print("---Missing/null values---")
print(dataFrame.isnull())
print(f"{dataFrame.isnull().sum()} missing")
# dataFrame.drop(['a']) # delete column a
# dataFrame['b'] # get all in column b
print(pandas.value_counts(dataFrame['a'])) # count how many in column a
print(dataFrame.groupby(['a', 'b']).mean()) # get mean of a and b
# can plot directly from array 
dataFrame.groupby('b') # separate into groups for b 

srsA.dropna() # drops all nan values
# srsA.dropna(axis=0) # specify which axis
# axis = 0 # same as axis = 'rows'
# axis = 1 same as axis = 'columns'
