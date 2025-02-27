import math
def is_armstrong(num):
    nod = int(math.log10(num)+1)
    n = num
    sum=0
    while(num>0):
        d = num%10
        sum = sum + math.pow(d,nod)
        num = num //10
    return sum == n
def main():
    n = int(input("Enter a no:"))
    if(is_armstrong(n)):
        print("Armstrong No")
    else:
        print("Not Armstrong No")
if __name__ == "__main__":
    main()