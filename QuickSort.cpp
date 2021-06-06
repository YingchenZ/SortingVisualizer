#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <time.h>
#include <vector>
#include <string>

class QuickSort {
private:
	std::vector<int> arr = {};
	time_t begin = 0;
	long long exchange = 0;
	int LOAD;
public:

	QuickSort(std::vector<int> vec, int load) {
		arr = vec;
		LOAD = load;
	}

	void visualize(std::vector<int> arr, std::string type) {
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0f, 1.0f, 1.0f);
		std::string title = "Algorithm: " + type;
		std::string status = "Load = " + std::to_string(LOAD) + "    Swap = " + std::to_string(exchange) + "    Time = " + std::to_string((clock() - begin) / 1000.0) + "s";
		glRasterPos2i(0, 850);
		for (char c : title) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}
		glRasterPos2i(0, 830);
		for (char c : status) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}

		// White
		glColor3f(1.0f, 1.0f, 1.0f);
		for (int i = 0; i < LOAD; i++) {
			glRecti(i, 0, i + 1, arr[i]);
		}
		glFlush();
		Sleep(1);
	}

	int partition(int left, int right) {
		int i = left, j = right;
		int pivot = arr[i];
		while (i < j) {
			while (i < j && arr[j] >= pivot)    j--;
			if (i >= j)  break;
			std::swap(arr[i], arr[j]);
			++exchange;
			visualize(arr, "Quick Sort");
			while (i < j && arr[i] <= pivot)    i++;
			if (i >= j)  break;
			++exchange;
			std::swap(arr[i], arr[j]);
			visualize(arr, "Quick Sort");
		}
		arr[i] = pivot;
		return i;
	}

	void quicksort(int left, int right) {
		if (left >= right)   return;

		int part = partition(left, right);

		quicksort(left, part - 1);
		quicksort(part + 1, right);

	}

	void sort() {
		begin = clock();
		quicksort(0, arr.size() - 1);
	}
};

