#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long long cases, days;
	scanf("%lld", &cases);
	for (long long testCases = 0; testCases < cases; testCases++) {
		scanf("%lld", &days);
		long long benefit = 0;
		vector<long long> value(days);
		for (long long testDays = 0; testDays < days; testDays++) 
			scanf("%lld", &value[testDays]);
		long long max = value[days-1];
		for (long long testDays = days - 1; testDays >= 0; testDays--) {
			if (max > value[testDays]) benefit += max - value[testDays];
			else max = value[testDays];
		}
		printf("%lld\n", benefit);
	}
	return 0;
}