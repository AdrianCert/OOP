class Sort
{
	unsigned int count = 0;
	int* array = nullptr;
	bool _reversing = false;
	void internal_quickSort(int left, int right);
public:
	Sort(int min, int max);
	Sort(int* init, int count);
	Sort(int count, int* array);
	Sort(int count, ...);
	Sort( const char * string);
	void InsertSort(bool reverse = false);
	void QuickSort(bool reverse = false);
	void BubbleSort(bool reverse = false);
	void Print();
	int  GetElementsCount();
	int  GetElementFromIndex(int index);
};

bool integer_evaluation(int, int, bool);