#include <TinyGPS.h>
#include <LiquidCrystal.h>
 
// initialiser la bibliothèque LiquidCrystal avec les numéros des pin de l'Arduino
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
// Création d'une instance pour l'objet TinyGPS
TinyGPS gps;
 
// Ceci est l'endroit où nous déclarons le prototypes pour la fonction 
// qui utilisera la bibliothéque TinyGPS et controlera l'affichage 
void getgps(TinyGPS &gps);
 
void setup()
{
  Serial.begin(9600);
  lcd.begin(20, 4);
  lcd.clear();
  lcd.setCursor(2,1);
  lcd.print("* CAMEROUN FOREVER *");
  lcd.setCursor(4,2);
  lcd.print("** CHINE 2020 **");
  delay(100);
  lcd.clear();
  lcd.setCursor(2,1);
  lcd.print("En attente ...");
}
 
// La fonction get gps va obtenir et imprimer les valeurs que nous voulons
void getgps(TinyGPS &gps)
{

  // Définir les variables qui seront utilisées
  float latitude, longitude;
  
  // appelle de la fonction qui récupère la latitude et la longitude
  gps.f_get_position(&latitude, &longitude);
  
  // clear LCD
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Lat: "); 
  lcd.print(latitude,5); 
  lcd.setCursor(0,1); 
  lcd.print("Long: "); 
  lcd.print(longitude,5);
  
  // la même opération pour la date et le temps
  int annee;
  byte mois, jour, heure, minute, seconde, millieme;
  gps.crack_datetime(&annee,&mois,&jour,&heure,&minute,&seconde,&millieme);
  
  lcd.setCursor(1,2);
  lcd.print(heure,DEC);
  lcd.print(":");
  if (minute<10)
  {
    lcd.print("0");
    lcd.print(minute, DEC);
  } 
  else if (minute>=10)
  {
    lcd.print(minute, DEC);
  }
  lcd.print(":");
  if (seconde<10)
  {
    lcd.print("0");
    lcd.print(seconde,DEC);
  } 
  else if (seconde>=10)
  {
    lcd.print(seconde,DEC);
  }
  lcd.print(" ");
  lcd.print(jour);
  lcd.print("/");
  lcd.print(mois,DEC);
  lcd.print("/");
  lcd.print(annee,DEC);
  lcd.setCursor(0,3);
  lcd.print(gps.f_altitude()); // lecture et affichage de l'altitude
  lcd.print("m ");             
  
  lcd.print(gps.f_speed_kmph()); // lecture et affichage de la vitesse 
  lcd.print("km/h");             
 
}
 
void loop()
{
  byte a;
  if ( Serial.available() > 0 ) 
  {
    a = Serial.read(); 
    if(gps.encode(a)) 
    {
      getgps(gps); 
                   // saisir les données et les afficher sur l'écran LCD
    }
  }
}
