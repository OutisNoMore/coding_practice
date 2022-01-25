import math

def srt(x1, x2):
    return math.sqrt(x1) + math.sqrt(x2)

if srt(1, 2) > srt(1, 3):
    print("1 + 2 is larger")
else:
    print("1 + 3 is larger")
