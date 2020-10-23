#include <sys/types.h>
#include <direct.h>
#include <unistd.h>
int main()
{
    DIR * dir;
    struct dirent * ptr;
    int i;
    dir = opendir("mnt/");
    while((ptr = readdir(dir)) != NULL)
    {
        printf("d_name : %s\n", ptr->d_name);
    }
    closedir(dir);
}
