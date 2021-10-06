void setup() {
  Serial.begin(115200); //設定傳輸鮑率，跟電腦傳輸資料的頻率
  pinMode(14, INPUT); //設定腳位為輸入用
  ledcSetup(0, 5000, 8);   //頻率5000，頻道0，解析度8;
  ledcAttachPin(13, 0);  //將上述頻道0附加到ledPin腳位14上
}

void loop() {
  int input = analogRead(14);
  if(input>500)input=500;
  int input_map = map(input, 0, 500, 0, 255);
  Serial.print(input);
  Serial.print(" ");
  Serial.println(input_map);

  ledcWrite(0, 255-input_map);  //頻道0
}
