#include "ThreadPool.h"

int main()
{
	ThreadPool pool(20);
	std::this_thread::sleep_for(std::chrono::seconds(20));
	pool.Finish();
	return 0;

}