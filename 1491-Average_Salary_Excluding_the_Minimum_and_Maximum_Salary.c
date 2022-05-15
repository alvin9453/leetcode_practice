double average(int* salary, int len){
    int max = 0;
    int min = INT_MAX;
    double sum = 0;
    for( int i = 0; i < len; i++)
    {
        sum += salary[i];
        if(salary[i] > max)
            max = salary[i];
        
        if(salary[i] < min)
            min = salary[i];
    }
    return (sum - min - max) / (len - 2);
}
