// Simply keep the last one in temp...
// shift all the elemnt by one to left...
// place a[0]=temp

void rotate(int arr[], int n)
{
    n = n - 1;
    int temp = arr[n];
    for (int i = n; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = temp;
}