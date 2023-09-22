# gcd
def gcd(a,b):
    if(b == 0):
        return a
    else :
        return gcd(b, a%b)
    
t = int(input()) # 테스트 케이스의 개수
for i in range(t):
    a,b = map(int, input().split())  # 입력 받기
    print(gcd(a,b))