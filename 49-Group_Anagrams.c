#define MAX_STR_LEN 100

int comp(const void *a, const void *b)
{
    return (*(char *)a) - (*(char *)b);
}

char* sort_char(char *str)
{
    char* s = malloc(strlen(str) + 1);
    strncpy(s, str, strlen(str) + 1);
    qsort(s, strlen(str), sizeof(char), comp);
    return s;
}

typedef struct word{
    char key[MAX_STR_LEN];
    char sorted[MAX_STR_LEN];
    UT_hash_handle hh; 
}word;

int word_sort(word *a, word *b)
{
    return strcmp(a->sorted, b->sorted);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    char *sortred_str;
    word *w = NULL, *words = NULL, *tmp = NULL;

    for(int i = 0; i < strsSize; i++)
    {
        w = (struct word *)malloc(sizeof(struct word));
        sortred_str = sort_char(strs[i]);
        // printf("[DEBUG] strs[%d] = %s , sotred_str = %s \n", i, strs[i], sortred_str);
        strncpy(w->key, strs[i], strlen(strs[i]) + 1);
        strncpy(w->sorted, sortred_str, strlen(strs[i]) + 1);
        
        HASH_ADD_STR(words, sorted, w);
        
        free(sortred_str);
    }
    // printf("\n");
    
    HASH_SORT(words, word_sort);
    
    char ***ans = malloc(strsSize * sizeof(char *));
    int *ans_colsizes = malloc(strsSize * sizeof(int));
    *returnColumnSizes = ans_colsizes;
    
    *returnSize = 0;
    
    char *anagram = NULL;
    
    HASH_ITER(hh, words, w, tmp) {
        // printf(" -[DEBUG] key = %s , sorted = %s\n", w->key, w->sorted);
        if( anagram != NULL && strcmp(w->sorted , anagram) == 0)
        {
            ans[ *returnSize ][ ans_colsizes[*returnSize] ] = w->key;
            ans_colsizes[*returnSize] += 1;
        }
        else
        {
            if(anagram != NULL)
                *returnSize += 1;
            
            anagram = w->sorted;
            ans [ *returnSize ] = malloc(strsSize * sizeof(char *));
            
            ans_colsizes[*returnSize] = 0;
            // printf(" [DEBUG] anagram = %s , *returnSize = %d\n", anagram, *returnSize);
                 
            ans[ *returnSize ][ ans_colsizes[*returnSize] ] = w->key;
            ans_colsizes[*returnSize] += 1;
        }
    }
    
    *returnSize += 1;
    
    return ans;
}