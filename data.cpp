#include <iostream>
#include <numeric>
#include <cmath>
using namespace std;

double correlationCoefficient(double X[], double Y[], int n)
{

    double sum_X = 0, sum_Y = 0, sum_XY = 0;
    double squareSum_X = 0, squareSum_Y = 0;

    for (int i = 0; i < n; i++)
    {
        // sum of elements of array X.
        sum_X = sum_X + X[i];

        // sum of elements of array Y.
        sum_Y = sum_Y + Y[i];

        // sum of X[i] * Y[i].
        sum_XY = sum_XY + X[i] * Y[i];

        // sum of square of array elements.
        squareSum_X = squareSum_X + X[i] * X[i];
        squareSum_Y = squareSum_Y + Y[i] * Y[i];
    }

    // use formula for calculating correlation coefficient.
    double corr = (double)(n * sum_XY - sum_X * sum_Y) / sqrt((n * squareSum_X - sum_X * sum_X) * (n * squareSum_Y - sum_Y * sum_Y));

    return corr;
}

double arrSum(double arr[], int n)
{
    double init_sum = 0;
    return accumulate(arr, arr + n, init_sum);
}

double mean(double arr[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + arr[i];
    return sum / n;
}

// Function to find covariance.
double covariance(double arr1[], double arr2[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + (arr1[i] - mean(arr1, n)) *
                        (arr2[i] - mean(arr2, n));
    return sum / (n);
}

int main()
{
    int nov = 0, i, j;
    cout << "Enter number of variables: ";
    cin >> nov;
    int *colSizes = new int[nov];
    for (i = 0; i < nov; i++)
    {
        cout << "enter no of items in var " << i + 1 << ": ";
        cin >> colSizes[i];
    }
    double **data = new double *[nov];
    for (i = 0; i < nov; i++)
    {
        cout << "Enter data set for var" << i + 1 << ": ";
        double *temp = new double[colSizes[i]];
        for (j = 0; j < colSizes[i]; j++)
            cin >> temp[j];
        data[i] = temp;
    }

    for (i = 0; i < nov; i++)
    {
        for (j = 0; j < colSizes[i]; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    cout << "The mean vector is :" << endl;
    for (i = 0; i < nov; i++)
        cout << arrSum(data[i], colSizes[i]) << endl;

    cout << "The covariance matrix is : " << endl;
    for (i = 0; i < nov; i++)
    {
        for (j = 0; j < nov; j++)
        {
            cout << covariance(data[i], data[j], colSizes[i]) << " ";
        }
        cout << endl;
    }
    cout << "The correlation matrix is : " << endl;
    for (i = 0; i < nov; i++)
    {
        for (j = 0; j < nov; j++)
        {
            cout << correlationCoefficient(data[i], data[j], colSizes[i]) << " ";
        }
        cout << endl;
    }

    for (i = 0; i < nov; i++)
        delete[] data[i];
    delete[] colSizes;
    return 0;
}