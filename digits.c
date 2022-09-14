/* Digit counter. 
 * Counts the occurence of each digit from zero to <input>. Results are stored in a file.
 * Graphing the results with GNUPlot gives some cool results.
 * John Soupir - version 1.0, Sept 2022
 */

//Include libs
#include <stdio.h>
#include <stdlib.h> 

//File for storing results. This is faster than printing and redirecting in the shell.
FILE *resultOut;

//Main 
int main(int argc, char **argv){

    //Usage
    if(argc != 2){
    printf("This program counts the occurrences of each digit (0-9) starting at zero and ending at <end-number>\n\n");
    printf("USAGE: %s <end-number>\n",argv[0]);
    printf("EXAMPLE: %s 10\n",argv[0]);
    printf("OUTPUT: is of the form: \n <current number> <zeros in current> <zeros running total> <ones in current> <ones running total> ... <nines in current> <nines running total> \n");
    return 1;
    } 
    
    //Define ints
    int num,temp,digit,count,rem;
    //Array to store count of each digit in the current number 
    int digitCount[10]={0};    
    //Array to keep the running total for each digit
    int runningTotal[10]={0};
    //Read first argument, it will be the ending number
    int input=atoi(argv[1]);
    //Initialize to zero
    num=0;
    digit=0; 
    count=0;
    temp=num;
    //Open file in append mode
    resultOut=fopen("digitCount.dat","a"); 
    
    //Counting loop. Runs once for each number until end.
    //Runs for each number in range
    for(num=0;num<=input;num++){
   	//Runs for each digit (0-9) counting occurrences
	for(digit=0;digit<=9;digit++){
	    count=0;
	    temp=num;
    	    //Count digit in current number
	    while(temp>0){
		//Find least significant digit using modulo 10. 
        	rem=temp%10;
		//If this is the digit we are seeking, add to the count.
        	if(rem==digit) count++;
        	//Drop the least significant digit. (Pushes the decimal place over, and integer division will drop the decimal.)
		temp/=10;
		//Now we loop again and check the next digit.
    		}
	    //Store count of current digit
	    digitCount[digit]=count;
	    //Add to running count
    	    runningTotal[digit]+=count;
	}

	//Print results to file and/or standard out
	
	//Uncomment printf lines to print results to the terminal. 
	//Warning: doing so slows down the program	
	
	//printf("Num: %d",num);
	fprintf(resultOut,"%d",num);
	
	for(int i=0;i<=9;i++){
	//printf(" %d",digitCount[i]);
	//printf(" %d",runningTotal[i]);
	fprintf(resultOut," %d",digitCount[i]);
	fprintf(resultOut," %d",runningTotal[i]);
	}
	
	//printf("\n");
	fprintf(resultOut,"\n");
    }
    printf("Completed calculations to %d.\n",input);
    printf("Results placed in digitCount.dat\n");
    //Close result file
    fclose(resultOut);
    return 0;
}
