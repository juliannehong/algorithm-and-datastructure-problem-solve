// Cracking Coding interview 6ed. 8.3

int magicIndexWithDup(const vector<int>& arr, int l, int r){
  if (r < l)
    return -1;
  int mid = l + (r - l) / 2;
  if (mid == arr[mid])
    return mid;
  else if (mid > arr[mid]){
    int leftSearch = magicIndexWithDup(arr, l, arr[mid]);
    if (leftSearch > 0)
      return leftSearch;
    else
      return magicIndexWithDup(arr, mid + 1, r);
  } else {
    int rightSearch = magicIndexWithDup(arr, arr[mid], r);
    if (rightSearch > 0)
      return rightSearch;
    else
      return magicIndexWithDup(arr, l, mid - 1);
  }
}

int magicIndexWithDup(const vector<int>& arr){
  return maicIndexWithDup(arr, 0, arr.size() - 1);
}