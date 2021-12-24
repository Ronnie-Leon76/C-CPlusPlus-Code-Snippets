template <class findMin>{
    findMin GetMin(findMin a){
        int min = 0;
        for(int i = 0;i<sizeof(a.Ms);i++){
            if(Ms[i]<min){
                min = Ms[i];
            }
        }
    }
}