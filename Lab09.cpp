#include <iostream>
using namespace std;

class temp{
  private:
    int size;
    int a1[5][5];

  public:
    temp(){
      size = 5;
      for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
          a1[i][j] = 0;
    }

    temp(int arr[][5], int s){
      size = s;
      for (int i = 0; i < size; i++)
        for (size_t j = 0; j < size; j++)
          a1[i][j] = arr[i][j];
    }

    // void initialize(int arr[][5], int s){
    //   temp(arr, s);
    //   return;
    // }

    void print(){
      for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
          cout << a1[i][j] << endl;

      return;
    }

    int max(){
      int max = a1[0][0];
      for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
          if (a1[i][j] > max)
            max = a1[i][j];

        }

      return max;
    }

    void add(int arr[][5]){
      for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
          a1[i][j] += arr[i][j];

      return;
    }
};

int main(){
  int size = 5;
  int array[size][size] = {{1, 3, 4, 5, 6},
                    {0, 7, 8, 5, 2},
                    {2, 11, 12, 10, 9},
                    {4, 4, 11, 5, 6},
                    {1, 3, 14, 5, 6}};

  temp t(array, size);
  t.add(array);
  t.print();
  cout << t.max() << endl;

  return 0;
}
