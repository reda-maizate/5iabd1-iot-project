

int inches = 0;

int cm = 0;

bool fermee;

int etatActuelValise = LOW;

int switchpin = 7;
int LED = 4;


long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void isPresent(int idObject){
	// measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(idObject, idObject);
  // convert to inches by dividing by 2.54
  
  if(cm < 311 && cm > 12){
  	bool isPresent = true;
    Serial.print("l'objet : ");
    Serial.print(idObject);
    Serial.println(" est présent dans la valise");
  }
  else {
    Serial.print("l'objet : ");
    Serial.print(idObject);
  	Serial.println(" est absent de la valise");
  }
}

bool isClosed(int photoValue){
  if(photoValue >= 900){
  	digitalWrite(LED, HIGH);
    Serial.println("Valise est fermee");
    return true;
  }
  digitalWrite(LED, LOW);
  Serial.println("Valise est ouverte");
  return false;
}

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(A5 ,INPUT);
  pinMode(switchpin, INPUT);
  Serial.begin(9600);
}

void loop(){
  etatActuelValise = digitalRead(switchpin);
  int photoValue = analogRead(A5);
  
  if(etatActuelValise == LOW){
  	Serial.println("La valise est eteinte");
  }
  else{
    Serial.println("La valise est alummée");
    if(isClosed(photoValue)){
      isPresent(8);
      isPresent(9);
      isPresent(10);
      isPresent(11);
    }
  }
  Serial.println("====================");
  Serial.println("====================");
  Serial.println("====================");
  delay(1000);
  
}




