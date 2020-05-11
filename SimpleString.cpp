#include "SimpleString.h"
#include <string.h>

SimpleString::SimpleString()
{
	fCharacters = new char[1];
	*fCharacters = '\0';
}
SimpleString::~SimpleString()
{
	delete fCharacters;
}

#if TEST >= 1

SimpleString::SimpleString(const SimpleString& aOtherString)
{
	int lLength = strlen(aOtherString.fCharacters) + 1;
	fCharacters = new char[lLength];

	for (unsigned int i = 0; i < lLength; i++)
	{
		fCharacters[i] = aOtherString.fCharacters[i];
	}
}

#endif

#if TEST >= 3

SimpleString& SimpleString::operator=(const SimpleString& aOtherString)
{

}

#endif

#if TEST >= 5

virtual SimpleString::SimpleString* clone()
{

}

#endif

SimpleString& SimpleString::operator+(const char aCharacter)
{
	char *lTemp = new char[strlen(fCharacters) + 2];
	unsigned int i = 0;
	for( ; i < strlen(fCharacters); i++)
	{
		lTemp[i] = fCharacters[i];
	}
	lTemp[i++] = aCharacter;
	lTemp[i] = '\0';

	delete fCharacters;
	fCharacters = lTemp;
	return *this;
}
const char* SimpleString::operator*() const
{
	return fCharacters;
}