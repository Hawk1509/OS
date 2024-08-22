#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
void main()
{
	char opcode[10],mnemonic[3],operand[10],label[10],code[10];
	int locctr,start=0,length;
	FILE *fp1,*fp2,*fp3,*fp4;
	fp1=fopen("input.txt","r");
	fp2=fopen("sym.txt","w");
	fp3=fopen("inter.txt","w");
	fp4=fopen("optab.txt","r");
	fscanf(fp1,"%s%s%s",label,opcode,operand);
	if(strcmp(opcode,"START")==0)
	{
		start=atoi(operand);
		locctr=start;
		fprintf(fp3,"\t%s\t%s\t%s\n",label,opcode,operand);
		fscanf(fp1,"%s%s%s",label,opcode,operand);
	}
	else
		locctr=0;
	while(strcmp(opcode,"END")!=0)
	{
		fprintf(fp3,"%d\t",locctr);
		if(strcmp(label,"**")!=0)
		    fprintf(fp2,"%s\t%d\n",label,locctr);
		fscanf(fp4,"%s%s",code,mnemonic);
		while(strcmp(code,"END")!=0)
		{
			if(strcmp(opcode,code)==0)
			{
				locctr+=3;
				break;
			}
			fscanf(fp4,"%s%s",code,mnemonic);
		}
		if(strcmp(opcode,"WORD")==0)
			locctr+=3;
		else if(strcmp(opcode,"RESW")==0)
			locctr+=(3*(atoi(operand)));
		else if(strcmp(opcode,"RESB")==0)
			locctr+=(atoi(operand));
		else if(strcmp(opcode,"BYTE")==0)
		{
			if(operand[0]=='X')
			{
				locctr+=1;
			}
			else if(operand[0]=='C')
			{
				locctr+=(strlen(operand)-3);
			}
		}
		fprintf(fp3,"%s\t%s\t%s\t\n",label,opcode,operand);
		fscanf(fp1,"%s%s%s",label,opcode,operand);
	}
	fprintf(fp3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
	length=locctr-start;
	printf("The length of the program is %d",length);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
}

/*
OUTPUT

INPUT
Input.txt

COPY START 1000
** LDA FIVE
** STA NUM1
** LDCH NUM2
** STCH C1
NUM1 RESW 2
FIVE WORD 5
NUM2 BYTE X'F1'
C1 RESB 1
** END **

OPTAB
optab.txt

LDA 00
STA 0C
LDCH 50
STCH 54
END

SYMTAB
symtab.txt

NUM1	1012
FIVE	1018
NUM2	1021
C1	1022

INTERMEDIATE
inter.txt

	COPY	START	1000
1000	**	LDA	FIVE	
1003	**	STA	NUM1	
1006	**	LDCH	NUM2	
1009	**	STCH	C1	
1012	NUM1	RESW	2	
1018	FIVE	WORD	5	
1021	NUM2	BYTE	X'F1'	
1022	C1	RESB	1	
1023	**	END	**
*/
