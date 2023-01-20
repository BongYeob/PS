int cnt=0;
int check[26];

void gen(){
    for(int i=0; i<26; i++){
        if(check[i]){
            cnt++;
            check[i]--;
            gen();
            check[i]++;
        }
    }
}

int numTilePossibilities(char * tiles){
    cnt =0;
    for(int i=0; i<26; i++)
        check[i] = 0;
    for(int i=0; i<strlen(tiles); i++)
        check[tiles[i]-'A']++;
    
    gen();
    
    return cnt;
}