//Developed by BAKUNIN#0001

#include <Windows.h>

#include "Util.h"

namespace Util
{
	static void accurate_sleep(int ms) // more accurate sleep better than the win32 sleep()
	{
		LONGLONG timerResolution;
		LONGLONG wantedTime;
		LONGLONG currentTime;

		QueryPerformanceFrequency((LARGE_INTEGER*)&timerResolution);
		timerResolution /= 1000;

		QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
		wantedTime = currentTime / timerResolution + ms;
		currentTime = 0;
		while (currentTime < wantedTime)
		{
			QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
			currentTime /= timerResolution;
		}
	}

	void simple_smooth(int move_point_x, int move_point_y, double delay) // Simple Smoothing function to allow for smooth movement from point a - b
	{
		for (int i = 0; i < 5; i++) { // loop 6 iterations

			mouse_event(1, move_point_x / 5, move_point_y / 5, 0, 0); // divide the total movement value by however so once the 6 iterations are over its completed a full move

			accurate_sleep(delay / 5); // same idea but diving the sleep time
		}

		mouse_event(1, move_point_x % 5, move_point_y % 5, 0, 0); // move for the remainer of the 6 iterations
	}
}



