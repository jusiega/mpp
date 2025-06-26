//program do morsa
//wpisujemy gdzieś w mainie wypowiedź i dostajemy wav w kodzie morskim
//wymagany linuks i ffmpeg bo na windowsie nie ma pipeów w przynajmniej nie tak łatwo
//użycie w wypowiedzi `` do oznaczenia kawałka jest jak mors specjalny bez spacji np `SOS` albo `CQD` albo `KA` albo `AR` można se wpisać i jest bezprzerwowe

#define _USE_MATH_DEFINES
#include<iostream>
#include <cmath>
#include<vector>
#include<string>
#define π M_PI


std::vector<int> ml (std::string A)
{
    //std::string A=str_toupper(a);

    if (A[0]=='A'||A[0]=='a') return {0,1};
    if (A[0]=='B'||A[0]=='b') return {1,0,0,0};
    if (A[0]=='C'||A[0]=='c') return {1,0,1,0};
    if (A[0]=='D'||A[0]=='d') return {1,0,0};
    if (A[0]=='E'||A[0]=='e') return {0};
    if (A[0]=='F'||A[0]=='f') return {0,0,1,0};
    if (A[0]=='G'||A[0]=='g') return {1,1,0};
    if (A[0]=='H'||A[0]=='h') return {0,0,0,0};
    if (A[0]=='I'||A[0]=='i') return {0,0};
    if (A[0]=='J'||A[0]=='j') return {0,1,1,1};
    if (A[0]=='K'||A[0]=='k') return {1,0,1};
    if (A[0]=='L'||A[0]=='l') return {0,1,0,0};
    if (A[0]=='M'||A[0]=='m') return {1,1};
    if (A[0]=='N'||A[0]=='n') return {1,0};
    if (A[0]=='O'||A[0]=='o') return {1,1,1};
    if (A[0]=='P'||A[0]=='p') return {0,1,1,0};
    if (A[0]=='Q'||A[0]=='q') return {1,1,0,1};
    if (A[0]=='R'||A[0]=='r') return {0,1,0};
    if (A[0]=='S'||A[0]=='t') return {0,0,0};
    if (A[0]=='T'||A[0]=='s') return {1};
    if (A[0]=='U'||A[0]=='u') return {0,0,1};
    if (A[0]=='V'||A[0]=='v') return {0,0,0,1};
    if (A[0]=='W'||A[0]=='w') return {0,1,1};
    if (A[0]=='X'||A[0]=='x') return {1,0,0,1};
    if (A[0]=='Y'||A[0]=='y') return {1,0,1,1};
    if (A[0]=='Z'||A[0]=='z') return {1,1,0,0};

    if (A=="Ą"|| A=="ą") return {0,1,0,1};
    if (A=="Ć"|| A=="ć") return {1,0,1,0,0};
    if (A=="Ę"|| A=="ę") return {0,0,1,0,0};
    if (A=="Ł"|| A=="ł") return {0,1,0,0,1};
    if (A=="Ń"|| A=="ń") return {1,1,0,1,1};
    if (A=="Ó"|| A=="ó") return {1,1,1,0};
    if (A=="Ś"|| A=="ś") return {0,0,0,1,0,0,0};
    if (A=="Ż"|| A=="ż") return {1,1,0,0,1,0};
    if (A=="Ź"|| A=="ź") return {1,1,0,0,1};

    if (A[0]=='1') return {0,1,1,1,1};
    if (A[0]=='2') return {0,0,1,1,1};
    if (A[0]=='3') return {0,0,0,1,1};
    if (A[0]=='4') return {0,0,0,0,1};
    if (A[0]=='5') return {0,0,0,0,0};
    if (A[0]=='6') return {1,0,0,0,0};
    if (A[0]=='7') return {1,1,0,0,0};
    if (A[0]=='8') return {1,1,1,0,0};
    if (A[0]=='9') return {1,1,1,1,0};
    if (A[0]=='0') return {1,1,1,1,1};

    if (A[0]=='.') return {0,1,0,1,0,1};
    if (A[0]==',') return {1,1,0,0,1,1};
    if (A[0]=='\'') return {0,1,1,1,1,0};
    if (A[0]=='\"') return {0,1,0,0,1,0};

    if (A[0]==' ') return {-1};

    else return {2137};
}

std::vector<int> ms(char a)
{
    if (a=='0') return {0};
    if (a=='1') return {1};
    //if (a==' ') return {-1};
    else return {2137};
}

//kropka -- jeden unit, kreska -- trzy units
//interelemet gap -- one unit, gap betqween letters -- 3 units
// gap between words -- seven units formerly five
std::vector<int> m2t(std::vector<int> mor)
{
    std::vector<int> out{};
    for (int i=0;i<mor.size();i++)
    {
        if (mor[i]==1) out.push_back(1),out.push_back(1),out.push_back(1),out.push_back(0);
        if (mor[i]==0) out.push_back(1),out.push_back(0);
        if (mor[i]==-1) out.push_back(0);
        //if (mor[i]==-1) out.push_back(0),out.push_back(0),out.push_back(0),out.push_back(0),out.push_back(0),out.push_back(0);// sześć bo siódma pauza jest po literce poprzedzającej
        //else out.push_back(0);
    }
    //out.pop_back();//nie kasować tego
    return out;
}

//void coutvec(std::vector <int> x)
//{
//    std::cout<<"{";
//    for (int i=0;i<x.size();i++)
//    {
//        std::cout<<x[i]<<", ";
//    }
//    std::cout<<"}";
//}

std::vector<int> t2mt(std::string telegram,const bool KAAR=false, const bool literalny=false)
{
    std::vector<int> mt{};
    if(KAAR) mt.insert(mt.end(),{1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,0,0,0,0,0,0});//ATTENTION (`KA`)
    //if (literalny)//literalny czyli daje sekwencje zero jeden
    //{
    //    for(int i=0;i<telegram.size();i++)
    //    {
    //        //std::cout<<"literka: "<<telegram[i]<<"\nmors";
    //        //coutvec(ml(telegram[i]));//problem tu
    //        //std::cout<<"\npadded";
    //        //coutvec(m2t(ml(telegram[i])));
    //        //std::cin.get();
    //
    //        std::vector<int> x=m2t(ms(telegram[i]));
    //        mt.insert(mt.end(),x.begin(),x.end());//wstawiam literke
    //    }
    //}
    //else
    {
        telegram+='0';//paduje na koniec żeby móc przekazywac po dwa i nic nie stracić
        for(int i=0;i<telegram.size()-1;i++)
        {
            //std::cout<<"literka: "<<telegram[i]<<"\nmors";
            //coutvec(ml(telegram[i]));//problem tu
            //std::cout<<"\npadded";
            //coutvec(m2t(ml(telegram[i])));
            //std::cin.get();
            if(telegram[i]!=' '&&telegram[i]!='`')
            {
                std::vector<int> x=m2t(ml({telegram[i],telegram[i+1]}));//przekazuje po dwa żeby działały polskie znaczki
                mt.insert(mt.end(),x.begin(),x.end());
                mt.insert(mt.end(),{0,0});//space between letters -- three units (2 here +1 from interletter spacing)
            }
            else if (telegram[i]=='`')
            {
                i++;
                while(telegram[i]!='`'&& i<telegram.size()-1)
                {
                    std::vector<int> x=m2t(ml({telegram[i],telegram[i+1]}));//przekazuje po dwa...
                    mt.insert(mt.end(),x.begin(),x.end());
                    //bez spacjowania międzyliterowego, zostaje spacja wewnątrzznakowa. spacja ' ' wewnątrz tych backticków bd miała jeden unit długości
                    i++;
                }
                mt.insert(mt.end(),{0,0});//wracam space between letters -- three units (2 here +1)

            }
            else
            {
                mt.insert(mt.end(),{0,0,0,0});//sapcja spacjowa space between words 7 units or 5 units (vintage) 3+4 here
            }
        }
    }
    if (mt.size()>1) mt.pop_back();//kasuje ostatniego który zawsze jest ciszą zgodnie z implementacjio m2t(), może być sygnał na samym końcu jak najbardziej jeszcze jak. może jednak nie istnieć jeśli mesydż to ``.
    if(KAAR) mt.insert(mt.end(),{0,0,0,0,1,0,1,1,1,0,1,0,1,1,1,0,1});//OUT (`AR`)
    return mt;
}

const int N=6000000;
double buf[N]{}; //buffer
const double fs=44100.;
const double unittime=0.05;//ile sekund trwa kropka (jednostka)
const int unitsamples=unittime*fs;//ile sampli trwa jednostka
int main()
{ 
    double dB=-12.;//decibel volume
    double vol=pow(10.,dB/20.);//volume (keep between 0 and 1 to avouid clippyn')
    //std::vector <int> signal={0,1,0,1,0,1,0,1,1,1,1,1};
    std::vector <int> signal=t2mt("`SOS   SOS` tu HMS titanic płyniemy na górę lodową odbiór");
    for (int i=0; i<signal.size(); i++) 
    {
        if(signal[i]==1)//condition
        {
            for (int j=0;j<unitsamples;j++)
            {
                buf[i*unitsamples+j]=vol*sin(double(i*unitsamples+j)*300.*2.*π/fs);//300hz sine
            }
        }
    }
    std::cout<<vol<<"\n";
    //std::cin.get();
    FILE *pipeout;
    pipeout = popen("ffmpeg -y -f f64le -ar 44100 -ac 1 -i -  -f s16le - mesydż.wav", "w");
    fwrite(buf, sizeof(double), N, pipeout);
    pclose(pipeout);
}



