//define button input pins
const int demoButton = 4;
const int resetButton = 3;
const int startButton = 2;
//set LED pins
const int greenLight = 9;
const int amberLight = 8;
const int redLight = 7;
//variables
int demoState = 0;
int resetState = 0;
int startState = 0;
int timerActive = 0;
int demoActive = 0;
int resetActive = 0;

//time variables
int timeActivated = 0;
int timeFinish = 0;
int demoLength = 10000;
int previousSeconds = 0;
int currentSeconds = 0;

void setup()
{
  //initialise Serial connection
  Serial.begin(9600);
  //set button pin states
  pinMode(demoButton, INPUT);
  pinMode(resetButton, INPUT);
  pinMode(startButton, INPUT);
  //set LED pin states
  pinMode(greenLight, OUTPUT);
  pinMode(amberLight, OUTPUT);
  pinMode(redLight, OUTPUT);
}

void loop()
{
  checkButtonStates();
  assignMode();
  if(demoActive > 0){
   demo(); 
  }
  if(resetActive > 0){
   resetTimer(); 
  }
  if(timerActive > 0){
   startTimer(); 
  }
}

void checkButtonStates()
{
  //check demo button
  demoState = digitalRead(demoButton);
  //check reset button
  resetState = digitalRead(resetButton);
  //check start button
  startState = digitalRead(startButton);
}

void assignMode()
{
 if (demoState == HIGH){
  demoActive = 1; 
 }
 if (resetState == HIGH){
   resetActive = 1;
 }
 if (startState == HIGH){
  resetTimer();
  startTimer(); 
 }
}

void resetTimer()
{
  //reset all modes
  timerActive = 0;
  demoActive = 0;
  resetActive = 0;
  //reset time variables
  timeActivated = 0;
  //turn off all LEDs
  digitalWrite(greenLight, LOW);
  digitalWrite(amberLight, LOW);
  digitalWrite(redLight, LOW);
}

void demo()
{
  if(timeActivated = 0){
   startTimer(); 
  }
}

void startTimer()
{
  timeActivated = millis();
}

int secondsRemaining(int startTime, int totalTime)
{
  int timeElapsed = (millis() - startTime);
}

void switchLeds(int totalTime, int timeLeft)
{
  
}
