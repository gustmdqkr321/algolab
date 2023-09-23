# 피보나치(double squaring)
def fibo(n, arr):
    if(n <= 1):
        return n
    else :
        arr = divide(n,arr)
    return arr[0][1]

def divide(n, arr):
    if(n > 1):
        arr = divide(n//2, arr)
        arr = multi(arr, arr)
        if(n % 2 == 1):
            arr_base = [[1,1],[1,0]]
            arr  = multi(arr,arr_base)
    return arr       
def multi(arr,arr2):
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