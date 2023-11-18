#include<iostream>
#include<sys/wait.h>
#include<unistd.h>
#include<cstring>
using namespace std;


int main(){
char*input=new char[100];
bool isRunning=true;
int result=-1;
while(isRunning){
cout<<"enter command : ";
cin.getline(input,100,'\n');
if(strcmp(input,"exit")!=0){
char* com=new char[100];
com=strtok(input," ");
char* arg[100];
int count=0;

while(com){
arg[count]=com;
com=strtok(NULL," ");
count++;
}

pid_t child;
child=fork();
if(child==0){
if(execvp(arg[0],arg)==-1){
cout<<"INVALID"<<endl;
}
}else{
wait(NULL);
}
}else{
cout<<"PROGRAM EXITED"<<endl;
isRunning=false;
break;
}
}
}







