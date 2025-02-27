#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sortColors(int *nums, int numsSize) {
  int left = 0;
  int right = numsSize - 1;
  int cnt = 0;

  while (cnt <= right) {
    if (nums[cnt] == 0)
      swap(&nums[cnt++], &nums[left++]);
    else if (nums[cnt] == 2)
      swap(&nums[cnt], &nums[right--]);
    else
      cnt++;
  }
}

/** another solution (faster)
 int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
void sortColors(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmp);
}
 */

int main(void) {
  int nums1[] = {2, 0, 2, 1, 1, 0};
  sortColors(nums1, 6);
  for (int i = 0; i < 6; i++)
    printf("num=%d\n", nums1[i]);

  int nums[] = {2, 0, 1};
  sortColors(nums, 3);
  for (int i = 0; i < 3; i++)
    printf("num=%d\n", nums[i]);

  return 0;
}
