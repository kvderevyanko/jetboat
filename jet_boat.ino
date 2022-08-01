#include "input.h"
#include "output.h"

bool motorActive = false; //Значение включён или нет мотор

void setup() {
  startInput(); //Подключаем приёмник
  setupOut();

  Serial.begin(115200);

}


void loop() {
  readPins();



  // ch1Speed = abs(ch1Speed);

  motorActive = setSpeedVal(abs(ch1Speed));

  //Если мотор отключён, то можем изменить реле
  if (!motorActive) {
    if (ch1Speed > 0) {
      setRelay(true);
    } else {
      setRelay(false);
    }
  }



  /*

    Serial.print("ch1Speed: ");
    Serial.print(ch1Speed);
    Serial.print(" | ch2Turn: ");
    Serial.print(ch2Turn);
    Serial.print(" | ch3Lamp: ");
    Serial.print(ch3Lamp);
    Serial.println("");

    delay(200);
  */
}
