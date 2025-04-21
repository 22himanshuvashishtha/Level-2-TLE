if (matrix.empty() || matrix[0].empty()) return false;

    int rows = matrix.size();
    int cols = matrix[0].size();
    int low = 0, high = rows * cols - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int value = matrix[mid / cols][mid % cols];  // convert 1D index to 2D
        if (value == target) return true;
        else if (value < target) low = mid + 1;
        else high = mid - 1;
    }

    return false;
}
