#include<stdio.h>
int main(int argc,char* argv[])
{
    int mins = atoi(argv[1]);
    printf("Hrs:%d\n",mins/60);
    printf("Mins:%d\n",mins%60);
    return 0;
}