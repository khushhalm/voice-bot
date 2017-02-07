String voice;
int
motora1 = 8,
motora2 = 9,
motorb1 = 10,
motorb2 = 11;
//--------------------------Call A Function-------------------------------//
void allstop() {
  digitalWrite(motora1, LOW);
  digitalWrite(motora2, LOW);
  digitalWrite(motorb1, LOW);
  digitalWrite(motorb2, LOW);
  digitalWrite(13, LOW);  
}
void backward() {
  digitalWrite(13, HIGH);
  digitalWrite(motora1, HIGH);
  digitalWrite(motora2, LOW);
  digitalWrite(motorb1, HIGH);
  digitalWrite(motorb2, LOW);
  delay(3000);
  allstop();
}
void forward() {
  digitalWrite(13, HIGH);
  digitalWrite(motora1, LOW);
  digitalWrite(motora2, HIGH);
  digitalWrite(motorb1, LOW);
  digitalWrite(motorb2, HIGH);
  delay(3000);
  allstop();
}
void right() {
  digitalWrite(13, HIGH);
  digitalWrite(motora1, LOW);
  digitalWrite(motora2, HIGH);
  digitalWrite(motorb1, HIGH);
  digitalWrite(motorb2, LOW);
  delay(1000);
  allstop();
}
void left() {
  digitalWrite(13, HIGH);
  digitalWrite(motora1, HIGH);
  digitalWrite(motora2, LOW);
  digitalWrite(motorb1, LOW);
  digitalWrite(motorb2, HIGH);
  delay(1000);
  allstop();
}
//-----------------------------------------------------------------------//
void setup() {
  Serial.begin(9600);
  Serial.println("Khushhal Maheshwari");
  pinMode(13, OUTPUT);
  pinMode(motora1, OUTPUT);
  pinMode(motora2, OUTPUT);
  pinMode(motorb1, OUTPUT);
  pinMode(motorb2, OUTPUT);
}
//-----------------------------------------------------------------------//
void loop() {
  while (Serial.available()) { //Check if there is an available byte to read
    delay(10); //Delay added to make thing stable
    char c = Serial.read(); //Conduct a serial read
    if (c == '#') {
      break; //Exit the loop when the # is detected after the word
    }
    voice += c; //Shorthand for voice = voice + c
  }
  if (voice.length() > 0) {
    Serial.println(voice);
    //-----------------------------------------------------------------------//
    //----------Control Multiple Pins/ LEDs----------//
    if (voice == "*stop") {
      allstop(); //Turn Off All Pins (Call Function)
    }
    else if (voice == "*all off") {
      allstop(); //Turn On  All Pins (Call Function)
    }

    //----------Turn On One-By-One----------//
    else if (voice == "*forward") {
      forward();
    }
    else if (voice == "*backward") {
      backward();
    }
    else if (voice == "*right") {
      right();
    }
    else if (voice == "*left") {
      left();
    }
    //-----------------------------------------------------------------------//
    voice = "";
  }
  Serial.println("superiorbots.com");
} //Reset the variable after initiating
