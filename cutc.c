//C Units of Time Calculator
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <time.h>

int split_t_strt(char ts_arg)
{
// Will come from argv[1]
    char token_list[20][20];
    char* context = NULL;
    const char s[2] = ":";
    char* token = strtok_r(argv[1], s, &context);
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

}
int main(int argc, char* argv[]) 
{ 

  
	int ret;
	struct tm info;
	char buffer[80];
	info.tm_hour = 23;
	info.tm_min = 30;
	int uts = 15;
	int uts_min = uts * 6;

	info.tm_min += uts_min;

	ret = mktime(&info);
if( ret == -1 ) {
	printf("Error: unable to make time using mktime\n");
} else {
	strftime(buffer, sizeof(buffer), "%H:%M", &info );
	printf("%s", buffer);
}

	return 0; 
}
