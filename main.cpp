#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <time.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <dlfcn.h>
#include <unistd.h>

bool w_file(char* path,char* data){
	FILE * fp = fopen(path, "w");
	if(fp == NULL)  
        {  
                perror("open error");  
                return false;  
        }
int len = strlen(data);

for(int i=0; i<len;i++)  
        {  
                if(fputc(data[i],fp) == EOF)  
                {  
                        perror("fputc error");  
                        return false;  
                }  
        }  
	fclose(fp);
return true;
}

static void * r(void* age){
	long s = (long)age;
	char buff[200000]={0}; //localhost  size
	recv(s,buff,200000,0);
	char name[50]={0};
	char json[200000] ={0};
	bool fuck = false;
	char path[250]={0};
	char l[]="/root/amazeui-2.4.2/tools/tasks/config/";



	for(int i=0,ii=0;i<200000;i++){

		if(!fuck){
			if(buff[i]=='|' || buff[i]=='\0'){
				fuck = true;
				continue;
			
			}
			name[i]=buff[i];
		}else{
			if(buff[i]=='\0'){
				break;
			}
			json[ii++]=buff[i];
		}
		
	}
sprintf(path,"%s%s.json",l,name);

	w_file(path,json);
	printf("TIME:\r\n%s\r\njson:\r\n%s",name,json);

char cmd[500]={0};
sprintf(cmd,"/root/node-v0.12.7-linux-x64/bin/gulp customize --type \"%s\" --path ./config/%s.json",name,name);
printf("%s\r\n",cmd);
	system(cmd);
char cmd1[500]={0};
sprintf(cmd1,"zip -r /root/amazeui-2.4.2/dist/%s.zip /root/amazeui-2.4.2/dist/%s",name,name);
	system(cmd1);

char cmd2[500]={0};
sprintf(cmd2,"mv /root/amazeui-2.4.2/dist/%s.zip /home/wwwroot/lnmp/domain/hyyyp.com/web/tmp/%s.zip",name,name);
	system(cmd2);
	send(s,"on",3,0);
	
	//printf("%s\n",buff );
	close(s);
}
int main(void){
	int s = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(s==-1)
	{
		printf("Socket Create Error = 1\n");
		return 0;
	}
	sockaddr_in SrvAddr;
	SrvAddr.sin_family = AF_INET;
	SrvAddr.sin_port = htons(1117);
	SrvAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	if (bind(s,(sockaddr*)&SrvAddr,sizeof(SrvAddr)) == -1)
	{
		printf("ServerAddr bind Error = 2`\n");
		exit(2);
	}
	if(listen(s,SOMAXCONN)==-1)
	{
		printf("Socket listen Error = 3\n");
		exit(3);
	}
	socklen_t len = sizeof(sockaddr);
	while(1)
	{
		sockaddr ConnAddr;
		int ConnSock=accept (s,(sockaddr*)&ConnAddr,&len) ;
		if (ConnSock == -1 )
		{
			close(ConnSock);
			continue ;
		}
		pthread_t id;
		pthread_create(
			&id, 
			NULL,
			r,
			(void*)ConnSock			
		);
	}
	system("ls");
	return 0;
}
