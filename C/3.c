#include <stdio.h>
int global=20;
int inc()
{
    int local=30;
    static int stat = 25;
    stat+=3;
    printf("Static=%d\n",stat);
    printf("Local=%d\n",local);
    printf("Global=%d\n",global);
    return 0;
}
int main()
{
    inc();
    inc();
    return 0;
}