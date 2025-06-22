#include<string.h>
#include<stdio.h>
#include<iostream>


int main()
{
    //dziala
    char h[]="A0 B1";
    char* b;
    b=strtok(h, " ");
    std::cout<<b<<"\n";
    b=strtok(NULL, " ");
    std::cout<<b<<"\n";
    bool t=false;
    if (!strcmp(b,"B1")) t=true;
    std::cout<<t<<"\n";
    t=false;
    std::string k=b;
    if (k=="B1") t=true;
    std::cout<<t<<"\n";
}