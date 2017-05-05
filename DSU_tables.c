#include <stdio.h>
#include <algorithm>

using namespace std;

int parent[100002], rank[100002];
int sizes[100002];

int max_size = -1;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void make_set (int v, int size) {
    parent[v] = v;
    rank[v] = 0;
    sizes[v] = size;
}
 
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
 
void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap (&a, &b);
        int new_size = sizes[a] + sizes[b];
        parent[b] = a;
        sizes[a] = new_size;
        max_size = max(max_size, new_size);
        if (rank[a] == rank[b])
            ++rank[a];
    }
    printf("%d\n", max_size);
}

int main ()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        int size;
        scanf("%d", &size);
        make_set(i, size);
        max_size = max(size, max_size);
    }
    for(int i = 1; i <= m; i++)
    {
        int first, second;
        scanf("%d %d", &first, &second);
        union_sets(first, second);
    }
    return 0;
}

