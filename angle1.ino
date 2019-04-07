#define m1 3
#define m2 4
#define m3 5
#define m4 6
#define ADC_ref 2.56
#define zero_x 1.569
#define zero_y 1.569
#define zero_z 1.569
#define sensitivity_x 0.3
#define sensitivity_y 0.3
#define sensitivity_z 0.3
unsigned int value_x;
unsigned int value_y;
unsigned int value_z;
float xv;
float yv;
float zv;
float angle_x;
float angle_y;
float angle_z;
void setup()   {
Serial.begin(9600);
pinMode(m1,OUTPUT);
pinMode(m2,OUTPUT);
pinMode(m3,OUTPUT);
pinMode(m4,OUTPUT);
}
void loop() {
value_x = analogRead(2);
value_y = analogRead(3);
value_z = analogRead(4);
xv=(value_x/1024.0*ADC_ref-zero_x)/sensitivity_x;
yv=(value_y/1024.0*ADC_ref-zero_y)/sensitivity_y;
zv=(value_z/1024.0*ADC_ref-zero_z)/sensitivity_z;
angle_x =atan2(-yv,-zv)*57.2957795+180;
angle_y =atan2(-xv,-zv)*57.2957795+180;
angle_z =atan2(-yv,-xv)*57.2957795+180;
if(angle_y > angle_x && angle_y > angle_z)
{
  Serial.println("left-side");
  digitalWrite(m1,HIGH);
    digitalWrite(m2,LOW);
    digitalWrite(m3,LOW);
    digitalWrite(m4,HIGH);
  }
  if(angle_z > angle_x && angle_z > angle_y)
{
  Serial.println("right-side");
  digitalWrite(m1,LOW);
    digitalWrite(m2,HIGH);
    digitalWrite(m3,HIGH);
    digitalWrite(m4,LOW);
  }
  if(angle_x > angle_y && angle_x > angle_z)
  {
    Serial.println("straight");
    digitalWrite(m1,HIGH);
    digitalWrite(m2,LOW);
    digitalWrite(m3,HIGH);
    digitalWrite(m4,LOW);
    }
}

