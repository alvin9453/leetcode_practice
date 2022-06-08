int comp(const void *a, const void *b)
{
    return (*(char *)a) - (*(char *)b);
}

char *sort_str(char *str)
{
    char *sorted = malloc(strlen(str) + 1);
    strcpy(sorted, str);
    
    qsort(sorted, strlen(str), sizeof(char), comp);
    
    return sorted;
}

bool isAnagram(char * s, char * t){

    char *s1 = sort_str(s);
    char *t1 = sort_str(t);
    
    return (strcmp(s1, t1) == 0);
}