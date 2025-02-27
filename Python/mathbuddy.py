import streamlit as st
import math

def GCD(a,b):
    while a>0 and b>0:
        if(a>b):
            a=a%b
        else:
            b=b%a
    if(a==0):
        return b
    return 

def LCM(a,b,c):
    return int((a*b)/c)

def main():
    st.title("Math Buddy: Your Companion to Key Mathematical Operations")
  
    st.subheader("GCD and LCM Calculator")

    a = st.number_input("Enter the first number:", step=1)
    b = st.number_input("Enter the second number:", step=1)

    if st.button("Find GCD"):
        st.success(f"GCD of {a} and {b} = {GCD(a,b)}")
        
    if st.button("Find LCM"):
        st.success(f"LCM of {a} and {b} = {LCM(a,b,GCD(a,b))}")
        
    if st.button("Find GCD and LCM"):
        st.success(f"GCD of {a} and {b} = {GCD(a,b)}")
        st.success(f"LCM of {a} and {b} = {LCM(a,b,GCD(a,b))}")
    
    st.subheader("Power Calculator")
    abc = st.number_input("Enter base:", step = 1.0)
    cba = st.number_input("Enter exponent:",step=1.0)
    
    if st.button("Calculate Power"):
        st.success(f"{abc} raised to the power {cba} is {abc**cba}")

    st.subheader("Square root and Cube root Calculator")
    number = st.number_input("Enter a number:", step=1.0)
    decimal_places = st.number_input("Enter the number of decimal places to round off to:", min_value=0, step=1)

    if st.button("Calculate Square Root"):
        sqrt_value = round(math.sqrt(number), decimal_places)
        st.success(f"Square Root of {number} = {sqrt_value}")

    if st.button("Calculate Cube Root"):
        cbrt_value = round(number ** (1/3), decimal_places)
        st.success(f"Cube Root of {number} = {cbrt_value}")

    if st.button("Calculate Both Square Root and Cube Root"):
        sqrt_value = round(math.sqrt(number), decimal_places)
        cbrt_value = round(number ** (1/3), decimal_places)
        st.success(f"Square Root of {number} = {sqrt_value}")
        st.success(f"Cube Root of {number} = {cbrt_value}")

if __name__ == "__main__":
    main()
