#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Helper function to convert a bit array to a decimal number
int convertToDecimal(const vector<int>& bitArray) {
    int decimalValue = 0;
    for (int bitIndex : bitArray) {
        decimalValue += pow(2, bitIndex); // Add the power of 2 corresponding to each bit set to 1
    }
    return decimalValue;
}

// Function to sort binary numbers represented as indices of 1-bits
vector<int> sortBinaryNumbers(vector<vector<int>>& bitArrays) {
    int n = bitArrays.size();
    vector<pair<int, int>> decimalWithIndex; // Pair to store {decimalValue, originalIndex}

    // Convert each bit array to its decimal equivalent and store with its index
    for (int i = 0; i < n; ++i) {
        int decimalValue = convertToDecimal(bitArrays[i]);
        decimalWithIndex.push_back({decimalValue, i});
    }

    // Sort based on the decimal values in descending order
    sort(decimalWithIndex.rbegin(), decimalWithIndex.rend());

    // Extract the indices in the order of the sorted decimal values
    vector<int> result;
    for (const auto& elem : decimalWithIndex) {
        result.push_back(elem.second);
    }

    return result;
}

int main() {
    // Example input
    vector<vector<int>> bitArrays = {{1}, {2}, {0}};

    // Call the function
    vector<int> result = sortBinaryNumbers(bitArrays);

    // Output the result
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
