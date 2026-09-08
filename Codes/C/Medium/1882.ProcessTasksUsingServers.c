void push1(long long *h, int *n, long long v) {
    int i = (*n)++;
    h[i] = v;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h[p] > h[i]) {
            long long t = h[p]; h[p] = h[i]; h[i] = t;
            i = p;
        } else break;
    }
}

long long pop1(long long *h, int *n) {
    long long r = h[0];
    h[0] = h[--(*n)];
    int i = 0;
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, s = i;
        if (l < *n && h[l] < h[s]) s = l;
        if (r < *n && h[r] < h[s]) s = r;
        if (s != i) {
            long long t = h[i]; h[i] = h[s]; h[s] = t;
            i = s;
        } else break;
    }
    return r;
}

void push2(long long *a, long long *b, int *n, long long x, long long y) {
    int i = (*n)++;
    a[i] = x; b[i] = y;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (a[p] > a[i] || (a[p] == a[i] && b[p] > b[i])) {
            long long t = a[p]; a[p] = a[i]; a[i] = t;
            t = b[p]; b[p] = b[i]; b[i] = t;
            i = p;
        } else break;
    }
}

void pop2(long long *a, long long *b, int *n, long long *x, long long *y) {
    *x = a[0]; *y = b[0];
    int m = --(*n);
    a[0] = a[m]; b[0] = b[m];
    int i = 0;
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, s = i;
        if (l < *n && (a[l] < a[s] || (a[l] == a[s] && b[l] < b[s]))) s = l;
        if (r < *n && (a[r] < a[s] || (a[r] == a[s] && b[r] < b[s]))) s = r;
        if (s != i) {
            long long t = a[i]; a[i] = a[s]; a[s] = t;
            t = b[i]; b[i] = b[s]; b[s] = t;
            i = s;
        } else break;
    }
}

int* assignTasks(int* servers, int serversSize, int* tasks, int tasksSize, int* returnSize) {
    *returnSize = tasksSize;
    int n = serversSize, m = tasksSize;
    int *ans = malloc(m * sizeof(int));
    long long *fr = malloc(n * sizeof(long long));
    long long *bt = malloc(n * sizeof(long long));
    long long *bw = malloc(n * sizeof(long long));
    int f = 0, b = 0;

    for (int i = 0; i < n; i++)
        push1(fr, &f, ((long long)servers[i] << 32) | (unsigned int)i);

    long long tim = 0;
    for (int j = 0; j < m; j++) {
        if (tim < j) tim = j;

        while (b > 0 && bt[0] <= tim) {
            long long t, w;
            pop2(bt, bw, &b, &t, &w);
            push1(fr, &f, w);
        }

        if (f == 0) {
            tim = bt[0];
            while (b > 0 && bt[0] <= tim) {
                long long t, w;
                pop2(bt, bw, &b, &t, &w);
                push1(fr, &f, w);
            }
        }

        long long cur = pop1(fr, &f);
        ans[j] = (int)cur;
        push2(bt, bw, &b, tim + tasks[j], cur);
    }

    free(fr); free(bt); free(bw);
    return ans;
}
