#include "readPH.h"

int readPH(struct PHStruct *phStruct)
{
	int i2c_fd;
	int adsAddress = 0x48;
	int16_t val;
	uint8_t writeBuf[3];
	uint8_t readBuf[2];
	float ph;

	const float VPS = 1/(198807.142857*0.02);    
    // volts per step

	/*
	The resolution of the ADC in single ended mode 
	we have 15 bit rather than 16 bit resolution, 
	the 16th bit being the sign of the differential 
	reading.
	*/

  	// open device on /dev/i2c-1 the default on Raspberry Pi B
  	if ((i2c_fd = open("/dev/i2c-1", O_RDWR)) < 0) {
    	printf("Error: Couldn't open device! %d\n", i2c_fd);
    	exit (1);
  	}

	// connect to ADS1115 as i2c slave
	if (ioctl(i2c_fd, I2C_SLAVE, adsAddress) < 0) {
		printf("Error: Couldn't find device on address!\n");
		exit (1);
	}

	// set config register and start conversion
	// AIN0 and GND, 4.096v, 128s/s
	// Refer to page 19 area of spec sheet
	writeBuf[0] = 1; // config register is 1
	writeBuf[1] = 0b11000010; // 0xC2 single shot off
	// bit 15 flag bit for single shot not used here
	// Bits 14-12 input selection:
	// 100 ANC0; 101 ANC1; 110 ANC2; 111 ANC3
	// Bits 11-9 Amp gain. Default to 010 here 001 P19
	// Bit 8 Operational mode of the ADS1115.
	// 0 : Continuous conversion mode
	// 1 : Power-down single-shot mode (default)

	writeBuf[2] = 0b10000101; // bits 7-0  0x85
	// Bits 7-5 data rate default to 100 for 128SPS
	// Bits 4-0  comparator functions see spec sheet.

  	// begin conversion
  	if (write(i2c_fd, writeBuf, 3) != 3) {
    	perror("Write to register 1");
    	exit (1);
  	}	

  	sleep(1);

 
  	// set pointer to 0
  	readBuf[0] = 0;
  	if (write(i2c_fd, readBuf, 1) != 1) {
    	perror("Write register select");
    	exit(-1);
  	}
  

  	while (1)   {

    	// read conversion register
    	if (read(i2c_fd, readBuf, 2) != 2) {
      		perror("Read conversion");
      	exit(-1);
    	}

    	// could also multiply by 256 then add readBuf[1]
    	val = readBuf[0] << 8 | readBuf[1];

    	// with +- LSB sometimes generates very low neg number.
    	if (val < 0)   val = 0;

    	ph = val * VPS; 

    
    	//printf("pH = %4.2f \n", ph);

        phStruct->phMutex.lock();
        phStruct->ph = ph;
        phStruct->phMutex.unlock();

     
     	sleep(5);


  	} // end while loop

  	// power down ASD1115
  	// writeBuf[0] = 1;    // config register is 1
  	// writeBuf[1] = 0b11000011; // bit 15-8 0xC3 single shot on
  	// writeBuf[2] = 0b10000101; // bits 7-0  0x85
  	// if (write(i2c_fd, writeBuf, 3) != 3) {
   //  	perror("Write to register 1");
   //  	exit (1);
  	// }

 	close(i2c_fd);

	return 0;
}
