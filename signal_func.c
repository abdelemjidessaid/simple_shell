#include "header_file.h"

/**
 * signal_stop - function that checks the signal of kayboard keys
 * if signal was a CTRL + C stop the program.
 * @signal: the signal of the keyboard keys pressed.
 * Return: void.
 */
void signal_stop(int signal)
{
	if (signal == 2)
	{
		_puts("");
		exit(1);
	}
}