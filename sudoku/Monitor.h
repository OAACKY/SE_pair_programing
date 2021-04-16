#pragma once
class Monitor {
public:
	Monitor(int argc, char* argv[]);
	void Operation();
private:
	int argc;
	char **argv;
};