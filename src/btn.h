#ifndef btn_h
#define btn_h

void init_btn()
{
    pinMode(BTN_GPIOPIN, INPUT);
}

void check_btn()
{
    btn_State = digitalRead(BTN_GPIOPIN);

    if (btn_State == HIGH)
    {

        if (btn == true)
        {
            btn = false;
        }
        if (btn == false)
        {
            btn = true;
        }
#ifdef DEBUG
        Serial.print("(btn_State == HIGH) btn = ");
        Serial.println(btn);
#endif
    }
    while (btn)
    {
        if (start)
        {
            WiFi.mode(WIFI_AP);
            start=false;
        }
        webSocket.loop();
        server.handleClient();
        onboard_led.on = millis() % 400 < 200;
        onboard_led.update();

        btn_State = digitalRead(BTN_GPIOPIN);

        if (btn_State == HIGH)
        {

            if (btn == true)
            {
                btn = false;
            }
            else if (btn == false)
            {
                btn = true;
            }
#ifdef DEBUG
            Serial.print("(State == HIGH) btn = ");
            Serial.println(btn);
#endif
        }

    }

}

#endif