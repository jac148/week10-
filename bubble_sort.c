#include<stdio.h> 

void bubble_sort(int list[], int);

//main function definition 
int main()
{
	int list[15], num, i;
	printf("Enter size of array or list: ");
	scanf("%d", &num);
	printf("Enter values in the array:\n");
	for (i = 0;i < num;i++)
	{
		scanf("%d", &list[i]);
	}
	printf("Array elements before sorting:\n");
	for (i = 0;i < num;i++)
	{
		printf("%d\t", list[i]);
	}
	bubble_sort(list, num);
	getch();
}

void bubble_sort(int list[], int n) //bubble_sort function definition
{
	int i, j, temp;
	for (i = 0;i < n - 1;i++)
	{
		for (j = 0;j < (n - 1 - i);j++)
		{
			if (list[j] > list[j + 1])
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
	printf("\nAfter Bubble sorting array elements are: \n");
	for (i = 0;i < n;i++)
	{
		printf("%d\t", list[i]);
	}
	return 0;
}