#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Heap {
public:
    Heap() {};
    void push(const int num) {
        vec.push_back(num);

        int son = vec.size() - 1;
        
        while (son != 0) {
            int father = (son - 1) >> 1;
            if (vec[son] < vec[father]) {
                swap(vec[son], vec[father]);
            }
            son = father;
        }
    }
    
    void pop() {
        if (vec.size() < 1) return;
        int num = vec.back();
        vec.pop_back();
        vec[0] = num;

        int father = 0;
        while (father < vec.size()) {
            int leftSon = (father << 1) + 1;
            int rightSon = (father << 1) + 2;
            // cout << leftSon << endl;
            
            int isLeft = true;
            int lessSonVal = leftSon < vec.size() ? vec[leftSon]: INT_MAX;
            if (rightSon < vec.size() && vec[rightSon] < lessSonVal) {
                lessSonVal = vec[rightSon];
                isLeft = false;
            }

            if (vec[father] > lessSonVal) {
                if (isLeft) {
                    swap(vec[father], vec[leftSon]);
                    father = leftSon;
                } else {
                    swap(vec[father], vec[rightSon]);
                    father = rightSon;
                }
            } else {
                break;
            }
        }
    }

    void show() {
        for (int i = 0; i < vec.size(); ++i) {
            cout << vec[i] << " ";
        }
        cout << endl;
    }

private:
    vector<int> vec;
};

int main() {
    Heap h;
    h.push(1);
    h.push(99);
    h.push(100);
    h.push(30);
    h.push(21);
    h.show();
    h.pop();
    h.show();
    return 0;
}
