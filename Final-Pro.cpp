#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;

void insertNode(int value)
{
    Node *curr = new Node();
    curr->data = value;
    curr->next = NULL;

    if (head == NULL)
    {
        head = curr;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = curr;
    }
    cout << "element inserted successfully: " << value << endl;
}

void deleteNode(int value)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node *temp = head;

    // delete head
    if (temp->data == value)
    {
        head = head->next;
        delete temp;
        cout << "Deleted element successfully: " << value << endl;
        return;
    }
    // delete in between or last
    Node *prev = NULL;
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Value not found" << endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
    cout << "Deleted element successfully: " << value << endl;
}

void displayList()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    cout << "Linked List: ";
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int piv = partition(arr, low, high);
        quickSort(arr, low, piv - 1);
        quickSort(arr, piv + 1, high);
    }
}

// ✅ New function
bool isSorted(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

int binarySearch(int arr[], int n, int key)
{
    int left = 0, right = n - 1;
    while (left <= right) // ✅ fixed here
    {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int choice;
    do
    {
        cout << "--- Menu-Driven Program---" << endl;
        cout << "\n1. Insert into Linked List" << endl;
        cout << "\n2. Delete from Linked List" << endl;
        cout << "\n3. Display Linked List" << endl;
        cout << "\n4. Sort Array (Merge Sort)" << endl;
        cout << "\n5. Sort Array (Quick Sort)" << endl;
        cout << "\n6. Binary Search in Array" << endl;
        cout << "\n0. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int value;
            cout << "Enter value to insert: ";
            cin >> value;
            insertNode(value);
            break;
        }
        case 2:
        {
            int value;
            cout << "Enter value to delete: ";
            cin >> value;
            deleteNode(value);
            break;
        }
        case 3:
            displayList();
            break;
        case 4:
        {
            int n;
            cout << "Enter size of array: ";
            cin >> n;
            int arr[n];
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];

            if (isSorted(arr, n))
            {
                cout << "Array is already sorted. No sorting needed." << endl;
            }
            else
            {
                cout << "Array is unsorted! Sorting using Merge Sort..." << endl;
                mergeSort(arr, 0, n - 1);
                cout << "Array after Merge Sort: ";
                for (int i = 0; i < n; i++)
                    cout << arr[i] << " ";
                cout << endl;
            }
            break;
        }
        case 5:
        {
            int n;
            cout << "Enter size of array: ";
            cin >> n;
            int arr[n];
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];

            if (isSorted(arr, n))
            {
                cout << "Array is already sorted. No sorting needed." << endl;
            }
            else
            {
                cout << "Array is unsorted! Sorting using Quick Sort..." << endl;
                quickSort(arr, 0, n - 1);
                cout << "Array after Quick Sort: ";
                for (int i = 0; i < n; i++)
                    cout << arr[i] << " ";
                cout << endl;
            }
            break;
        }
        case 6:
        {
            int n, key;
            cout << "Enter size of array: ";
            cin >> n;
            int arr[n];
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];

            if (!isSorted(arr, n))
            {
                cout << "Array is unsorted! Automatically sorting using Merge Sort..." << endl;
                mergeSort(arr, 0, n - 1);
                cout << "Array after sorting: ";
                for (int i = 0; i < n; i++)
                    cout << arr[i] << " ";
                cout << endl;
            }

            cout << "Enter value to search: ";
            cin >> key;
            int result = binarySearch(arr, n, key);
            if (result != -1)
                cout << "Element found at index " << result << endl;
            else
                cout << "Element not found!" << endl;
            break;
        }
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
// output :-

/*
  --- Menu-Driven Program---

1. Insert into Linked List

2. Delete from Linked List

3. Display Linked List

4. Sort Array (Merge Sort)

5. Sort Array (Quick Sort)

6. Binary Search in Array

0. Exit

Enter your choice: 1

Enter value to insert: 10

element inserted successfully: 10

--- Menu-Driven Program---

1. Insert into Linked List

2. Delete from Linked List

3. Display Linked List

4. Sort Array (Merge Sort)

5. Sort Array (Quick Sort)

6. Binary Search in Array

0. Exit

Enter your choice: 1

Enter value to insert: 20

element inserted successfully: 20

--- Menu-Driven Program---

1. Insert into Linked List

2. Delete from Linked List

3. Display Linked List

4. Sort Array (Merge Sort)

5. Sort Array (Quick Sort)

6. Binary Search in Array

0. Exit

Enter your choice: 1

Enter value to insert: 30

element inserted successfully: 30

--- Menu-Driven Program---

1. Insert into Linked List

2. Delete from Linked List

3. Display Linked List

4. Sort Array (Merge Sort)

5. Sort Array (Quick Sort)

6. Binary Search in Array

0. Exit

Enter your choice: 1

Enter value to insert: 40

element inserted successfully: 40

--- Menu-Driven Program---

1. Insert into Linked List

2. Delete from Linked List

3. Display Linked List

4. Sort Array (Merge Sort)

5. Sort Array (Quick Sort)

6. Binary Search in Array

0. Exit

Enter your choice: 1

Enter value to insert: 50

element inserted successfully: 50

--- Menu-Driven Program---

1. Insert into Linked List

2. Delete from Linked List

3. Display Linked List

4. Sort Array (Merge Sort)

5. Sort Array (Quick Sort)

6. Binary Search in Array

0. Exit

Enter your choice: 3

Linked List: 10 -> 20 -> 30 -> 40 -> 50 -> NULL

--- Menu-Driven Program---

1. Insert into Linked List

2. Delete from Linked List

3. Display Linked List

4. Sort Array (Merge Sort)

5. Sort Array (Quick Sort)

6. Binary Search in Array

0. Exit

Enter your choice: 2

Enter value to delete: 40

Deleted element successfully: 40
--- Menu-Driven Program---

1. Insert into Linked List

2. Delete from Linked List

3. Display Linked List

4. Sort Array (Merge Sort)

5. Sort Array (Quick Sort)

6. Binary Search in Array

0. Exit

Enter your choice: 2

Enter value to delete: 44

Value not found
--- Menu-Driven Program---

1. Insert into Linked List

2. Delete from Linked List

3. Display Linked List

4. Sort Array (Merge Sort)

5. Sort Array (Quick Sort)

6. Binary Search in Array

0. Exit

Enter your choice: 4

Enter size of array: 5

Enter elements: 10
20
30
40
50
Array is already sorted. No sorting needed.

--- Menu-Driven Program---

1. Insert into Linked List

2. Delete from Linked List

3. Display Linked List

4. Sort Array (Merge Sort)

5. Sort Array (Quick Sort)

6. Binary Search in Array

0. Exit

Enter your choice: 4
Enter size of array: 5
Enter elements: 55
4
74
0
22
Array is unsorted! Sorting using Merge Sort...

Array after Merge Sort: 0 4 22 55 74

--- Menu-Driven Program---

1. Insert into Linked List

2. Delete from Linked List

3. Display Linked List

4. Sort Array (Merge Sort)

5. Sort Array (Quick Sort)

6. Binary Search in Array

0. Exit

Enter your choice: 5

Enter size of array: 5

Enter elements: 22
33
44
55
66
Array is already sorted. No sorting needed.

--- Menu-Driven Program---

1. Insert into Linked List

2. Delete from Linked List

3. Display Linked List

4. Sort Array (Merge Sort)

5. Sort Array (Quick Sort)

6. Binary Search in Array

0. Exit

Enter your choice: 5

Enter size of array: 5

Enter elements: 22
0
90
44
287
Array is unsorted! Sorting using Quick Sort...

Array after Quick Sort: 0 22 44 90 287

--- Menu-Driven Program---

1. Insert into Linked List

2. Delete from Linked List

3. Display Linked List

4. Sort Array (Merge Sort)

5. Sort Array (Quick Sort)

6. Binary Search in Array

0. Exit

Enter your choice: 6

Enter size of array: 5

Enter elements: 12
13
14
15
16
Enter value to search: 15

Element found at index 3

--- Menu-Driven Program---

1. Insert into Linked List

2. Delete from Linked List

3. Display Linked List

4. Sort Array (Merge Sort)

5. Sort Array (Quick Sort)

6. Binary Search in Array

0. Exit

Enter your choice: 6

Enter size of array: 5

Enter elements: 33
5
77
6
43
Array is unsorted! Automatically sorting using Merge Sort...

Array after sorting: 5 6 33 43 77

Enter value to search: 6

Element found at index 1

--- Menu-Driven Program---

1. Insert into Linked List

2. Delete from Linked List

3. Display Linked List

4. Sort Array (Merge Sort)

5. Sort Array (Quick Sort)

6. Binary Search in Array

0. Exit

Enter your choice: 7

Invalid choice Try again.

--- Menu-Driven Program---

1. Insert into Linked List

2. Delete from Linked List

3. Display Linked List

4. Sort Array (Merge Sort)

5. Sort Array (Quick Sort)

6. Binary Search in Array

0. Exit

Enter your choice: 0

Exiting program...

*/
