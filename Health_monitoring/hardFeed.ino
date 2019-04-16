#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 5

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

float Celcius=0;
float Fahrenheit=0;
float temp;
int tempPin = 0;


void setup() {
   Serial.begin(9600);
    sensors.begin();
   Serial.println("AT+CIPSHUT");
     delay(1000);
     

     Serial.println("AT+CIPMUX=0");
     delay(1000);
     

     Serial.println("AT+CGATT=1");
     delay(1000);


     Serial.println("AT+CSTT=\"internet\",\"\",\"\"");
     delay(1000);
   

     Serial.println("AT+CIICR");
     delay(1000);
     

     Serial.println("AT+CIFSR");
     delay(1000); 
    

     Serial.println("AT+CIPSTART=\"TCP\",\"xxx.xxx.xxx.xxx\", 80");
     delay(1000);
     

     Serial.println("AT+CIPSEND");
     delay(1000);
     

     Serial.println("GET http://xxx.xxx.xxx.xxx/data/read.txt HTTP/1.1");
     delay(1000);
     

     Serial.println("Host: xxx.xxx.xxx.xxx\r\n");
     delay(1000);
    
     Serial.write(0x1A);
     delay(10000);
}


void loop() {
    temp = analogRead(tempPin);
    // read analog volt from sensor and save to variable temp
    temp = temp * 0.48828125;
    // convert the analog volt to its temperature equivalent
    Serial.print("TEMPERATURE = ");
    Serial.print(temp); // display temperature value
    Serial.print("*C");
    Serial.println();
    delay(1000); // update sensor reading each one second
    sensors.requestTemperatures(); 
    Celcius=sensors.getTempCByIndex(0);
    Fahrenheit=sensors.toFahrenheit(Celcius);
    Serial.print(" C  ");
    Serial.print(Celcius);
    Serial.print(" F  ");
    Serial.println(Fahrenheit);
    delay(1000);
}

