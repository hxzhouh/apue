//
// Created by hxzhouh on 2020/11/25.
//

#include <dirent.h>
#include "apue.h"

void my_readdir(char name[256]);

int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2)
        err_quit("usage: ls directory_name");
    dp = opendir(argv[1]);
    if (dp == NULL)
        err_sys("can't open %s", argv[1]);
    while ((dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp->d_name);
        if (strcmp(dirp->d_name, ".") != 0 && strcmp(dirp->d_name, "..") != 0) {
            my_readdir(dirp->d_name);
        }
    }

    closedir(dp);
    exit(0);
}

void my_readdir(char *argv1) {
    DIR *dp;
    struct dirent *dirp;
    dp = opendir(argv1);
    if (dp == NULL)
        return;
    while ((dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp->d_name);
        if (strcmp(dirp->d_name, ".") != 0 && strcmp(dirp->d_name, "..") != 0) {
            my_readdir(dirp->d_name);
        }
    }
}