//I declare upon my honor, that I made this mp by myself
#include <stdio.h>
int largest(int,int,int);//declaring function for finding the largest among 3 numbers
void series(int);//function for displaying n numbers in a series
int power(int,int);//raising numbers to a certain number
int base(int);//this is to find the decimal equivalent of a base
int main(){
	int choice, n1, n2, n3,i=0,ans,check, pow, sum, ten, base8, rem, ctr;//n1-n3=variables for storing three integers, n1 in option 2 is the number of numbers in the series to be displayed, n1 in option 3 is for
	char word[30], not=0;
    system("color 0B");
	do{//This is the menu
		printf("\n\t\t\tMenu\n\t1.Largest \n\t2.Series\n\t3.Base 8 to Decimal\n\t4.Exit\n");//Menu
		printf("\n\tWhat would you like me to solve? Please press the number of your choice. ");
		scanf("%d",&choice);

		if(choice == 1){//Solves which of the numbers are greater
			printf("\n\tPlease enter three numbers.\n");
			scanf("\t%i\t%i\t%i", &n1, &n2, &n3);//can be a negative
			ans=largest(n1,n2,n3);//calling a function for displaying n numbers in a series
			printf("\n\tThe largest among them is %i\n",ans);
		}

     	else
		if(choice == 2){//displays n numbers in a series
			do{
			printf("\n\tPlease enter a positive number\n\t");
			scanf(" %i", &n1);
			} while(n1<1);
			series(n1);
       }
		else//converts base 8 to decimal
		if(choice == 3){
            do{
                do{
                    printf("\n\tPlease enter a number in base 8.\n");
                    scanf("%i", &n1);
                }while (n1<0);
                check=checker(n1);//A function to check whether it is truly a base 8
                if (check==0)
                    printf("\n\tThat is not a number in base 8\n");
            } while (check==0);
            printf("\n\t%i in decimal is ",n1);
			sum=base(n1);//calling a function for the conversion
			printf(" %i",sum);//
		}
		else
        if (choice!=4)//For when a stubborn user chooses items not part of the choices
			printf("\n\tIt is not one of the choices\a");
	}while(choice!=4);
	return 0;
}
int largest (int n1, int n2, int n3){//defining a function for finding the largest among 3 numbers
int big=0;
    if (n1>n2)
        big=n1;
    else
        big=n2;
    if (big<n3)
        big=n3;
    return big;
}
void series(int n1){//defining a function for displaying n numbers in a series
    int ctr=1, mult4=1, mult7=1,ans,numb=4;
    printf("\n\tThe first %i number/s in the series is: ",n1);
    while (ctr<=n1){
        if (ctr%2!=0){
            ans=numb*mult4;
            mult4++;
            printf("%i ",ans);
        }
        else
        if (ctr%2==0){
            ans=numb*mult4;
            printf("%i ",ans);
            mult4--;
            if (numb==7)
                numb=4;
            else if(numb==4)
                numb=7;
            if (ctr%4==0)
                mult4=mult4+2;
        }
    ctr++;
    }
}
int checker(int n1){//defining a function that checks whether the user has input a non base8 number
    int ten=1, check=1;
    float r=0;
    for(ten=1;ten*10<=n1;ten=ten*10);
    while (ten>=1){
        r=n1/ten;
        if (r>7){
            check=0;
            break;
        }
        n1=n1-r*ten;
        ten=ten/10;
    }
    return check;
}
int power(int a, int b){//defining a function for raising a number to a number
    int ans=1;
    for(;b>0;b--)
    ans = ans * a;
    return ans;
}
int base(int n1){//converting base8 to decimal
    int sum, ten, rem, ctr,base;
    sum=0;
    ten=10;
    ctr=0;
    while(n1>0){
        rem=n1%ten;
        base=power(8,ctr);
        sum=sum+rem*base;
        ctr++;
        n1=(n1-rem)/10;
    }
    return sum;
}
