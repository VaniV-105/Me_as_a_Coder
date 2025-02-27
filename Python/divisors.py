import math
def print_divisors(num):
    a = int(math.sqrt(num))
    div =[]
    for i in range (1,a+1):
        if(num%i==0):
            div.append(i)
            if(i!=num//i):
                div.append(num//i)
    div.sort()
    for i in div:
        print(i,end=" ")
def main():
    n=int(input("Enter a no:"))
    print_divisors(n)
if __name__ == "__main__":
    main()