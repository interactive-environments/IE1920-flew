////////////////
// Flew init //
////////////////
#include <Adafruit_NeoPixel.h>
int NUM_1 = 236;
int NUM_2 = 231;
                                   //      //      //      //      //      //      //      //      //      //      //      //
int count[24] =               {22, 21, 12, 17, 11, 18, 14, 21, 12, 16, 11, 18, 16, 27, 20, 24, 18, 26, 24, 32, 20, 24, 18, 26};                                 //Number of leds per arm.
int long_circle_count[32] =   {12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 11, 10,  8,  8,  8,  6,  6,  6,  4,  4,  2,  1,  1,  1,  1,  1}; //Number of active arms per circle starting at 0 moving outwards (long arms)
int short_circle_count[24] =  {12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 10,  8,  8,  7,  7,  6,  6,  4,  4,  2,  2,  1,  1};                                 //Number of active arms per circle starting at 0 moving outwards (short arms)
int spiral[24][32] = 
{    //                   5                       10                       15                       20                       25                       30      
  {  21,  20,  19,  18,  17,  16,  15,  14,  13,  12,  11,  10,   9,   8,   7,   6,   5,   4,   3,   2,   1,   0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
  {  22,  23,  24,  25,  26,  27,  28,  29,  30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
  {  54,  53,  52,  51,  50,  49,  48,  47,  46,  45,  44,  43,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
  {  55,  56,  57,  58,  59,  60,  61,  62,  63,  64,  65,  66,  67,  68,  69,  70,  71,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
  {  82,  81,  80,  79,  78,  77,  76,  75,  74,  73,  72,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
  {  83,  84,  85,  86,  87,  88,  89,  90,  91,  92,  93,  94,  95,  96,  97,  98,  99, 100,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
  { 114, 113, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
  { 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
  { 147, 146, 145, 144, 143, 142, 141, 140, 139, 138, 137, 136,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
  { 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
  { 174, 173, 172, 171, 170, 169, 168, 167, 166, 165, 164,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
  { 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
  { 208, 207, 206, 205, 204, 203, 202, 201, 200, 199, 198, 197, 196, 195, 194, 193,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
  { 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235,  -1,  -1,  -1,  -1,  -1},
  { 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 464, 465, 466,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
  { 446, 445, 444, 443, 442, 441, 440, 439, 438, 437, 436, 435, 434, 433, 432, 431, 430, 429, 428, 427, 426, 425, 424, 423,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
  { 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
  { 404, 403, 402, 401, 400, 399, 398, 397, 396, 395, 394, 393, 392, 391, 390, 389, 388, 387, 386, 385, 384, 383, 382, 381, 380, 379,  -1,  -1,  -1,  -1,  -1,  -1},
  { 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
  { 355, 354, 353, 352, 351, 350, 349, 348, 347, 346, 345, 344, 343, 342, 341, 340, 339, 338, 337, 336, 335, 334, 333, 332, 331, 330, 329, 328, 327, 326, 325, 324},
  { 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
  { 303, 302, 301, 300, 299, 298, 297, 296, 295, 294, 293, 292, 291, 290, 289, 288, 287, 286, 285, 284, 283, 282, 281, 280,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
  { 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
  { 261, 260, 259, 258, 257, 256, 255, 254, 253, 252, 251, 250, 249, 248, 247, 246, 245, 244, 243, 242, 241, 240, 239, 238, 237, 236,  -1,  -1,  -1,  -1,  -1,  -1},
};

int pin1 = 5;
int pin2 = 7;
Adafruit_NeoPixel leds_1 = Adafruit_NeoPixel(NUM_1, pin1, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel leds_2 = Adafruit_NeoPixel(NUM_2, pin2, NEO_RGB + NEO_KHZ800);

///////////////////////
// CmdMessenger init //
///////////////////////
#include <CmdMessenger.h>
enum {
  coords,
  num,
  unblock,
};
const int BAUD_RATE = 9600;
CmdMessenger c = CmdMessenger(Serial,',',';','/');

///////////////
// Main code //
///////////////
void setup() {
  Serial.begin(BAUD_RATE);
  attach_callbacks();
  start();
  clean();
  out();
}

void loop() {
  c.feedinSerialData();
}
