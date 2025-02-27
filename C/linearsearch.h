int linearsearch(int a[],int n,int val)
{
    for(int i=0;i<n;i++)
        if (val==a[i])
            return i+1;
    return -1;
}