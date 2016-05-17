#include "InputHandler.h"

InputHandler* InputHandler::Get()
{
	static InputHandler singleton;
	return &singleton;
}

bool InputHandler::IsPressed(char key)
{
	return keys[key];
}

void InputHandler::SetKeyPressed(char key, bool pressed)
{
	keys[key] = pressed;
}
