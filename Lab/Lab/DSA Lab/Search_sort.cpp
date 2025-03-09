#include <iostream>
using namespace std;

/*
1. StoreList(int list[], int size)
    initialize list from user
2. LinearSearch()
    take the array storeList returns
    implement the linearsearch algo
3. MultiplesOf(int list[],int size, int multiple)
    Returns multiples of a given number
4. InsertionSort()
    take the list from storeList
    sorts using insertion sort algorithm
5. BinarySearch()
    take sorted list from insertionsort and perform binary search.
*/
const int SIZE = 4;
void DisplayList(int list[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}
void StoreList(int list[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter element " << i << ":";
        cin >> list[i];
    }
}
void LinearSearch(int list[], int SIZE, int value)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (list[i] == value)
        {
            cout << value << " is found at index position: " << i << endl;
            return;
        }
    }
    cout << "The number " << value << " doesn't exist in the list" << endl;
}
void MultiplesOf(int list[], int SIZE, int multiple)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (list[i] % multiple == 0)
        {
            cout << list[i] << " ";
        }
    }
    cout << endl;
}
void InsertionSort(int list[], int SIZE)
{
    int temp;
    for (int i = 1; i < SIZE; i++)
    {
        temp = list[i];
        for (int j = i; j > 0 && temp < list[j - 1]; j--)
        {
            list[j] = list[j - 1];
            list[j - 1] = temp;
        }

    }
}
bool BinarySearch(int list[], int SIZE, int val){
    int left=0;
    int right = SIZE - 1;
    while(left<=right){
        int mid = left + ((right-left)/2);
        if(list[mid]==val){
            
            return true;
        }
        else if (list[mid]<val){
            left = mid +1;
        }
        else {
            right = mid-1;
        }
    }
    
    return false;

}

int main()
{
    int arr[SIZE];
    int val = 2;
    StoreList(arr, SIZE);
    DisplayList(arr, SIZE);
    LinearSearch(arr, SIZE, 2);
    MultiplesOf(arr, SIZE, 2);
    InsertionSort(arr, SIZE);
    DisplayList(arr, SIZE);
    BinarySearch(arr, SIZE, 2);
    if (BinarySearch(arr, SIZE, val)){
        cout << "Number: " << val << " is in the list";
    }
    else{
        cout << "Number: " << val << "isn't in the list";
    }

        return 0;
}