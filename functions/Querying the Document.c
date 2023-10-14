#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5
char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}

int getWord(char ** sen, int s, char * text){
    int chs = 1;
    for(int i = 0; text[i] != ' ' && text[i] != '\n' && text[i] != 0 && text[i] != '.'; i++) chs++;
    sen[s] = (char *) calloc(chs, 1);
    for(int i = 0; i < chs-1; i++) sen[s][i] = text[i];
    for(int i = 0; chs + i < strlen(text); i++) if(('a' <= text[chs + i] && text[chs + i] <= 'z') || ('A' <= text[chs + i] && text[chs + i] <= 'Z')) return chs + i;
    return strlen(text);
}

int getSentence(char *** par, int s, char * text){
    int words = 1;
    for(int i = 0; text[i] != '\n' && text[i] != 0 && text[i] != '.'; i++) if(text[i] == ' ') words++;
    par[s] = (char **) calloc(words, sizeof(char *));
    int newindex = 0;
    for(int i = 0; i < words; i++) newindex += getWord(par[s], i, text+newindex);
    return newindex;
}



int getParagraph(char **** doc, int p, char * text){
    int sentences = 0;
    for(int i = 0; text[i] != '\n' && text[i] != 0; i++) if(text[i] == '.') sentences++;
    doc[p] = (char ***) calloc(sentences, sizeof(char **));
    int newindex = 0;
    for(int i = 0; i < sentences; i++) newindex += getSentence(doc[p], i, text+newindex);
    return newindex;
}

char**** get_document(char* text) {
    int paragraphs = 1;
    for(int i = 0; i < strlen(text); i++) if(text[i] == '\n') paragraphs++;
    
    char **** result = (char ****) calloc(paragraphs, sizeof(char***));
    int newindex = 0;
    for(int i = 0; i < paragraphs; i++) newindex += getParagraph(result, i, text+newindex);
    return result;
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}
