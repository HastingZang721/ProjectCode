#define Header_Bubble.h
template<class T>
void Swap(T &x,T&y){
    T temp;
    temp=x;
    x=y;
    y=temp;

}

template<class T>

void bubble_sort(T arr[], int len) {
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1])
                Swap(arr[j], arr[j + 1]);
}

