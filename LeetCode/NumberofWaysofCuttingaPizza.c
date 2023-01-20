int row;
int col;
char **pizza1;
int memo[51][51][11];

int check(int start_row, int row, int start_col, int col) {
	for (int i = start_col; i < col; i++)
		for (int j = start_row; j < row; j++)
			if (pizza1[i][j] == 'A')
				return 1;
	return 0;
}

int count(int start_col, int start_row, int k) {
    if(memo[start_col][start_row][k] >=0)
        return memo[start_col][start_row][k];
	if (k == 1) {
		if (check(start_row, row, start_col, col)){
            memo[start_col][start_row][k] = 1;
            return 1;
        }
	}

	int total = 0;
    
    for (int i = start_col; i < col; i++) {
		if (check(start_row, row, start_col, i+1))
			total = (total + count(i+1, start_row, k - 1))%1000000007;
	}
	for (int i = start_row; i < row; i++) {
		if (check(start_row, i+1, start_col, col))
			total = (total + count(start_col, i+1, k-1))%1000000007;
	}
	
    memo[start_col][start_row][k] = total;
	return total;
}

int ways(char ** pizza, int pizzaSize, int k){
    pizza1 = pizza;
    col = pizzaSize;
    row = strlen(pizza[0]);
    for (int i = 0; i < 51; i++)
		for (int j = 0; j < 51; j++)
			for (int k = 0; k < 11; k++)
				memo[i][j][k] = -1;
    count(0,0,k);
    return memo[0][0][k];
    
}