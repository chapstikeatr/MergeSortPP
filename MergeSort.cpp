// divide
// conquer
// merge
#include <chrono>
#include <cstdio>
#include <iostream>
#include <time.h>
#include <stdexcept>
#include <vector>

using namespace std;
void merge(vector<int>& arr, int m, int l, int r) {
  int ls = m - l + 1;
  int rs = r - m;

  vector<int> arrL(ls);
  vector<int> arrR(rs);

  for (int i = 0; i < ls; i++) {
    arrL[i] = arr[l + i];
  }

  for (int j = 0; j < rs; j++) {
    arrR[j] = arr[m + 1 + j];
  }

  int x = 0;
  int y = 0;
  int c = l;
  while (x < ls && y < rs) {
    if (arrL[x] < arrR[y]) {
      arr[c] = arrL[x];
      c++;
      x++;
    } else {
      arr[c] = arrR[y];
      c++;
      y++;
    }
  }
  while (x < ls) {
    arr[c] = arrL[x];
    c++;
    x++;
  }

  while (y < rs) {
    arr[c] = arrR[y];
    c++;
    y++;
  }
}

void mergeSort(vector<int>& arr, int l, int r) {
  if (l >= r) {
    return;
  }

  int m = l + (r - l) / 2;

  mergeSort(arr, l, m);
  mergeSort(arr, m + 1, r);
  merge(arr, m, l, r);
}

int main(int argc, char *argv[]) {
  bool sorted = false;
  srand(time(NULL));
  while (!sorted) {
    try {
      const int ARRAY_LEN = stoi(argv[1]);
      vector<int> arr(ARRAY_LEN);

      for (int i = 0; i <= ARRAY_LEN - 1; i++) {
        arr[i] = rand();
      }

      using clock = chrono::steady_clock;
      auto start = clock::now();

      mergeSort(arr, 0, ARRAY_LEN - 1);

      auto end = clock::now();
      chrono::duration<double> elapsed = end - start;

      cout << ARRAY_LEN << "," << elapsed.count() << endl;

      sorted = true;
    } catch (const std::invalid_argument &e) {
      printf("Error: invalid_argument - not and integer!\n");
      printf("Enter an Integer: ");
      cin >> argv[1];
    }
  }
  return 0;
}
