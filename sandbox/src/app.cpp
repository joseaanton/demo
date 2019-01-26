namespace demo {

__declspec(dllimport) void print();

}

int main() {

	demo::print();
	return 0;
}
