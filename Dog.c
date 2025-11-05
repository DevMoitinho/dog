#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	if(argc < 2){
		printf("Too few arguments. %s must recive at least 2 arguments.\n", argv[0]);
	}else if(argc == 3){
		
		if(strcmp("-n",argv[2]) == 0){
			char path[] = "./";
			strcat(path, argv[1]);
			int file = open(path, O_RDONLY);
			char buffer[2048];
			int br = read(file, buffer, sizeof(buffer));
			if(br == -1){
				close(file);
				return 1;
			}
			close(file);
			int line = 1;
			for(int i = 0; i<strlen(buffer);i++){
				if(buffer[i] == '\n'){
					printf("\n%d ", line++);
				}else{
					printf("%c",buffer[i]);
				}
			}
	
		}

	}else{

		char path[] = "./";
		strcat(path, argv[1]);
		int file = open(path, O_RDONLY);
		char buffer[2048];
		int br = read(file, buffer, sizeof(buffer));
		if(br == -1){
			close(file);
			return 1;
		}
		close(file);
		printf(buffer);


	}
	printf("\n");
}
