#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//���@�Ӽ������I�t�O
//��sturect �s����
//�ܬ��j�g���I�t�O  a=97 z=122 A=65 Z=90
//Ū���ɮץαo�ƨ禡

//1�nŪ�������K�X\
2.�ΰj��Ū��code\
3.
FILE *mos_in;
char mos(char *code){
	char mo2[10],mo1;
	
	mos_in=fopen("mos.txt","r");
	while(fscanf(mos_in,"%s",&mo1)!=EOF){	//�Q���D������o�̥uscanf�@�� //�o�̥�%c �쥻�bA�|�X�{���D ��%s�N���| �u�O�_�F 
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
