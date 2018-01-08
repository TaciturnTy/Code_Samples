/*
	Tyler Paulley
	10/15/2017
	ReverseWords.cpp
	Exercise 3
*/
#include <iostream> 

//Reverses the chars between a start and stop value in a char array
void Reverse(char * start, char * stop)
{
	while (start < stop)
	{
		char swap = *start;
		*start = *stop;
		start++;
		*stop = swap;
		stop--;
	}
}

//Reverses the words in a char array
//Parameters: szWords is the char array, nSize is the size of the char array
void WordReverse(char * szWords, const int nSize)
{
	//WordReverse first reverses all the chars in the array then reverses the chars in each word. 
	//I was able to borrow code from exercise 4 to do the char reversal.
	char * begin = szWords;
	char * end = szWords + nSize - 2;
	while (begin < end)
	{
		char swap = *begin;
		*begin = *end;
		begin++;
		*end = swap;
		end--;
	}

	char * start = szWords;
	char * stop;
	for (int i = 0; i < nSize; i++)
	{
		if (szWords[i] == ' ')
		{
			stop = szWords + i - 1;
			Reverse(start, stop);
			start = stop + 2;
		}
		else if (szWords[i] == '\0')
		{
			stop = szWords + i - 1;
			Reverse(start, stop);
		}
	}
}

int main(int argv, char** argc)
{
	char myMessage[] = "This world is but a canvas to our imagination";		
	const int size = sizeof(myMessage) / sizeof(myMessage[0]);
		
	std::cout << "The original message is: " << myMessage << "\n";

	WordReverse(myMessage, size);
	
	std::cout << "The word reversed message is: " << myMessage << "\n";

	std::getchar();
	return 0;
}

