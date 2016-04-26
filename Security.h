#pragma once
using namespace System;
using namespace System::Text;
using namespace System::Security::Cryptography;
using namespace System::Security::AccessControl;
using namespace System::Collections;

public ref class Service
{

private: 
	String^ securityKey = "Fqw4$@gwertgHRTEWs";


	/// This will convert text to Encrypted Text format.

public:
	array<Byte>^ EncryptText(UTF8Encoding^ utf8, String^ encryptString)
	{

		// A Unicode string with two characters outside an 8-bit code range.
		String^ unicodeString = encryptString;
		Console::WriteLine("Original string:");
		Console::WriteLine(unicodeString);

		// Encode the string.
		array<Byte>^ encodedBytes = utf8->GetBytes(unicodeString);
		Console::WriteLine();
		Console::WriteLine("Encoded bytes:");
		for (int ctr = 0; ctr < encodedBytes->Length; ctr++) {
			Console::Write("{0:X2} ", encodedBytes[ctr]);
			if ((ctr + 1) % 25 == 0)
				Console::WriteLine();
		}
		return encodedBytes;
	}
	/*String^ Encrypting(String^ toEncrypt)
	{
		String^ encrypted = "";
		for (int temp = 0; temp < toEncrypt->Length; temp++) {
			encrypted += toEncrypt[temp] ^ (int(key[temp % (sizeof(key) / sizeof(char))]));
		}
		return encrypted;
	}*/


	String^ DecryptText(UTF8Encoding^ utf8, array<Byte>^ encodedBytes)
	{
		// Decode bytes back to string.
		String^ decodedString = utf8->GetString(encodedBytes);
		return decodedString;
	}


};
