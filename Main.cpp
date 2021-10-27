int mergeSort(std::vector<int> &arr, int l, int r) {
    int res = 0;
    if (l < r - 1) {
        int mid = (l + r) / 2, l1 = 0, r1 = 0, idx = l;
        res += mergeSort(arr, l, mid);
        res += mergeSort(arr, mid, r);
        std::vector<int> arr1(arr.begin() + l, arr.begin() + mid),arr2(arr.begin() + mid, arr.begin() + r);
        while (l1 != arr1.size() && r1 != arr2.size()) {
            if (arr1[l1] <= arr2[r1]) {
                arr[idx] = arr1[l1];
                l1++;
            } else {
                res += arr1.size() - l1;
                arr[idx] = arr2[r1];
                r1++;
            }
            idx++;
        }
        while (l1 != arr1.size()) {
            arr[idx] = arr1[l1];
            l1++;
            idx++;
        }
        while (r1 != arr2.size()) {
            arr[idx] = arr2[r1];
            r1++;
            idx++;
        }
    }
    return res;
}

int solve(std::vector<int> arr)
{
    return mergeSort(arr,0,arr.size());
}
