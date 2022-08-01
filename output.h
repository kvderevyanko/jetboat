#define speedPin 23 //пин PWM скорости

#define speedStep 10 //Количество шагов для pwm скорости

#define relayPinL 17 //Пин реле левый 
#define relayPinR 5  //Пин реле правый

int speedVal = 0; //Значение скорости

// задаём свойства ШИМ-сигнала
const int freq = 15000;
const int speedChannel = 0;
const int resolution = 8;

void setupOut() {
  ledcSetup(speedChannel, freq, resolution);

  // привязываем канал к порту
  ledcAttachPin(speedPin, speedChannel);

  pinMode(relayPinL, OUTPUT);
  pinMode(relayPinR, OUTPUT);
}

//Установка скорости
bool setSpeedVal(int val) {

  if (speedVal + speedStep >= val && speedVal - speedStep <= val) {
    //Если скорость не изменилась, то оставляем предыдущее значение
    speedVal = val;
  }
  else if (val > speedVal) {
    //Если скорость что пришла больше текущей, то увеличиваем
    speedVal = speedVal + speedStep;
  }  else if (val < speedVal) {
    //Если скорость что пришла меньше текущей, то уменьшаем быстрее в 2 раза
    speedVal = speedVal - (speedStep * 2);
  }

  //Если скорость выходит за пределы, то нормализуем
  if (speedVal > 255) {
    speedVal = 255;
  }

  if (speedVal < speedStep) {
    speedVal = 0;
  }
  Serial.println(speedVal);
  ledcWrite(speedChannel, speedVal);


  // проверка, включин ли мотор, что бы могли переключить реле
  if (speedVal) {
    return false;
  } else {
    return true;
  }
}

//Управление реле
void setRelay(bool val) {
  if (val) {
    digitalWrite(relayPinL, LOW);
    digitalWrite(relayPinR, LOW);
  } else {
    digitalWrite(relayPinL, HIGH);
    digitalWrite(relayPinR, HIGH);
  }

}
