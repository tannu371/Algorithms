#include<iostream>

using namespace std;

template<typename T>
void Merge(T init_list[], int lb, int mid, int ub) {
    T merged_list[ub+1];
    int i=lb, j = mid+1, k=lb;
    while(i<=mid and j<= ub) {
        if(init_list[i] < init_list[j]) merged_list[k++] = init_list[i++];
        else merged_list[k++] = init_list[j++];
    }
    while(i<=mid) {
        merged_list[k++] = init_list[i++];
    }
    while(j<=ub) {
        merged_list[k++] = init_list[j++];
    }
    for(int i=lb; i<=ub; i++) {
        init_list[i] = merged_list[i];
    }
    
}

template<typename T>
void Merge_sort(T init_list[], int lb, int ub) {
    if(lb<ub) {
        int mid = (lb+ub)/2;
        Merge_sort(init_list, lb, mid);
        Merge_sort(init_list, mid+1, ub);
        Merge(init_list, lb, mid, ub);
    }
}

int main() {
    int a[8]{24, 35, 45, 63, 11, 17, 10, 96};

    Merge_sort(a, 0, 7);

    for(int i=0; i<8; i++) cout << a[i] << " ";
    
}