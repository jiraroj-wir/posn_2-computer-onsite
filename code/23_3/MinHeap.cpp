#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int *pt, count = 0;

int parent(int idx) {
    if (idx == 0 || idx >= count) {
        return -1;
    }
    return (idx - 1) / 2;
}

int l_child(int idx) {
    int l = 2 * idx + 1;
    return (l >= count) ? -1 : l;
}

int r_child(int idx) {
    int r = 2 * idx + 2;
    return (r >= count) ? -1 : r;
}

bool is_leaf(int idx) {
    return (l_child(idx) == -1) && (r_child(idx) == -1);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int find_min() {
    return count > 0 ? pt[0] : -1;
}

void add(int value) {
    if (count >= 1000) {
        printf("Heap full\n");
        return;
    }
    pt[count] = value;
    int i = count;
    count++;

    while (i != 0 && pt[parent(i)] > pt[i]) {
        swap(&pt[i], &pt[parent(i)]);
        i = parent(i);
    }
}


int find(int value) {
    for (int i = 0; i < count; i++) {
        if (pt[i] == value) {
            return i;
        }
    }
    return -1;
}

bool delete_idx(int idx) {
    if (idx < 0 || idx >= count) {
        return false;
    }
    
    pt[idx] = pt[count - 1];
    count--;
    
    while (idx < count) {
        int left = l_child(idx);
        int right = r_child(idx);
        int smallest = idx;

        if (left != -1 && pt[left] < pt[smallest]) {
            smallest = left;
        }

        if (right != -1 && pt[right] < pt[smallest]) {
            smallest = right;
        }

        if (smallest != idx) {
            swap(&pt[idx], &pt[smallest]);
            idx = smallest;
        } else {
            break;
        }
    }
    
    int parentIdx = parent(idx);
    while (idx > 0 && pt[parentIdx] > pt[idx]) {
        swap(&pt[parentIdx], &pt[idx]);
        idx = parentIdx;
        parentIdx = parent(idx);
    }

    return true;
}


void print_mh() {
    for (int i = 0; i < count; i++) {
        printf("%d ", pt[i]);
    }
    printf("\n");
}

int main() {
    pt = (int*)malloc(1000 * sizeof(int));
    if (pt == NULL) {
        printf("Memory not allocated\n");
        exit(0);
    }

    // Test add
    add(5);
    add(3);
    add(9);
    add(4);
    add(8);
    add(2);

    // Test print
    print_mh();

    add(7);
    print_mh();

    // Test parent, left and right child
    printf("Parent of index 1: %d\n", parent(1));
    printf("Left child of index 0: %d\n", l_child(0));
    printf("Right child of index 0: %d\n", r_child(0));

    // Test is_leaf
    printf("Is index 5 a leaf? %s\n", is_leaf(5) ? "Yes" : "No");
    printf("Is index 2 a leaf? %s\n", is_leaf(2) ? "Yes" : "No");

    // Test find_min
    printf("Minimum element: %d\n", find_min());

    // Test find
    printf("'4' at index: %d\n", find(4));

    // Test delete
    delete_idx(0);

    print_mh();

    free(pt);

    return 0;
}

