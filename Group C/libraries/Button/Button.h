#ifndef Button_h
#define Button_h

class Button {
private:
	int pinNum;
public:
	Button(int thePinNum);
	bool isPressed();
};

#endif
