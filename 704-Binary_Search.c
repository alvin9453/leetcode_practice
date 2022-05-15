int search(int* nums, int len, int target){
    int start = 0;
    int end = len - 1;
    int mid = (start + end ) / 2;
    int ans = -1;
    if(target == nums[start])
    {
        return start;
    }
        
    do{
        if(target == nums[mid]){
            ans = mid;
            break;
        }
        else if(target < nums[mid])
            end = mid;
        else if(target > nums[mid])
            start = mid;
        
        mid = (start + end) / 2;
    }while(start != mid);
    
    if(target == nums[end])
        ans = end;
    
    return ans;
}
