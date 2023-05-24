#include "header_file.h"

/**
 * signal_stop - Function that checks the signal of kayboard keys.
 * If signal was a CTRL + C stop the program.
 * @signal: The signal of the keyboard keys pressed.
 * Return: Void.
 */
void signal_stop(int signal)
{
	if (signal == 2)
	{
		_puts("");
		exit(1);
	}
}
