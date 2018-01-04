#include <stdio.h>
int main(){
	int i,x, choice,cnt=1,a;//cnt=counter for number of words, a= my second index for palindrome
	char word[30], not=0,extra;//word=the string to be inputted by the user; not=flag for when it is not a palindrome
    system("color 0B");//aesthetic
	do{
		printf("\n\t\t\tMenu\n\t1.Palindrome \n\t2.String Reversal \n\t3.Count words\n\t4.Exit\n");//Menu
		printf("\n\tWhat would you like me to solve? Please press the number of your choice. ");
		scanf("%d",&choice);

		if(choice == 1){//Choice 1, solves Palindrome
            system("cls");
			printf("\n\tPlease enter a string and I shall determine whether it is a palindrome (including multiple word palindromes). \n\t");
			scanf(" %[^\n]s", word);//Gets input string

			for(i=0; word[i]!='\0'; i++){//For loop to find the index of the last variable where i'll start comparting
			}
			a=i;//Initialization
			i=0, not=0;
			for(--a; a>i; a--){//loop for comparing the individual characters. I stop when it a is greater than i since it means that I have already compared the two halves of the string and continuing it will be futile since it obviously is already equal lest the loop would have ended because of the 'break' option.
                if (word[i]== ' '){//when it is a MULTIPLE WORD PALINDROME such as 'was it a cat I saw' it skips the space to compare only characters.
                i++;
                }
                if (word[a]==' '){
                    a--;
                }
				if (word[i]==word[a]){
					i++;
				}

				else{
					not=1;//flag for when it isn't equal
					break;
				}
			}
			if (not==1)
				printf("\n\tIt is not a palindrome\n");
			else if (not==0)
				printf("\n\tIt is a palindrome\n");
		}

        else//Choice 2, solves reverse of string
		if(choice == 2){
		    system("cls");
			printf("\tPlease enter a string and I shall reverse it\n\t");
			scanf(" %[^\n]s",word);//gets string input from the user
            cnt=0;
			for(i=0,cnt=0; word[i]!='\0'; i++){
			}
			a=0;
			printf("\n\t");//prints a space for consistency
			for(--i;i>=a;i--){//From the index of the last character we decrement it while we increment another variable and exchange them a little similar to what we did in fibonacci
				extra=word[a]; //extra is a place holder as we exchange them
				word[a]=word[i];
				word[i]=extra;
                a++;
            }
            printf("\n\t%s\n",word);
        }

		else//Choice 3, counts the words
		if(choice == 3){
            system("cls");
            printf("\n\tI will count the number of words\n\t");
            scanf(" %[^\n]s", word);//gets input from the user once he presses enter
            cnt=0;//initialization
			for(i=0; word[i]!='\0'; i++){//This iterates until the last character of the input of the user
				if(word[i]!=' ' && word[i+1]==' '){//For every character with a space after it, the code considers it a word and incements cnt
					cnt++;
				}
			}

			if (word[i-1]!=' '){//This is an error trap that if the last line is not a space, it adds 1 to the number of words for it was not counted above
                cnt++;
			}
            if (cnt==1)//To avoid grammatical errors, I seperated it. But it ultimately displays how many words I have inputted.
			printf("\n\tThere is 1 word \n", cnt);
			else
			printf("\n\tThere are %i words \n", cnt);
		}
		else
        if (choice!=4)//For when a stubborn user chooses items not part of the choices
			printf("\n\tIt is not one of the choices\a");
	}while(choice!=4);
	return 0;
}
