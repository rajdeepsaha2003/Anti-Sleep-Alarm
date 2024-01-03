#define SENSE A0 // IR Sensor
#define BUZZER 3   // Buzzer connected to digital pin 3

void setup() 
{ 
    pinMode(SENSE, INPUT); 
    pinMode(2, OUTPUT); 
    pinMode(LED_BUILTIN, OUTPUT); // 13+
    pinMode(BUZZER, OUTPUT);
}

void loop() 
{ 
    if(digitalRead(SENSE)) 
    {  
        delay(2000);
        if (digitalRead(SENSE)) // Check if sensor is still HIGH after delay
        {
            digitalWrite(LED_BUILTIN, HIGH);
            pinMode(2, HIGH);
            playMelody();
        }
        else
        {
            digitalWrite(LED_BUILTIN, LOW);
            pinMode(2, LOW);
        }
    } 
    else
    {   
        digitalWrite(LED_BUILTIN, LOW);      
        pinMode(2, LOW);
    } 
}

void playMelody()
{
    // Play a simple melody on the buzzer when LED is on
    tone(BUZZER, 261, 200);  // Play middle C for 200ms
    delay(200);
    tone(BUZZER, 293, 200);  // Play D for 200ms
    delay(200);
    tone(BUZZER, 329, 200);  // Play E for 200ms
    delay(200);
    noTone(BUZZER);           // Stop playing the melody
}