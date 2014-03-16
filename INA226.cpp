#include "INA226.h"

void INA226::setAddr(int _addr)
{
  addr = _addr;
}

void INA226::setup()
{
  // 0x45ff
  // average: 16 times, conversion time: 8.244ms/8.244ms
  write(INA226_CONFIG, INA226_RESET_INACTIVE
                | INA226_MODE_CONT_SHUNT_AND_BUS
                | INA226_VSH_8244uS
                | INA226_VBUS_8244uS
                | INA226_AVG_16);
  // current conversion
  write(INA226_CALIB, INA226_CALIB_VAL); 
}

short INA226::read(byte reg)
{
  short ret = 0;
  
  Wire.beginTransmission(addr);
  Wire.write(reg);
  Wire.endTransmission();  
  Wire.requestFrom((int)addr, 2);

  while(Wire.available()) {
    ret = (ret << 8) | Wire.read();
  }

  return ret;
}

void INA226::write(byte reg, unsigned int val)
{
  Wire.beginTransmission(addr);
  Wire.write(reg);
  Wire.write(val >> 8);
  Wire.write(val & 0xff);
  Wire.endTransmission(); 
}