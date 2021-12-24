template <typename M, int arraySize>void arrMin(M arr[arraySize])
{
    int i;
    int smallest = 0;
    for(i = 1; i<arraySize;i++){
        if(arr[i]< smallest){
            smallest = arr[i];
        }
        
    }
    return smallest;
}