#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <time.h>
#include <vector>
#include <string>

class RadixSort {
private:
	std::vector<int> arr = {};
	time_t begin = 0;
	long long exchange = 0;
	int LOAD;
public:
	RadixSort(std::vector<int> vec, int load) {
		arr = vec;
		LOAD = load;
	}

	void visualize(std::vector<int> arr, std::string type) {
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0f, 1.0f, 1.0f);
		std::string title = "Algorithm: " + type + "    Load = " + std::to_string(LOAD);
		std::string status = "Swap = " + std::to_string(exchange) + "    Time = " + std::to_string((clock() - begin) / 1000.0) + "s";
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

	void countingSort(int exp) {
		std::vector<int> output(arr.size());
		std::vector<int> counting(10);

		for (int i = 0; i < arr.size(); i++) {
			int dig = (arr[i] / exp) % 10;
			counting[dig]++;
		}

		for (int i = 1; i < 10; i++) {
			// find out the actual position
			counting[i] += counting[i - 1];
		}

		for (int i = arr.size() - 1; i >= 0; i--) {
			int dig = (arr[i] / exp) % 10;
			output[counting[dig] - 1] = arr[i];
			counting[dig]--;
		}

		for (int i = 0; i < arr.size(); i++) {
			arr[i] = output[i];
			++exchange;
			visualize(arr, "Insertion Sort");
		}
	}

	int longestDig() {
		int maxDig = arr[0];
		for (int i : arr) {
			if (maxDig < i) {
				maxDig = i;
			}
		}
		return maxDig;
	}

	void sort() {
		int maxNum = longestDig();
		begin = clock();
		for (int num = maxNum, base = 1; num > 0; num /= 10, base *= 10) {
			countingSort(base);
		}
	}
};

