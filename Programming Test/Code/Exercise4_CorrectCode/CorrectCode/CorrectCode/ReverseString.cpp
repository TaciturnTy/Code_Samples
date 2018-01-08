/*
	Tyler Paulley
	10/15/2017
	ReverseString.cpp
	Exercise 4
*/
#include <iostream> 

int main(int argv, char** argc)
{
	char szMessage[] = "Who wants Toast!!!";								//szMessage points to the starting address of the char array
	char * begin = szMessage;												//copy address szMessage to begin
		
	char * end = szMessage + sizeof(szMessage) / sizeof(szMessage[0]) - 2;	//sizeof returns 19 due to null terminated byte
																			//equivalent to: address + 19 / 1 - 2 = 17
																			//end points to the address in memory 17 bytes above the address of szMessage
	while (begin < end)
	{
		char swap = *begin;													//set swap to the value at the address pointed to by begin
		
		//*begin++ = *end;													//this statement is incorrect: it tries to increment the address of 
																			//begin by one byte and change the value at that address in one statement.
																			//We need to use two statements
			
		*begin = *end;														//set value at begin's address to the value at end's address


		begin++;															//increment address of begin by 1 byte
																			//knowing chars are 1 byte, we can use begin++ instead of begin += sizeof(szMessage[0]);


		//*end++ = swap;													//this statement is incorrect for the same reason as *begin++ = *end;
																			//this statement also should decrement the address of end instead of incrementing it


		*end = swap;														//set value at end's address to the value of swap
		end--;		
	}
	std::cout << szMessage;
	std::getchar();
	return 0;
}

