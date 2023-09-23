# selection sort

def selection_sort(arr):
    comp = 0
    swap = 0
    n = len(arr)
    for i in range(0,n): # 가장 작은 값을 고르는 것은 배열의 크기 만큼 해야함
        index = i # 최솟값의 인덱스
        for j in range(i+1,n):
            comp = comp + 1
            if(arr[j] < arr[index]) :
                index = j
        if(index != i): # index와 i가 같다는 의미는 최솟값이 바뀌지 않았다는 뜻, 교환 x
            temp = arr[index] 
            arr[index] = arr[i]
            arr[i] = temp
            swap = swap + 1
    return comp, swap

    
t = int(input()) # 테스트 케이스의 개수
for i in range(t):
    numbers = list(map(int,input().split()))  # 입력 받기
    n = numbers[0] # 배열의 크기
    arr = numbers[1:] # 정렬해야할 배열
    comp, swap = selection_sort(arr)
    print(comp, swap)