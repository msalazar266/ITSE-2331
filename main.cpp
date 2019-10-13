//-------------------------------------------------------------------------------------------------------------------------------
// Title : Self made string class
// Author: Matthew Salazar
// Date  : 09/19/2019
// Descr :
//		 A string class made for envp content printing.
//
//
//-------------------------------------------------------------------------------------------------------------------------------
// Side notes :
//			  Naive implementation
//			  Pointer + constant gives me a pointer, p + c = p
//
//
//-------------------------------------------------------------------------------------------------------------------------------
//SAS:   BLOCK COMMENT IN FRONT OF EVERY FUNCTION
//       Time management: Work on code *every* day.




#include <iostream>

using namespace std;

//STRLEN
//string length : STRLEN

//Initialize intLength to 0
//Validate intLength
//Loop until str is a NULL terminating character
//Return the length

size_t STRLEN( const char* str) {
	
	const char *ptr = str; /* pointer to character constant */
	 /* Loop over the data in s.  */
	while (*ptr != '\0')
		ptr++;
	return (size_t)(ptr - str);
	//int intLength = 0;

	//int i = 0;

 //  //SAS: OOPS... does the string pointer ever move forward????  You have to force yourself to see
 //  //     that the POINTER *IS* the COUNTER.  (i) in this loop is... unused.  (intLength) in this loop...
 //  //     is NOT needed: the pointer itself is enough (yes, you need to copy the original pointer to 
 //  //     compute the length as (pointerToEnd - str)
	//while ( *str != '\0') {
	//	intLength++;
	//	i = i + 1;
	//}

	//return intLength;
}



//STRCPY
//Validate destStr and sourceStr
//LOOP until *sourceStr is a NULL terminating character
//Return the destination 

char* STRCPY( char* dstStr,const char* srcStr) {
	//string copy : STRCPY
	//				int x;
	//				(x=10);
	
	//*p
	while ( *dstStr++ = *srcStr++) {
		// Empty body intentional
	}

	return dstStr;
}



//STRCHR
//string find char : STRCHR
//Compare the char at the index to the target char
//If char is not target char, increment
//If target char found return null pointer

//SAS:  Your mixing CONST and NON-CONST here... either const in, const out; or non-const in, non-const out!
char* STRCHR( const char* str, size_t c) {
	
	//size_t ctr = 0;
	char ch = c;
	///* Scan str for the character.  When this loop is finished,
	//   str will either point to the end of the string or the
	//   character we were looking for.*/
	//while (*str != '\0' && *str != c)
	//	str--;
	//return (*str == c) ? (char *)str : NULL;
	
	//char ch = c;
	while (*str != '\0' && *str != ch) {
		str++;
		//ctr++;
	}
	//cout << "CTR = " << ctr << endl;
	return (*str == ch) ? (char *)str : NULL;
	
	///*while ( *str != ch) {
	//	if ( !*str++) {
	//		return NULL;
	//	}
	//}
	//
	//return nullptr;*/
}



//strncpy
//Set length to copy
//Copy source string
//If '\0' is found before end of length, stop

char* STRNCPY(char *dstStr, const char *srcStr, size_t len) {

	char *ret = dstStr;
	do {
		if (!len--) {
			return ret;
		}
	} while (*dstStr++ = *srcStr++);
	while (len--) {
		*dstStr++ = 0;
		return ret;
	}

	////char *dst = s1;
	////const char *src = s2;
	////* Copy bytes, one at a time.  */
	//while (len > 0) {
	//	len--;
	//	if ((*dstStr++ = *srcStr++) == '\0') {
	//		/* If we get here, we found a null character at the end
	//		   of s2, so use memset to put null bytes at the end of
	//		   s1.  */
	//		memset(dstStr, '\0', len);
	//		break;
	//	}
	//}
	//return dstStr;


	////*char *dst = s1;
	//const char *src = s2;*/
	////* Do the copying in a loop.  */
	//while ((*dstStr++ = *srcStr++) != '\0');
	////* The body of this loop is left empty. */
	//
	////* Return the destination string.  */
	//return dstStr;


	//unsigned int len = 0;

 //  //SAS: Combine pointer with counter... 
 //  //SAS: This loop stops at the end of the source string...
 //  //     Shouldn't loop ALWAYS copy LENGTH character?
	//while (*(srcStr + len) != '\0' || len < n) {

	//	if (*(srcStr + len) != '\0' && len < n) {
	//		*(dstStr + len) = *(srcStr + len);
	//		
	//	}
	//	else {
	//		*(dstStr + len) = '\0';    //SAS: And since loops stops at end of src, this never executes...
	//		len++;
	//	}
	//	
	//	//dstStr = '\0';
	//	return dstStr;
	//}

 //  //SAS: Must be a return of something here...
}



//STRTRUNC
//Truncate str to length characters, ending with "..."
//If STRLEN(str) <= length, make no modification to str
//return orginal str pointer

char* STRTRUNC( char* str, size_t len) {
	
	//STRLEN(str) = (char*)strlen;
	char* ptr = (str - len + 70);	//+3

	*ptr = '\0';
	
	char* q = ptr - 70;	//-3

	//if ( STRLEN(str) <= len) {
	//	return str;
	//}
	//else{
	//	return str - 
	//}
	//strncpy( namebuffer, )
	
	return str;
	
}



//Main function
//Printing out envp contents
//Contents separated at '='
//Left of '=' is name, right of '=' is value
//Print to screen

int main(int argc, char* argv[], char* envp[]) {

	char nameBuffer[33];
	char valueBuffer[65];
	int intLoop = 0;
	int intDiff = 0;
	
	cout << "NAME" << "\t\t\t\t\t" << "VALUE" << endl;
	cout << endl;
	
	while (envp[intLoop] != nullptr) { // stop when reaching end of array
	
		STRCPY(valueBuffer, STRCHR(envp[intLoop], '='));
		
		intDiff = (STRLEN(envp[intLoop])) - (STRLEN(valueBuffer));
		
		STRNCPY(nameBuffer, envp[intLoop], intDiff);
		
		STRTRUNC(valueBuffer, 6);
		
		STRTRUNC(nameBuffer, 38);
		
		cout << nameBuffer << "...";
		cout << "\t" << valueBuffer << endl;
		cout << endl;

		intLoop++;
	}
}

	//cout << STRLEN(envp[intloop]) << endl;
	//for (i = 0; i < STRLEN(envp[intloop]); i++) {
	//	string splitResult = envp[intloop].split('=');
	//	string expectedValue = splitResult[1];
	//	// Note: Both null and yes will be a string.
	//	if (expectedValue == "null") { // Do something}
	//	else if (expectedValue == "yes") { // Do something else }
	//	}
	//cout << STRRCHR(envp[intloop], '=') << endl;
	//STRNCPY(nameBuffer, envp[intloop], 32);
	//cout << STRTRUNC(nameBuffer, 39) << endl;
	//cout << STRNCPY(nameBuffer, envp[intloop], 6) << endl;;
	//cout << "\t\t" << valueBuffer << endl;
	//STRLEN(envp[intloop]);
	//cout << STRCHR(envp[intloop], '=') << endl;
	//STRCHR(envp[intloop], '=');
	//STRCPY(valueBuffer, );
	//cout << STRCPY(valueBuffer, STRCHR(envp[intloop], '=')) << endl;
	//cout << STRTRUNC(valueBuffer, 7) << endl;
	//cout << intloop << "	";
	//cout << &envp[intloop] << "	"; // print address of array
	//cout << (void*)envp[intloop] << "	";
	//cout << strlen(envp[intloop]) << "	"; // print length of cstring
	//cout << envp[intloop] << endl << endl;

	//STRNCPY(nameBuffer, "ABC", 10);		//  ABC0000000 => "ABC"
	//STRNCPY(nameBuffer, dogName, 4);		//  BOC0000000 => "BOC"
	//cout << "STRNCPY\n" << nameBuffer << endl;
	//const char* dogName = "Doggmutt";
	//int intIndex = 0;
	//char *srcName = envp[intIndex];
	//cout << "STRCHR\n" << STRCHR( dogName, 'm') << endl;
	//STRCPY( nameBuffer, dogName);
	//cout << "STRCPY\n" << nameBuffer << endl;
	//cout << "STRNCPY\n" << STRNCPY( valueBuffer, dogName, 4) << endl;	
	//cout << "STRTRUNC\n" << STRTRUNC( envp[intIndex], 32) << endl;
	
	//cout << "PtrContent" << endl;
	//while (envp[intIndex] != nullptr) { //This while loop will stop when reaching end of array
	//   
 //     //SAS: Number on problem: srcName is initialized ONCE... shouldn't it be INSIDE THE LOOP??
 //     //SAS: You're on the right track, but ran out of time.
	//	STRCHR(srcName, '=');      //SAS:  What are you doing with the RESULT??? Nothing!?
	//	
	//	STRLEN(srcName);           //SAS:  Ditto
	//	
	//	STRNCPY( nameBuffer, srcName, STRLEN(srcName));
	//	
	//	STRTRUNC(srcName, 32);
	//	
	//	cout << "STRCHR: " << srcName << endl;
	//	cout << srcName << endl; //Prints the pointer content
	//	intIndex++;
	////Can't seem to figure this out, sadly.
	//}
	//char** p = envp;
	//for (*p != nullptr);{
	//	cout << *p++ << endl;
	//}
	//return 0;
