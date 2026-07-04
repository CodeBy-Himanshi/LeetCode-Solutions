int mostWordsFound(char** sentences, int sentencesSize) {
    int max=0;
    for(int i=0;i<sentencesSize;i++){
        int words=1,j=0;
        while (sentences[i][j] != '\0') {
            if (sentences[i][j] == ' ')
                words++;
            j++;
        }
        if(words>max)
            max=words;
    }
    return max;
}