#pragma once

// extern hazel::App* hazel::CreateApp();

int main(int argc, char** argv) {

	// Main Logger Init
	static plog::ColorConsoleAppender<plog::TxtFormatter> appender;
	plog::init(plog::debug, &appender);
	hazel::initializeLog(plog::debug, plog::get());  // Hazel Logger Init

	HAZEL_TRACE("Hola {0}", "tonto");

	auto app = hazel::CreateApp();
	app->run();
	delete app;
}
