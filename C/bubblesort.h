void swap(int* a,int* b) // Function to swap using pointers
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubblesort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                swap(&a[i],&a[j]); 
            }
        }
    }
}
