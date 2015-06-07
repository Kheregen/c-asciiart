#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "asciifont.h"

int argcheck( char* arg){
    //Funkce zjistuje jestli zadany parametr je cele cislo
    int length;
    char str = '0';
    sscanf(arg,"%d%c",&length,&str);
    if(str != '0'){
        return 0;
    };
    return length;
}

void set(char* text, int length){
    //Funkce vypisuje jeden radek textu v asciifontu
    unsigned int length2 = length;
    for(int i = 0; i<8; i++){
        for(unsigned int j = 0; (j<length2/8) && (j < strlen(text));j++){
            int multiple = 128;
            int helper = text[j];
            for(int k = 0; k< 8; k++){
            if((font_data[helper][i] & multiple) == multiple ){
                printf("#");
            }
            else{
                printf(" ");
            }
            multiple = multiple >> 1;
            }
        }
        printf("\n");
    }
}

int main(int argc, char** argv){
    if(argc !=2 ){
        fputs("Wrong input.", stderr);
        return 1;
    }
    int length = argcheck(argv[1]);
    if( length < 8 ){
        fputs("Wrong input.", stderr);
        return 1;
    }
    char * text = (char*)calloc(101, sizeof(char));
    scanf("%[^\n]s", text);
    int num_of_char = length/8;
    for(unsigned int i = 0; i <= (strlen(text)/num_of_char) && (i*num_of_char != strlen(text)); i++){
        set( text + (num_of_char*i), length);
    }
    return 0;
}
