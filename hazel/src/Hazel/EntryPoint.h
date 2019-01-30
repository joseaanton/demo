#pragma once

extern hazel::App* hazel::CreateApp();

int main(int argc, char** argv) {
	auto app = hazel::CreateApp();
	app->run();
	delete app;
}
