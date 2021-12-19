#include<stdio.h>
#include<string.h>
char str[100];

int validity(int start , int end){
    for(int i = start ; i <=end ; i++){
        if( (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9'))
            continue;
        return 0;
    }
    return 1;
}
int isDigit(){
    int len = strlen(str);
    for(int i = 0 ; i<len ; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            continue;
        }
        return 0;
    }
    return 1;
}
int isFloat(){
    int i ,len = strlen(str);
    for(i = 0 ; i<len ; i++){
        if(str[i] == '.') {
            for(int j = 0 ; j<len;j++){
                if(j!=i && (str[j] < '0' || str[j] > '9')){
                   return 0;
                }
            }
            if(str[0] == '0' && str[1] != '.'){
                return 0;
            }
            return len-i-1;
        }
        
    }
    return 0;
}
int isBinary(){
    int len = strlen(str);
    for(int i = 0 ; i<len ; i++){
            if(str[i] == '0' || str[i] == '1'){
               continue;
            }
            return 0;
    }
    return 1;
}


int main(){

    int n , i , j , len;

    while(scanf("%s",str)!=EOF){
        len = strlen(str);
        printf("%s\n",str);
        if(len > 3 && str[0] == 'c' && str[1] == 'h' && str[2] == '_' && validity(3,len-1) ){
            printf("Character Variable\n");
        }
        else if(len > 3 && str[0] == 'b' && str[1] == 'n' && str[2] == '_' && validity(3,len-1) ){
            printf("Binary Variable\n");
        }
        else if(len>1 && str[0] == '0' && isBinary()){
            printf("Binary Number\n");
        }
        else if((str[0]>='i' && str[0]<='n') || (str[0]>'I' && str[0]<='N') && validity(0,len-1))
            printf("Integer Variable\n");
        else if((str[0] >= '1' && str[0] <= '9') && len <5 && isDigit())
            printf("ShortINT Number\n");
        else if((str[0] >= '1' && str[0] <= '9') && len >4 && isDigit())
            printf("LongINT Number\n");
        else if((str[0]>='a' && str[0]<='h') || (str[0]>'A' && str[0]<='Z' || str[0]>='o' && str[0]<='z') || (str[0]>'O' && str[0]<='Z') && validity(0,len-1))
            printf("float Variable\n");
        else if(isFloat() <= 2)
            printf("float Number\n");
        else if(isFloat() >= 3)
            printf("Double Number\n");
        else
            printf("Invalid Input\n");

    }

    return 0;
}
