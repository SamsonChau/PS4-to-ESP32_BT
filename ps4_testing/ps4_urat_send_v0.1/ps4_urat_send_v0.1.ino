#include <PS4Controller.h>

#define BT_MAC_ADDR "70:9c:d1:04:9e:75"  //black

#define TXD2 17
#define RXD2 16

void esp32_ps4_receive() {
  if (PS4.Right()) {
    Serial.println("Right Button");
  }
  if (PS4.Down()) {
    Serial.println("Down Button");
  }
  if (PS4.Up()) {
    Serial.println("Up Button");
  }
  if (PS4.Left()) {
    Serial.println("Left Button");
  }

  
  if (PS4.Square()) {
    Serial.println("Square Button");
  }
  if (PS4.Cross()) {
    Serial.println("Cross Button");
  }
  if (PS4.Circle()) {
    Serial.println("Circle Button");
  }
  if (PS4.Triangle()) {
    Serial.println("Triangle Button");
  }

  
  if (PS4.UpRight()) {
    Serial.println("Up Right");
  }
  if (PS4.DownRight()) {
    Serial.println("Down Right");
  }
  if (PS4.UpLeft()) {
    Serial.println("Up Left");
  }
  if (PS4.DownLeft()) {
    Serial.println("Down Left");
  }

  
  if (PS4.L1()) {
    Serial.println("L1 Button");
  }
  if (PS4.R1()) {
    Serial.println("R1 Button");
  }

  
  if (PS4.Share()) {
    Serial.println("Share Button");
  }
  if (PS4.Options()) {
    Serial.println("Options Button");
  }

  
  if (PS4.L3()) {
    Serial.println("L3 Button");
  }
  if (PS4.R3()) {
    Serial.println("R3 Button");
  }

  
  if (PS4.PSButton()) {
    Serial.println("PS Button");
  }
  if (PS4.Touchpad()) {
    Serial.println("Touch Pad Button");
  }

  
  if (PS4.L2()) {
    Serial.printf("L2 button at %d\n", PS4.L2Value());
  }
  if (PS4.R2()) {
    Serial.printf("R2 button at %d\n", PS4.R2Value());
  }

  
  if (PS4.LStickX()) {
    Serial.printf("Left Stick x at %d\n", PS4.LStickX());
  }
  if (PS4.LStickY()) {
    Serial.printf("Left Stick y at %d\n", PS4.LStickY());
  }
  if (PS4.RStickX()) {
    Serial.printf("Right Stick x at %d\n", PS4.RStickX());
  }
  if (PS4.RStickY()) {
    Serial.printf("Right Stick y at %d\n", PS4.RStickY());
  }

  
  if (PS4.Charging()) {
    Serial.println("The controller is charging");
  }
  if (PS4.Audio()) {
    Serial.println("The controller has headphones attached");
  }
  if (PS4.Mic()) {
    Serial.println("The controller has a mic attached");
  }
  
  Serial.printf("Battery Level : %d\n", PS4.Battery());
  
  Serial.println();
  // This delay is to make the output more human readable
  // Remove it when you're not trying to see the output
}



void esp32_uart_send(){
  if (PS4.Right()) {
    Serial2.println("Right Button %s \n");
  }
  if (PS4.Down()) {
    Serial2.println("Down Button %s \n");
  }
  if (PS4.Up()) {
    Serial2.println("Up Button");
  }
  if (PS4.Left()) {
    Serial2.println("Left Button");
  }

  
  if (PS4.Square()) {
    Serial2.println("Square Button");
  }
  if (PS4.Cross()) {
    Serial2.println("Cross Button");
  }
  if (PS4.Circle()) {
    Serial2.println("Circle Button");
  }
  if (PS4.Triangle()) {
    Serial2.println("Triangle Button");
  }

  
  if (PS4.UpRight()) {
    Serial2.println("Up Right");
  }
  if (PS4.DownRight()) {
    Serial2.println("Down Right");
  }
  if (PS4.UpLeft()) {
    Serial2.println("Up Left");
  }
  if (PS4.DownLeft()) {
    Serial2.println("Down Left");
  }

  
  if (PS4.L1()) {
    Serial2.println("L1 Button");
  }
  if (PS4.R1()) {
    Serial2.println("R1 Button");
  }

  
  if (PS4.Share()) {
    Serial2.println("Share Button");
  }
  if (PS4.Options()) {
    Serial2.println("Options Button");
  }

  
  if (PS4.L3()) {
    Serial2.println("L3 Button");
  }
  if (PS4.R3()) {
    Serial2.println("R3 Button");
  }

  
  if (PS4.PSButton()) {
    Serial2.println("PS Button");
  }
  if (PS4.Touchpad()) {
    Serial2.println("Touch Pad Button");
  }

  
  if (PS4.L2()) {
    Serial2.printf("L2 button at %d\n", PS4.L2Value());
  }
  if (PS4.R2()) {
    Serial2.printf("R2 button at %d\n", PS4.R2Value());
  }

  
  if (PS4.LStickX()) {
    Serial2.printf("Left Stick x at %d\n", PS4.LStickX());
  }
  if (PS4.LStickY()) {
    Serial2.printf("Left Stick y at %d\n", PS4.LStickY());
  }
  if (PS4.RStickX()) {
    Serial2.printf("Right Stick x at %d\n", PS4.RStickX());
  }
  if (PS4.RStickY()) {
    Serial2.printf("Right Stick y at %d\n", PS4.RStickY());
  }

  
  if (PS4.Charging()) {
    Serial2.println("The controller is charging");
  }
  if (PS4.Audio()) {
    Serial2.println("The controller has headphones attached");
  }
  if (PS4.Mic()) {
    Serial2.println("The controller has a mic attached");
  }
  
  Serial2.printf("Battery Level : %d\n", PS4.Battery());
  
  Serial.println();
  // This delay is to make the output more human readable
  // Remove it when you're not trying to see the output
}


void setup() {
  Serial.begin(115200);
  while(!Serial);

  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  while(!Serial2);
  Serial.println("UART Ready!!");
  
  PS4.begin(BT_MAC_ADDR);
  Serial.println("PS4 Ready.");
}

void loop() {
  // Below has all accessible outputs from the controller
  if (PS4.isConnected()){
    esp32_ps4_receive();
    esp32_uart_send();
    delay(1000);

  }else{
    Serial.println("PS4 Disconnect!!");
    Serial2.println("PS4 Disconnect!!");
    delay(1000);
  }
  
}
