#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* _replace(char *ip){
        int size=strlen(ip);
        char* repl = malloc(size+1);
	strcpy(repl,ip);
        int i;
        printf("Size %d: \n", size);
        for(i=0;i<size;i++){
	printf("%c\n",repl[i]);
                if(repl[i]=='.')
                        repl[i]='_';
        }
        printf("New String %s\n",repl);
        return repl;

}


int main(){

const char *ip="172.27.231.17";
_replace(ip);
}
