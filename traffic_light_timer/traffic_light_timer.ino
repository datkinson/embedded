//set LED pins
const int greenLight = 9;
const int amberLight = 8;
const int redLight = 7;

const int runtime = 60;
int timeSeconds;
int previousSeconds;
int timeRemaining;

int timerActive = 1;

void setup()
{
  Serial.begin(9600);
  //set LED pin states
  pinMode(greenLight, OUTPUT);
  pinMode(amberLight, OUTPUT);
  pinMode(redLight, OUTPUT);
}

void loop()
{
  checkButtons();
  if(timerActive = 1)
  {
   timer(); 
  }
}

void checkButtons()
{
  
}

void timer()
{
  timeSeconds = millis() / 1000;
  if(previousSeconds != timeSeconds)
  {
    previousSeconds = timeSeconds;
    timeRemaining = runtime - timeSeconds;
    printStats();
    processLeds(runtime, timeRemaining);
  }
}

void printStats()
{
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
