#include<stdio.h>
#include<stdlib.h>

void head(){
	printf("Content-type:plain-text\r\n\r\n");
	printf("<html><head><title>");	
	printf("counter");
	printf("</title><head><body bgcolor='#008800'>");
}
void body(){
	char r[2080];
	int i=0;
	FILE *f1;
	f1=fopen("0","r");
	if(f1==NULL){
		f1=fopen("0","w");
		fprintf(f1,"0");
		fclose(f1);		
		f1=fopen("0","r");
	}
	fgets(r,2048,f1);
	r[2049]=0;
	fclose(f1);
	i=atoi(r);
	i++;
	printf("%d",i);
	f1=fopen("0","w");
	fprintf(f1,"%d",i);
	fclose(f1);		

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