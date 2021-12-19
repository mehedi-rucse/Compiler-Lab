#include <stdio.h>
#include <string.h>

int getLetter(char ch){
    if((ch >= 'A' && ch <='Z') || (ch >= 'a' && ch <= 'z'))
        return 1;
    return 0;
}
int getDigit(char ch){
    if(ch >='0'&& ch <='9')
        return 1;
    return 0;
}
int getVowel(char ch){
    if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
        ch == 'a' || ch == 'e' || ch =='i' || ch == 'o' || ch == 'u')
            return 1;
    return 0;
}
void aNo(char str[]){
    int i,j,word=1,letter=0,digit=0,other=0,len = 0;
    len = strlen(str);
    for (i = 0;i<len;i++){
        if(str[i] == ' ' && str[i+1] !=' ')
            word++;
        if(getLetter(str[i]))
            letter++;
        else if(getDigit(str[i]))
            digit++;
        else if(str[i]  != ' ')
            other++;
    }
    printf("Number of Words = %d, letters = %d, digits = %d and others = %d\n",word,letter,digit,other);
}

void bNo(char str[]){
    int i,j,l = 0,d = 0, t = 0,len = 0;
    char letters[30] , digits[30], others[30];
    len = strlen(str);
    for (i = 0 ;i < len;i++){
        if(getLetter(str[i])){

            letters[l++] = str[i];
        }
        else if(getDigit(str[i])){

            digits[d++] =  str[i];
        }
        else if(str[i] != ' '){

            others[t++] = str[i];
        }
    }
    letters[l] = digits[d] = others[t] = '\0';
    printf("\nLetters: %s\nDigits: %s\nOthers: %s\n",letters,digits,others);


}

void cNo(char str[]){
    int i,j,vowel = 0, consonant = 0 ,len = 0;
    len = strlen(str);
    for (i = 0;i<len;i++){
        if(getLetter(str[i])){
           if(getVowel(str[i]))
                vowel++;
            else
                consonant++;
        }
    }
    printf("\nNumber of Vowel = %d, Consonant = %d\n",vowel,consonant);
}
int mr[200];
void dNo(char str[]){
    int i,j,k,v = 0, c = 0 ,len = 0;
    len = strlen(str);
    char vowels[100],consonants[100];

    for (i = 0;i<len;i++){
        if(getVowel(str[i])){
                if( mr[(int)str[i]] == 0 ){
                    vowels[v++] = str[i];
                }
        }
        else if(getLetter(str[i])){

                if(mr[(int)str[i]] == 0){
                    consonants[c++] = str[i];
                }
        }
        mr[(int)str[i]] = 1;
    }
    printf("\nVowels : ");
    for(i=0;i<v;i++){
        printf("%c ",vowels[i]);
    }
    printf("\nConsonants : ");
    for(i=0;i<c;i++){
        printf("%c ",consonants[i]);
    }
}
void eNo(char str[]){
    int i,j,k,len=0,m,n,inc1=0,inc2=0;
    char vw[1000],cns[1000];
    len = strlen(str);
    for(i=0;i<len;i++){
        if(getVowel(str[i])){
            while(str[i] != ' ' && str[i] != '\0'){
                vw[inc1++] = str[i++];
            }
            i--;
            vw[inc1++] = ' ';
        }
        else if(getLetter(str[i])){
            while(str[i] != ' ' && str[i] != '\0'){
                cns[inc2++] = str[i++];
            }
            i--;
            cns[inc2++] = ' ';
        }
    }

    vw[inc1] = '\0';
    cns[inc2] = '\0';
    printf("\n\nWords started with vowel : %s\n",vw);
    printf("Words started with consonant : %s\n",cns);
}

int main(){
    char str[100] = "Md. Tareq Zaman, Part-3, 2011 ami kola khai";
    aNo(str);
    bNo(str);
    cNo(str);
    dNo(str);
    eNo(str);

    return 0;
}
