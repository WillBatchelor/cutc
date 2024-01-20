// C program to demonstrate the 
// functioning of the atoi() function 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
int main() 
{ 
  // Will come from argv[1]
    char t_strt[] = "09:45";
    char token_list[20][20];
    char* context = NULL;
    const char s[2] = ":";
    char* token = strtok_r(t_strt, s, &context);
    int num_tokens = 0; //Inted to token list. We will append to the list

	while (token != NULL){
	    strcpy(token_list[num_tokens], token); // Copy to token list
	    num_tokens++;
	    token = strtok_r(NULL, s, &context);
	}
	// Type casting hours and minutes variables to calculate with later 	
int t_strt_hr = atoi(token_list[0]);
int t_strt_min = atoi(token_list[1]);


	printf("Hour variable is %d \n", t_strt_hr);  
	printf("Minute variable is %d \n", t_strt_min);

	return 0; 
}
