import java.util.*;
public class BankAccount{
    private int acc_no;
    private double balance;
    String acc_type;
    BankAccount(int a,double b,String c){
        acc_no = a;
        balance = b;
        acc_type = c;
    }
    void check_balance(){
        System.out.println("Acc Balance:"+balance);
    }
    void deposit(double amt){
        balance+=amt;
        System.out.println(amt+" Deposited");
        System.out.println("Acc Balance:"+balance);
    }
    void withdraw(double amt){
        if (amt>balance){
            System.out.println("Amount unavailable");
            System.out.println("Acc Balance:"+balance);
        }
        else{
            System.out.println(amt+ " Withdrawn.");
            balance-=amt;
            System.out.println("Acc Balance:"+balance);
        }
    }
    public static void main(String[] args){
        BankAccount b1 = new BankAccount(6072,1000,"Savings");
        b1.deposit(1000);
        b1.withdraw(3000);
        b1.check_balance();
        b1.withdraw(2000);
    }
}