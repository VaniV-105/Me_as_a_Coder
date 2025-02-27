int binarysearch(int a[],int n,int val)
{
    int start=0,end=n-1,mid;
    while(start<=end){
        mid=(start+end)/2;
        if(a[mid]==val)
            return mid+1;
        else if(a[mid]>val)
            end=mid-1;
        else
            start=mid+1;
    }
    return -1;
}