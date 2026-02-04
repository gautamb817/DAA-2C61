#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
};


bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int main() {
    int N = 3;
    int W = 50;

    vector<Item> items = {
        {100, 20},
        {60, 10},
        {120, 40}
    };

    
    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0;
    int remainingWeight = W;

    for (int i = 0; i < N && remainingWeight > 0; i++) {
        if (items[i].weight <= remainingWeight) {
            
            maxValue += items[i].value;
            remainingWeight -= items[i].weight;
        } else {
            
            maxValue += items[i].value * 
                        ((double)remainingWeight / items[i].weight);
            remainingWeight = 0;
        }
    }

    cout << "Maximum value = " << maxValue << endl;

    return 0;
}
