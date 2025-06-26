#include <OneWire.h>
#include <DallasTemperature.h>


// Piny podłączenia docelowo spójne z arduino mkr
#define termo 3
#define led 6
#define głośniczek A0
#define guziczek 0//chyba jest to wszystko spójne z KiCadem
#define głośniczekwrite analogWrite
#define dacrange 1023.

#define esp32 //na takim se testuję osobiście ale testuję bez temperatury i bez guziczka
#ifdef esp32
#define led LED_BUILTIN
#define głośniczekwrite dacWrite
#define głośniczek 25
#define termo 4
#define dacrange 255.
#endif

// Inicjalizacja OneWire i biblioteki temperatury
OneWire ow(termo);
DallasTemperature ts(&ow);

double termoread()
{
    ts.requestTemperatures(); // rozpocznij pomiar
    return static_cast<double>(ts.getTempCByIndex(0)); // pobierz temperaturę
}

#include<string>
#include<vector>
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
    return out;
}


std::vector<int> t2mt(std::string telegram,const bool KAAR=false, const bool literalny=false)
{
    std::vector<int> mt{};
    if(KAAR) mt.insert(mt.end(),{1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,0,0,0,0,0,0});//ATTENTION (`KA`)
    {
        telegram+='0';//paduje na koniec żeby móc przekazywac po dwa i nic nie stracić
        for(int i=0;i<telegram.size()-1;i++)
        {
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
    if(KAAR) mt.insert(mt.end(),{0,0,0,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0});//OUT (`AR`)
    return mt;
}

//long t1;
unsigned long t2=0;
unsigned long interval(bool update=1)
{
    unsigned long i=(unsigned long) (millis()-t2);
    if(update) t2=millis();
    return i;
}

double π=3.141592653589793238462643383279502884197169399375105820974944592307816406;
double spkrwave()
{
    return sin(double(micros())/1000.*300.);
}

int sound=1;
int light=1;

const int durationdot=50;//50 ms trwa kropa
void transmit(int state)
{
    interval();
    if (state==0)
    {
        while(interval(0)<durationdot)
        {
            digitalWrite(led,LOW*light);
            głośniczekwrite(głośniczek,int(dacrange/2.*(1.+0.977*double(state)*spkrwave()))*sound);
        }
        return;
    }
    else if (state==1)
    {
        while(interval(0)<durationdot)
        {
            digitalWrite(led,HIGH*light);
            głośniczekwrite(głośniczek,int(dacrange/2.*(1.+0.977*double(state)*spkrwave()))*sound);
        }
        return;
    }
}


void moorsing(std::vector<int> mesydż)
{
    for (int i=0;i<mesydż.size();i++)
    {
        transmit(mesydż[i]);
    }
}

void setup() 
{
    // put your setup code here, to run once:
    pinMode(led, OUTPUT);
    pinMode(głośniczek, OUTPUT);
    pinMode(guziczek, INPUT);
    pinMode(termo, INPUT);
    Serial.begin(921600);
    ts.begin();
}

unsigned long rest=10000;//w milisekundacj
int operationmode=0;//jaki tryb wariacie
//0: auto obydwa co czas rest
//1: na komendę obydwa (tutaj przez serial)
//2: auto światełko
//3: auto głośniczek
//4: na komendę światełko
//5: na komendę głos
//6: uśpij
//zmiana czasu rest komendą REST 100000 na przykład
double temp;

unsigned long TTTT=0;
unsigned long biginterval(bool update)
{
    unsigned long i=(unsigned long) (millis()-TTTT);
    if(update) TTTT=millis();
    return i;
}
void loop() 
{
    //temp=termoread();//w idealnym świecie
    temp=21.376192;//dla testów
    String in=Serial.readStringUntil('\n');
    if (in=="MODE 0")//tak jak jesgt teraz trzeba wysyłać new line terminated
    {
        Serial.write("MODE 0 APPLIED\n");
        operationmode=0;
        sound=1;
        light=1;
    }
    else if (in=="MODE 1")
    {
        Serial.write("MODE 1 APPLIED\n");
        operationmode=1;
        sound=1;
        light=1;
    }
    else if (in=="MODE 2")
    {
        Serial.write("MODE 2 APPLIED\n");
        operationmode=2;
        sound=0;
        light=1;
    }
    else if (in=="MODE 3")
    {
        Serial.write("MODE 3 APPLIED\n");
        operationmode=3;
        sound=1;
        light=0;
    }
    else if (in=="MODE 4")
    {
        Serial.write("MODE 4 APPLIED\n");
        operationmode=4;
        sound=0;
        light=1;
    }
    else if (in=="MODE 5")
    {
        Serial.write("MODE 5 APPLIED\n");
        operationmode=5;
        sound=1;
        light=0;
    }
    else if (in=="SLEEP")
    {
        Serial.write("SLEEPING\n");
        operationmode=6;
        sound=0;
        light=0;
    }
    //to służy do ustawiania okresu spoczynku
    else
    {
        std::string w=std::string(in.c_str());
        int l=w.size();
        if(l>=5)
        {
            if(w[0]=='R'&&w[1]=='E'&&w[2]=='S'&&w[3]=='T'&&w[4]==' ')
            {
                rest=0;
                for (int j=5;j<l;j++) rest+=int(w[j]-'0')*pow(10,l-j-1);
                Serial.write("REST SET TO ");
                Serial.print(rest,DEC);
                Serial.write("\n");
            }
        }
    }

    if (operationmode==0||operationmode==2||operationmode==3)
    {
        if(biginterval(0)>=rest) moorsing(t2mt("temperatura wynosi"+std::to_string(temp)+"stopni Celsjusza",1)), biginterval(1);
    }
    else if (operationmode==1||operationmode==4||operationmode==5)
    {
        if (in=="ANALIZA") moorsing(t2mt("temperatura wynosi"+std::to_string(temp)+"stopni Celsjusza",0));   
    }
}
