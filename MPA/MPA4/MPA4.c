 #include <stdio.h>
 //I DECLARE THAT I MADE THIS MP BY MYSELF!!!
int main(){
    char str[40],str2[40],str3[30],str4[30],tmp;
    int i=0,m=0,ctr,ctr2,ctr3=0,choice,flag;

    do{
        printf("\n\t\tMenu\n\t1.Flames\n\t2.Gene\n\t3.Exit\n");
        scanf("%i",&choice);

        if(choice==1){                              //this solves for the first problem
            printf("Please type a name.\n");
            fflush(stdin);
            scanf(" %[^\n]s",&str);
            printf("Please type another name.\n");
            fflush(stdin);
            scanf(" %[^\n]s",&str2);
            if((str[i]<65 && str[i]>90)&&(str2[m]<65 && str2[m]>90)){
                    printf("ONLY ALPHABET FOR THE 1st STRING!\n");
                    printf("Please type a name.\n");
                    fflush(stdin);
                    scanf(" %[^\n]s",&str);
                    printf("ONLY ALPHABET FOR THE 2nd STRING!\n");
                    printf("Please type a name.\n");
                    fflush(stdin);
                    scanf(" %[^\n]s",&str2);
            }
            ctr=0;
            i=0;
            m=0;
            while(str[i]!='\0'){
                    while(str2[m]!='\0'){
                        if(str[i]==str2[m]){
                            ctr++;
                            if(str[i]==' '&& str2[m]==' ')
                                ctr--;
                        }
                    m++;
                    }

            if(str2[m]=='\0')
                m=0;
            i++;
            }
            if(ctr%6 == 1)
                printf("%s is FRIENDS with %s.\n",str,str2);
            else
            if(ctr%6 == 2)
                printf("%s is LOVERS with %s.\n",str,str2);
            else
            if(ctr%6 == 3)
                printf("%s is ACCEPTED by %s.\n",str,str2);
            else
            if(ctr%6 == 4)
                printf("%s is MARRIED with %s.\n",str,str2);
            else
            if(ctr%6 == 5)
                printf("%s is ENGAGED with %s.\n",str,str2);
            else
            if(ctr%6 == 0)
                printf("%s is SWEETHEARTS with %s.\n",str,str2);
            ctr2=0;
            i=0;
            m=0;
            while(str2[m]!='\0'){
                if(str2[m]==' ')
                    m++;
                while(str[i]!='\0'){
                    if(str2[m]==str[i])
                        ctr2++;
                    i++;
                }
            if(str[i]=='\0')
                i=0;
            m++;
            }
            if(ctr2%6 == 1)
                printf("%s is FRIENDS with %s.\n",str2,str);
            else
            if(ctr2%6 == 2)
                printf("%s is LOVERS with %s.\n",str2,str);
            else
            if(ctr2%6 == 3)
                printf("%s is ACCEPTED by %s.\n",str2,str);
            else
            if(ctr2%6 == 4)
                printf("%s is MARRIED with %s.\n",str2,str);
            else
            if(ctr2%6 == 5)
                printf("%s is ENGAGED with %s.\n",str2,str);
            else
            if(ctr2%6 == 0)
                printf("%s is SWEETHEARTS with %s.\n",str2,str);
            ctr3=0;
            ctr3=ctr+ctr2;
            if(ctr3%6 == 1)
                printf("As an overall,%s and %s are FRIENDS.\n",str,str2);
            else
            if(ctr3%6 == 2)
                printf("As an overall,%s and %s are LOVERS.\n",str,str2);
            else
            if(ctr3%6 == 3)
                printf("As an overall,%s and %s are ACCEPTED by one another.%s.\n",str,str2);
            else
            if(ctr3%6 == 4)
                printf("As an overall,%s and %s are MARRIED with one another.%s.\n",str,str2);
            else
            if(ctr3%6 == 5)
                printf("As an overall,%s and %s are ENGAGED with one another.\n",str,str2);
            else
            if(ctr3%6 == 0)
                printf("As an overall,%s and %s are SWEETHEARTS with one another.\n",str,str2);

            }
    else
    if(choice==2){                                              //this solves for the 2nd problem
        printf("Please enter a string(DNA).\n");
        scanf(" %[^\n]s",&str3);
        printf("Please enter a shorter string(DNA).\n");
        scanf(" %[^\n]s",&str4);
        i=0;
        flag=0;
        ctr=0;
        m=0;
        while(str4[m]!='\0'){
            while(str3[i]!=0){
                if((str4[m]&&str4[m+1])==(str3[i]&&str3[i+1]))
                    flag=1;
            }
        }
    }
    else                                                                //this exits my problem
    if(choice==3)
        printf("You choose to exit instead.\n");
    }while(choice != 3);




return 0;

}
