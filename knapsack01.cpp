#include <iostream>
#include <vector>

using namespace std;

struct Knapsack{
    int size;
    Knapsack():size(0){}
    Knapsack(int size):size(size){}
};

struct Item{
    signed long long int weight;
    signed long long int value;

    Item():weight(0), value(0){}
    Item(signed long long int weight, signed long long int value):weight(weight), value(value){}
};

struct KnapsackProblem{
    Knapsack knapsack;
    vector<Item> items;
    vector<vector<signed long long int>> valueArray;
    vector<vector<bool>> keepArray;

    void init(){
        valueArray.clear();
        valueArray.resize(items.size() + 1);
        for (auto& row : valueArray) {
            row.resize(knapsack.size, 0);
        }
        keepArray.clear();
        keepArray.resize(items.size() + 1);
        for (auto& row : keepArray) {
            row.resize(knapsack.size, false);
        }
    }

    void solve(){
        for(unsigned int rowIndex = 1; rowIndex < valueArray.size(); ++rowIndex) {
            for (unsigned int columnIndex = 0; columnIndex < valueArray[0].size(); ++columnIndex) {
                Item item = items[rowIndex - 1];
                unsigned int knapsackSize = columnIndex + 1;

                if(item.weight <= knapsackSize){
                    signed long long int upperRowValue = valueArray[rowIndex - 1][columnIndex];
                    signed long long int spaceLeftValue =  0;
                    if(columnIndex - item.weight >= 0 && rowIndex - 1 > 0){
                        spaceLeftValue = valueArray[rowIndex - 1][columnIndex - item.weight];
                    }

                    if(item.value + spaceLeftValue > upperRowValue){
                        keepArray[rowIndex][columnIndex] = 1;
                        valueArray[rowIndex][columnIndex] = item.value + spaceLeftValue;
                    }else{
                        valueArray[rowIndex][columnIndex] = upperRowValue;
                    }
                }
            }
        }
    }

    void clear() {
        valueArray.clear();
        keepArray.clear();
    }

    vector<Item> getFitableItems() {
        vector<Item> result;

        int sizeLeft = knapsack.size - 1;       // coloumn
        int itemIndex = items.size() - 1;   // row

        while (sizeLeft > 0 && itemIndex > 0) {
            if (keepArray[itemIndex][sizeLeft] == true) {
                result.push_back(items[itemIndex - 1]); // because 0 row
                sizeLeft = sizeLeft - items[itemIndex - 1].weight;
            }
            itemIndex--;
        }

        return result;
    }

    void setKnapsack(Knapsack _knapsack){
        knapsack = _knapsack;
    }

    void addItem(Item item){
        items.push_back(item);
    }

    void print(){
        cout << "Knapsack current state" << endl;
        cout << "Size: " + to_string(knapsack.size) + " Item count: " + to_string(items.size()) << endl;

        for(auto& item : items){
            cout << "{ Weight: " << to_string(item.weight) << ", Value: " << to_string(item.value) << " }" << endl;
        }

        cout << endl << "Value matrix: " << endl;
        printValueMatrix();
        cout << endl;
        cout << "Keep matrix: " << endl;
        printKeepMatrix();
    }

    void printValueMatrix(){
        int rowIndex = 0;

        cout << "V" << "   ";
        for (int colomnIndex = 0; colomnIndex < valueArray[0].size(); ++colomnIndex) {
            cout << to_string(colomnIndex + 1) << " ";
        }
        cout << endl;
        cout << "   ";
        for (int colomnIndex = 0; colomnIndex < valueArray[0].size(); ++colomnIndex) {
            cout << " -";
        }
        cout << endl;

        for(const auto& row : valueArray){
            cout << to_string(rowIndex) << " | ";
            for(const auto& cell : row){
                cout << to_string(cell) + " ";
            }
            cout << endl;
            rowIndex++;
        }
    }

    void printKeepMatrix(){
        int rowIndex = 0;

        cout << "K" << "   ";
        for (int colomnIndex = 0; colomnIndex < valueArray[0].size(); ++colomnIndex) {
            cout << to_string(colomnIndex + 1) << " ";
        }
        cout << endl;
        cout << "   ";
        for (int colomnIndex = 0; colomnIndex < valueArray[0].size(); ++colomnIndex) {
            cout << " -";
        }
        cout << endl;

        for(const auto& row : keepArray){
            cout << to_string(rowIndex) << " | ";
            for(const auto& cell : row){
                cout << to_string(cell) + " ";
            }
            cout << endl;
            rowIndex++;
        }
    }
};

int main()
{
    KnapsackProblem problem;
    Knapsack knapsack;
    knapsack.size = 5;

    problem.setKnapsack(knapsack);

    // https://www.youtube.com/watch?v=EH6h7WA7sDw&t
    Item item1(3,5);
    Item item2(2,3);
    Item item3(1,4);

    problem.addItem(item1);
    problem.addItem(item2);
    problem.addItem(item3);

    problem.init();
    problem.solve();
    problem.print();

    return 0;
}