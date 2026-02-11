#include <iostream>
using namespace std;

void findMinAndMax(const int arr[], int size, int *min, int *max)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < *min)
		{
			*min = arr[i];
		}
		
		if (arr[i] > *max)
		{
			*max = arr[i];
		}
	}
}

int main()
{
	int numbers[] = {23, 5, 67, -2, 45, 87, 1, 99, 34, -10};
	int min = numbers[0];
	int max = numbers[0];

	findMinAndMax(numbers, 10, &min, &max);

	cout << "The final value of min is: " << min << endl;
	cout << "The final value of max is: " << max << endl;

	return 0;
}