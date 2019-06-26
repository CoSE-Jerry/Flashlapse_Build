void serialEvent() {
  int current = 0;
  clearCMD();
  serialResponse = Serial.readStringUntil('\r\n');
  // Convert from String Object to String.
  char buf[sizeof(sz)];
  serialResponse.toCharArray(buf, sizeof(buf));
  char *p = buf;
  char *str;
  while ((str = strtok_r(p, "~", &p)) != NULL)
  {
    int temp;
    temp = atoi(str);
    commands[current] = temp;
    current++;
  }
  exeCMD();
}

void clearCMD() {
  for (int i = 0; i < COMMANDSIZE; i++)
  {
    commands[i] = 0;
  }
}

void exeCMD() {

  switch (commands[0]) {
    case 0:
      stripReset();
      break;

    case 1:
      stripUpdate();
      break;

    case 2:
      switch (commands[1]) {
        case 0:
          disco(commands[2]);
          break;

        case 1:
          rainbow(commands[2]);
          break;

        case 2:
          sunDial(commands[2]);
          break;

        case 3:
          pulse(commands[2]);
          break;
      }
      break;

    case 3:
      lightUpdate();
      break;

    case 4:
      lightshow();
      break;

    case 5:
      reflex(int((commands[1] * 20.38) / 3.6));
      break;

    case 6:
      delayTime = commands[1];
      break;

    case 7:
      clino();
      break;

    case 8:
      rotate_to(int((commands[1] * 20.38) / 3.6));
      break;


      
  }
}
