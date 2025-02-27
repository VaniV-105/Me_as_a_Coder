#include<stdio.h>
#include<math.h>
int main(){
int a, b, c, d, e, f;
double m, n, p, r, s, t, u, v, x;
printf("Enter a and b :");
scanf("%d%d", &a, &b);
printf("Enter c and d :");
scanf("%d%d", &c, &d);
printf("Enter e and f :");
scanf("%d%d", &e, &f);
printf("\n");
printf("The coordinate you entered (%d , %d)", a, b);
printf("\n");
printf("The coordinate you entered (%d , %d)", c, d);
printf("\n");
printf("The coordinate you entered (%d , %d)", e, f);
m = (pow((d - b), 2)) + (pow((c - a), 2));
r = sqrt(m);
n = (pow((f - d), 2)) + (pow((e - c), 2));
s = sqrt(n);
p = (pow((f - b), 2)) + (pow((e - a), 2));
t = sqrt(p);
printf("\n");
printf("\n");
printf("Length of 1st side %f", r);
printf("\n");
printf("Length of 2nd side %f", s);
printf("\n");
printf("Length of 3rd side %f", t);
printf("\n");
printf("\n");
if ((r + s) > t && (s + t) > r && (t + r) > s) {
printf("The above three coordinates can constitute a triangle.");
if (r == s && s == t && t == r) {
printf("\n");
printf("\n");
printf("It is an equilateral triangle.");
} else if (r == s || s == t || t == r) {
printf("\n");
printf("\n");
printf("It is an isosceles triangle.");
} else {
printf("\n");
printf("\n");
printf("It is a scalene triangle.");
}
printf("\n");
u = (r + s + t) / 2;
v = sqrt(u * (u - r) * (u - s) * (u - t));
printf("\n");
printf("Area of triangle %f", v);
printf("\n");
x = (r + s + t);
printf("\n");
printf("Perimeter of triangle %f", x);
} else {
printf("\n");
printf("The above three coordinates cannot constitute a triangle.");
}
return 0;
}