//engr 121-01      enigmaencoder.c      sophia austin
//
//enigma team project

#include <stdio.h>
#include <string.h>

char message[15];
char code[15];
void userInput();
int r1,r2,encoder,length,encrypted,ASCIIUI;

int main()
{
	char letter1,letter2,encoded;

	int ascii1,ascii2;
	int i,j;
	
	printf("\nEnter the two letter code as XX: \t"); //user inputs the code that re-maps the alphabet to encode the message
	scanf("%c%c",&letter1,&letter2);
	ascii1=(int)letter1;
	ascii2=(int)letter2;
	printf("\nThe associated ASCII code is: %d %d \t",ascii1,ascii2);
	r1=ascii1-65; //rotor 1 calculating the distance of the key from position A
	r2=ascii2-65; //rotor 2 calculating the distance of the key from position A

	userInput();
	printf("\nMessage is: %s\n",message);
	//length=strlen(message);
	
	encoder=r1+r2;

	//for(i=0;i<length;++i){
	for(i=0;i<15;++i){
		ASCIIUI=(int)message[i]; //converts each using input character to ASCII code
		encrypted=ASCIIUI+encoder+i; //increment rotor

		if(encrypted>90){
			while(encrypted>90){
				encrypted=encrypted-26; //must subtract 26 to get back to top of alphabet
			}
		}
		code[i]=(char)encrypted; //convert integer variable to characters, encrypts the message using code entered at beginning by user
	}
	printf("\nThe encrypted message is: %s \n\t",code); //displays encrypted message, keep in terminal window, you need it for the input on the decoder part

	printf("\nEnd Program\n");

}

void userInput()
{
	printf("\n\nInput 15 letter message: "); //user inputs the 15-character message to encode and later decode
	scanf("%s",message);
}
