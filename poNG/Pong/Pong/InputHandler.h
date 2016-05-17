#ifndef __INPUT_HANDLER_H__
#define __INPUT_HANDLER_H__

class InputHandler
{
public:
	static InputHandler* Get();

	bool IsPressed(char key);
	void SetKeyPressed(char key, bool pressed);
private:
	bool keys[255];
};

#endif