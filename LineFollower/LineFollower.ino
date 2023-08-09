int RMP=5;
int RMN=6;
int LMP=11;
int LMN=10;

int SLLL=19;
int SLL=18;
int SL=17;
int SML=16;
int SMR=15;
int SR=14;
int SRR=13;
int SRRR=12;


void setup() {
  // put your setup code here, to run once:
pinMode(SRRR,INPUT);
pinMode(SRR,INPUT);
pinMode(SR,INPUT);
pinMode(SMR,INPUT);
pinMode(SML,INPUT);
pinMode(SL,INPUT);
pinMode(SLL,INPUT);
pinMode(SLLL,INPUT);
pinMode(RMP,OUTPUT);
pinMode(RMN,OUTPUT);
pinMode(LMP,OUTPUT);
pinMode(LMN,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(SLLL)== HIGH && digitalRead(SLL)== LOW && digitalRead(SL)== LOW && digitalRead(SML)== LOW && digitalRead(SMR)== LOW && digitalRead(SR)== LOW &&digitalRead(SRR)== LOW && digitalRead(SRRR)== LOW )
{Sharp_Leftt();
Serial.println("SLLL Left");
}
else if(digitalRead(SLLL)== HIGH && digitalRead(SLL)== HIGH && digitalRead(SL)== LOW && digitalRead(SML)== LOW && digitalRead(SMR)== LOW && digitalRead(SR)== LOW &&digitalRead(SRR)== LOW && digitalRead(SRRR)== LOW )
{Sharp_Leftt();
Serial.println("SLL Left");
}
else if(digitalRead(SLLL)== LOW && digitalRead(SLL)== HIGH && digitalRead(SL)== LOW && digitalRead(SML)== LOW && digitalRead(SMR)== LOW && digitalRead(SR)== LOW &&digitalRead(SRR)== LOW && digitalRead(SRRR)== LOW )
{Sharp_Left();
Serial.println("SL Left");
}
else if(digitalRead(SLLL)== LOW && digitalRead(SLL)== HIGH && digitalRead(SL)== HIGH && digitalRead(SML)== LOW && digitalRead(SMR)== LOW && digitalRead(SR)== LOW &&digitalRead(SRR)== LOW && digitalRead(SRRR)== LOW )
{Sharp_Left();
Serial.println("S Left");
}
else if(digitalRead(SLLL)== LOW && digitalRead(SLL)== LOW && digitalRead(SL)== HIGH && digitalRead(SML)== LOW &&digitalRead(SMR)== LOW && digitalRead(SR)== LOW &&digitalRead(SRR)== LOW && digitalRead(SRRR)== LOW )
{Left();
Serial.println(" Left");
}
else if(digitalRead(SLLL)== LOW && digitalRead(SLL)== LOW && digitalRead(SL)== HIGH && digitalRead(SML)== HIGH &&digitalRead(SMR)== LOW && digitalRead(SR)== LOW &&digitalRead(SRR)== LOW && digitalRead(SRRR)== LOW )
{Left();
Serial.println(" Left");
}
else if(digitalRead(SLLL)== LOW && digitalRead(SLL)== LOW && digitalRead(SL)== LOW && digitalRead(SML)== HIGH &&digitalRead(SMR)== LOW && digitalRead(SR)== LOW &&digitalRead(SRR)== LOW && digitalRead(SRRR)== LOW )
{forward();
Serial.println(" forward");
}
else if(digitalRead(SLLL)== LOW && digitalRead(SLL)== LOW && digitalRead(SL)== LOW && digitalRead(SML)== HIGH &&digitalRead(SMR)== HIGH && digitalRead(SR)== LOW &&digitalRead(SRR)== LOW && digitalRead(SRRR)== LOW )
{forward();
Serial.println(" forward");
}
else if(digitalRead(SLLL)== LOW && digitalRead(SLL)== LOW && digitalRead(SL)== LOW && digitalRead(SML)== LOW &&digitalRead(SMR)== HIGH && digitalRead(SR)== LOW &&digitalRead(SRR)== LOW && digitalRead(SRRR)== LOW )
{forward();
Serial.println(" forward");
}
else if(digitalRead(SLLL)== LOW && digitalRead(SLL)== LOW && digitalRead(SL)== LOW && digitalRead(SML)== LOW &&digitalRead(SMR)== HIGH && digitalRead(SR)== HIGH &&digitalRead(SRR)== LOW && digitalRead(SRRR)== LOW )
{RIGHT();
Serial.println(" RIGHT");
}
else if(digitalRead(SLLL)== LOW && digitalRead(SLL)== LOW && digitalRead(SL)== LOW && digitalRead(SML)== LOW &&digitalRead(SMR)== LOW && digitalRead(SR)== HIGH &&digitalRead(SRR)== LOW && digitalRead(SRRR)== LOW )
{ RIGHT();
Serial.println("RIGHT");
}
else if(digitalRead(SLLL)== LOW && digitalRead(SLL)== LOW && digitalRead(SL)== LOW && digitalRead(SML)== LOW &&digitalRead(SMR)== LOW && digitalRead(SR)== HIGH &&digitalRead(SRR)== HIGH && digitalRead(SRRR)== LOW )
{ SHARP_RIGHT();
Serial.println("SHARP RIGHT");
}
else if(digitalRead(SLLL)== LOW && digitalRead(SLL)== LOW && digitalRead(SL)== LOW && digitalRead(SML)== LOW &&digitalRead(SMR)== LOW && digitalRead(SR)== LOW &&digitalRead(SRR)== HIGH && digitalRead(SRRR)== LOW )
{ SHARP_RIGHT();
Serial.println("SHARP RIGHT");
}
else if(digitalRead(SLLL)== LOW && digitalRead(SLL)== LOW && digitalRead(SL)== LOW && digitalRead(SML)== LOW &&digitalRead(SMR)== LOW && digitalRead(SR)== LOW &&digitalRead(SRR)== HIGH && digitalRead(SRRR)== HIGH)
{ SHARP_RIGHTT();
Serial.println("SHARP RIGHTT");
}
else if(digitalRead(SLLL)== LOW && digitalRead(SLL)== LOW && digitalRead(SL)== LOW && digitalRead(SML)== LOW &&digitalRead(SMR)== LOW && digitalRead(SR)== LOW &&digitalRead(SRR)== LOW && digitalRead(SRRR)== HIGH)
{ SHARP_RIGHTT();
Serial.println("SHARP RIGHTT");
}

else if(digitalRead(SLLL)== HIGH && digitalRead(SLL)== HIGH && digitalRead(SL)== HIGH && digitalRead(SML)== HIGH &&digitalRead(SMR)== HIGH && digitalRead(SR)== HIGH &&digitalRead(SRR)== HIGH && digitalRead(SRRR)== HIGH)
{ STOP ();
Serial.println("STOP");
}
else
{forward();
Serial.println("forward");
}
}
void Left()
{digitalWrite(RMP,HIGH);
 digitalWrite(RMN,LOW);
 digitalWrite(LMP,HIGH);
 digitalWrite(LMN,LOW);
 delay(80);
}

void Sharp_Left()
{digitalWrite(RMP,HIGH);
 digitalWrite(RMN,LOW);
 digitalWrite(LMP,HIGH);
 digitalWrite(LMN,LOW);
 delay(40);
}

void Sharp_Leftt()
{digitalWrite(RMP,HIGH);
 digitalWrite(RMN,LOW);
 digitalWrite(LMP,HIGH);
 digitalWrite(LMN,LOW);
 delay(60);
}

void RIGHT()
{digitalWrite(RMP,LOW);
 digitalWrite(RMN,HIGH);
 digitalWrite(LMP,LOW);
 digitalWrite(LMN,HIGH);
 delay(80);
}
 void SHARP_RIGHT()
{digitalWrite(RMP,LOW);
 digitalWrite(RMN,HIGH);
 digitalWrite(LMP,LOW);
 digitalWrite(LMN,HIGH);
 delay(40);
}

void SHARP_RIGHTT()
{digitalWrite(RMP,LOW);
 digitalWrite(RMN,HIGH);
 digitalWrite(LMP,LOW);
 digitalWrite(LMN,HIGH);
 delay(60);
}

void forward()
{digitalWrite(RMP,HIGH);
 digitalWrite(RMN,LOW);
 digitalWrite(LMP,LOW);
 digitalWrite(LMN,HIGH);
 delay(80);
}

void STOP()
{digitalWrite(RMP,LOW);
 digitalWrite(RMN,LOW);
 digitalWrite(LMP,LOW);
 digitalWrite(LMN,LOW);
}
