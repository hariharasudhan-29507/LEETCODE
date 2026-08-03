int* countBits(int n, int* returnSize) {
    
    *returnSize = n + 1;
    int *result = malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        int temp = i;
        int count = 0;

        while (temp > 0) {
            count += temp % 2;
            temp /= 2;
        }

        result[i] = count;
    }

    return result;
}
