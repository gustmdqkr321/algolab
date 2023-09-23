# 거듭제곱(double squaring)
def p(a,b):
    if(b == 0):
        return 1
    elif(b%2 == 1):
        y =  p((a*a)%1000, (b-1)/2) # 3개만 출력하기 때문에 1000으로 나눈 나머지를 계속 곱해도 마지막 3자리는 안바뀜
        return (a%1000)*y%1000 # 1000으로 나눈 나머지는 항상 마지막 3자리이기 때문
    else :
        y = p((a*a)%1000, b/2)
        return y%1000
       
    
t = int(input()) # 테스트 케이스의 개수
for i in range(t):
    a,b = map(int, input().split()) # 입력 받기
    str_sol = str(p(a,b))
    print(str_sol[-3::]) # 마지막부터 3개만 출력