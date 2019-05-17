template<class T>
//插入排序
void insertion(T a[],int n) {
    int i, j;
    T temp;

    for (int i = 1; i < n; i++) {
        int j = i;
        T temp = a[i];

        while (j > 0 && temp < a[j - 1]) {
            a[j] = a[j - 1];
            j--;

        }//插入位置已经找到；
        a[j] = temp;


    }
}