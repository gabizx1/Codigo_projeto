//Programa: Sensor TCS3200 e led RGB
//Autor: MakerHero
 
//Pinos de conexao do modulo
const int s0 = 8;
const int s1 = 9;
const int s2 = 12;
const int s3 = 11;
const int out = 10;
 
//Pinos do led RGB
int pinoledverm = 2;
int pinoledverd = 3;
int pinoledazul = 4;
 
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
  pinMode(pinoledverm, OUTPUT);
  pinMode(pinoledverd, OUTPUT);
  pinMode(pinoledazul, OUTPUT);
  Serial.begin(9600);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
}
 
void loop()
{
  //Detecta a cor
  color();
  //Mostra valores no serial monitor

 //Verifica se a cor azul foi detectada
  if ((rred > intensidade) && (rblue < intensidade) && (rgreen < intensidade))
  {
    bool c = 0;
    if((0.6*rblue > rgreen)) // nao entra pois vermelho é maior que intensidade e menor que azul.
    {
      c = 1;
      Serial.println("Rosa");
      digitalWrite(pinoledverm, HIGH);
      digitalWrite(pinoledverd, HIGH);
      digitalWrite(pinoledazul, LOW); //Acende o led azul
    };
    if((rblue < 0.8 * rgreen) )
    {
      c = 1;
      Serial.println("Amarelo");
      digitalWrite(pinoledverm, HIGH);
      digitalWrite(pinoledverd, HIGH);
      digitalWrite(pinoledazul, LOW); //Acende o led azul

    };
    if ( c == 0 )
    {
    Serial.println("Vermelho");
    digitalWrite(pinoledverm, HIGH);
    digitalWrite(pinoledverd, HIGH);
    digitalWrite(pinoledazul, LOW); //Acende o led azul
    };
  }
  /*
  //Verifica se a cor vermelha foi detectada
  if ((rred> intensidade) && (rblue < intensidade) && (rgreen < intensidade))
    //if ((red < green) && (blue < green))// && red < lim)
    {
      Serial.println("Vermelho");
      digitalWrite(pinoledverm, LOW); //Acende o led vermelho
      digitalWrite(pinoledverd, HIGH);
      digitalWrite(pinoledazul, HIGH);
    };
 */
     if ((rblue > intensidade) && (rgreen < intensidade) && (rred > intensidade) && (0.6*rblue > rgreen)) // nao entra pois vermelho é maior que intensidade e menor que azul.
    {
      //c = 1;
      Serial.println("Rosa");
      digitalWrite(pinoledverm, HIGH);
      digitalWrite(pinoledverd, HIGH);
      digitalWrite(pinoledazul, LOW); //Acende o led azul
    };
  //Verifica se a cor azul foi detectada
  if ((rblue > intensidade) && (rgreen < intensidade) && (rred < intensidade))
  {
    bool a = 0;
    if((0.8*rgreen > rred))
    {
      a = 1;
      Serial.println("Ciano");
      digitalWrite(pinoledverm, HIGH);
      digitalWrite(pinoledverd, HIGH);
      digitalWrite(pinoledazul, LOW); //Acende o led azul
    };
    if((rgreen < 0.8 * rred) )
    {
      a = 1;
      Serial.println("Roxo");
      digitalWrite(pinoledverm, HIGH);
      digitalWrite(pinoledverd, HIGH);
      digitalWrite(pinoledazul, LOW); //Acende o led azul

    };
    if ( a == 0 )
    {
    Serial.println("Azul");
    digitalWrite(pinoledverm, HIGH);
    digitalWrite(pinoledverd, HIGH);
    digitalWrite(pinoledazul, LOW); //Acende o led azul
    };
  }
  
  

  if ((blue < 30) && (red < 30) && (green < 30))
  {
    Serial.println("Branco");
    digitalWrite(pinoledverm, HIGH);
    digitalWrite(pinoledverd, HIGH);
    digitalWrite(pinoledazul, LOW); //Acende o led azul
  };
 //Verifica se a cor verde foi detectada
  if ((rgreen > intensidade) && (rblue < intensidade) && (rred < intensidade))
  {
    bool b = 0;
    if((0.9*rblue > rred))
    {
      b = 1;
      Serial.println("Verde Mar Baitola");
      digitalWrite(pinoledverm, HIGH);
      digitalWrite(pinoledverd, HIGH);
      digitalWrite(pinoledazul, LOW); //Acende o led azul
    };
    if((rblue < 0.9 * rred) )
    {
      b = 1;
      Serial.println("desconhecida");
      digitalWrite(pinoledverm, HIGH);
      digitalWrite(pinoledverd, HIGH);
      digitalWrite(pinoledazul, LOW); //Acende o led azul

    };
    if ( b == 0 )
    {
    Serial.println("Verde");
    digitalWrite(pinoledverm, HIGH);
    digitalWrite(pinoledverd, HIGH);
    digitalWrite(pinoledazul, LOW); //Acende o led azul
    };
  }
  /*
  //Verifica se a cor verde foi detectada
  if ((rgreen > intensidade) )
      {
      Serial.println("Verde");
      digitalWrite(pinoledverm, HIGH);
      digitalWrite(pinoledverd, LOW); //Acende o led verde
      digitalWrite(pinoledazul, HIGH);
    };
*/
 /* if ((rgreen < 0.5) && (rred < 0.5) && (rblue < 0.5))// && green < lim)
  {
    Serial.println("Preto");
    digitalWrite(pinoledverm, HIGH);
    digitalWrite(pinoledverd, LOW); //Acende o led verde
    digitalWrite(pinoledazul, HIGH);
  };
*/
  /*if ((rblue > intensidade) && (rred > rgreen))
    //if(red<100)
    {
    Serial.println("Roxo");
    digitalWrite(pinoledverm, HIGH);
    digitalWrite(pinoledverd, LOW); //Acende o led verde
    digitalWrite(pinoledazul, HIGH);
    };*/
  Serial.print(rred);
  Serial.print("  ");
  Serial.print(rblue);
  Serial.print("  ");
  Serial.print(rgreen);
  Serial.print("  ");
  //Serial.print(Clear);
  //Serial.print("  ");
  Serial.println(intensidade);



  Serial.println();
 
  //Delay para apagar os leds e reiniciar o processo
  
  digitalWrite(pinoledverm, HIGH);
  digitalWrite(pinoledverd, HIGH);
  digitalWrite(pinoledazul, HIGH);
  delay(200);
}
 
void color()
{
  int Verm, Azu, Verd;
 // float rred, rgreen, rblue;
  //Rotina que le o valor das cores
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  //count OUT, pRed, RED
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  
  digitalWrite(s3, HIGH);
  //count OUT, pBLUE, BLUE
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  
  digitalWrite(s2, HIGH);
  //count OUT, pGreen, GREEN
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

  digitalWrite(s3, LOW);
  //count OUT, pClear, 0
  Clear = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

  rred=float(Clear)/float(red);
  rblue=float(Clear)/float(blue);
  rgreen=float(Clear)/float(green);
  intensidade = (rred+rblue+rgreen)/3;

  Verm = map((int)(rred*100),0,105,0,255);
  Verd = map((int)(rgreen*100),8,80,0,255);
  Azu = map((int)(rblue*100),0,84,0,255) ;
  //intensidade = map((int)(intens*100),0,84,0,255) ;
/*  Verm > 255? 255: Verm;
  Verd > 255? 255: Verd;
  Azu > 255? 255: Azu;
*/
  Serial.print("R ");
  Serial.print(Verm);
  Serial.print("  G ");
  Serial.print(Verd);
  Serial.print("  B ");
  Serial.print(Azu);
  Serial.print("  ");
  //Serial.print(Clear);
  //Serial.print("  ");
  Serial.print("   I ");
  Serial.println((Verm+Verd+Azu)/3);
}

