void swap(int* nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void quick_sort(int *nums, int first, int last)
{
    int pivot, i, j;
    
    if(first >= last)
        return;
    
    pivot = first;
    i = first;
    j = last;
    
    while(i < j)
    {
        while(nums[i] <= nums[pivot] && i < last)
            i++;
        while(nums[j] > nums[pivot])
            j--;
        
        if( i < j){
            // swap
            swap(nums, i , j);
        }
    }
    
    swap(nums, pivot, j);
    quick_sort(nums, first, j - 1);
    quick_sort(nums, j + 1, last);
}

int missingNumber(int* nums, int numsSize){    
    quick_sort(nums, 0, numsSize - 1);
    if(nums[0] != 0)
        return 0;
    
    for(int i = 1; i < numsSize; i++)
    {
        if(nums[i] - nums[i - 1] != 1)
            return nums[i - 1] + 1;
    }   
    return nums[numsSize - 1] + 1;
}