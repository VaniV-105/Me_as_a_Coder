import math
n=int(input("Enter a number:"))
print("The number of digits in the number:"+str(int(math.log10(n)+1)))
a=str(n)
b=a[::-1]
print(b)
