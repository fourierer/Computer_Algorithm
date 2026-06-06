"""
冒泡排序
时间复杂度：平均 O(n²)，最坏 O(n²)，最好 O(n)（已有序时）
空间复杂度：O(1)
稳定性：稳定（相邻元素交换，相等元素不会改变相对顺序）
"""


def bubble_sort(arr: list[int]) -> list[int]:
    n = len(arr)
    # 外层循环：n 轮，每轮将最大值「冒泡」到末尾
    for i in range(n):
        # 内层循环：比较相邻元素，大的往后冒泡
        for j in range(n - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr


if __name__ == "__main__":
    assert bubble_sort([5, 3, 8, 4, 2]) == [2, 3, 4, 5, 8]
    assert bubble_sort([1, 2, 3, 4, 5]) == [1, 2, 3, 4, 5]
    assert bubble_sort([]) == []
    assert bubble_sort([1]) == [1]
    print("All tests passed!")