int *scanArray(int len) {
  int *arr = (int *)malloc(sizeof(int) * len);
  int i;
  for(i = 0;i < len;i++) {
    scanf("%d", &arr[i]);
  }
  return arr;
}