import streamlit as st

def Multiplication_Table(num):
    for i in range(1,11):
        st.success(f"{num} * {i} = {num*i}")
def main():
    st.title("Multiplication Table")

    num = st.number_input("Enter the number:", step=1)
  
    if st.button("Print Multiplication Table"):
        Multiplication_Table(num)
        st.success("Multiplication Table Printed Successfully.")

if __name__ == "__main__":
    main()