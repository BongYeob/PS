int trailingZeroes(int n){
    int cnt2=0;
    int cnt5=0;
    for(int i=1; i<=n; i++){
        int temp = i;
        while(temp%2==0){
            cnt2++;
            temp = temp /2;
        }
        temp = i;
        while(temp %5==0){
            cnt5++;
            temp = temp /5;
        }
    }

    return (cnt2<cnt5)?cnt2 : cnt5;
    
}