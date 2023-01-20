bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    
    int input[1001] = {0,};
    int pushtop = 0;
    int poptop = 0;
    int stop = -1;
    
    while(1){
        if(stop == -1 || input[stop] != popped[poptop]) //비어있거나 top이 pop이 아니면
            input[++stop] = pushed[pushtop++];
        else{
            poptop++;
            stop--;
        }
        
        if(poptop == poppedSize)
            return true;
        if(pushtop == pushedSize && (popped[poptop]!=input[stop]))
            return false;
    }
}