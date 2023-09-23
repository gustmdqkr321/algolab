# fibo
def fibo(n):
    if(n == 0):
        return 0
    elif(n == 1):
        return 1
    else:
        return fibo(n-2) + fibo(n-1)

    
t = int(input()) # 테스트 케이스의 개수
for i in range(t):
    n = int(input())  # 입력 받기
    print(fibo(n))