#ifndef INCLUDED_TIMER
#define INCLUDED_TIMER

class Timer {
public:
	static Timer * instance();
	bool Timr(int timeDown);
private:
	Timer();
	~Timer();
	static Timer * sm_instance;
};
#endif // !INCLUDED_TIMER
