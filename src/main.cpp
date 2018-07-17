#include <ThreadSafeQueue.h>

#include <thread>


using namespace std;

int main()
{
	ThreadSafeQueue<int> q;

	std::thread consumer([&q]() {
		while (true)
		{
			int i = q.pop();
			if (i == 0)
			{
				break;
			}
		}
	});

	q.emplace(1);
	q.emplace(2);
	q.emplace(3);
	q.emplace(4);

	std::thread producer([&q]() {
		for (int i = 10; i >= 0; i--)
		{
			q.emplace(i);
		}
	});

	producer.join();
	consumer.join();

	return !q.empty();
}