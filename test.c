#include <stdio.h>
#include <unistd.h>

int main()
{
    long openMax = sysconf(_SC_OPEN_MAX);
    printf("La valeur maximale du descripteur de fichiers est : %ld\n", openMax);
    
    return (0);
}