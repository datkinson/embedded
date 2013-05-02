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
  
}

void checkButtonStates()
{
  
}
