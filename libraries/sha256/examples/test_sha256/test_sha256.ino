#include <sha256.h>

void FAIL(const __FlashStringHelper * msg){
  Serial.println(F("FAIL "));
  Serial.println(msg);
}

void setup(){
  Serial.begin(9600);
  Serial.println("BEGIN");

  uint8_t data[] = {0x04};
  uint8_t data1[] = {0x50,0x86,0x3A,0xD6,0x4A,0x87,0xAE,0x8A,0x2F,0xE8,0x3C,0x1A,0xF1,0xA8,0x40,0x3C,0xB5,0x3F,0x53,0xE4,0x86,0xD8,0x51,0x1D,0xAD,0x8A,0x04,0x88,0x7E,0x5B,0x23,0x52};
  uint8_t data2[] = {0x2C,0xD4,0x70,0x24,0x34,0x53,0xA2,0x99,0xFA,0x9E,0x77,0x23,0x77,0x16,0x10,0x3A,0xBC,0x11,0xA1,0xDF,0x38,0x85,0x5E,0xD6,0xF2,0xEE,0x18,0x7E,0x9C,0x58,0x2B,0xA6};
  uint8_t expectedhash[] = {0x60,0xF,0xFE,0x42,0x2B,0x4E,0x0,0x73,0x1A,0x59,0x55,0x7A,0x5C,0xCA,0x46,0xCC,0x18,0x39,0x44,0x19,0x10,0x6,0x32,0x4A,0x44,0x7B,0xDB,0x2D,0x98,0xD4,0xB4,0x8};
  uint8_t hash[32];

  struct SHA256_CTX ctx;
  sha256_init(&ctx);
  sha256_update(&ctx,data,sizeof(data));
  sha256_update(&ctx,data1,sizeof(data1));
  sha256_update(&ctx,data2,sizeof(data2));
  sha256_final(&ctx,hash);

  if( memcmp(hash,expectedhash,32) != 0 ){
    FAIL(F("Hash Mismatch"));
  }

  Serial.println("END");
}

void loop()
{
}
