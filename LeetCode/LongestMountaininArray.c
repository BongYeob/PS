int longestMountain(int* arr, int arrSize){
    int start=0, change=0, finish=0;
    int length =0;

    while(finish <arrSize){
        if(finish == arrSize-1){
            if(start != change && change != finish)
                if(length < finish-start +1 ){
                    length = finish-start+1;
                    break;
                }
            break;
        }
        else if(start == change && arr[start] >= arr[start+1]){
            start++; 
            change++;
            finish++;
        }
        else if(change == finish && arr[change] < arr[change+1]){
            change++;
            finish++;
        }
        else if(arr[finish] > arr[finish+1])
            finish++;
        else{
            if(length < finish-start+1 && start!=change && change != finish)
                length = finish-start+1;
            start=finish;
            change = finish;
        }
    }
    return length;
}