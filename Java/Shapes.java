import java.util.*;
public class Circle{
    double radius;
    double pi = 3.14;
    public Circle(double r){
        radius = r;
    }
    double area(){
        return pi*radius*radius;
    }
    double perimeter(){
        return 2*pi*radius;
    }
}
public class Rectangle{
    double length,width;
    public Rectangle(double l,double w){
        length = l;
        width = w;
    }
    double area(){
        return length*width;
    }
    double perimeter(){
        return 2*(length+width);
    }
}
public class Triangle{
    double base,height;
    public Triangle(double b,double h){
        base = b;
        height = h;
    }
    double area(){
        return 0.5*base*height;
    }
    double perimeter(){
        return 3*base;
    }
}
public class Shapes{
    public static void main(String args[]){
        Circle c1 = new Circle(6.4);
        Rectangle r1 = new Rectangle(5,6);
        Triangle t1 = new Triangle(4,6);
        System.out.println("Area of Circle:"+c1.area());
        System.out.println("Perimeter of Circle:"+c1.perimeter());
        System.out.println("Area of Rectangle:"+r1.area());
        System.out.println("Perimeter of Rectangle:"+r1.perimeter());
        System.out.println("Area of Triangle:"+t1.area());
        System.out.println("Perimeter of Triangle:"+t1.perimeter());

    }
}