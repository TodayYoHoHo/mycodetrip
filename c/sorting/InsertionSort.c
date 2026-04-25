#include <stdio.h>

int main() {
    int i,j,key, arr[100], len;
    scanf("%d", &len);
    for (i=0;i<len;i++) scanf("%d",&arr[i]);
    for (i=1;i<len;i++){
        key = arr[i];
        j=i-1;
        while((j>=0) && (arr[j]>key)) { //先和前面的比，再往前去比较
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    for (i=0;i<len;i++) {printf("%d",arr[i]);}
    return 0;
}


/*
void insertion_sort(int arr[], int len){
    int i,j,key;
    for (i=1;i<len;i++){
        key = arr[i];
        j=i-1;
        while((j>=0) && (arr[j]>key)) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
*/