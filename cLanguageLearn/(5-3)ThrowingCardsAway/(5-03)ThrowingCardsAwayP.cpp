#include<iostream>
#include<queue>

int N;

int main()
{
	//freopen("in.txt", "r", stdin);
	while (scanf("%d", &N) != -1 && N != 0) {
		std::queue<int> cardQueue;

		for (int i = 1; i <= N; ++i) cardQueue.push(i);
		printf("Discarded cards:");

		for (int n = 0; n < N - 1; ++n) {
			if (n) printf(",");
			printf(" %d", cardQueue.front());
			cardQueue.pop();
			cardQueue.push(cardQueue.front());
			cardQueue.pop();
		}
		printf("\nRemaining card: %d\n", cardQueue.front());
	}
	return 0;
}















