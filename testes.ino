#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "RP2040_PWM.h"

#define _PWM_LOGLEVEL_        3

#define buzz 0
#define e1 2
#define e2 3
#define e3 4
#define e4 5
#define r1 14
#define r2 15
#define r3 16
#define r4 17
#define pwm1 18//NUMEROS DA PORTA GPIO
#define pwm2 19//NUMEROS DA PORTA GPIO
#define pwm3 20//NUMEROS DA PORTA GPIO
#define pwm4 21//NUMEROS DA PORTA GPIO


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Endereço I2C do display OLED
#define OLED_ADDR 0x3C

// Define o tamanho do display, 128x64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

RP2040_PWM* PWM1;
RP2040_PWM* PWM2;
RP2040_PWM* PWM3;
RP2040_PWM* PWM4;



int SampTime = 50; //50 micro segundos
int l, fl, fr, r; 
float frequency=20000;
float dutycycle;

// Funções para leitura dos sensores
int readl() {
  int luz, val = 0;
  luz = analogRead(r1);  
  digitalWrite(e1, HIGH);
  delayMicroseconds(SampTime);
  val = analogRead(r1);
  digitalWrite(e1, LOW);
  return val = val - luz;
}

int readfl() {
  int luz, val = 0;
  luz = analogRead(r2);  
  digitalWrite(e2, HIGH);
  delayMicroseconds(SampTime);
  val = analogRead(r2);
  digitalWrite(e2, LOW);
  return val = val - luz;
}

int readfr() {
  int luz, val = 0;
  luz = analogRead(r3);  
  digitalWrite(e3, HIGH);
  delayMicroseconds(SampTime);
  val = analogRead(r3);
  digitalWrite(e3, LOW);
  return val = val - luz;
}

int readr() {
  int luz, val = 0;
  luz = analogRead(r4);  
  digitalWrite(e4, HIGH);
  delayMicroseconds(SampTime);
  val = analogRead(r4);
  digitalWrite(e4, LOW);
  return val = val - luz;
}

void setup() {
  // Configura os pinos
  pinMode(buzz, OUTPUT);//buzz
  pinMode(e1, OUTPUT);//e1
  pinMode(r1, INPUT);//r1
  pinMode(e2, OUTPUT);//e2
  pinMode(r2, INPUT);//r2
  pinMode(e3, OUTPUT);//e3
  pinMode(r3, INPUT);//r3
  pinMode(e4, OUTPUT);//e4
  pinMode(r4, INPUT);//r4
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(pwm3, OUTPUT);
  pinMode(pwm4, OUTPUT);

  // Inicializa o display OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("Falha ao inicializar o OLED"));
    for(;;);
  }

  display.clearDisplay();
  display.setTextSize(1); // Tamanho do texto pequeno
  display.setTextColor(SSD1306_WHITE); // Cor do texto

  PWM1 = new RP2040_PWM(pwm1, 20000, 0);
  PWM2 = new RP2040_PWM(pwm2, 20000, 0);
  PWM3 = new RP2040_PWM(pwm3, 20000, 0);
  PWM4 = new RP2040_PWM(pwm4, 20000, 0);
}

void loop() {

  dutycycle=60;
  
  PWM1->setPWM(pwm1, frequency, dutycycle);
  PWM4->setPWM(pwm4, frequency, dutycycle);
  PWM2->setPWM(pwm2, frequency, 0);
  PWM3->setPWM(pwm3, frequency, 0); 

  delay(3000);
  
  PWM1->setPWM(pwm1, frequency, 0);
  PWM4->setPWM(pwm4, frequency, 0);
  PWM2->setPWM(pwm2, frequency, dutycycle);
  PWM3->setPWM(pwm3, frequency, dutycycle); 
  
  delay(3000);
  /*
  // Lê os valores dos sensores
  l = readl();
  fl = readfl();
  fr = readfr();
  r = readr();

  // Limpa o display
  display.clearDisplay();

  // Primeira linha com os nomes dos sensores
  display.setCursor(0, 0);
  display.println("l");
  display.setCursor(32, 0);
  display.println("fl");
  display.setCursor(64, 0);
  display.println("fr");
  display.setCursor(96, 0);
  display.println("r");

  // Segunda linha com os valores dos sensores
  display.setCursor(0, 16);
  display.println(l);
  display.setCursor(32, 16);
  display.println(fl);
  display.setCursor(64, 16);
  display.println(fr);
  display.setCursor(96, 16);
  display.println(r);

  // Atualiza o display
  display.display();

  // Aguarda 2 segundos antes de atualizar novamente
  delay(2000);*/



}
