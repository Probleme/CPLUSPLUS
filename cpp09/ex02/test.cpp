#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <algorithm> // for std::lower_bound

// Function to perform binary insertion for a vector of ints
void binaryInsertVector(std::vector<int> &mainChain, int element)
{
    std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), element);
    mainChain.insert(it, element);
}

// Function to perform binary insertion for a deque of ints
void binaryInsertDeque(std::deque<int> &mainChain, int element) {
    std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), element);
    mainChain.insert(it, element);
}

// Merge insertion sort for std::vector<int>
void mergeInsertionSortVector(std::vector<int> &arr) {
    int n = arr.size();
    if (n <= 1) return;

    std::vector<int> larger, smaller;
    for (int i = 0; i < n / 2; ++i)
    {
        if (arr[2 * i] < arr[2 * i + 1])
        {
            smaller.push_back(arr[2 * i]);
            larger.push_back(arr[2 * i + 1]);
        }
        else
        {
            smaller.push_back(arr[2 * i + 1]);
            larger.push_back(arr[2 * i]);
        }
    }

    if (n % 2 != 0) 
        smaller.push_back(arr[n - 1]);

    // Recursively sort both halves
    mergeInsertionSortVector(smaller);
    mergeInsertionSortVector(larger);

    // Insert the elements from the larger half into the smaller half
    for (std::vector<int>::iterator it = larger.begin(); it != larger.end(); ++it) 
        binaryInsertVector(smaller, *it);

    // Copy sorted elements back to the original array
    arr.clear();
    arr.insert(arr.end(), smaller.begin(), smaller.end());
}

// Merge insertion sort for std::deque<int>
void mergeInsertionSortDeque(std::deque<int> &arr)
{
    int n = arr.size();
    if (n <= 1) return;

    std::deque<int> larger, smaller;
    for (int i = 0; i < n / 2; ++i)
    {
        if (arr[2 * i] < arr[2 * i + 1]) { // Compare two elements at a time the arr[2 * i] it means the first element of the pair and arr[2 * i + 1] is the second element of the pair
            smaller.push_back(arr[2 * i]); 
            larger.push_back(arr[2 * i + 1]);
        }
        else
        {
            smaller.push_back(arr[2 * i + 1]);
            larger.push_back(arr[2 * i]);
        }
    }

    if (n % 2 != 0)
        smaller.push_back(arr[n - 1]);

    // Recursively sort both halves
    mergeInsertionSortDeque(smaller);
    mergeInsertionSortDeque(larger);

    // Insert the elements from the larger half into the smaller half
    for (std::deque<int>::iterator it = larger.begin(); it != larger.end(); ++it)
        binaryInsertDeque(smaller, *it);

    // Copy sorted elements back to the original array
    arr.clear();
    arr.insert(arr.end(), smaller.begin(), smaller.end());
}

// Helper function to print a vector
void printVector(const std::vector<int> &vec) {
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

// Helper function to print a deque
void printDeque(const std::deque<int> &deq) {
    for (std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2)
    {
        std::cerr << "Error: No input provided." << std::endl;
        return 1;
    }

    // Vector container for first implementation
    std::vector<int> vecContainer;
    std::deque<int> dequeContainer;

    try
    {
        for (int i = 1; i < argc; ++i)
        {
            int num = std::atoi(argv[i]);
            if (num <= 0)
                throw std::invalid_argument("Error: Input must be a positive integer.");
            vecContainer.push_back(num);
            dequeContainer.push_back(num);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    // Display original inputs
    std::cout << "Original sequence (vector): ";
    printVector(vecContainer);
    
    std::cout << "Original sequence (deque): ";
    printDeque(dequeContainer);

    // Perform merge insertion sort on vector
    mergeInsertionSortVector(vecContainer);

    // Perform merge insertion sort on deque
    mergeInsertionSortDeque(dequeContainer);

    // Display sorted results
    std::cout << "Sorted sequence (vector): ";
    printVector(vecContainer);

    std::cout << "Sorted sequence (deque): ";
    printDeque(dequeContainer);

    return 0;
}
