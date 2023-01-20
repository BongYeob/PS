int cnt;
int **result;
int check[21];
int *temp;

void f(int start, int depth, int n, int k) {
	if (depth == k) {
		for (int i = 0; i < k; i++)
			result[cnt][i] = temp[i];
		cnt++;
		return;
	}
	for (int i = start + 1; i <= n; i++) {
		if (check[i] == 0) {
			temp[depth] = i;
			check[i] = 1;
			f(i, depth + 1, n, k);
			check[i] = 0;
		}
	}
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    
	  long nck = 1;
		for (int i = 0; i < k; i++)
			nck *= n - i;
		for (int i = 1; i <= k; i++)
			nck /= i;
    
    result = (int**)malloc(sizeof(int*) * nck);
    for(int i=0; i<nck; i++)
        result[i] = (int*)malloc(sizeof(int) * k);
    for(int i=0; i<21; i++)
        check[i] = 0;
    
    temp = (int*)malloc(sizeof(int)*k);
    
    cnt = 0;
	
		f(0, 0, n, k);
    *returnSize = cnt;
    *returnColumnSizes = (int*)malloc(sizeof(int)*cnt);
    for(int i=0; i<cnt; i++)
        (*returnColumnSizes)[i] = k;
    free(temp);
    return result;
}