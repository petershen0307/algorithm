import time
import random


def selection_sort(in_list):
    for i in range(len(in_list)):
        s = i
        for j in range(i, len(in_list)):
            if in_list[s] > in_list[j]:
                s = j
        in_list[s], in_list[i] = in_list[i], in_list[s]


def quick_sort(in_list, start, end):
    if start >= end:
        return
    pivot_index = start
    pivot = in_list[pivot_index]
    i = start
    j = end
    while i <= j:
        if in_list[i] > pivot and in_list[j] < pivot:
            in_list[i], in_list[j] = in_list[j], in_list[i]
        if in_list[i] <= pivot:
            i += 1
        if in_list[j] >= pivot:
            j -= 1
    swap_index = min(i, j)
    in_list[pivot_index], in_list[swap_index] = in_list[swap_index], in_list[pivot_index]
    quick_sort(in_list, start, swap_index)
    quick_sort(in_list, swap_index + 1, end)


if '__main__' == __name__:
    test_list = [random.randint(1, 1000) for _ in range(1000)]
    start_time = time.time()
    selection_sort(test_list)
    end_time = time.time()
    print('times: {}'.format(end_time - start_time))

    test_list = [random.randint(1, 1000) for _ in range(1000)]
    start_time = time.time()
    quick_sort(test_list, 0, len(test_list) - 1)
    end_time = time.time()
    print('times: {}'.format(end_time - start_time))

    test_list = [random.randint(1, 1000) for _ in range(1000)]
    start_time = time.time()
    test_list.sort()
    [str(i) for i in test_list]
    end_time = time.time()
    print('times: {}'.format(end_time - start_time))
