#include <stdio.h>

int findDuplicate(int arr[], int n) {
    int slow = arr[0];
    int fast = arr[0];

    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    slow = arr[0];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    long long actualSum = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        actualSum += arr[i];
    }

    int duplicate = findDuplicate(arr, n);

    long long expectedSum = (long long)n * (n + 1) / 2;

    int missing = expectedSum - (actualSum - duplicate);

    printf("Missing Number: %d\n", missing);
    printf("Duplicate Number: %d\n", duplicate);

    return 0;
}

