#include <Keypad.h>
#include <LiquidCrystal.h>



const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 =9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5 , d6, d7);
const byte ROWS = 4;
const byte COLS = 4;
char hexakeys[ROWS][COLS] = {
  {'7', '8', '9','/'},
  {'4', '5', '6','x'},
  {'1', '2', '3','-'},
  {'C', '0', '=','+'}
};

byte rowPins[ROWS] = {3, 2, A4, A5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5,4}; //connect to the column pinouts of the keypad

Keypad customKeypad = Keypad( makeKeymap(hexakeys), rowPins, colPins, ROWS, COLS); //initialize an instance of class NewKeypad
#define Password_Lenght 7 // Give enough room for six chars + NULL char


char Data[Password_Lenght]; // 6 is the number of chars it can hold + the null char = 7
char Master[Password_Lenght] = "123456";
byte data_count = 0;
char customKey;
void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("WELCOME TO 237");
  lcd.setCursor(0, 1);
  lcd.print("DOOR IS LOCKED!!");


}

void loop() {
 
  customKey=customKeypad.getKey();
  if(customKey)
  {if(data_count==0)
       {lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("ENTER PASSWORD:");
        lcd.setCursor(0,1);}
    Data[data_count] = customKey; // store char into data array
    lcd.setCursor(data_count, 1); // move cursor to show each new char
    lcd.print(Data[data_count]); // print char at said cursor
    data_count++; // increment data array by 1 to store new char, also keep track of the number of chars entered

      if (data_count == Password_Lenght - 1) // if the array index is equal to the number of expected chars, compare data to master
  {
    if (!strcmp(Data, Master)) // equal to (strcmp(Data, Master) == 0)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("UNLOCKED");
      lcd.setCursor(0,1);
      lcd.print("ON/C TO LOCK");
      while(1)
      {
      customKey=customKeypad.getKey();
      if(customKey=='C')
      {lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("ENTER PASSWORD:");
      break;}
       
    }}
    else
    {
      lcd.clear();
      lcd.print("Wrong Password");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("ENTER PASSWORD:");
    }
    clearData();}
  
  }




}

void clearData()
{
  while (data_count != 0)
  { // This can be used for any array size,
    Data[data_count--] = 0; //clear array for new data
  }
  return;
}
