
// Получение сигнала с приёмника


#define CH1 32 //пин скорости
#define CH2 35 //пин поворота
#define CH3 33 //пин третьего канала

 
int ch1Speed; //Значение скорости
int ch2Turn; //Значение поворота
int ch3Lamp; //Значение третьего канала


//Чтение канала и возврат значений от и до
int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue){
  int ch = pulseIn(channelInput, HIGH, 30000);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}
 
//Чтение канала и возврат булевого значения (0, 1)
bool readSwitch(byte channelInput, bool defaultValue){
  int intDefaultValue = (defaultValue)? 100: 0;
  int ch = readChannel(channelInput, 0, 100, intDefaultValue);
  return (ch > 50);
}

void startInput(){
  pinMode(CH1, INPUT);
  pinMode(CH2, INPUT);
  pinMode(CH3, INPUT);

}

//Получение значений
void readPins(){
  ch1Speed = readChannel(CH1, 255, -255, 0);
  ch2Turn = readChannel(CH2, 255, -255, 0);
  //ch3Lamp = readSwitch(CH3, -100, 100, -100);
   ch3Lamp = readSwitch(CH3, 0);
  
  
}
