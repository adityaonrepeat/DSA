def solve():
    n, k = map(int, input().split())
    for i in range(1, k+1):
        if (n%10 == 0):
            n//=10
        else:
            n-=1
 
    print(n)
 
if __name__ == "__main__":solve()
