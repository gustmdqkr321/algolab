import sys
sys.setrecursionlimit(10**6)

# factorial
def factorial(n, TR = 1):
    if(n <= 1):
        return TR
    else:
        return factorial(n-1, n*TR)

    
t = int(input()) # 테스트 케이스의 개수
for i in range(t):
    n = int(input())  # 입력 받기
    sol = factorial(n)
    str_sol = str(sol)
    first = False
    if(len(str_sol) > 3): # 계산 결과가 3자리보다 작으면 0을 제거할 필요가 없음
        last_three = "" # 여기에 3자리 추가
        count = 1 
        for digit in reversed(str_sol): # str으로 바꾼 계산결과의 뒤에서부터 탐색
            if(digit != "0"):  # 0이 아닌게 나오면 3개 세기 시작
                first = True
            if(first == True):
                last_three = last_three + digit # 뒤에서부터 그대로 추가
                count = count + 1
            if(count == 4): # 3개가 더해지면 정지
                break
        print(last_three[::-1]) # 뒤에서부터 추가한 정답 반대로 출력
    else :
        print(str_sol)