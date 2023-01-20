int titleToNumber(char * columnTitle){
    int result=0;
    int length = strlen(columnTitle);
    for(int i=0; i<length; i++)
         result = result + pow(26, length-i-1) * (columnTitle[i] - 'A' +1);

    return result;
}