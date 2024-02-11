#include <iostream>
#include <vector>
#include <string>

struct Measurement {
    std::string location;
    int sensorNumber;
    int value;
};

// Function to get the maximum number of digits in a given integer
int getMaxDigits(int num) {
    int digits =  0;
    while (num !=  0) {
        num /=  10;
        digits++;
    }
    return digits;
}

// Counting sort function to sort on individual digit
void countingSortOnDigit(std::vector<Measurement>& arr, int exp) {
    // Create output array and count array
    int size = arr.size();
    std::vector<Measurement> output(size);
    std::vector<int> count(10,  0);

    // Store count of occurrences in count[]
    for (int i =  0; i < size; i++)
        count[(arr[i].location[exp] - '0')]++;

    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (int i =  1; i <  10; i++)
        count[i] += count[i -  1];

    // Build the output array
    for (int i = size -  1; i >=  0; i--) {
        output[count[(arr[i].location[exp] - '0')] -  1] = arr[i];
        count[(arr[i].location[exp] - '0')]--;
    }

    // Copy the output array to arr[] so that arr[] contains sorted numbers according to current digit
    for (int i =  0; i < size; i++)
        arr[i] = output[i];
}

// Radix sort function to sort arr[] on basis of digit represented by exp.
void radixSort(std::vector<Measurement>& arr) {
    // Find the maximum number to know number of digits
    int maxNum =  0;
    for (int i =  0; i < arr.size(); i++) {
        if (arr[i].location.length() > maxNum)
            maxNum = arr[i].location.length();
    }

    // Do counting sort for every digit. Note that instead of passing digit number, exp is passed.
    // exp is  10^i where i is current digit number
    for (int exp =  0; exp < maxNum; exp++)
        countingSortOnDigit(arr, exp);
}

// Utility function to print an array
void print(const std::vector<Measurement>& arr) {
    for (auto& measurement : arr)
        std::cout << measurement.location << " " << measurement.sensorNumber << " " << measurement.value << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<Measurement> measurements(n);
    for (int i =  0; i < n; ++i) {
        std::cin >> measurements[i].location >> measurements[i].sensorNumber >> measurements[i].value;
    }

    // Sort the measurements using radix sort
    radixSort(measurements);

    // Now you would continue with sorting by sensorNumber and value, and finally calculate the sum

    // Placeholder for the sum calculation after full sorting
    // long long sum = ...

    // Print the measurements for debugging purposes
    print(measurements);

    return  0;
}
