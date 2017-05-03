#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//打一個摩斯的富含是
//用sturect 存摩斯
//變為大寫的富含是  a=97 z=122 A=65 Z=90
//讀取檔案用得副函式

//1要讀取摩斯密碼\
2.用迴區讀取code\
3.
FILE *mos_in;
char mos(char *code){
	char mo2[10],mo1;
	
	mos_in=fopen("mos.txt","r");
	while(fscanf(mos_in,"%s",&mo1)!=EOF){	//想知道為什麼這裡只scanf一次 //這裡用%c 原本在A會出現問題 改%s就不會 真是奇了 
		fscanf(mos_in,"%s",mo2);
		printf("%c\t%s\n",mo1,mo2);
		//fscanf(mos_in,"%c",&mo1);
		
		
		if(strcmp(code,mo2)==0){
			fclose(mos_in);
			return mo1;
		}
		continue;
	}
	
}

char decode(char *code,char pw){
	
}

 

int main(){
    char w[10],a;
    scanf("%s",w);
    
	a=mos(&w);
    printf("%c",a);

}
