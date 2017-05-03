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
int k=0;
char mos(char *code){
	char mo2[10],mo1;
	
	mos_in=fopen("mos.txt","r");
	while(fscanf(mos_in,"%s",&mo1)!=EOF){	//想知道為什麼這裡只scanf一次 //這裡用%c 原本在A會出現問題 改%s就不會 真是奇了 
		fscanf(mos_in,"%s",mo2);
		//printf("%c\t%s\n",mo1,mo2);
		//fscanf(mos_in,"%c",&mo1);
		
		if(strcmp(code,mo2)==0){
			fclose(mos_in);
			return mo1;
		}
				
	}
	
	if(*code=='|'){
		fclose(mos_in);
		return ' ';
	}
		
	else{
		fclose(mos_in);
		return *code;	
	}
	
	
}

char en_mos(char code){
	char mo2[10],mo1;
	FILE *mos_out;
	mos_in=fopen("mos.txt","r");
	mos_out=fopen("output_decode.txt","w");
	while(fscanf(mos_in,"%s",&mo1)!=EOF){	//想知道為什麼這裡只scanf一次 //這裡用%c 原本在A會出現問題 改%s就不會 真是奇了 
		fscanf(mos_in,"%s",mo2);
		//printf("%c\t%s\n",mo1,mo2);
		//fscanf(mos_in,"%c",&mo1);
		
		if(strcmp(&code,&mo1)==0){
			fprintf(mos_out,"%s ",mo2);
			fclose(mos_in);
			
		}
				
	}
	
			
	if(strcmp(&code,&mo1)!=0){
		fprintf(mos_out,"%c ",code);
		fclose(mos_in);
			
	}
	
	
}

char decode(char letter,char pw[20]){
	int n=strlen(pw);
	if(k==n)
		k=0;
	
	if(64<letter&&letter<91){
		
		if(96<pw[k]&&pw[k]<123)
			return (letter-65-pw[k++]+97+260)%26+65;
		else if(64<pw[k]&&pw[k]<91)
			return (letter-65-pw[k++]+65+260)%26+65;
		else {
			printf("error");
			exit(0);
		}
			
	}
	else 
		return letter;
	
	
}

char encode(char letter,char pw[20]){
	int n=strlen(pw),j;
	if(k==n)
		k=0;
	
	if(96<letter&&letter<122){
		letter-=32;			
	}
	for(j=0;j<n;j++){
		if(96<pw[j]&&pw[j]<122){
			pw[j]-=32	;		
		}
	}
	
	if(64<letter&&letter<91){
		
		
		if(64<pw[k]&&pw[k]<91)
			return (letter-65+pw[k++]-65)%26+65;
		else {
			printf("error");
			exit(0);
		}
			
	}
	else if(letter=='-'){
		return '|';
	}
	else 
		return letter;
	
	
}



int main(){
	FILE *in_dec;
	FILE *in_enc;
	FILE *out_dec;
	in_dec=fopen("decode.txt","r");
	in_enc=fopen("encode.txt","r");
	out_dec=fopen("output_encode.txt","w");
	
    char w[10],pw[20],wi,a;
    int c;
    
    printf("chose what do you want to do:\n");
    printf("1\)decode:\n");
    printf("2\)encode:");
    scanf("%d",&c);
    
    
    if(c==1){
    	printf("enter the password:");
    	scanf("%s",pw);
    
    	while(fscanf(in_dec,"%s",w) !=  EOF){
    		fprintf(out_dec,"%c",decode(mos(w),pw));
    	
		}
		printf("\n....success");
	}
    
    if(c==2){
    	printf("enter the password:");
    	scanf("%s",pw);
    	while(fscanf(in_enc,"%c",&wi) != EOF){
    		en_mos(encode(wi,pw));
		}
		printf("\n....success");
	}
	
    

}
