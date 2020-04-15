#include "shell.h"

/**
  * interrupt - handle process intrruption when ctrl c pressed
  * @state:int
  */
void interrupt(int state)
{
	(void) state;
	write(1, "\n#> ", 3);
}
