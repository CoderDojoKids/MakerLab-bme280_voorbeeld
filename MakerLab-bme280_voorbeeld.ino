/* 
Dit is een voorbeeld schets voor het uitlezen van een BME280 sensor.
In deze schets wordt de BME280 iedere 1000ms uitgelezen. De gemeten waarden worden daarna via de
seriele poort getoond.

Gebruiksaanwijzing:
- Sluit het BME280 sensor bordje aan op een Arduino Uno
  * Verbind de GND pin van de Arduino met de GND pin van de BME280. Gebruik een zwarte draad.
  * Verbind de 5V pin van de Arduino met de VIN pin van de BME280. Gebruik een rode draad.
  * Verbind de A4 pin van de Arduino met de SDA pin van de BME280
  * Verbind de A5 pin van de Arduino met de SCL pin van de BME280
- Open de schets met Arduino IDE 2
- Installeer de BME280 bibliotheek van Tyler Glenn.
  * Doe dit door de bibliotheek op te zoeken mbv de "bibliotheken beheerder" (het boeken icoontje aan de rechter kant).
  * Zoek de bibliotheek "BME280 door Tyler Glenn" op.
  * Selecteer van deze bibliotheek versie 3.0.0 en klik op installeren.
- Selecteer links boven in het scherm, de COM poort van de Arduino (in het rechthoekige drop down menu)
  Zoek de Arduino Uno op, selecteer deze en druk op OK.
- Druk op "Uploaden" rechts boven in het scherm.
- Als het uploaden is gelukt, open dan de seriele monitor.
  Deze is te vinden in het menu Hulpmiddelen, boven in het scherm.


  Voor de duidelijkheid, het commentaar dat verderop bij de code staat, is een uitleg van wat de Arduino opgedragen krijgt om te doen.
  Dit zijn dus geen instructies aan u als lezer.
  
  (c)2023 MakerLab Drachten, Lambertus Gorter
*/

//Deze schets gebruikt de I2C bibliotheek van Arduino. Deze bibliotheek wordt Wire genoemd.
#include <Wire.h> 
//Deze schets gebruikt de BME280 bibliotheek van Tyler Glenn (3.0.0)
//Uit deze bibliotheek wordt specifiek de I2C variant van de BME280 gebruikt.
#include <BME280I2C.h>


BME280I2C sensor; //Maak een BME280 I2C sensor object aan.


// Iedere schets moet verplicht een setup functie bevatten.
// De setup functie wordt eenmalig uitgevoerd, zodra de Arduino start
void setup() {
  Serial.begin(9600); //Start de seriele poort met een snelheid van 9600 baud
  Wire.begin();       //Start de I2C bus
  sensor.begin();     //Start de sensor 
}


// Iedere schets moet verplicht een loop functie bevatten.
// De loop functie wordt continu herhaald door de Arduino
void loop() {
  //Print een streep via de seriele poort, om onderscheid te kunnen maken tussen de huidige en de voorgaande metingen.
  Serial.println("--------------------------------");

  float temperature = sensor.temp(); //Lees met de sensor de temperatuur uit
  //Print de temperatuur via de seriele poort
  Serial.print("Temperatuur: ");
  Serial.print(temperature);
  Serial.println(" °C");

  float humidity = sensor.hum();  //Lees met de sensor vochtigheid uit
  //Print de vochtigheid via de seriele poort
  Serial.print("Vochtigheid: ");
  Serial.print(humidity);
  Serial.println(" %");

  float pressure = sensor.pres(); //Lees met de sensor luchtdruk uit
  //Print de luchtdruk via de seriele poort
  Serial.print("Luchtdruk: ");
  Serial.print(pressure);
  Serial.println(" hPa");

  delay(1000); //wacht 1 seconde voordat de loop opnieuw begint
}
