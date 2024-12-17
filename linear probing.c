#include<stdio.h>
#include<stdbool.h>
void insert(int arr[], int val, int size);
void search(int arr[], int val, int size);
void display(int arr[], int size);

int main()
{
    int pref, val, n;

    printf("Enter the size of the array (hash table):\n");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = -1;

    printf("Select 1 to insert()\n");
    printf("Select 2 to display()\n");
    printf("Select 3 to search()\n");
    printf("Select 4 to exit()\n");

    while (true)
    {
        printf("Enter the preference:\n");
        scanf("%d", &pref);

        if (pref == 1)
        {
            printf("Enter the value to insert:\n");
            scanf("%d", &val);
            insert(arr, val, n);
        }
        else if (pref == 2)
        {
            display(arr, n);
        }
        else if (pref == 3)
        {
            printf("Enter the value to search for:\n");
            scanf("%d", &val);
            search(arr, val, n);
        }
        else if (pref == 4)
        {
            break;
        }
        else
        {
            printf("Invalid preference\n");
        }
    }
}
void insert(int arr[],int val,int n)
{
    int h_key;
    h_key=val%n;
    int i,index;
    for(i=0;i<n;i++)
    {
        index=(h_key+i);
        if(arr[index]==-1)
        {
            arr[index]=val;
            break;
        }
    }
    printf("No of probes of %d is %d\n",val,i+1);
}
void search(int arr[],int val,int n)
{
    int h_key;
    h_key=val%n;
    int i,index;
    for(i=0;i<n;i++)
    {
        index=(h_key+i);
        if(arr[index]==val)
        {
            printf("element is found at index:%d\n",index);
            break;
        }
    }
}
void display(int arr[], int size)
{
    printf("Elements in the hash table are:\n");
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == -1)
            printf("At index %d: Empty slot\n", i);
        else
            printf("At index %d: %d\n", i, arr[i]);
    }
}
