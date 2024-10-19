namespace myMath {
	int sum(int a, int b) {
		return a + b;
	}
}

namespace momFriendMath {
	int sum(int a, int b) {
		return a - b;
	}
}

int main() {
	return myMath::sum(1, 2) + momFriendMath::sum(1, 2);
}
