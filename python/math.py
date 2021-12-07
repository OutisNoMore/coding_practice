""" Simple math library """


def power_function(function):
    """ returns the integrated form of the power function """
    power = int(function[function.index('^')+1: function.index('^')+2])
    power = power + 1
    return power


def integral(lower, upper, function):
    """ calculates a single integral """
    integrated = power_function(function)
    return (pow(upper, integrated) - pow(lower, integrated)) / integrated


FUNCTION = input("Please enter a function: ")
print("integral " + FUNCTION + " from 0 to 1 is %.2f" % integral(0, 1, FUNCTION))
