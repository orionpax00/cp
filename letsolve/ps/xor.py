n = input();
k = input();
x = str(input());

ans = ""

for c in x:
    if c == '0' and k > 0:
        ans += '1'
        k -= 1
    else:
        ans += '0'

print(ans)
"""
print(n)
print(k)
print(x)
print(type(n))
print(type(k))
print(type(x))"""
