#include<iostream>  
#include<vector>  

using namespace std;

template <typename T>
void Swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}
template <typename T>
void Log(vector<T> arr) {
    cout << "Sorted array:  " << endl;
    for (int i = 0; i < arr.size() - 1; ++i) {
        cout << arr[i] << " ";
    }
    cout << arr[arr.size() - 1] << endl;
}
//冒泡排序  
template <typename T>
void BubbleSort(vector<T>& arr) {
    cout << "Bubble Sort" << endl;
    int Swaps = 0;
    for (int i = 0; i < arr.size() - 1; ++i) {
        cout << "Iteration " << i << endl;
        for (int j = 0; j < arr.size() - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                Swap(arr[j], arr[j + 1]);
                cout << "Swap " << Swaps++ << " : " << arr[j + 1] << " and " << arr[j] << endl;
            }
        }
    }
    cout << "Total swaps: " << Swaps << endl;
    Log(arr);
}
//插入排序  
template <typename T>
void InsertSort(vector<T>& arr) {
    cout << "Insertion Sort" << endl;
    for (int i = 1; i < arr.size(); ++i) {
        int j;
        T tmp = arr[i];
        for (j = i - 1; j > -1 && arr[j] > tmp; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = tmp;
        cout << "Number " << tmp << " inserts at position " << j + 1 << endl;
    }
    Log(arr);
}
//选择排序  
template <typename T>
void SelectionSort(vector<T>& arr) {
    cout << "Selection Sort" << endl;
    for (int i = 0; i < arr.size() - 1; ++i) {
        int min = i;
        for (int j = i; j < arr.size(); ++j) {
            if (arr[j] < arr[min]) min = j;
        }
        swap(arr[min], arr[i]);
        cout << "Iteration " << i << " minIndex is " << min << endl;
    }
    Log(arr);
}
//归并排序  
template <typename T>
void Merge(vector<T>& arr, int start, int mid, int end) {
    vector<T> tmp(arr.size());
    int i = start, j = mid + 1, k = start;
    while (i != mid + 1 && j != end + 1) {
        if (arr[i] > arr[j]) {
            tmp[k++] = arr[j++];
        }
        else tmp[k++] = arr[i++];
    }
    while (i != mid + 1) {
        tmp[k++] = arr[i++];
    }
    while (j != end + 1) {
        tmp[k++] = arr[j++];
    }
    for (int i = start; i <= end; ++i) {
        arr[i] = tmp[i];
    }
}
template <typename T>
void MergeSort(vector<T>& arr, int start, int end) {
    if (start >= end) return;
    int mid = start + (end - start) / 2;
    MergeSort(arr, start, mid);
    cout << "Merge sort elements from index " << start << " to " << mid << endl;
    MergeSort(arr, mid + 1, end);
    cout << "Merge sort elements from index " << mid + 1 << " to " << end << endl;
    Merge(arr, start, mid, end);
}
template <typename T>
void MergeSort(vector<T>& arr) {
    cout << "Merge Sort" << endl;
    MergeSort(arr, 0, arr.size() - 1);
    cout << "Merge sort elements from index " << 0 << " to " << arr.size() - 1 << endl;
    Log(arr);
}
//快速排序  
template <typename T>
int Partition(vector<T>& arr, int low, int high) {
    T pivot = arr[low];
    cout << "Partition " << low << " to " << high;
    while (low < high) {
        while (low < high && arr[high] >= pivot) {
            --high;
        }
        arr[low] = arr[high];
        while (low < high && arr[low] <= pivot) {
            ++low;
        }
        arr[high] = arr[low];
    }
    cout << ": pivot " << pivot << " at index " << low << endl;
    arr[low] = pivot;
    return low;
}
template <typename T>
void QuickSort(vector<T>& arr, int low, int high) {
    if (low < high) {
        int pivot = Partition(arr, low, high);
        QuickSort(arr, low, pivot - 1);
        QuickSort(arr, pivot + 1, high);
    }
}
template <typename T>
void QuickSort(vector<T>& arr) {
    cout << "Quick Sort" << endl;
    QuickSort(arr, 0, arr.size() - 1);
    Log(arr);
}
//堆排序  
template <typename T>
void Heapify(vector<T>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left<n && arr[left]>arr[largest]) largest = left;
    if (right<n && arr[right]>arr[largest]) largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        cout << "Hepify root " << i << " to element " << arr[i] << endl;
        Heapify(arr, n, largest);
    }
}
template <typename T>
void HeapSort(vector<T>& arr) {
    cout << "Heap Sort\nConstruct Max Heap" << endl;
    for (int i = arr.size() / 2 - 1; i >= 0; --i) {
        Heapify(arr, arr.size(), i);
    }
    cout << "Start Sorting" << endl;
    for (int i = arr.size() - 1; i >= 0; --i) {
        cout << "Iteration " << arr.size() - 1 - i << " max number is " << arr[0] << endl;
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
    Log(arr);
}

int main()
{
    int SortType;
    bool NumbleType;
    int num;

    cin >> SortType;
    cin >> num >> NumbleType;
    int x;
    float y;
    if (NumbleType) {
        vector<float> Numbles;
        while (num--) {
            cin >> y;
            Numbles.push_back(y);
        }
        if (SortType == 1) BubbleSort(Numbles);
        if (SortType == 2) InsertSort(Numbles);
        if (SortType == 3) SelectionSort(Numbles);
        if (SortType == 4) MergeSort(Numbles);
        if (SortType == 5) QuickSort(Numbles);
        if (SortType == 6) HeapSort(Numbles);
    }
    else {
        vector<int> numbles;
        while (num--) {
            cin >> x;
            numbles.push_back(x);
        }
        if (SortType == 1) BubbleSort(numbles);
        if (SortType == 2) InsertSort(numbles);
        if (SortType == 3) SelectionSort(numbles);
        if (SortType == 4) MergeSort(numbles);
        if (SortType == 5) QuickSort(numbles);
        if (SortType == 6) HeapSort(numbles);
    }
    return 0;
}
