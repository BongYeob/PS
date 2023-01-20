int check[10] = { 0, };
int num[10] = {0,};
char result[10];
int cnt =0;

void f(int n, int k, int depth) {
	if (depth == n) {
		cnt++;
		if (cnt == k) {
			for (int j = 0; j < n; j++){
                result[j] = num[j] + '0';
            }
			return;
		}
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (check[i] == 0) {
			num[depth] = i;
			check[i] = 1;
			f(n, k, depth + 1);
			check[i] = 0;
			num[depth] = 0;
		}
	}
	return;
}

char * getPermutation(int n, int k){
    
    for(int i=0; i<10; i++){
        check[i] = 0;
        num[i] = 0;
        result[i] = '\0';
    }
    cnt =0;
    f(n, k, 0);
    
    return result;
}