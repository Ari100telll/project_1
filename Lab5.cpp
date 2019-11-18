#include <iostream>
#include <stdio.h>
using namespace std;
class ArrayColumn
{
	friend void sortMatrix(ArrayColumn matrix[]);
	friend void inputMatrix(ArrayColumn matrix[]);
	friend void outputMatrix(ArrayColumn matrix[]);
	friend void Dob_raw_average(ArrayColumn matrix[]);

private:
	int column[5];

public:
	void merge(int* A, int left, int middle, int right)
	{
		int i = left, j = middle + 1, k = 0;
		int T[5];
		while (i <= middle && j <= right)
		{
			if (A[i] > A[j])
			{
				T[k] = A[i];
				i++;
			}
			else
			{
				T[k] = A[j];
				j++;
			}
			k++;
		}
		while (i <= middle)
		{
			T[k] = A[i];
			k++;
			i++;
		}
		while (j <= right)
		{
			T[k] = A[j];
			k++;
			j++;
		}
		for (i = left; i <= right; i++)
			A[i] = T[i - left];
	}
	void mergesort(int* A, int left, int right)
	{
		/* for (int i = left; i < right; i++)
		std::cout << A[i] << '\t';
	   std::cout << std::endl;*/
		int middle = (left + right) / 2;
		if ((right - left) > 0)
		{
			mergesort(A, left, middle);
			mergesort(A, middle + 1, right);
		}
		merge(A, left, middle, right);
	}


};
void inputMatrix(ArrayColumn matrix[])
{
	cout << "please enter matrix" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << "Matrix [" << i << "][" << j << "]= ";

			cin >> matrix[j].column[i];

		}
	}
}
void outputMatrix(ArrayColumn matrix[])
{
	cout << "Your matrix is" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << matrix[j].column[i] << '\t';
		}
		cout << endl;
	}
}
void sortMatrix(ArrayColumn matrix[])
{

	for (int i = 0; i < 5; i++)
	{
		matrix[i].mergesort(matrix[i].column, 0, 4);
	}
}


void Dob_raw_average(ArrayColumn matrix[])
{
	double dob_raw, average = 0;
	double k = 0;
	for (int i = 4; i > 0; i--)
	{
		k++;
		dob_raw = 1;
		for (int j = 4; j > 4 - i; j--)
		{
			dob_raw *= matrix[j].column[i];

		}
		cout << "product in raws under auxiliary diagonal " << i << "=" << dob_raw << endl;
		average += dob_raw;
	}
	average = average / k;
	cout << "product of average =" << average << endl;
}
int main()
{
	/*   -1 -5 -47 -8 -1
		 -4 - 98 –90 - 45 - 78
	  - 3 - 2 - 5 - 9 - 4
	  - 8 - 67 –33 - 91 - 40
	  - 2 - 58 –11 - 65 - 77 */
	ArrayColumn matrix[5];
	inputMatrix(matrix);
	outputMatrix(matrix);
	sortMatrix(matrix);
	cout << "Sorting..." << endl;
	outputMatrix(matrix);
	Dob_raw_average(matrix);
	return 0;
}