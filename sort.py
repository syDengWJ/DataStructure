def insertion_sort(num):
    for j in range(1, len(num)):
        key = num[j]
        i = j - 1
        while i >= 0 and num[i] > key:
            num[i + 1] = num[i]
            i -= 1
        num[i + 1] = key
    return num


def selection_sort(num):
    for i in range(0, len(num) - 1):
        key = i
        for j in range(i + 1, len(num)):
            if num[j] < num[key]:
                key = j
        if i != key:
            tmp = num[i]
            num[i] = num[key]
            num[key] = tmp
    return num


def bubble_sort(num):
    for i in range(0, len(num) - 1):
        for j in range(len(num) - 2, i - 1, -1):
            if num[j] > num[j + 1]:
                tmp = num[j]
                num[j] = num[j + 1]
                num[j + 1] = tmp
    return num


def bubble_sort2(num):
    flag = True
    for i in range(0, len(num)):
        if flag:
            flag = False
            for j in range(len(num)-2, i-1, -1):
                if num[j] > num[j + 1]:
                    tmp = num[j]
                    num[j] = num[j + 1]
                    num[j + 1] = tmp
                    flag = True
    return num


def shell_sort(num):
    increase = len(num)
    while increase > 1:
        increase = increase // 3 + 1
        for i in range(increase + 1, len(num)):
            if num[i] < num[i - increase]:
                buff = num[i]
                j = i - increase
                while True:
                    num[j + increase] = num[j]
                    j -= increase
                    if j < 0 or buff >= num[j]:
                        break
                num[j + increase] = buff
    return num


def parent(i):
    return i // 2


def left(i):
    return 2 * (i + 1) - 1


def right(i):
    return 2 * (i + 1)


def max_heapify(num, i, size):
    l = left(i)
    r = right(i)
    if l <= size - 1 and num[l] > num[i]:
        largest = l
    else:
        largest = i
    if r <= size - 1 and num[r] > num[largest]:
        largest = r
    if largest != i:
        tmp = num[largest]
        num[largest] = num[i]
        num[i] = tmp
        max_heapify(num, largest, size)


def build_max_heap(num, size):
    for i in range((size - 1) // 2, -1, -1):
        max_heapify(num, i, size)


def heap_sort(num):
    size = len(num)
    build_max_heap(num, size)
    for i in range(size - 1, 0, -1):
        tmp = num[0]
        num[0] = num[i]
        num[i] = tmp
        size -= 1
        max_heapify(num, 0, size)
    return num


def partition(num, p, r):
    x = num[r]
    i = p - 1
    for j in range(p, r):
        if num[j] <= x:
            i += 1
            tmp = num[i]
            num[i] = num[j]
            num[j] = tmp
    tmp = num[i+1]
    num[i+1] = num[r]
    num[r] = tmp
    return i+1


def quick_sort(num, p, r):
    if p < r:
        q = partition(num, p, r)
        quick_sort(num, p, q-1)
        quick_sort(num, q+1, r)
    return num


def merge(num, p, q, t):
    n1 = q - p + 1
    n2 = t - q
    l = []
    r = []
    for i in range(0, n1):
        l.append(num[p + i])
    for j in range(0, n2):
        r.append(num[q + j + 1])
    l.append(10000)
    r.append(10000)
    i = 0
    j = 0
    for k in range(p, t + 1):
        if l[i] <= r[j]:
            num[k] = l[i]
            i += 1
        else:
            num[k] = r[j]
            j += 1


def merge_sort(num, p, t):
    if p < t:
        q = (p + t - 1) // 2
        merge_sort(num, p, q)
        merge_sort(num, q + 1, t)
        merge(num, p, q, t)
    return num


def test():
    ls = [12, 21, 56, 65, 78, 89, 6, 4, 9, 2, 1]
    print(' Before sort: ')
    print(ls)
    print(' Insertion sort: ')
    print(insertion_sort(ls))
    ls.reverse()
    print(' Selection sort: ')
    print(insertion_sort(ls))
    ls.reverse()
    print(' Bubble sort: ')
    print(bubble_sort(ls))
    ls.reverse()
    print(' Bubble sort2: ')
    print(bubble_sort2(ls))
    ls.reverse()
    print(' Shell sort: ')
    print(shell_sort(ls))
    ls.reverse()
    print(' Heap sort: ')
    print(heap_sort(ls))
    ls.reverse()
    print(' Quick sort: ')
    print(quick_sort(ls, 0, len(ls) - 1))
    ls.reverse()
    print(' Merge sort: ')
    print(merge_sort(ls, 0, len(ls) - 1))


if __name__ == "__main__":
    test()
