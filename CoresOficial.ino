//Programa: Sensor TCS3200 

 
//Pinos de conexao do modulo
const int s0 = 8;
const int s1 = 9;
const int s2 = 12;
const int s3 = 11;
const int out = 10;
 
//Variaveis cores
int red = 0;
int green = 0;
int blue = 0;
int Clear = 0;
float rred, rgreen, rblue, intensidade;
void color();
void setup()
{
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  Serial.begin(9600);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
}
 
void loop()
{
  //Detecta a cor
  color();

 //Verifica se a cor azul foi detectada
  if ((rred > rblue ) && (rred > rgreen)) Serial.println("Vermelho");
  
  //Verifica se a cor azul foi detectada
  if ((rblue > rgreen) && (rblue > rred)) Serial.println("Azul");

 //Verifica se a cor verde foi detectada
  if ((rgreen > rblue ) && (rgreen > rred)) Serial.println("Verde");

  delay(500);
}
 
void color()
{
  int Verm, Azu, Verd;
  //Rotina que le o valor das cores
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  delay(50);
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  
  digitalWrite(s3, HIGH);
  delay(50);
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  
  digitalWrite(s2, HIGH);
  delay(50);
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

  digitalWrite(s3, LOW);
  delay(50);
  Clear = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

  rred=float(Clear)/float(red);
  rblue=float(Clear)/float(blue);
  rgreen=float(Clear)/float(green);
  intensidade = (rred+rblue+rgreen)/3;

  Verm = map(int(rred*100),0,105,0,255);
  Verd = map(int(rgreen*100),8,80,0,255);
  Azu = map(int(rblue*100),0,84,0,255);

  Serial.print("R ");
  Serial.print(Verm);
  Serial.print("  G ");
  Serial.print(Verd);
  Serial.print("  B ");
  Serial.print(Azu);
  Serial.print("  ");
  Serial.print("   I ");
  Serial.println((Verm+Verd+Azu)/3);
  rred = float(Verm);
  rgreen = float(Verd);
  rblue = float(Azu);
  intensidade = float((Verm+Verd+Azu)/3);

}

