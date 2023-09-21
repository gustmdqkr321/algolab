# shell sort

def shell_sort(arr):
    comp = 0
    swap = 0
    n = len(arr)
    gap = int(n//2)
    while(gap > 0):
        for i in range(gap,n): # gap부터 시작 마지막 숫자 까지
            for j in range(i,gap-1,-gap): # gap만큼 앞에 있는 숫자들과 insertion하기 위한 인덱스
                comp = comp + 1
                if(arr[j] >= arr[j-gap]): 
                    break
                else:
                    swaptemp = arr[j]
                    arr[j] = arr[j-gap]
                    arr[j-gap] = swaptemp
                    swap = swap + 1
              
        gap = int(gap//2)
            
    return comp, swap

    
t = int(input()) # 테스트 케이스의 개수
for i in range(t):
    numbers = list(map(int,input().split()))  # 입력 받기
    n = numbers[0] # 배열의 크기
    arr = numbers[1:] # 정렬해야할 배열
    comp, swap = shell_sort(arr)
    print(comp, swap)