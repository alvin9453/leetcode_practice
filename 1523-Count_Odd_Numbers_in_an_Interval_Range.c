int countOdds(int low, int high){
    if(low == high)
    {
        if( low % 2 == 1 )
            return 1;
        else
            return 0;
    }
    
    int i = low;
    if( i % 2 == 0 )
        i++;

    return (high - i) / 2 + 1;
}
