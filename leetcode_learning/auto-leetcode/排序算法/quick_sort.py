"""
快速排序
时间复杂度：平均 O(n log n)，最坏 O(n²)（数组已有序且每次选首元素为 pivot）
空间复杂度：O(log n)（递归栈深度，平均情况）
稳定性：不稳定（partition 时跨距离交换元素）
"""


def quick_sort(arr: list[int]) -> list[int]:
    _solve(arr, 0, len(arr) - 1)
    return arr


def _solve(arr: list[int], start: int, end: int) -> None:
    if start >= end:
        return

    # 取最左元素为 pivot
    i, j = start, end
    pivot = arr[i]

    # 左右指针交替扫描，将比 pivot 小的放左边，大的放右边
    while i < j:
        # 从右往左找第一个比 pivot 小的
        while arr[j] >= pivot and j > i:
            j -= 1
        arr[i], arr[j] = arr[j], arr[i]

        # 从左往右找第一个比 pivot 大的
        while arr[i] <= pivot and i < j:
            i += 1
        arr[i], arr[j] = arr[j], arr[i]

    # pivot 已归位到位置 i，递归排序两侧
    _solve(arr, start, i - 1)
    _solve(arr, i + 1, end)


if __name__ == "__main__":
    assert quick_sort([5, 3, 8, 4, 2]) == [2, 3, 4, 5, 8]
    assert quick_sort([1, 2, 3, 4, 5]) == [1, 2, 3, 4, 5]
    assert quick_sort([]) == []
    assert quick_sort([1]) == [1]
    print("All tests passed!")