// Client application
#include "hazel.h"

//
class Sandbox : public hazel::App {
public:
	Sandbox() {}
	~Sandbox() {}
};

hazel::App* hazel::CreateApp() {
	return new Sandbox();
}
