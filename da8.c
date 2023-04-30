#include<stdio.h>
#include<string.h>
int convert(char a[12]){
    int i=0;
    int sum=0;
    while(a[i]!='/'){
        sum=sum*10+a[i]-'0';
        i++;
    }
    return sum;
}
int convert1(char a[12]){
    int  i=0;
    int sum=0;
    while(a[i]!='/'){
        i++;
    }
    i++;
    while(a[i]!='/'){
        sum=sum*10+a[i]-'0';
        i++;
    }
    return sum;
}
int convert2(char a[12]){
    int i=0;
    while(a[i]!='/'){
        i++;
    }
    i++;
    while(a[i]!='/'){
        i++;
    }
    i++;
    return i;
}
struct employeed{
    char name[23];
    int age;
    char position[20];
    char dateofjoining[23];
};
int main(){
    struct employeed a[100];
    struct employeed b[100];
    char x[12],z[12];
    int n,i=0,j;
    printf("Enter the number of employees:");
    scanf("%d",&n);
    for(;i<n;i++){
        printf("Enter the details of employee %d:\n",i+1);
        printf("Name:");
        scanf("%s",&(a[i].name));
        printf("Age:");
        scanf("%d",&(a[i].age));
        printf("Position:");
        scanf("%s",&(a[i].position));
        printf("Date of joining(dd/mm/yyyy):");
        scanf("%s",&(a[i].dateofjoining));
    }
    for(i=0;i<n;i++){
        b[i]=a[i];
    }
    char k[23];
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(strcmp(a[i].name,a[j].name)>0){
                strcpy(k,a[i].name);
                strcpy(a[i].name,a[j].name);
                strcpy(a[j].name,k);
            }   
        }
    }
    printf("Employee list sorted by name:\n");
    for(i=0;i<n;i++){
        j=0;
        for(j=0;j<n;j++){
            if(strcmp(a[i].name,b[j].name)==0){
                break;
            }
        }
        printf("%s\n",a[i].name);
        printf("%d\n",b[j].age);
        printf("%s\n",b[j].position);
        printf("%s\n",b[j].dateofjoining);
        printf("\n");
    }
    printf("Employee list sorted by date of birth:\n");
    char v[12];
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            strcpy(x,a[i].dateofjoining);
            strcpy(z,a[j].dateofjoining);
            int l=convert2(z),t;
            int s=convert2(x);
            char f[12],p[12];
            strncpy(f,z+l,4);
            f[4]='\0';
            strncpy(p,x+s,4);
            p[4]='\0';
            if(strcmp(f,p)==1){
                t=1;//larger
            }
            else if(strcmp(f,p)==-1){
                t=-1;//smaller
            }
            else{
              int q=convert1(z) ;
              int w=convert1(x);
              if(q>w){
                t=1;
              }
              else if(q<w){
                t=-1;
              }
              else{
                q=convert(z);
                w=convert(x);
                if(q>w){
                    t=1;
                }
                else if(q<w){
                    t=-1;
                }
                else{
                    t=0;//equal
                }
              }
            }
            if(t==-1){
                strcpy(v,a[i].dateofjoining);
                strcpy(a[i].dateofjoining,a[j].dateofjoining);
                strcpy(a[j].dateofjoining,v);
            }
        }
    }
    for(i=0;i<n;i++){
        j=0;
        for(j=0;j<n;j++){
            if(strcmp(a[i].dateofjoining,b[j].dateofjoining)==0){
                break;
            }
        }
        printf("%s\n",b[j].name);
        printf("\n");
    }
    return 0;
}