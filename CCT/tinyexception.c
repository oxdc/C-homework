#include "tinyexception.h"

Exception ** exception_items = NULL;

Exception Exception__(const char * msg)
{
	Exception e;
	e.message = msg;
	return e;
}

void throw__f(Exception e)
{
	Exception * exception_item = New(Exception, 1);
	$(exception_item) = e;
	exception_items[0] = exception_item;
}

void AddException()
{
	if (exception_items == NULL)
	{
		exception_items = New(Exception*, 1);
		exception_items[0] = NULL;
	}
	else
	{
		Exception ** new_exception_items = 
			New(Exception*, 
				CountOf(exception_items, Exception*) + 1);
		memcpy(new_exception_items + 1, 
			exception_items, 
			SizeOf(exception_items));
		new_exception_items[0] = New(Exception, 1);
		new_exception_items[0] = NULL;
		Delete(exception_items);
		exception_items = new_exception_items;
	}
}

int CheckException()
{
	if (exception_items[0] == NULL)
	{
		return FALSE;
	}
	else
	{
		exception_items[0] = NULL;
		return TRUE;
	}
}

void DisplayExceptionMessage__f(Exception e)
{
	printf("%s\n", e.message);
}
