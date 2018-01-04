//I declare upon my honor that I made this mp by myself.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    float curmon[3]={20000,20000,20000},bankmon=100000, bet[3]={1,1,1};;//"curmon" is a variable for current money of a player; "bankmon" is a variable for the current money of the banker,Bet[] is used as the variable holding the bets
    int player[3]={0,1,2}, numbplayers=3,guess[3]={2,2,2}, i, a, rsum, r1, r2,resp=1,endgame=0, sumbets;//player[i] is the variable used as a flag that as long as it equals to i, it will loop; numbplayers is used as a counter for the number of players,guess[i] is a variable that stores the guesses, i is the number used for index, a is for display purposes and for pinpointing on which player the iteration is running, rsum is the sum of random numbers, r1 and r2 is the variable for the rolled dices, resp is response when being asked to continue,sumbets is the sum of the bets.
    srand((unsigned int)time(NULL));
    while(numbplayers>1){//My biggest loop is to test whether there is still TWO or more players playing, if not, the game will terminate.
        sumbets=0;//initialization for when I loop
        r1 = rand() %6 +1;
        r2 = rand() %6 +1;
        rsum=r1+r2; //sum of the two random numbers
        printf("%i\n",rsum);//printing of the rsum
        printf("\n\nPlease guess the sum of the two rolled dices.\n", a);
        for (i=0;i<3;i++){//'For' is a loop which iterates a specific number of times. I have decided to use "for loop" to drastically shorten my code since it was previously 300+ lines and also since I already know how many times I want it to iterate. Although, I am still using nested loops within the code.Sorry sir if I wasn't supposed to use the 'for' loop or the array.
            bet[i]=1;//initialization of bet & to erase the previous stored bet.
            a=i+1;//player number
            if(player[i]==i){// Here, I have used player[i] as a flag. If it doesn't equal to the variable i it will skip the entire process.
                printf("\n\nIt is now player %i's turn. \n", a);
                printf("Your current money is now P %.2f \n", curmon[i]);
                do{//This is for getting the guesses of each. I have error trapped it to be not be lower than two since the lowest sum of two dices is two and not higher than twelve since the highest sum of two dices is twelve.
                    if (guess[i]<2 || guess[i]>12)
                        printf("Your guess is invalid, The sum cannot be lower than two or higher than twelve\n");//To specifically tell the user where his input
                    printf("Please enter a guess\n");
                    scanf("%i", &guess[i]);
                }while (guess[i]<2 || guess[i]>12);
                do{// Here, I am getting the bets of each.
                    if (curmon[i]==100)//if the current money of the player reaches one hundred, It will skip this process since the player is already supposedly out of the game.
                        break;
                    else if (bet[i]>curmon[i] || curmon[i]-bet[i]<100){//Error trap so that bets cannot exceed the current money
                        printf("You cannot bet that much money \n");
                        printf("Your bet is %.2f. It must not exceed your current money and at least a hundred must be left\n", bet[i], curmon[i]);
                    }
                    else if (bet[i]<=0)//No negative bets
                        printf("Invalid bet\n");
                    printf("Please enter the amount of your bet\n");//To specifically tell the user where his input
                    scanf("%f", &bet[i]);
                }while (bet[i]>curmon[i] || bet[i]<=0 || curmon[i]-bet[i]<100);// repeat while the above error traps are done
                if (rsum==7 && guess[i]==7 || rsum==11 && guess[i]==11){
                    sumbets=sumbets+2*bet[i];
                }
                else{
                    sumbets=sumbets+bet[i];
                }
            }
        }
        while (sumbets > bankmon-10000){//error trap if the sum of bets is greater than the capital of the banker AND STILL leaving the banker with 10,000
            sumbets=0;//initialization
            printf("The total sum of your bets which is %i exceeds or has the potential to exceed the capital of the banker, please re-enter your bets.\n", sumbets);
            for (i=0;i<3;i++){//For loop to iterate for each player
                if(player[i]==i)//an error trap that skips a player that has either given up or has reached the 100th limit.
                {
                a=i+1;
                    do{ //The same as above but done to specifically leave the banker with at least 10000
                        printf("Player %i, please enter another amount\n",a);
                        if (curmon[i]==100)//To specifically tell the user where his input
                            break;
                        else if (bet[i]>curmon[i] || curmon[i]-bet[i]<100)
                            printf("You cannot bet that much money \n");
                        else if (bet[i]<=0)//To specifically tell the user where his input
                            printf("Invalid bet\n");
                        printf("Please enter the amount of your bet\n");
                        scanf("%f", &bet[i]);
                    }while (bet[i]>curmon[i] || bet[i]<=0 || curmon[i]-bet[i]<100);
                    if (rsum==7 && guess[i]==7 || rsum==11 && guess[i]==11)//I am getting the sum of bets for an error trap later which anticipates the 7 and 11 guesses of each player
                        sumbets=sumbets+2*bet[i];//if it is a 7 or 11 I assume it is correct for the error trap later
                    else
                        sumbets=sumbets+bet[i];//if it isnt a 7 or 11 I just normally add it
                }
            }
        }
        system("cls");// Clear Screen. Purely aesthetic and cleanliness
        for (i=0;i<3;i++){//For loop to iterate for each player
            if(player[i]==i)//To check if player is still playing. If not, this is skipped
            {
                a=i+1;//For display purposes
                if (rsum==7 && guess[i]==7 || rsum==11 && guess[i]==11)//special case in which 7 or 11 is selected
                    {
                        printf("Congratulations Player %i has guessed the sum of the two dices and since it is %i, your bet is doubled\n", a, rsum);
                        curmon[i]=curmon[i]+2*bet[i];//We double the bet since it is a 7 or 11 and add it to the current players
                        bankmon=bankmon-2*bet[i];//We double the bet since it is a 7 or 11 and subtract it from the bankers money
                        printf("Player %i's current money is now P %.2f and the banker's money is now P %.2f \n",a , curmon[i], bankmon);
                    }
                else if (guess[i]==rsum)//If the player has gotten it right
                    {
                        printf("Congratulations Player %i has guessed the sum of the two dices which was %i\n",a, rsum);
                        curmon[i]=curmon[i]+ bet[i];//we add the bet from the current players money
                        bankmon=bankmon- bet[i];//we subtract the bet from the banker
                        printf("Player %i's current money is now P %.2f and the banker's money is now P %.2f \n",a , curmon[i], bankmon);
                    }
                else if (guess[i]!=rsum)//This is for when the player cannot guess the sum of the dices
                    {
                        printf("Sorry, but Player %i couldn't guess the sum of the two dices which was %i\n", a, rsum);
                        curmon[i]=curmon[i]- bet[i];//we subtract the bet from the current players money
                        bankmon= bankmon + bet[i]; //we add the bet to the banker
                        printf("Player %i's current money is now P %.2f and the banker's money is now P %.2f \n",a , curmon[i], bankmon);
                    }
                if (curmon[i]==100)//This tests if the current money is equal to  100.
                    {
                    player[i]=4;// This is to change the value of player[i] so that the program will skip the part of player [i] once he has reacher 100 or voluntarily stopped.
                    numbplayers=numbplayers-1;//To decrease the number of players playing since the player that has reached 100 will automatically be disqualified.
                    printf("Game Over for Player %i\n", a);
                    }
            }
        }
        if (bankmon==10000)//If the bankers money is equal to 10,000 the program will end
        {
            printf("The banker's money has dwindled down to 10,000. The banker has lost. \n", a);
            break;
        }
        if (numbplayers<2)//If the number of players is less than 2 the program will automatically end
        {
            printf("There is only one player left, the game is terminated\n", a);
            break;
        }
        for (i=0;i<3;i++)//For loop to iterate for each player when checking the responses of each.
        {
            if(player[i]==i)//This is an error trap to ask only those still part of the game
            {
                a=i+1;//player number
                do//To get a response from the player
                {
                    if (resp < 1 || resp >2)//Error trap in which it gets only 1 or 2 no other numbers
                        printf(" Invalid response ");
                    printf("\nPlayer %i, Do you wish to continue? Press 1 for yes and 2 for no.\n",a);
                    scanf("%i", &resp);
                }while (resp < 1 || resp >2);
                if (resp==2)//If the response is no, it will end the program
                {
                    printf("Player %i has quit the game\n",a);
                    player[i]=4;// This is to change the value of player[i] so that the program will skip the part of player [i] once he has reacher 100 or voluntarily stopped.
                    numbplayers=numbplayers-1;//I decrease the number of players as part of error trapping.
                }
                if (resp==1)//If the response is yes, it will let the player the program still play.
                {
                printf("Player %i has decided to continue the game\n",a);
                }
            system("cls");//Clear screen. For aesthetic purposes and cleanliness .
            }
        }
    }
    return 0;
}

