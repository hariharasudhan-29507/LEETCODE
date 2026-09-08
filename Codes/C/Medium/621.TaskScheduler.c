#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int leastInterval(char* tasks, int tasksSize, int n) {
    int f[26] = {0};
    int maxf = 0;
    int maxc = 0;

    for (int i = 0; i < tasksSize; i++) {
        f[tasks[i] - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        if (f[i] > maxf) {
            maxf = f[i];
            maxc = 1;
        } else if (f[i] == maxf) {
            maxc++;
        }
    }

    int slots = (maxf - 1) * (n - (maxc - 1));
    int leftover = tasksSize - (maxf * maxc);
    int idles = max(0, slots - leftover);

    return tasksSize + idles;
}
