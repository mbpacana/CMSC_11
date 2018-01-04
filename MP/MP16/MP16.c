//I declare upon my honor that I made this mp by myself.
#include <stdio.h>

int main(){
	float sjudge[10], rjudge[10], tjudge[20], sum, suma=0;//sjudge= stadium judge's scores; rjduge= remote area judges scores; tjudge= the overall scores of the judges; sum=sum of the scores of the maximum and minimum for the entire array of scores for the average; suma= is the sum of total scores to be used in finding the average.
	int i=0,a, smin, smax, rmin, rmax;//i= used as index; a= used for display since the i is one less than the judges' actual number; smin, smax rmin,rmax are the indexes for storing the minimum/maximum scores given by the judges from the stadium and remote area.
    system ("color 0B");//For aesthetic purpose
    printf("This program will calculate the maximum scores and minimum scores given by both the judges on the remote area and stadium as well as the average scores of the gymnasts.\n");//Prompting the user of the function of the program
    printf("\nPlease input the scores of the judges on the stadium\n");//Tells the user specifically which judges' scores should be inputted

    do{//This is a do while loop for storing the data  given by the user for storing the judges' scores on the Stadium
        a=i+1;//For display purposes
        printf("What is the score of Judge %i in the stadium? ", a);
        scanf("%f", &sjudge[i]);
        while (sjudge[i]<1 || sjudge[i]>10){// Prompts user exactly what he has done wrong
            printf("\nA judge cannot give a score higher than 10 or lower than 0\n");
            printf("What is the score of Judge %i in the stadium? ", a);
        scanf("%f", &sjudge[i]);
        }
        i++;//increment of the index to move to another Judge
    }while (i<10);

    printf("\nPlease input the scores of the judges in the remote area\n");//Tells the user specifically which judges' scores should be inputted
    i=0;//Initialization of the index to start from Judge 1
    do{
        a=i+1;//For display purposes to pinpoint which judge contains the information(since there is no Judge 0)
        printf("What is the score of Judge %i in the remote area? ", a);
        scanf("%f", &rjudge[i]);
        while (rjudge[i]<1 || rjudge[i]>10){
            printf("\nA judge cannot give a score higher than 10 or lower than 0\n");
            printf("What is the score of Judge %i in the stadium? ", a);// Prompts user exactly what he has done wrong
            scanf("%f", &rjudge[i]);
        }
        i++;//increment of the index to move to another Judge
    }while (i<10);
    system ("cls");//For aesthetic purpose
    i = 1, smin = 0, smax=0, rmin=0, rmax=0;//initialization so as to not yield weird numbers
    do {//Finding of the min and max of both the judges on the stadium and remote venue all in one loop
        if (sjudge[i] < sjudge[smin])
            smin=i;
        if (sjudge[i] > sjudge[smax])
            smax=i;
        if (rjudge[i] < rjudge[rmin])
            rmin=i;
        if (rjudge[i] > rjudge[rmax])
            rmax=i;
			i++;//increment of the index to move to another judge
    } while(i<10);

    printf("\nIn the stadium, Judge/s %i ,", smin+1);//I found it tedious to have another array to store the max's and min's so I used loop to find duplicates of the max's and min's.
    i=0; //initialization of i to start at the first judge
    do { //Here my code finds which judges have given the same score
        if (sjudge[i] == sjudge[smin]){
            if (i!=smin)//This makes sure there is no repitition among the scores. It checks whether the index of the min is not equal to the index of the duplicate
                printf("%i ,", i+1);
        }
        i++;//increment of the index to move to another judge
    } while(i<10);
    printf(" gave the lowest score which is %.1f", sjudge[smin] );//prints the minimum score of the judge in the stadium

    i=0;
    printf("\nIn the stadium, Judge/s %i ,", smax+1);
    do {//Here my code finds which judges have given the same score
        if (sjudge[i] == sjudge[smax]){
            if (i!=smax)//This makes sure there is no repitition among the scores. It checks whether the index of the min is not equal to the index of the duplicate
                printf("%i ,", i+1);
        }
        i++;
    } while(i<10);//increment of the index to move to another judge
    printf(" gave the highest score which is %.1f \n\n", sjudge[smax]);//prints the maximum score of the judge in the stadium
    i=0;
    printf("\nIn the remote area, Judge/s %i ,", rmin+1);
    do {//Here my code finds which judges have given the same score
        if (rjudge[i] == rjudge[rmin]){
            if (i!=rmin)//This makes sure there is no repitition among the scores. It checks whether the index of the min is not equal to the index of the duplicate
                printf("%i ,", i+1);
        }
        i++;//increment of the index to move to another judge
    } while(i<10);
    printf(" gave the lowest score which is %.1f", rjudge[rmin] );//prints the minimum score of the judge in the remote area

    i=0;
    printf("\nIn the remote area, Judge/s %i ,", rmax+1);
    do {//Here my code finds which judges have given the same score
			if (rjudge[i] == rjudge[rmax]){
                if (i!=rmax)//This makes sure there is no repitition among the scores. It checks whether the index of the min is not equal to the index of the duplicate
                    printf("%i ,", i+1);
        }
        i++;//increment of the index to move to another judge
    } while(i<10);
    printf(" gave the highest score with a score of %.1f \n", rjudge[rmax]);//prints the maximum score of the judge in the remote area

    i=0;//Here,I find the lowest and highest scores among the minimums and maximums I have collected from the judges of the stadium and remote area
    if (rjudge[rmax] < sjudge [smax])
        sjudge[smax]= rjudge [rmax];
    if (rjudge[rmin] > sjudge [smin])
        sjudge[smin]= rjudge [rmin];
    sum=sjudge[smin]+sjudge[smax];
    i=0;
    while (i<10){//Here I store them all in one big array
        tjudge[i] = sjudge [i];
        tjudge[i+10] = rjudge [i];
        i++;
    }
    i=0;
    while (i<20){//Finding of the sum of the entire array
        suma=suma+tjudge[i];//
        i++;
    }

    suma=(suma-sum)/18;//Here is my computation of the average, excluding the max and min by subtracting their sum. I use 18 since excluded the judges who gave the max and min
    printf("\n\nThe average score of the gymnast is %.2f\a\a", suma);

	return 0;
}
