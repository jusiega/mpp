void setup() {
  // put your setup code here, to run once:
  SerialUSB.begin(921600);
}

void loop() {
  // put your main code here, to run repeatedly:

  //int x=1939;
  //SerialUSB.write("AEEEEEAEAEEEEEEEE\n");
  //SerialUSB.println(x,DEC);//prosty konwerter uad na usb println łamie tekst ale ten czyta całymi stringami
  //ale wyrzuci liczbę jako wartość
  //odczytać z dowolnego wejścia analogowego zobaczycie że one są caly czas aktwne
  //SerialUSB.println(val,DEC);
  //map --1023 =3.3 volt
  //fajna funkcja trim
  //fajna funkcja equals
  if (SerialUSB.readStringUntil('\n')=="Kowalski analiza")//tak jak jesgt teraz trzeba wysyłać new line terminated
  {
    int val=analogRead(A0);
    SerialUSB.print(double(val)/1023.*3.3,DEC);
    SerialUSB.write(" V\n");
  }
  //bardziej ambitne:
  //mamy komunikacje to teraz zrobmy ze wypisze kiedy poprosimy
  //jest funkcja sprawdzajaca czy cos jest


}
