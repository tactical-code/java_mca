#include <stdio.h>
int main()
{
int i, low, high, mid, n, key, array[100], a, j;
printf("Enter array of elementsn");
scanf("%d",&n);
printf("Enter %d integersn", n);
for(i = 0; i < n; i++)
scanf("%d",&array[i]);
//sorting in ascending order
for (i = 0; i < n; ++i) 
        {
 
            for (j = i + 1; j < n; ++j)
            {
 
                if (array[i] > array[j]) 
                {
 
                    a =  array[i];
                    array[i] = array[j];
                    array[j] = a;
 
                }
 
            }
 
        }
 
        printf("The arrays arranged in ascending order are given below \n");
        for (i = 0; i < n; ++i)
            printf(" %d", array[i]);

printf("Enter value to findn");
scanf("%d", &key);
low = 0;
high = n - 1;
mid = (low+high)/2;
while (low <= high) {
if(array[mid] < key)
low = mid + 1;
else if (array[mid] == key) {
printf("%d found at location %d.n", key, mid+1);
break;
}
else
high = mid - 1;
mid = (low + high)/2;
}
if(low > high)
printf("Not found! %d isn't present in the list.n", key);
return 0;
}