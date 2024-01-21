//C Units of Time Calculator
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <time.h>


int main(int argc, char* argv[]) 
{ 
// Split hour and minute digits from CL argument
    char token_list[20][20];
    char* context = NULL;
    const char s[2] = ":";
    char* token = strtok_r(argv[1], s, &context);
    int num_tokens = 0; 

	while (token != NULL){
	    strcpy(token_list[num_tokens], token); 
	    num_tokens++;
	    token = strtok_r(NULL, s, &context);
	}
	// Type casting hours minutes and UT variables to calculate with later 	
int t_strt_hr = atoi(token_list[0]);
int t_strt_min = atoi(token_list[1]);
int uts = atoi(argv[2]);

// Calculate End Time by adding minutes converted from UTs to Start Time
	int ret;
	struct tm info;
	char t_end[80];
	info.tm_hour = t_strt_hr;
	info.tm_min = t_strt_min;
	int uts_min = uts * 6;

	info.tm_min += uts_min;

	ret = mktime(&info);
if( ret == -1 ) {
	printf("Error: unable to make time using mktime\n");
} else {
	//Print Inputs and Outputs
	strftime(t_end, sizeof(t_end), "%H:%M", &info );
	printf("\nStart Time: %s:%s\n---\nUTs: %s\n---\nEnd Time: %s",token_list[0], token_list[1], argv[2], t_end);
}

	return 0; 
}
