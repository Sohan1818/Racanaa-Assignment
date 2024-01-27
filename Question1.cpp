#include <iostream>
#include <vector>
#include <algorithm>

bool canSwapToEqualizeSums(std::vector<int>& A, std::vector<int>& B, int m) {
    int sumA = 0, sumB = 0;
 // Calculate the sum of elements in arrays A and B

    for (int num : A)
    sumA += num;
    for (int num : B) 
    sumB += num;
 // Calculate the target difference needed to equalize the sums after swapping

    int targetDiff = (sumB - sumA) / 2;
//Sort both arrays
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        int diff = B[j] - A[i];
        if (diff == targetDiff)
 // If the difference equals the target difference, return true

            return true;
        else if (diff < targetDiff)
// If the difference is less than the target, move to the next element in B

            j++;
        else
// If the difference is greater than the target, move to the next element in A

            i++;
    }

    return false;
}

int main() {
    int m;
    cout << "Enter the value of m: ";
    cin >> m;

    int n;
    cout << "Enter the size of arrays A and B: ";
    cin >> n;

    vector<int> A(n);
    vector<int> B(n);

   cout << "Enter the elements of array A: ";
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    cout << "Enter the elements of array B: ";
    for (int i = 0; i < n; ++i)
        cin >> B[i];

    if (canSwapToEqualizeSums(A, B, m))
      cout << "There exists a swap operation to equalize the sums.\n";
    else
        cout << "No swap operation can equalize the sums.\n";

    return 0;
}

/*
Time Complexity: O(n log n)
Space Complexity: O(1)
*/