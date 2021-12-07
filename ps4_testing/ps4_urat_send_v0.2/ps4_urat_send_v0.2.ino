#include <PS4Controller.h>

#define BT_MAC_ADDR "70:9c:d1:04:9e:75"  //black
#define TXD2 17
#define RXD2 16

float Txbuffer[8]; 
int btstate = 0;
bool button[20];
double axis[6];
int8_t battery = 0;

void esp32_ps4_receive() {
  //buttonstate
  button[0] = PS4.Up();
  button[1] = PS4.Down();
  button[2] = PS4.Left();
  button[3] = PS4.Right();
  
  button[4] = PS4.Square();
  button[5] = PS4.Cross();
  button[6] = PS4.Circle();
  button[7] = PS4.Trangle();
  
  button[8] = PS4.UpRight();
  button[9] = PS4.UpLeft();
  button[10] = PS4.DownRight();
  button[11] = PS4.DownLeft();
 
  button[12] = PS4.L1();
  button[13] = PS4.R1();
  button[14] = PS4.L3();
  button[15] = PS4.R3();
  
  button[16] = PS4.Share();
  button[17] = PS4.Options();
  button[18] = PS4.PSButton();
  button[19] = PS4.TouchPad();
  
  axis[0] = PS4.L2Value();
  axis[1] = PS4.R2Value();
  axis[2] = PS4.LStickX();
  axis[3] = PS4.LStickY();
  axis[4] = PS4.RStickX();
  axis[5] = PS4.RStickY();
  
  battery = PS4.Battery();
  
  btstate = 0;
  for (int i =0; i<20; i++){
    btstate = btstate + (button[i]*(pow(2,i)));
  }
}

void esp32_uart_send(){
  Txbuffer[0] = btstate;
  for (int i = 0; i<6; i++){
    Txbuffer[i+1] = axis[i];
  }
  Txbuffer[7] = battery;
  Serial2.print(Txbuffer);
}


void setup() {
  PS4.begin(BT_MAC_ADDR);
  
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
  while(!Serial2);
  
}

void loop() {
  if (PS4.isConnected()){
    esp32_ps4_receive();
    esp32_uart_send();
    delay(1);
  }else{
    Serial.println("PS4 Disconnect!!");
    Serial2.println("PS4 Disconnect!!");
  }
}
