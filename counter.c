#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void head(){
	printf("Content-type:plain-text\r\n\r\n");
	printf("<html><head><title>");	
	printf("counter");
	printf("</title><head><body bgcolor='#008800'>");
}
void body(){
	char r[2080];
	char envi[2080];
	char c[2080];
	char d[2080];
	char *cc;
	int i=0;
	FILE *f1;
	strcpy(envi,"QUERY_STRING");
	cc=getenv(envi);
	if(cc!=NULL ){

		strcpy(d,"zzz");
		strcat(d,cc);
		f1=fopen(d,"r");
		if(f1==NULL){
			f1=fopen(d,"w");
			fprintf(f1,"0");
			fclose(f1);		
			f1=fopen(d,"r");
		}
		fgets(r,2048,f1);
		r[2049]=0;
		fclose(f1);
		i=atoi(r);
		i++;
		printf("%d",i);
		f1=fopen(d,"w");
		fprintf(f1,"%d",i);
		fclose(f1);		
	}
}
void tail(){
	printf("</body></html>");	
}
int main(){
	head();
	body();
	tail();
	return 0;
}