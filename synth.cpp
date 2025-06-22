#define _USE_MATH_DEFINES
#include<iostream>
#include <cmath>
#include<vector>
#include<string.h>
#define π M_PI

const double A_REF=440.;//reference pitch [Hz]


const double fmap(int p)//get frequency from note index
{
    if (p<0) return 0.;
    else return A_REF*pow(2.,(p-49.)/12.);
}

int nmap(char* NT)//return note index from input note name
{
    std::string nt=NT;
    if (nt=="0" || nt=="p") return -1; //pauza
    
    if (nt=="A0")   return 0;
    if (nt=="A#0")  return 1;
    if (nt=="B0")   return 2;
    if (nt=="C0")   return 3;
    if (nt=="C#0")  return 4;
    if (nt=="D0")   return 5;
    if (nt=="D#0")  return 6;
    if (nt=="E0")   return 7;
    if (nt=="F0")   return 8;
    if (nt=="F#0")  return 9;
    if (nt=="G0")   return 10;
    if (nt=="G#0")  return 11;
    
    if (nt=="A1")   return 12;
    if (nt=="A#1")  return 13;
    if (nt=="B1")   return 14;
    if (nt=="C1")   return 15;
    if (nt=="C#1")  return 16;
    if (nt=="D1")   return 17;
    if (nt=="D#1")  return 18;
    if (nt=="E1")   return 19;
    if (nt=="F1")   return 20;
    if (nt=="F#1")  return 21;
    if (nt=="G1")   return 22;
    if (nt=="G#1")  return 23;

    if (nt=="A2")   return 24;
    if (nt=="A#2")  return 25;
    if (nt=="B2")   return 26;
    if (nt=="C2")   return 27;
    if (nt=="C#2")  return 28;
    if (nt=="D2")   return 29;
    if (nt=="D#2")  return 30;
    if (nt=="E2")   return 31;
    if (nt=="F2")   return 32;
    if (nt=="F#2")  return 33;
    if (nt=="G2")   return 34;
    if (nt=="G#2")  return 35;

    if (nt=="A3")   return 36;
    if (nt=="A#3")  return 37;
    if (nt=="B3")   return 38;
    if (nt=="C3")   return 39;
    if (nt=="C#3")  return 40;
    if (nt=="D3")   return 41;
    if (nt=="D#3")  return 42;
    if (nt=="E3")   return 43;
    if (nt=="F3")   return 44;
    if (nt=="F#3")  return 45;
    if (nt=="G3")   return 46;
    if (nt=="G#3")  return 47;

    if (nt=="A4")   return 48;
    if (nt=="A#4")  return 49;
    if (nt=="B4")   return 50;
    if (nt=="C4")   return 51;
    if (nt=="C#4")  return 52;
    if (nt=="D4")   return 53;
    if (nt=="D#4")  return 54;
    if (nt=="E4")   return 55;
    if (nt=="F4")   return 56;
    if (nt=="F#4")  return 57;
    if (nt=="G4")   return 58;
    if (nt=="G#4")  return 59;   
    else return -2137; 
}

std::vector<double>



const int N=6000000;
double buf[N]{}; //buffer
const double fs=44100.;

double synthfunction(int p, double t)
{
    return sin(t*fmap(p)*2.*π);
}

int main()
{ 
    double dB=-12.;//decibel volume
    double vol=pow(10.,dB/20.);//volume (keep between 0 and 1 to avouid clippyn')

    char notebuffer[]="A2 p E3 G3";

    
    std::vector <double> timebuffer={1,1.2,3,4};
    char* note;
    note=strtok(notebuffer," ");
    //std::cout<<note<<"\n";
    //std::cin.get();
    int j=0;
    for (int i=0; i<N; i++) 
    {
        double t=double(i)/fs;
        if (t>=timebuffer[j]) 
        {
            j++;
            if (j>=timebuffer.size()) goto quit;
            else note=strtok(NULL," ");
            //std::cout<<note<<"\n";
            //std::cin.get();
        }
        int p=nmap(note);
        //std::cout<<p<<"\n";
        //std::cin.get();
        buf[i]=synthfunction(p, t);//troche klika głośno trzeba wygładzić 
    }
    quit:;

    std::cout<<vol<<"\n";
    //std::cin.get();
    FILE *pipeout;
    pipeout = popen("ffmpeg -y -f f64le -ar 44100 -ac 1 -i -  -f s16le - mesydż.wav", "w");
    fwrite(buf, sizeof(double), N, pipeout);
    pclose(pipeout);
}


//jakby to pisać w arduiono no to trzeba rozważyc że trzeba całość tekstu najwierw wczytać albo tekstu albo zapisu muzycznego bez znaczenia więc pełny bufor i jazda z nim na wyjście powinien być bufor wyjściowy uzupełniany asynchronicznie i opróżniany co przerwanie systemowe albo inaczej odliczony prawidłowo czas lepiej nie millisami bo szybko się zderzymy ze ścianą bufor wyjściowy tak ze 128 będzie duży uzupełniany periodycznie pilnując żeby nie wyprzedzić znacznika czytającego. 