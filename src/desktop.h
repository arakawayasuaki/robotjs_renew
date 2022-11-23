#pragma once
#ifndef DESKTOP_H
#define DESKTOP_H

#include <string>

#include "types.h"

#if defined(_MSC_VER)
	#include "ms_stdbool.h"
#else
	#include <stdbool.h>
#endif

	std::string getActiveDesktopI();
	std::string getCurrentDesktopI();
	void setThreadActiveDesktopI();


#endif /* DESKTOP_H */
