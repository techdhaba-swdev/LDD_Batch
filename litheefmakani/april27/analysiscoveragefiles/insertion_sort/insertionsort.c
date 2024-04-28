void insertionSort(int arr[], int n) {

int temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j>0;j--){
            if(arr[j]<arr[j-1]){
                temp =arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
                }
                else {
                    break; // if j loop going for next it will already sorted to indext no need to sort and check elements its already sorted
                }
            }
        }
}
