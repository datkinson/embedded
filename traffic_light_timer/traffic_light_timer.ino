//set button pins
const int startButton = 3;
const int stopButton = 4;
//set LED pins
const int greenLight = 9;
const int amberLight = 8;
const int redLight = 7;

int startButtonState = 0;
int stopButtonState = 0;
const int runtime = 900;
int startTime;
int timeSeconds;
int previousSeconds;
int timeRemaining;

boolean timerActive = false;

void setup()
{
  Serial.begin(9600);
  //set LED pin states
  pinMode(greenLight, OUTPUT);
  pinMode(amberLight, OUTPUT);
  pinMode(redLight, OUTPUT);
  allLedsOff();
  timerActive = 0;
//  delay(2000);
}

void loop()
{
  checkButtons();
  if(timerActive = true)
  {
   timer(); 
  }
}

void checkButtons()
{
  startButtonState = digitalRead(startButton);
  stopButtonState = digitalRead(stopButton);
  if(startButtonState == HIGH)
  {
    startTime = millis() / 1000;
    timerActive = true;
  }
  if(stopButtonState == HIGH)
  {
    timerActive = false;
  }
}

void timer()
{
  timeSeconds = millis() / 1000;
  if(previousSeconds != timeSeconds)
  {
    previousSeconds = timeSeconds;
    timeRemaining = (startTime + runtime) - timeSeconds;
    printStats();
    processLeds(runtime, timeRemaining);
  }
}

void printStats()
{
  Serial.print("startState: ");
  Serial.print(startButtonState);
  Serial.print(" stopState: ");
  Serial.println(stopButtonState);
  Serial.print("Time:  ");
  Serial.print(timeSeconds);
  Serial.print(" Target: ");
  Serial.println(runtime);
  Serial.print("RTime: ");
  Serial.print(timeRemaining);
}

void finished()
{
  Serial.println("Finished!");
  allLedsOff();
  delay(500);
  setRed();
  delay(500);
}

void processLeds(int targetTime, int currentTime)
{
  Serial.print(" Colour: ");
  if(currentTime > targetTime - (targetTime / 3))
  {
    Serial.println("Green");
    setGreen();
  }else
  {
    if(currentTime > (targetTime / 3))
    {
      Serial.println("Amber");
      setAmber();
    }else
    {
      if(currentTime > 0)
      {
        Serial.println("Red");
        setRed();
      }else
      {
        finished();
      }
    }
  }
}

void allLedsOff()
{
  //turn off all LEDs
  digitalWrite(greenLight, LOW);
  digitalWrite(amberLight, LOW);
  digitalWrite(redLight, LOW); 
}
void setGreen()
{
  allLedsOff();
  digitalWrite(greenLight, HIGH);
}
void setAmber()
{
  allLedsOff();
  digitalWrite(amberLight, HIGH);
}
void setRed()
{
  allLedsOff();
  digitalWrite(redLight, HIGH);
}
