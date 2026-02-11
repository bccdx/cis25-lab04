#include <iostream>
#include <iomanip>
using namespace std;

void getScores(double *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		double score;
		cout << "Enter score " << i + 1 << ": " << endl;
		cin >> score;

		while (score < 0)
		{
			cout << "Invalid score. Score must be a non-negative number. Enter score " << i + 1 << ": " << endl;
			cin >> score;
		}

		*(arr + i) = score;
	}
}

void sortScores(double *arr, int size)
{
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i < size - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				sorted = false;
				double temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
}

double calculateAverage(const double *arr, int size)
{
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum / size;
}

int main()
{
	int size;

	cout << "How many test scores would you like to enter?: " << endl;
	cin >> size;

	while (size <= 0)
	{
		cout << "Invalid number of test scores. Please enter a positive number of test scores: " << endl;
		cin >> size;
	}

	double *scores = new double[size];

	getScores(scores, size);

	sortScores(scores, size);

	double average = calculateAverage(scores, size);

	cout << fixed << setprecision(2);
	cout << "The sorted scores are: ";
	for (int i = 0; i < size; i++)
	{
		cout << scores[i] << " ";
	}
	cout << endl;

	cout << "The average score is: " << average << endl;

	delete[] scores;
	scores = nullptr;

	return 0;
}