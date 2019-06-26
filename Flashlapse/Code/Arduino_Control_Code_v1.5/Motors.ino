void clino()
{
  while (!Serial.available())
  {
    moveCWStep();
    aciveDelay(delayTime);
  }
}

void reflex(int stt)
{
  if (stt > 0)
  {
    for (int i = 0; i < stt; i++)
    {
      moveCWStep();
      delay(delayTime);
    }
    for (int i = 0; i < stt; i++)
    {
      moveCCWStep();
      delay(delayTime);
    }
  }

  else
  {
    for (int i = 0; i < stt * -1; i++)
    {
      moveCCWStep();
      delay(delayTime);
    }
    for (int i = 0; i < stt * -1; i++)
    {
      moveCWStep();
      delay(delayTime);
    }
  }

  resetMotors();
}

void rotate_to(int stt)
{
  if (stt > 0)
  {
    for (int i = 0; i < stt; i++)
    {
      moveCWStep();
      delay(delayTime);
    }
  }

  else
  {
    for (int i = 0; i < stt * -1; i++)
    {
      moveCCWStep();
      delay(delayTime);
    }
  }

  resetMotors();
}


void moveCWStep()
{

  switch (currentStep) {
    case 0:
      digitalWrite(MOTORPIN1, HIGH);
      digitalWrite(MOTORPIN2, LOW);
      digitalWrite(MOTORPIN3, LOW);
      digitalWrite(MOTORPIN4, LOW);
      currentStep++;
      break;
    case 1:
      digitalWrite(MOTORPIN1, LOW);
      digitalWrite(MOTORPIN2, HIGH);
      digitalWrite(MOTORPIN3, LOW);
      digitalWrite(MOTORPIN4, LOW);
      currentStep++;
      break;
    case 2:
      digitalWrite(MOTORPIN1, LOW);
      digitalWrite(MOTORPIN2, LOW);
      digitalWrite(MOTORPIN3, HIGH);
      digitalWrite(MOTORPIN4, LOW);
      currentStep++;
      break;
    case 3:
      digitalWrite(MOTORPIN1, LOW);
      digitalWrite(MOTORPIN2, LOW);
      digitalWrite(MOTORPIN3, LOW);
      digitalWrite(MOTORPIN4, HIGH);
      currentStep = 0;
      break;
  }
}

void moveCCWStep()
{

  switch (currentStep) {
    case 0:
      digitalWrite(MOTORPIN1, LOW);
      digitalWrite(MOTORPIN2, LOW);
      digitalWrite(MOTORPIN3, LOW);
      digitalWrite(MOTORPIN4, HIGH);
      currentStep++;
      break;
    case 1:
      digitalWrite(MOTORPIN1, LOW);
      digitalWrite(MOTORPIN2, LOW);
      digitalWrite(MOTORPIN3, HIGH);
      digitalWrite(MOTORPIN4, LOW);
      currentStep++;
      break;
    case 2:
      digitalWrite(MOTORPIN1, LOW);
      digitalWrite(MOTORPIN2, HIGH);
      digitalWrite(MOTORPIN3, LOW);
      digitalWrite(MOTORPIN4, LOW);
      currentStep++;
      break;
    case 3:
      digitalWrite(MOTORPIN1, HIGH);
      digitalWrite(MOTORPIN2, LOW);
      digitalWrite(MOTORPIN3, LOW);
      digitalWrite(MOTORPIN4, LOW);
      currentStep = 0;
      break;
  }
}

void resetMotors()
{
  digitalWrite(MOTORPIN1, LOW);
  digitalWrite(MOTORPIN2, LOW);
  digitalWrite(MOTORPIN3, LOW);
  digitalWrite(MOTORPIN4, LOW);
}

void getdelay()
{
  delayTime = int((60000 / (2038 * rpm)));
}
