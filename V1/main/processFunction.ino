void processMain()
{
  if (buttonStartBlynk == 1 || digitalRead(buttonStart) == 0) //!= lastCurrentButton
  {  
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("     CAFE MIXER");
    display.display();
    display.setTextSize(1);
    display.setCursor(0, 10);
    display.println("Decive Is Running");
    display.display();

    buttonStartBlynk = 0; 

    Blynk.syncVirtual(V0);
    Blynk.syncVirtual(V1);
    Blynk.syncVirtual(V2);

    timeV1 = timeV1 * 1000;
    timeV2 = timeV2 * 1000;
    timeV3 = timeV3 * 1000;

    switch (flagBlynk)
    {
      case 0:
        Serial.println("Process taking coffee");

        Blynk.virtualWrite(V3, 1);

        display.setTextSize(1);
        display.setCursor(0, 20);
        display.println("Taking coffee:  ");
        display.display();

        digitalWrite(volume1, 1);
        delay(timeV1);
        digitalWrite(volume1, 0);

        display.setTextSize(1);
        display.setCursor(0, 20);
        display.println("Taking coffee: OK");
        display.display();

        flagBlynk = 1;

        ringBell(150, 2);

        Serial.println("Process taked coffee");
      break;
        
      case 1:
        Serial.println("Process taking milk");

        Blynk.virtualWrite(V3, 1);

        display.setTextSize(1);
        display.setCursor(0, 20);
        display.println("Taking coffee: OK");
        display.display();
        display.setTextSize(1);
        display.setCursor(0, 30);
        display.println("Taking milk:  ");
        display.display();

        digitalWrite(volume2, 1);
        delay(timeV2);
        digitalWrite(volume2, 0);

        display.setTextSize(1);
        display.setCursor(0, 20);
        display.println("Taking coffee: OK");
        display.display();
        display.setTextSize(1);
        display.setCursor(0, 30);
        display.println("Taking milk: OK");
        display.display();

        flagBlynk = 2;

        ringBell(150, 2);

        Serial.println("Process taked milk");
      break;
        
      case 2:
        Serial.println("Process taking tea");

        Blynk.virtualWrite(V3, 1);

        display.setTextSize(1);
        display.setCursor(0, 20);
        display.println("Taking coffee: OK");
        display.display();
        display.setTextSize(1);
        display.setCursor(0, 30);
        display.println("Taking milk: OK");
        display.display();
        display.setTextSize(1);
        display.setCursor(0, 40);
        display.println("Taking tea:   ");
        display.display();

        digitalWrite(volume3, 1);
        delay(timeV3);
        digitalWrite(volume3, 0);

        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(0, 0);
        display.println("     CAFE MIXER");
        display.display();
        display.setTextSize(1);
        display.setCursor(0, 10);
        display.println("Decive Is Complete");
        display.display();
        display.setTextSize(1);
        display.setCursor(0, 20);
        display.println("Taking coffee: OK");
        display.display();
        display.setTextSize(1);
        display.setCursor(0, 30);
        display.println("Taking milk: OK");
        display.display();
        display.setTextSize(1);
        display.setCursor(0, 40);
        display.println("Taking tea: OK");
        display.display();

        flagBlynk = 0;

        ringBell(150, 3);

        Serial.println("Process taked tea");
      break;
    }
    Blynk.virtualWrite(V3, 0);
    // lastCurrentButton = digitalRead(buttonStart);
  }
  else
  {
    digitalWrite(volume1, 0);
    digitalWrite(volume2, 0);
    digitalWrite(volume3, 0);
  }
}

void resetProcess()
{
  if (buttonClearBlynk == 1 || digitalRead(buttonClear) == 0) 
  {
    Serial.println("Reset device");

    flagBlynk = 0;
    buttonClearBlynk = 0;

    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(23, 8);
    display.println("RESET");
    display.display();
    delay(1000);

    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(23, 8);
    display.println("WELCOME");
    display.display();
    delay(2000);

    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("     CAFE MIXER");
    display.display();

    display.setTextSize(1);
    display.setCursor(0, 10);
    display.println("Device Is Ready");
    display.display();

    ringBell(100, 2);

    Serial.println("Reseted device");
    
    return;
  }
}






/*Code by SevKan*/