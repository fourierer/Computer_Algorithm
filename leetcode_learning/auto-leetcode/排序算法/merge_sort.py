"""
归并排序
时间复杂度：始终 O(n log n)（分割 log n 层，每层合并 O(n)）
空间复杂度：O(n)（需要临时数组存放合并结果）
稳定性：稳定（合并时左边优先，相等元素保持原顺序）
"""


def merge_sort(arr: list[int]) -> list[int]:
    _solve(arr, 0, len(arr) - 1)
    return arr


def _solve(arr: list[int], left: int, right: int) -> None:
    if left >= right:
        return

    mid = (left + right) // 2
    # 递归排序左半部分和右半部分
    _solve(arr, left, mid)
    _solve(arr, mid + 1, right)
    # 合并两个有序子数组
    _merge(arr, left, mid, right)


def _merge(arr: list[int], left: int, mid: int, right: int) -> None:
    # 临时数组存放合并结果
    b = [0] * (right - left + 1)
    i, j, k = left, mid + 1, 0

    # 双指针比较，取较小的放入临时数组
    while i <= mid and j <= right:
        if arr[i] <= arr[j]:
            # <= 保证稳定性：相等时左半部分优先
            b[k] = arr[i]
            i += 1
        else:
            b[k] = arr[j]
            j += 1
        k += 1

    # 拼接左半部分剩余元素
    while i <= mid:
        b[k] = arr[i]
        i += 1
        k += 1

    # 拼接右半部分剩余元素
    while j <= right:
        b[k] = arr[j]
        j += 1
        k += 1

    # 将合并结果拷贝回原数组
    for i in range(k):
        arr[left + i] = b[i]


if __name__ == "__main__":
    assert merge_sort([5, 3, 8, 4, 2]) == [2, 3, 4, 5, 8]
    assert merge_sort([1, 2, 3, 4, 5]) == [1, 2, 3, 4, 5]
    assert merge_sort([]) == []
    assert merge_sort([1]) == [1]
    print("All tests passed!")