int latchPin = 11;
int clockPin = 9;
int dataPin = 12;
byte leds = 0;
int adc_id = 0;
int HistoryValue = 0;
int tDelay = 100;
char printBuffer[128];

void updateShiftRegister()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  updateShiftRegister();
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(adc_id); // get adc value

  if (((HistoryValue >= value) && ((HistoryValue - value) > 10)) || ((HistoryValue < value) && ((value - HistoryValue) > 10)))
  {
    leds = 0;
    updateShiftRegister();
    if (value < 330)
    {
      leds = 0;
      updateShiftRegister();
    }
    else if (value < 360)
    {
      bitSet(leds, 7);
    }
    else if (value < 376)
    {
      bitSet(leds, 7);
      bitSet(leds, 6);
    }
    else if (value < 386)
    {
      bitSet(leds, 7);
      bitSet(leds, 6);
      bitSet(leds, 5);
    }
    else if (value < 399)
    {
      bitSet(leds, 7);
      bitSet(leds, 6);
      bitSet(leds, 5);
      bitSet(leds, 4);
    }
    else if (value < 412)
    {
      bitSet(leds, 7);
      bitSet(leds, 6);
      bitSet(leds, 5);
      bitSet(leds, 4);
      bitSet(leds, 3);
    }
    else if (value < 425)
    {
      bitSet(leds, 7);
      bitSet(leds, 6);
      bitSet(leds, 5);
      bitSet(leds, 4);
      bitSet(leds, 3);
      bitSet(leds, 2);
    }
    else if (value < 438)
    {
      bitSet(leds, 7);
      bitSet(leds, 6);
      bitSet(leds, 5);
      bitSet(leds, 4);
      bitSet(leds, 3);
      bitSet(leds, 2);
      bitSet(leds, 1);
    }
    else
    {
      bitSet(leds, 7);
      bitSet(leds, 6);
      bitSet(leds, 5);
      bitSet(leds, 4);
      bitSet(leds, 3);
      bitSet(leds, 2);
      bitSet(leds, 1);
      bitSet(leds, 0);
    }
    sprintf(printBuffer, "Level is %d\n", value);
    Serial.print(printBuffer);
    HistoryValue = value;
    updateShiftRegister();
    delay(tDelay);
  }
}
