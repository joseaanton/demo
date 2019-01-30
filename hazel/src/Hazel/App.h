#pragma once
#include "core.h"

namespace hazel {

class HZ_API App {
public:
	App();
	virtual ~App();
	void run();
};

// to be defined in CLIENT
App* CreateApp();

}  // namespace hazel
