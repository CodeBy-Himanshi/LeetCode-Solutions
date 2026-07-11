bool detectCapitalUse(char* word) {
    int uppercase=0;
    for(int i=0;i<strlen(word);i++){
        if(isupper(word[i]))
            uppercase++;
    }
    return (uppercase==0 || uppercase==strlen(word) || (uppercase==1 && isupper(word[0])));
}