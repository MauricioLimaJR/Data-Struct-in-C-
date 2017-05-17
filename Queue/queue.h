class Queue{
	int capacity;
	float *data;
	int first;
	int last;
	int amount;
	public:
		Queue(int value);
		void enqueue(int element);
		int dequeue();
		void peek();
		void inverse();
		bool q_empty();
		bool q_full();
		int q_size();
};