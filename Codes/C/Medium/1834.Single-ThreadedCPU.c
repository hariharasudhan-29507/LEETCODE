int compareTasks(const void *a, const void *b) {
    int *t1 = *(int **)a;
    int *t2 = *(int **)b;
    if (t1[0] != t2[0]) {
        return t1[0] - t2[0];
    }
    return t1[2] - t2[2];
}

void heapPush(int *heap, int *size, int **allTasks, int val) {
    int i = (*size)++;
    heap[i] = val;
    while (i > 0) {
        int parent = (i - 1) / 2;
        int *pTask = allTasks[heap[parent]];
        int *cTask = allTasks[heap[i]];
        if (pTask[1] > cTask[1] || (pTask[1] == cTask[1] && pTask[2] > cTask[2])) {
            int temp = heap[parent];
            heap[parent] = heap[i];
            heap[i] = temp;
            i = parent;
        } else {
            break;
        }
    }
}

int heapPop(int *heap, int *size, int **allTasks) {
    int top = heap[0];
    heap[0] = heap[--(*size)];
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        int *sTask = allTasks[heap[smallest]];
        if (left < *size) {
            int *lTask = allTasks[heap[left]];
            if (lTask[1] < sTask[1] || (lTask[1] == sTask[1] && lTask[2] < sTask[2])) {
                smallest = left;
                sTask = lTask;
            }
        }
        if (right < *size) {
            int *rTask = allTasks[heap[right]];
            if (rTask[1] < sTask[1] || (rTask[1] == sTask[1] && rTask[2] < sTask[2])) {
                smallest = right;
            }
        }
        if (smallest != i) {
            int temp = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = temp;
            i = smallest;
        } else {
            break;
        }
    }
    return top;
}

int* getOrder(int** tasks, int tasksSize, int* tasksColSize, int* returnSize) {
    *returnSize = tasksSize;
    int *result = malloc(tasksSize * sizeof(int));
    int **allTasks = malloc(tasksSize * sizeof(int*));
    int *heap = malloc(tasksSize * sizeof(int));

    for (int i = 0; i < tasksSize; i++) {
        allTasks[i] = malloc(3 * sizeof(int));
        allTasks[i][0] = tasks[i][0];
        allTasks[i][1] = tasks[i][1];
        allTasks[i][2] = i;
    }

    qsort(allTasks, tasksSize, sizeof(int*), compareTasks);

    int heapSize = 0, taskIdx = 0, resIdx = 0;
    long long currentTime = 0;

    while (resIdx < tasksSize) {
        while (taskIdx < tasksSize && allTasks[taskIdx][0] <= currentTime) {
            heapPush(heap, &heapSize, allTasks, taskIdx);
            taskIdx++;
        }

        if (heapSize == 0) {
            currentTime = allTasks[taskIdx][0];
        } else {
            int cur = heapPop(heap, &heapSize, allTasks);
            result[resIdx++] = allTasks[cur][2];
            currentTime += allTasks[cur][1];
        }
    }

    for (int i = 0; i < tasksSize; i++) {
        free(allTasks[i]);
    }
    free(allTasks);
    free(heap);

    return result;
}
