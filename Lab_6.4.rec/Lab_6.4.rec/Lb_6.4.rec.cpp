#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

void create(double* arr, int SIZE, double MIN, double MAX, int i)
{
    if (i < SIZE)
    {
        arr[i] = MIN + (double)rand() / RAND_MAX * (MAX - MIN);
        create(arr, SIZE, MIN, MAX, i + 1);
    }
}


void Print(double* arr, const int SIZE, int i)
{
    if (i < SIZE)
    {
        cout << setw(15) << arr[i];
        Print(arr, SIZE, i + 1);
    }
    else
        cout << endl;
}


double sumPositivesBeforeMax(double* arr, int SIZE, double maxElement, int i, double sum)
{
    if (i >= SIZE)
        return sum;

    if (arr[i] > maxElement)
        return sumPositivesBeforeMax(arr, SIZE, arr[i], i + 1, sum); 

    if (arr[i] > 0)
        sum += arr[i];

    return sumPositivesBeforeMax(arr, SIZE, maxElement, i + 1, sum);
}


double productNegatives(double* arr, int SIZE, int i, double product)
{
    if (i >= SIZE)
        return product == 1.0 ? 0 : product; 

    if (arr[i] < 0)
        product *= arr[i];

    return productNegatives(arr, SIZE, i + 1, product);
}

void copyArray(double* arr, double* tempArr, int SIZE, int i)
{
    if (i >= SIZE) {
        return;
    }

    arr[i] = tempArr[i];
    copyArray(arr, tempArr, SIZE, i + 1);
}


void rearrangeEvenElements(double* arr, int SIZE, double* tempArr, int left, int right, int i)
{
    if (i >= SIZE)
    {
        copyArray(arr, tempArr, SIZE, 0);
        return;
    }

    if (static_cast<int>(arr[i]) % 2 == 0)
    {
        tempArr[left] = arr[i]; 
        rearrangeEvenElements(arr, SIZE, tempArr, left + 1, right, i + 1);
    }
    else
    {
        tempArr[right] = arr[i]; 
        rearrangeEvenElements(arr, SIZE, tempArr, left, right - 1, i + 1);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int SIZE;
    cout << "Введіть розмір масиву (SIZE): "; cin >> SIZE;

    double MIN = -20.0, MAX = 20.0;

    double* arr = new double[SIZE];
    create(arr, SIZE, MIN, MAX, 0);

    cout << "Початковий масив: " << endl;
    Print(arr, SIZE, 0);

   
    cout << "Добуток від'ємних елементів масиву: " << productNegatives(arr, SIZE, 0, 1.0) << endl;


    cout << "Сума додатних елементів перед максимальним: " << sumPositivesBeforeMax(arr, SIZE, arr[0], 0, 0.0) << endl;

   
    double* tempArr = new double[SIZE];
    rearrangeEvenElements(arr, SIZE, tempArr, 0, SIZE - 1, 0);

    cout << "Масив після зміни порядку парних елементів: " << endl;
    Print(arr, SIZE, 0);

    delete[] arr;
    delete[] tempArr;

    return 0;
}
