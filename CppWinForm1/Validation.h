class Validation {
private:
	bool isValid;
public:
	Validation();
	bool validateString(String^ string);
	bool validateNumber();
};