#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[])
{
	struct tm t_strt;
	int ret;
	char hr_val[2];
	char min_val[2];
	
	memset (&t_strt, '\0', sizeof (struct tm));

	strptime (argv[1], "%H:%M", &t_strt);


	ret = mktime(&t_strt);
if( ret == -1 ) {
	printf("Error: unable to make time using mktime\n");
} else {
	strftime(hr_val, sizeof(hr_val), "%H", &t_strt);
	strftime(min_val, sizeof(min_val), "%M", &t_strt);
	printf("\nThe hour value is: %s\nThe minutes value is: %s", hr_val, min_val);  
}
	return (0);
}
