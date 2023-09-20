# insertion sort

def insertion_sort(arr):
    comp = 0
    swap = 0
    n = len(arr)
    for i in range(n): # i는 알맞은 위치로 가야하는 숫자
        for j in range(i,0,-1): # i가 j의 위치에서 비교를 함
            comp = comp + 1
            if(arr[j] > arr[j-1]):
                break
            else:
                swaptemp = arr[j]
                arr[j] = arr[j-1]
                arr[j-1] = swaptemp
                swap = swap + 1
            
    return comp, swap

    
t = int(input()) # 테스트 케이스의 개수
for i in range(t):
    numbers = list(map(int,input().split()))  # 입력 받기
    n = numbers[0] # 배열의 크기
    arr = numbers[1:] # 정렬해야할 배열
    comp, swap = insertion_sort(arr)
    print(comp, swap)