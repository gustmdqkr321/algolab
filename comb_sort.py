# comb sort
def comb_sort(arr):
    comp = 0
    swap = 0
    n = len(arr)
    gap = n
    sorted = False # 정렬이 완료됬는지 체크
    while(sorted == False): # 완료 될때까지 진행
        gap = int(gap/1.3) # gap의 갱신
        if(gap <= 1): # gap이 1보다 작아지면(버블소트와 동일, gap : 1)
            gap = 1
            sorted = True
        for i in range(0,n-gap): # 한번의 pass는 전체 개수에서 gap을 뺀만큼 연산함
            comp = comp + 1
            if(arr[i] > arr[i+gap]):
                temp = arr[i]
                arr[i] = arr[i+gap]
                arr[i+gap] = temp
                swap = swap + 1
                sorted = False
            
        
    return comp, swap

    
t = int(input()) # 테스트 케이스의 개수
for i in range(t):
    numbers = list(map(int,input().split()))  # 입력 받기
    n = numbers[0] # 배열의 크기
    arr = numbers[1:] # 정렬해야할 배열
    comp, swap = comb_sort(arr)
    print(comp, swap)