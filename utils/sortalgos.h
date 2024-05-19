void bubble_sort(int *arr,int n){
    for(int i = n;i>=1;i--){
        for(int j = 1;j<i;j++){
            if(arr[j-1] > arr[j]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }

}

void insertion_sort(int *arr, int n) {
    for(int i = 1;i<n;i++){
        int temp = arr[i];
        int j = i-1;
        while(j >= 0 && temp < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
int arg_min(int *arr, int n, int start) {
    int min = arr[start];
    int idx = start;

    for (int i = start; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            idx = i;
        }
    }
    return idx;
}

void selection_sort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        int min_idx = arg_min(arr, n, i);
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void merge(int *arr, int l, int m, int r) {
    int l_idx, r_idx, arr_idx;
    int l_len = m - l + 1;
    int r_len = r - m;

    int L[l_len], R[r_len];

    for (l_idx = 0; l_idx < l_len; l_idx++) {
        L[l_idx] = arr[l + l_idx];
    }
    for (r_idx = 0; r_idx < r_len; r_idx++) {
        R[r_idx] = arr[m + 1 + r_idx];
    }

    for (l_idx = 0, r_idx = 0, arr_idx = l; arr_idx <= r; arr_idx++) {
        if ((l_idx < l_len) && (r_idx >= r_len || L[l_idx] <= R[r_idx])) {
            arr[arr_idx] = L[l_idx];
            l_idx++;
        } else {
            arr[arr_idx] = R[r_idx];
            r_idx++;
        }
    }
}

void merge_sort(int *arr, int l, int r) {
    if (r - l == 0) {
        return;
    }
    int m = l + (r - l) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);

    merge(arr, l, m, r);
}

int partition(int *arr, int l, int r) {
    int pivot_val = arr[l];
    int i = l, j = r + 1;

    do {
        do {
            i++;
        } while (arr[i] < pivot_val);

        do {
            j--;
        } while (arr[j] > pivot_val);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    } while (i < j);

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;

    return j;
}

void quick_sort(int *arr, int l, int r) {
    if (r - l <= 0) {
        return;
    }
    int pivot = partition(arr, l, r);
    quick_sort(arr, l, pivot - 1);
    quick_sort(arr, pivot + 1, r);
}
