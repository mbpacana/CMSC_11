//I declare upon my honor that I made this mp by myself.
#include <stdio.h>

int main(){
	int choice, m, cf, ctr, n, sum;//m is the number that is the nth perfect number, n is the number,cf is the candidate factor, choice is for which option the person would pick.
	do{//loop for the menu
		printf("\n\n\t\t\tMenu\n\t1. Germaine Primes\n\t2. Perfect numbers\n\t3. Exit\n");//the menu itself
		scanf("%d",&choice);

		if(choice == 1){//if the first choice was chosen it will compute for the first n Germain primes.
            system("cls");//clear screen for aesthetic purposes
            printf("\nYou have chosen option 1. I will now calculate the first n Germaine Primes.\n");
		    n=2,cf=2,ctr=0,m=1;//initialization for the program not to error in asking for the m. The ctr,n and cf must be initialized for when the option is looped again.
            do{//getting input from the user that is a positive number
                if (m<1)
                    printf("Please enter a positive number");
                printf("\nHow many of the first Germain Primes should be displayed? \n");
                scanf("%i",&m);
            }while(m<1);
            if (m==1)//To avoid errors in grammar such as "The first 1 Germain primes are"
                printf("The first Germain Prime is: ");
            else
                printf("The first %i Germain Primes are ", m);
            while (m!=ctr){// As long as the counter(for the number of germain primes) is not equal to the user input, it will loop.
                cf=2;//initialization of cf for when it loops again
                while(cf*cf<=n && n%cf!=0){//The while loop with a boolean expression that asks whether the cf is still lesser or equal than the square of n and if there is a cf that can divide n.  If it is the the cf increments.
                    cf++;
                }
                if(n%cf==0 && n!=2 || n==1){//Because I used the shortcut boolean expression above, this is the expression that makes sure all that goes through here are the non prime numbers.
                }
                else{
                    n=2*n+1;//This sets the n to another form and we test it whether it is prime again because that is the definition of a Germain Prime.
                    cf=2;// We initialize the cf to 2 to overwrite what we have done above.
                    while(cf*cf<=n && n%cf!=0){//The while loop with a boolean expression that asks whether the cf is still lesser or equal than the square of n and if there is a cf that can divide n.  If it is the the cf increments.
                        cf=cf+1;
                    }
                    if(n%cf==0 && n!=2 || n==1){//Because I used the shortcut boolean expression above, this is the expression that makes sure all that goes through here are the non prime numbers.
                        n=(n-1)/2;
                    }
                    else{
                        ctr++;//All the primes go here so definitely this is a germain prime and we increment the counter to tally the number of germain primes we have found
                        n=(n-1)/2;//we revert it back to its form
                        printf(" %i ", n);//We display it
                    }
                }
            n=n+1; //This increases the n to move to the next number to test if the next number is a Germain Prime
            }
        }
		else
		if(choice == 2){//If the choice chosen by the player is two, it will take the player here which is the code for the nth perfect number
            ctr=0, sum=1, m=1;//Here I initialized variables like m so that the error wont be displayed, the sum and ctr so that when the option is selected again, it wont accumulate,
            printf("\n I will now calculate the nth Perfect number.\n");
            do{//here I ask for input
                printf("\n%i\n",m);
                if (m<1)//here I explicitly state what the user has done wrong
                    printf("Please enter a positive number ");
                printf("\nWhat nth perfect number should be displayed? ");
                scanf("%i", &m);
            }while (m<1);//I did this so that the user can only input positive integers
            n=6;//I initialize this variable to 6 since I know 6 is the first perfect number
            while (m!=ctr){// I use THE LONG METHOD since our topic is nested loop and since the "SHORT METHOD" has the following loop holes: (120,2016,32640,1130816,523776) unless specifically error trapped
                sum=1;//I initialize the sum and cf so that when it iterates, it wont accumulate
                cf=2;
                while(cf*cf<=n){//Here, I find the candidate factors that is lower or equal to the number
                    if (n%cf==0){// Here I try to see if the candidate factor is the square so that whenever it is a square I can only add it once
                        if (cf*cf==n){
                            sum=sum+cf;
                        }
                    else{
                        sum=sum+cf+n/cf;
                    }
                }
            cf=cf+1;//To move to next cf
            }
            if(sum==n){//If the sum of the factors of the number is equal to the number than it is a perfect number. T
                ctr=ctr+1;
            }
            n=n+1;//To move to the next n
            }
            n=n-1;//To get to the nth Perfect number I need to subtract 1 since my program still adds 1 when it reaches the specific nth perfect number
            printf("\nThe Perfect number is %i\n", n);
        }
        else//If the user wants to end
		if(choice == 3){
			break;
		}
		else
			printf("It's not one of the choices!\n");
	}while(choice!=3);
	return 0;
}
