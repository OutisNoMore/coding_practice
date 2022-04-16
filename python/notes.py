# dir() - shows attributes of class

mylist = list()
print(type(mylist))
print(type(None)) # none type/class
# none is singleton - exactly one copy of none
print(type(5))

# MRO - inherit from order of classes listed
# dunder/special/magic methods - override some operator ie __eq__(self, other)

def myfunc():
    # returns None
    pass

def myfunc2():
    # also returns None
    print("help")

print(f"myfunc: {myfunc()}") # myfunc: None

x = [1]
y = [1]
print(f"x = {x}, y = {y}")
print(f"Same memory address: {x is y}")
print(f"Same values: {x == y}")
print(f"Address of x: {id(x)}")

x1 = None
x2 = None
# Singleton - only one copy - not null, but a class
print(f"x = {x}, y = {y}")
print(f"Same memory address: {x1 is x2}")
print(f"Same values: {x1 == x2}")
print(f"Address of x: {id(x2)}")

# *args, **kwargs
# id = *args - positional argument
# name, chicken = **kwargs keyword arguments
# *<var_name> - treat as array of parameter
def func(ID, name=None, chicken=None):
    pass

def func2(*var):
    print("Positional Arguments!")
    for param in var:
        print(param)

def func3(**kwarg):
    print("Key word Arguments!")
    for key, value in kwarg.items():
        print(f"{key}: {value}")

def func4(a = 0, b = 0, c = 0):
    print("PARAM!")
    for key, value in myDict.items():
        print(f"{key}: {value}")

func2("help", 1, [1, 2, 3], 2.714)

func3(first = "1", second = 2, third = "3")
myArgs = {"first": 1, "second": 2, "third": 3}
func3(**myArgs) # almost like de-referencing myArgs

# Functions are objects - more like memory address not an object - bc object is abstract
# can store address/pointer to function
def Hello():
    print("Ello!")

myFunction = Hello
myFunction()

# del = free memory address - garbage collect
del(Hello) # myFunction is a new instance of
myFunction()
# Hello() # deleted

# Nested function
def hello_function():
    print("Parent")
    def say_hi():
        print("Child")
        return "Hi"

    return say_hi

hello_function()
