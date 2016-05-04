#ifndef __DISPLAY__
#define __DISPLAY__

void start();
unsigned char get_key();
unsigned char pressed(int r, int c);
void updatedate();
void printdate();
void printtime();
void incdec(unsigned char key);
void setit();

#endif

