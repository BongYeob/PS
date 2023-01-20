int hIndex(int* citations, int citationsSize){
    
  int max = citationsSize-1;
	int min = 0;
	int h = 0;

	while (min <= max) {
		int mid = (max + min) / 2;	// index
		int value = citations[mid];
		if (citationsSize - mid <= value) {
			h = citationsSize - mid;
			max = mid - 1;
		}
		else
			min = mid + 1;
	}

    return h;
}