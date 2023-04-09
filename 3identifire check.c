#include<stdio.h>
int main()
{
    int flag=0,i=0; char a[50];
    gets(a);

    if(isalpha(a[0]) || a[0]=='_'){
        while(a[i]!='\0'){
        if(isdigit(a[i]) || isalpha(a[i]) || a[i]=='_'){
            flag = 1;
        }
        else{
            flag = 0;
        }
        i++;
    }
    }
    else
        printf("\n %s is not identifier",a);


    if(flag==1){
        printf("\n %s is identifier!",a);
    }

}
