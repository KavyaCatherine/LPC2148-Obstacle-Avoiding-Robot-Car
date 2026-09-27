//#include <lpc214x.h>      
//void delay(unsigned int x)
//{
//    unsigned int i, j;

//    for(i = 0; i < x; i++)
//        for(j = 0; j < 59999; j++);
//}
//int main()
//{
//    
//    PINSEL0 = 0x00000000;
//    PINSEL1 = 0x00000000; 	
//	  PINSEL2 = 0x00000000;

//    IO0DIR |= (1<<0);  // output
//    IO0DIR |= (1<<1);
//    IO0DIR |= (1<<2);
//    IO0DIR |= (1<<3);
//	
//	  IO1DIR &= ~(1<<16); //input
//    IO1DIR &= ~(1<<17);
//    IO1DIR &= ~(1<<18);
//    IO1DIR &= ~(1<<19);
//	  IO1DIR &= ~(1<<20);
//	
//	  IO1DIR &= ~(1<<21);// ir sensor
//    IO1DIR &= ~(1<<22);
//    IO1DIR &= ~(1<<23);
//	
//	  IO0CLR = (1<<0) | (1<<1) | (1<<2) | (1<<3);
//	  delay(10);
//    while(1)
//    { 
//			
//		if(!(IO1PIN & (1 << 21)))
//		{
//			IO0CLR = (1<<0) | (1<<1) | (1<<2) | (1<<3);
//	    delay(20);
//			IO0SET = (1<<1) | (1<<3);//anticlockwise 
//      IO0CLR = (1<<0) | (1<<2);
//			delay(50);
//		}
//		else if(!(IO1PIN & (1 << 22)))
//			 {
//			 IO0CLR = (1<<0) | (1<<1) | (1<<2) | (1<<3); 
//			 delay(20);
//			 IO0SET = (1<<0);//right and motor 1
//       IO0CLR = (1<<1) | (1<<2)| (1<<3);
//			 delay(50);
//			 }
//		else if(!(IO1PIN & (1 << 23)))
//			 {
//				 IO0CLR = (1<<0) | (1<<1) | (1<<2) | (1<<3);  
//			   delay(20);
//			 IO0SET = (1<<2);//left and motor 2
//       IO0CLR = (1<<0) | (1<<1)| (1<<3) ;
//			 delay(50);
//			 }
//		else
//		{
//			IO0SET = (1<<0) | (1<<2);//clockwise and forward
//      IO0CLR = (1<<1) | (1<<3);
//			delay(50);
//		}
//			
//		/*	IO0CLR = (1<<0) | (1<<1) | (1<<2) | (1<<3);
//	    delay(10);
//			
//			IO0SET = (1<<1) | (1<<3);//anticlockwise 
//          IO0CLR = (1<<0) | (1<<2);
//			delay(50);
//			
//			IO0CLR = (1<<0) | (1<<1) | (1<<2) | (1<<3);
//	    delay(10);*/
//			
//		/*if(!(IO1PIN & (1 << 22)))
//				{
//					IO0CLR = (1<<0) | (1<<1) | (1<<2) | (1<<3); // middle ir 
//					delay(100);
//			    IO0SET = (1<<1) | (1<<3);//anticlockwise 
//          IO0CLR = (1<<0) | (1<<2);
//			 delay(10000);
//			 IO0CLR = (1<<0) | (1<<1) | (1<<2) | (1<<3);
//				}
//			 else if(!(IO1PIN & (1 << 22)))
//			 {
//				 IO0CLR = (1<<0) | (1<<1) | (1<<2) | (1<<3); // left ir 
//			 delay(100);
//			 IO0SET = (1<<0);//right and motor 1
//       IO0CLR = (1<<1) | (1<<2)| (1<<3);
//			 delay(10000);
//			 IO0CLR = (1<<0) | (1<<1) | (1<<2) | (1<<3);
//			 }
//			 else if((IO1PIN & (1<<23)) == 0)
//			 {
//				 IO0CLR = (1<<0) | (1<<1) | (1<<2) | (1<<3); // right ir 
//			 delay(100);
//			 IO0SET = (1<<2);//left and motor 2
//       IO0CLR = (1<<0) | (1<<1)| (1<<3) ;
//			 delay(10000);
//			 IO0CLR = (1<<0) | (1<<1) | (1<<2) | (1<<3);
//			 }
//			 
//       else if(!(IO1PIN & (1 << 16)))
//				{
//					IO0SET = (1<<0) | (1<<2);//clockwise and forward
//          IO0CLR = (1<<1) | (1<<3);
//				}
//					
//        else if (!(IO1PIN & (1 << 17)))
//				{
//					IO0SET = (1<<1) | (1<<3);//anticlockwise and reverse
//          IO0CLR = (1<<0) | (1<<2);
//				}
//				
//				else if (!(IO1PIN & (1 << 18)))
//				{
//					IO0SET = (1<<0);//right and motor 1
//          IO0CLR = (1<<1) | (1<<2)| (1<<3);
//				}
//				
//				 else if (!(IO1PIN & (1 << 19)))
//        {
//					IO0SET = (1<<2);//left and motor 2
//          IO0CLR = (1<<0) | (1<<1)| (1<<3) ;
//				}

//        else if (!(IO1PIN & (1 << 20)))
//				{
//			    IO0CLR = (1<<1) | (1<<3)|(1<<0) | (1<<2);//stop
//				}*/

//    }
//}



 
#include <lpc214x.h>
#define bit(x) (1 << (x))

unsigned int i;

//void lcd_int(void);
//void dat(unsigned char);
//void cmd(unsigned char);
//void string(unsigned char *);
//void delay(unsigned int);


void delay(unsigned int x)
{
    unsigned int i,j;
    for(i=0; i<x; i++)
	  for(j=0; j<59999; j++);
}
void cmd(unsigned char a)
{
    IO0CLR = 0xFF << 16;     // Clear only LCD data pins P0.16-P0.23
     IO0SET = a << 16;

    IO0CLR |= bit(10);    // RS = 0
    IO0CLR |= bit(12);    // RW = 0
    IO0SET |= bit(13);   // EN = 1
    delay(1);
    IO0CLR |= bit(13);   // EN = 0
}
void dat(unsigned char b)
{
    IO0CLR = 0xFF << 16;    
    IO0SET = b << 16;

    IO0SET |= bit(10);    // RS = 1
    IO0CLR |= bit(12);    // RW = 0
    IO0SET |= bit(13);   // EN = 1
    delay(1);
    IO0CLR |= bit(13);   // EN = 0
}
void string(unsigned char *p)
{
    while(*p != '\0')
    {
        dat(*p++);
    }
}
void lcd_int()
{
    cmd(0x38);   // 8-bit mode, 2 lines
    cmd(0x0C);   // Display ON, Cursor OFF
    cmd(0x06);   // Auto increment cursor
    cmd(0x01);   // Clear display
}
void forward()
{
	cmd(0x80);           // First line
  string("Forward ");
	IO0CLR= (1<<2) | (1<<4);
	IO0SET = (1<<3) | (1<<5);//forward
	delay(50);
	
}
void reverse()
{
  cmd(0x01);
	cmd(0x80);           // First line
    string("Reverse ");
	IO0CLR= (1<<3) | (1<<5);
	IO0SET = (1<<2) | (1<<4);//reverse
	delay(50);
	
}
void left()
{
	cmd(0x01);
	cmd(0x80);           // First line
    string("Left ");
	IO0CLR = (1<<2) | (1<<3)| (1<<4);
	IO0SET = (1<<5);//left 
  delay(50);
}
void right()
{
	cmd(0x01);
	cmd(0x80);           // First line
    string("Right ");
	IO0CLR = (1<<2) | (1<<4)| (1<<5);
	IO0SET = (1<<3);//right 
  delay(50);
}
void stop()
{
	IO0CLR = (1<<2) | (1<<3) | (1<<4) | (1<<5);
	 delay(100);
}
int main()
{
    
    PINSEL0 = 0x00000000;
    PINSEL1 = 0x00000000;
    PINSEL2 = 0x00000000; 	

    IO0DIR |= (1<<2);  // output
    IO0DIR |= (1<<3);
    IO0DIR |= (1<<4);
    IO0DIR |= (1<<5);
	   IO0DIR |= (1<<7);
	  
    IO0DIR |= (0xFF << 16);      
    IO0DIR |= bit(10);       // RS
    IO0DIR |= bit(12);       // RW
     IO0DIR |= bit(13);       // EN
   
	  
	  IO1DIR &= ~(1<<27);// ir sensor
    IO1DIR &= ~(1<<28);
    IO1DIR &= ~(1<<29);
	
	  IO0CLR = (1<<2) | (1<<3) | (1<<4) | (1<<5);
	  delay(10);
		 lcd_int();delay(10);
		cmd(0x01);    
	   cmd(0x80);           // First line
    string("Robot Car ");
		 delay(500);
    while(1)
    {
			cmd(0x01);    
	    cmd(0x80);           // First line
     // string("Robot Car Moving....");
		  //delay(100);
			cmd(0x01); 
			
			
        if (!(IO1PIN & (1 << 27)))
				{
					  stop();
					reverse();
					 stop();
			  }
				else if(!(IO1PIN & (1 << 28)))
			 {
				  stop();
				 reverse();
				 stop();
			   left();
				 stop();

			 }
			 else if (!(IO1PIN & (1 << 29)))
			 {
				  stop();
				 reverse();
				  stop();
				 right();
				  stop();
			 }	
			else
		{
			forward();
		}
				
    }
		}
	
/*#include <lpc214x.h>
#define bit(x) (1 << (x))

unsigned int i;
void pwm_init(void);



void delay(unsigned int x)
{
    unsigned int i,j;
    for(i=0; i<x; i++)
	  for(j=0; j<59999; j++);
}
void cmd(unsigned char a)
{
    IO0CLR = 0xFF << 16;     // Clear only LCD data pins P0.16-P0.23
     IO0SET = a << 16;

    IO0CLR |= bit(10);    // RS = 0
    IO0CLR |= bit(12);    // RW = 0
    IO0SET |= bit(13);   // EN = 1
    delay(1);
    IO0CLR |= bit(13);   // EN = 0
}
void dat(unsigned char b)
{
    IO0CLR = 0xFF << 16;    
    IO0SET = b << 16;

    IO0SET |= bit(10);    // RS = 1
    IO0CLR |= bit(12);    // RW = 0
    IO0SET |= bit(13);   // EN = 1
    delay(1);
    IO0CLR |= bit(13);   // EN = 0
}
void string(unsigned char *p)
{
    while(*p != '\0')
    {
        dat(*p++);
    }
}
void lcd_int()
{
    cmd(0x38);   // 8-bit mode, 2 lines
    cmd(0x0C);   // Display ON, Cursor OFF
    cmd(0x06);   // Auto increment cursor
    cmd(0x01);   // Clear display
}
void pwm_init(void)
{
    PINSEL0 |= (2 << 0);       // P0.0 = PWM1
    PINSEL0 |= (2 << 14);      // P0.7 = PWM2

    PWMPR = 59;                // PWM counter resolution
    PWMMR0 = 1000;             // PWM period

    PWMMR1 = 300;              // PWM1 duty
    PWMMR2 = 300;              // PWM2 duty

    PWMMCR = (1 << 1);         // Reset PWM counter at MR0

    PWMPCR = (1 << 9) | (1 << 10);   // Enable PWM1 and PWM2

    PWMLER = (1 << 0) | (1 << 1) | (1 << 2);

    PWMTCR = (1 << 0) | (1 << 3);     // Enable PWM
}

void forward()
{
	cmd(0x80);           // First line
  string("Forward ");
	IO0CLR= (1<<2) | (1<<4);
	IO0SET = (1<<3) | (1<<5);//forward
	delay(50);
	
}
void reverse()
{
  cmd(0x01);
	cmd(0x80);           // First line
    string("Reverse ");
	IO0CLR= (1<<3) | (1<<5);
	IO0SET = (1<<2) | (1<<4);//reverse
	delay(50);
	
}
void left()
{
	cmd(0x01);
	cmd(0x80);           // First line
    string("Left ");
	IO0CLR = (1<<2) | (1<<3)| (1<<4);
	IO0SET = (1<<5);//left 
  delay(50);
}
void right()
{
	cmd(0x01);
	cmd(0x80);           // First line
    string("Right ");
	IO0CLR = (1<<2) | (1<<4)| (1<<5);
	IO0SET = (1<<3);//right 
  delay(50);
}
void stop()
{
	IO0CLR = (1<<2) | (1<<3) | (1<<4) | (1<<5);
	 delay(100);
}
int main()
{
    
    PINSEL0 = 0x00000000;
    PINSEL1 = 0x00000000;
    PINSEL2 = 0x00000000; 
pwm_init();		

    IO0DIR |= (1<<2);  // output
    IO0DIR |= (1<<3);
    IO0DIR |= (1<<4);
    IO0DIR |= (1<<5);
	   
	  
    IO0DIR |= (0xFF << 16);      
    IO0DIR |= bit(10);       // RS
    IO0DIR |= bit(12);       // RW
     IO0DIR |= bit(13);       // EN
   
	  
	  IO1DIR &= ~(1<<27);// ir sensor
    IO1DIR &= ~(1<<28);
    IO1DIR &= ~(1<<29);
	
	  IO0CLR = (1<<2) | (1<<3) | (1<<4) | (1<<5);
	  delay(10);
		 lcd_int();delay(10);
		cmd(0x01);    
	   cmd(0x80);           // First line
    string("Robot Car ");
		 delay(500);
    while(1)
    {
			//cmd(0x01);    
	    //cmd(0x80);           // First line
     // string("Robot Car Moving....");
		  //delay(100);
			//cmd(0x01); 
			
        if (!(IO1PIN & (1 << 27)))
				{
					stop();
					reverse();
					stop();
			  }
				else if(!(IO1PIN & (1 << 28)))
			 {
				 stop();
				 reverse();
				 stop();
			   left();
				 stop();

			 }
			 else if (!(IO1PIN & (1 << 29)))
			 {
				 stop();
				 reverse();
				 stop();
				 right();
				 stop();
			 }	
			else
		{
			forward();
		}
				
    }
		}*/