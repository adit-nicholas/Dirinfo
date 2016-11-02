#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

int listdir(char path[256] ){
  DIR * dir = opendir(path);
  printf("Files\n");
  struct dirent *info;
  info = readdir(dir);
  while (info != NULL){
    if (info -> d_type != DT_DIR){
      printf("%s \n", info -> d_name);
 
    }
    else{
      printf("Directory %s \n", info ->d_name);
    }
    info = readdir(dir);  
  }
  
  closedir(dir);
  return 0;
}

int main(){
  char path[256] = ".";
  listdir(path);
  return 0;
}
