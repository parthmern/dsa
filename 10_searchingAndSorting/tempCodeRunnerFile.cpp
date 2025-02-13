 int start = 0;
    int end = arr.size() - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] < arr[mid + 1]) {
            // Right side, move start to mid + 1
            start = mid + 1;
        } else {
            // Left side, or the peak could be mid, so move end to mid
            end = mid;
        }
    }

    // At the end of the loop, start == end, which points to the peak
    return start;