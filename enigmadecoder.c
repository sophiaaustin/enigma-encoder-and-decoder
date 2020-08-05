//engr 121-01      enigmadecoder.c      sophia austin
//
//enigma team project

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char message[15];
char code[15];
char decoded;
void userInput();
int r1,r2,decoder,length,decrypted,ASCIIUI;

int main()
{
	char letter1,letter2,encoded;
	int ascii1,ascii2;
	int i,j;
	
	printf("\nEnter the two letter (ALL CAPITAL) code as XX: \t"); //user must enter the same two letter code from the encryption code in order to properly decode
	scanf("%c%c",&letter1,&letter2);
	ascii1=(int)letter1;
	ascii2=(int)letter2;
	printf("\nThe associated ASCII code is: %d %d \t",ascii1,ascii2);
	r1=ascii1-65; //rotor 1 calculating the distance of the key from position A
	r2=ascii2-65; //rotor 2 calculating the distance of the key from position A

	decoder=r1+r2; //add the positions of the rotors so that the value can be used to encode the user input

	userInput();

	for(i=0;i<15;++i){
		ASCIIUI=(int)message[i]; //convert each userinput character into ASCII integer
		decrypted=ASCIIUI-decoder-i; //add the encoder value plus the rotational value (i) to the ASCII integer to create another integer
		if (decrypted<65){ //if the value of the encryption is less than 65(A)
			while(decrypted<65){ //if the value is too small to be in the range, 26 will be continuously added until it is greater than 65(A)
				decrypted=(decrypted+26); //the 26 then must be subtracted from the value to get back to original position in alphabet
			}
		}
		//char decoded=decrypted; //converted the integer variable encrypted to characters
		//strcat(code,&decoded); //converted the encrypted variables to a string
		code[i]=(char)decrypted; //convert integer variable to characters
	}

	printf("\nYour decrypted message is: %s\n",code); //displays decrypted message
}
void userInput()
{
	printf("\n\nInput 15 letter message: \n"); //read this from the encrypted message displayed from the first part of the code
	scanf("%s",message);
}
