// {0,1,1,0,1}

void sort_array(int *arr, int size) {
    int *start = arr;
    int *end = arr + (size - 1);
    int temp;

    while (start < end) {
        if (*start == 0) {
            start++;
        } else if (*end == 1) {
            end--;
        } else {
            // Swap values
            temp = *start;
            *start = *end;
            *end = temp;
            start++;
            end--;
        }
    }
}

