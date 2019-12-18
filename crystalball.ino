/* Crystal ball
 * An Arduino Sketch to make a prop crystal ball change colors
 */


int redPin = 9;    // LED connected to digital pin 9
int greenPin = 10;
int bluePin = 11;
int delayTime = 60;
int bottomValue = 0;
int topValue = 253;
int redValue = topValue;
int stepValue = 1;
int blueValue = bottomValue;
int greenValue = bottomValue;
int u = 2;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 
}


void setColor(int red, int green, int blue)
{
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);  
}

void loop() {
    
    if (topValue<=redValue) {
      u=1;
    } else if (topValue<=blueValue) {
      u=2;
    } else if (topValue<=greenValue) {
      u=3;
    }
    
    if (3==u) {
      redValue += stepValue;
      greenValue -= stepValue;
    } else if (1==u) {
      redValue -= stepValue;
      blueValue += stepValue;
    } else if (2==u) {
      blueValue -= stepValue;
      greenValue += stepValue;
    }

    analogWrite(redPin, 255-redValue);
    analogWrite(bluePin, 255-blueValue);
    analogWrite(greenPin, 255-greenValue);
    
    delay(delayTime);
}
