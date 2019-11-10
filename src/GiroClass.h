#include<Wire.h>
class GiroObject{  
  int MPU=0x68;
  
  
  public:
    int minDiff = 500;    
    int acX,acY,acZ,tmp,gyX,gyY,gyZ;
    int lastAcX,lastAcY,lastAcZ,lastTmp,lastGyX,lastGyY,lastGyZ;  
    
    GiroObject(int newMPU){
      /*
      MPU = newMPU;
      Wire.begin();
      Wire.beginTransmission(MPU);
      Wire.write(0x6B); 
       
      //Inicializa o MPU-6050
      Wire.write(0); 
      Wire.endTransmission(true);    
      */
    }

   
    bool dif (int last, int actual){
      return abs(last - actual)  > minDiff;
    }

    void wiffiUpdate(){
      update();      
      acX=Wire.read()<<8|Wire.read(); //0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)  if(dif(lastAcX, acX)) {
      if(dif(lastAcX, acX)) {
        lastAcX = acX;
      }
    }

    void update(){
      Wire.beginTransmission(MPU);
      Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
      Wire.endTransmission(false);
      
      //Solicita os dados do sensor
      Wire.requestFrom(MPU,14,true);
    }
    
       
    inline void updateAcel(){ 
      acX=Wire.read()<<8|Wire.read(); //0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
      acY=Wire.read()<<8|Wire.read(); //0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
      acZ=Wire.read()<<8|Wire.read(); //0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)  
      if(dif(lastAcX, acX)) {
        Serial.print("Acel. X = "); Serial.println(acX);  
        lastAcX = acX;
      }
      
      if(dif(lastAcY, acY)) {
        Serial.print("Acel. Y =  "); Serial.println(acY);        
        lastAcY = acY;
      }
      
      if(dif(lastAcZ, acZ)) {
        Serial.print("Acel. Z = "); Serial.println(acZ);         
        lastAcZ = acZ;
      }
      
    }
     
    void updateGyro(){ 
      gyX=Wire.read()<<8|Wire.read(); //0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
      gyY=Wire.read()<<8|Wire.read(); //0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
      gyZ=Wire.read()<<8|Wire.read(); //0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

      if(dif(lastGyX, gyX)) {
        Serial.print("Gir. X = "); Serial.println(gyX);
        lastGyX = gyX;
      }
      
      if(dif(lastGyY, gyY)) {
        Serial.print("Gir. Y =  "); Serial.println(gyY);        
        lastGyY = gyY;
      }
      
      if(dif(lastGyZ, gyZ)) {
        Serial.print("Gir. Z = "); Serial.println(gyZ);         
        lastGyZ = gyZ;
      }
    }

    void updateTemp(){
      tmp=Wire.read()<<8|Wire.read(); //0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
      
      if(dif(lastTmp, tmp)) {
        Serial.print(" | Temp = "); Serial.println(tmp/340.00+36.53);       
        lastTmp = tmp;
      }
    }
};
