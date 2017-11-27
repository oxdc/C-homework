#include "h20171116.h"

void homework_2017_11_16_main(void)
{
	display_rectangle();
	walkant();
}

void display_rectangle(void)
{
	char mark = '*';

	CharRectangleList list = (CharRectangleList)malloc(1 * sizeof(CharRectangle));
	int size = 1;

	while (TRUE)
	{
		printf("Please input the (x, y) and (width, height) of a rectangle: \n"
			"Any error to end: ");
		int x = 0, y = 0, width = 0, height = 0;
		while (
			4 != scanf("%d %d %d %d", &x, &y, &width, &height) ||
			x < 0 ||
			y < 0 ||
			width < 0 ||
			height < 0)
		{
			ClearInputQueue();
			return;
		}
		ClearInputQueue();

		CharRectangle newRectangle;
		InitCharRectangle(
			&newRectangle,
			x,
			y,
			height,
			width, 
			mark
		);

		list[size - 1] = newRectangle;

		Draw(list, size);

		size++;
		CharRectangleList newlist = (CharRectangleList)malloc(size * sizeof(CharRectangle));
		memcpy(newlist, list, sizeof(CharRectangle) * (size - 1));
		free(list);
		list = newlist;
	}

	free(list);
}

void walkant(void)
{
	printf("How many ants are there? ");
	int count = 0;
	while (1 != scanf("%d", &count) ||
		count <= 0 ||
		count > 62)
	{
		printf("Input error. Must be an integer within [1, 62];");
		ClearInputQueue();
	}
	ClearInputQueue();

	printf("How long is the road? ");
	int length = 0;
	while (1 != scanf("%d", &length) ||
		length <= count ||
		length > ConsoleWidth() - 1)
	{
		printf("Input error. Must be an integer within [%d, %d];", 
			count + 1, 
			ConsoleWidth() - 1);
		ClearInputQueue();
	}
	ClearInputQueue();

	const char * id_char = 
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	int * direction = (int*)malloc(sizeof(int) * count);
	memset(direction, 0, sizeof(int) * count);
	int * ants_location = (int*)malloc(sizeof(int) * count);
	memset(direction, 0, sizeof(int) * count);
	char * road = (char*)malloc(sizeof(char) * (length + 1));
	memset(road, '_', length);
	road[length] = '\0';

	{
		int id = 0;
		while (id < count)
		{
			ClearConsoleWindow();

			printf("Please input the start location and moving direction of "
				"the No.%d ant. L for left, R for right.\n"
				"Example:\n"
				"Name Loc Direction\n"
				"  A  0 R\n\n",
				id + 1);

			char d = '\0';
			int start_loc = 0;

			while (TRUE)
			{
				printf("  %c  ", id_char[id]);

				if (2 != scanf("%d %c", &start_loc, &d))
				{
					printf("Input Error. Must be an integer and a character "
						"splitted by a blank.\n");
					ClearInputQueue();
					continue;
				}
				ClearInputQueue();

				if (start_loc < 0 || start_loc >= length)
				{
					printf("The ant must be on the road!\n");
					continue;
				}

				BOOL isConflicted = FALSE;
				int i;
				for (i = 0; i < id; ++i)
				{
					if (ants_location[i] == start_loc)
					{
						printf("You cannot put two ants at one place.\n");
						isConflicted = TRUE;
						break;
					}
				}

				if (isConflicted)
				{
					continue;
				}

				if (toupper(d) != 'R' && toupper(d) != 'L')
				{
					printf("Only R(r) or L(l) is accepted.\n");
					continue;
				}

				break;
			}

			ants_location[id] = start_loc;
			direction[id] = (toupper(d) == 'R') ? 1 : -1;
			id++;
		}
	}

	while (TRUE)
	{
		ClearConsoleWindow();

		memset(road, '_', length);
		road[length] = '\0';

		BOOL noAnt = TRUE;
		int id;
		for (id = 0; id < count; ++id)
		{
			if (ants_location[id] == -1)
			{
				continue;
			}

			noAnt = FALSE;

			if (road[ants_location[id]] == '_')
			{
				road[ants_location[id]] = id_char[id];
			}
			else
			{
				road[ants_location[id]] = '#';
			}
		}

		printf("%s\n",road);

		if (noAnt)
		{
			printf("No Ants are there!\n");
			Pause();
			break;
		}

		for (id = 0; id < count; ++id)
		{
			if (ants_location[id] + direction[id] < 0 || 
				ants_location[id] + direction[id] >= length || 
				ants_location[id] == -1)
			{
				ants_location[id] = -1;
				continue;
			}

			int i;
			for (i = id + 1; i < count; ++i)
			{
				if (ants_location[id] == -1 ||
					ants_location[i] == -1)
				{
					continue;
				}

				if (ants_location[i] == ants_location[id])
				{
					direction[id] = -direction[id];
					direction[i] = -direction[i];
				}
				else if (abs(ants_location[i] - ants_location[id]) == 1 &&
					direction[i] + direction[id] == 0)
				{
					direction[id] = -direction[id];
					direction[i] = -direction[i];
				}
			}

			ants_location[id] += direction[id];
		}

		Wait(2000);
	}

	free(direction);
	free(ants_location);
	free(road);
}