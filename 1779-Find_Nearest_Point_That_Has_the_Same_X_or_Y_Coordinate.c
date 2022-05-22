#define MAX_INT 100000

int nearestValidPoint(int x, int y, int** points, int pointsSize, int* pointsColSize){
    int small = MAX_INT;
    int val = MAX_INT;
    int index = -1;
    
    for(int i = 0; i < pointsSize; i++)
    {
        if(points[i][0] != x && points[i][1] != y)
            continue;
        
        val = abs((x - points[i][0]) + (y - points[i][1]));
        
        if(val < small)
        {
            small = val;
            index = i;
        }
    }
    
    return index;
}
