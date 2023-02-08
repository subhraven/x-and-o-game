#include<stdio.h>
#include <time.h>
#include<stdlib.h>
//extern int a=10;
void store_date_and_time(){
    FILE *fp;
    fp=fopen("score.txt","a");
    time_t now = time(NULL);
    struct tm *cur_time = localtime(&now);
    fprintf(fp,"%s","DATE: ");
    fprintf(fp,"%d",cur_time->tm_mday);
    fprintf(fp,"%s","/");
    fprintf(fp,"%d",(cur_time->tm_mon+1));
    fprintf(fp,"%s","/");
    fprintf(fp,"%d",((cur_time->tm_year)+1900));  

    fprintf(fp,"%c",'\n');
    fprintf(fp,"%s","TIME: ");
    fprintf(fp,"%d",cur_time->tm_hour);
    fprintf(fp,"%s","(hr):");
    fprintf(fp,"%d",cur_time->tm_min);
    fprintf(fp,"%s","(min):");
    fprintf(fp,"%d",cur_time->tm_sec);
    fprintf(fp,"%s","(sec)");
    fprintf(fp,"%c",'\n');
    fclose(fp);
}