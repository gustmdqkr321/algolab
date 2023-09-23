# 피보나치(double squaring)
def fibo(n, arr):
    if(n <= 1):
        return n
    else :
        arr = divide(n,arr)
    return arr[0][1]

def divide(n, arr): # 행렬을 2개의 행렬의 곱으로 계속 나누기 위함
    if(n > 1): # 지수가 1이 될때까지 나눔
        arr = divide(n//2, arr) # 지수가 짝수면 반반으로 나누고
        arr = multi(arr, arr) # 나눈 2개를 곱해서 동일해짐
        if(n % 2 == 1): # 짝수면 위에서 나누고 곱한 값에 기본 행렬을 곱함
            arr_base = [[1,1],[1,0]]
            arr  = multi(arr,arr_base)
    return arr       
def multi(arr,arr2): # 행렬 곱하는 함수
    mul_arr = [[0,0],[0,0]]
    mul_arr[0][0] = ((arr[0][0] * arr2[0][0]) + (arr[0][1] * arr2[1][0])) % 1000
    mul_arr[0][1] = ((arr[0][0] * arr2[0][1]) + (arr[0][1] * arr2[1][1])) % 1000
    mul_arr[1][0] = ((arr[1][0] * arr2[0][0]) + (arr[1][1] * arr2[1][0])) % 1000
    mul_arr[1][1] = ((arr[1][0] * arr2[0][1]) + (arr[1][1] * arr2[1][1])) % 1000
    return mul_arr


t = int(input()) # 테스트 케이스의 개수
for i in range(t):
    n = int(input())
    arr_base = [[1,1],[1,0]]
    print(fibo(n,arr_base)%1000)