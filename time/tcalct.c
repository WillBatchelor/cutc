#include <stdio.h>
#include <time.h>

int main () {
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

return(0);
}
