//источник http://wiki.amperka.ru/%D0%BF%D1%80%D0%BE%D0%B4%D1%83%D0%BA%D1%82%D1%8B:hc-sr04-ultrasonic-sensor-distance-module
// Укажем, что к каким пинам подключено
int trigPin = 10; 
int echoPin = 11;  
int first_distance;
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  int duration;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  // Подождем 10 μs 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
   duration = pulseIn(echoPin, HIGH); 
   first_distance = duration / 58;
   Serial.print(first_distance); 
  Serial.println(" cm - first_distance");
}

// duration - продолжительност с англ
void loop() {
  int duration, distance, delta;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  // Подождем 10 μs 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
   duration = pulseIn(echoPin, HIGH); 
   distance = duration / 58;
   delta = first_distance - distance;
  // Выведем значение в Serial Monitor
  Serial.print(delta); 
  Serial.println(" cm - delta");
  Serial.print(distance); 
  Serial.println(" cm - distance");  
  delay(5000);
}
// необходимая переодичность измерений для ледника? раз в какой период времени надо измерять уровень ледника???
//сделать БД, в которую будут записываться данные с датчика
//корпус для датчика, с обогревом - Датчик снежного покрова ТМ-4221-У выполнен в литом 
//алюминиевом корпусе со встроенным нагревательным устройством, 
//что позволяет прибору выдерживать даже самые низкие температуры и передавать точные данные в любых погодных условиях
//от 4см до 400см - посмотри даташит!
//прописать условие если abs(delta) больше first_distance то ВОРНИНГ