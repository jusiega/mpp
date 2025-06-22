void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
}

//najgorszy jest dilej
unsigned long delta()
{

}
char chtoupper(char ch)
{
    return static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
}
std::string ml (char a)
{
  char A=chtoupper(a);
  if (A='A') return "01";
  if (A='B') return "1000";
  if (A='C') return "1010";
  if (A='D') return "100";
  if (A='E') return "0";
  if (A='F') return "0010";
  if (A='G') return "110";
  if (A='H') return "0000";
  if (A='I') return "00";
  if (A='J') return "0111";
  if (A='K') return "101";
  if (A='L') return "0100";
  if (A='M') return "11";
  if (A='N') return "10";
  if (A='O') return "111";
  if (A='P') return "0110";
  if (A='Q') return "1101";
  if (A='R') return "010";
  if (A='S') return "000";
  if (A='T') return "1";
  if (A='U') return "001";
  if (A='V') return "0001";
  if (A='W') return "011";
  if (A='X') return "1001";
  if (A='Y') return "1011";
  if (A='Z') return "1100";
}

std::string w2m(std::string zdanie)
{
  std::string m{};
  m+="10101";
  //blablabla
  m+="000111000";
  m+="01010";

}

//kropka -- jeden unit, kreska -- trzy units
//interelemet gap -- one unit, gap betqween letters -- 3 units
// gap between words -- seven units formerly five
int morse2time(std::string mor)
{
  
}

void morse(std::string x)
{

}

void loop() {
  // put your main code here, to run repeatedly:

}
