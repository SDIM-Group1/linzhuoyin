 
void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  digitalWrite(2,LOW);
  digitalWrite(4,LOW);//设置2号，4号引脚为输出口
  Serial.begin(9600);//串口通讯波特率为9600
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int data;
  
   while(Serial.available()>0){
      data=Serial.read();//读取串口通信
      delay(2);
      if(data==49){//当串口输入为1时，读取到的数值为49，控制推杆推出
    Serial.println("111");//提示状态代码
    digitalWrite(2,HIGH);
    delay(10000);//推杆推出时间暂时未定，需要通过测试找到合适的推出持续时间
    digitalWrite(2,LOW);//停止推杆推出
     }
      if(data==50){//当串口输入为2时，读取到的数值为50，控制推杆收回
    Serial.println("222");//提示状态代码
     digitalWrite(4,HIGH);//开始推杆收回
     delay(10000);
  digitalWrite(4,LOW);  //结束推杆收回
     }
     }
     
  digitalWrite(2,LOW);
  digitalWrite(4,LOW);//每次操作结束后清空推杆数据   
  data=0;
   
   
    
  
}
//关于接线：In1接2号口，In2 接4号口
