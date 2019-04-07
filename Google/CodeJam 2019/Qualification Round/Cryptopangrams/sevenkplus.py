def gcd(a, b):
	while b != 0:
		a, b = b, a%b
	return a
T = int(input())
for t in range(T):
	N, L = map(int, input().split())
	a = list(map(int, input().split()))
	p = [0]*(L+1)
	for i in range(L-1):
		c = gcd(a[i], a[i+1])
		if c != a[i] and c != a[i+1]:
			p[i+1] = c
	for i in range(L):
		if p[i] != 0 and p[i+1] == 0:
			p[i+1] = a[i] // p[i]
	for i in range(L, 0, -1):
		if p[i] != 0 and p[i-1] == 0:
			p[i-1] = a[i-1] // p[i]
	b = sorted(set(p))
	d = dict()
	for i in range(26):
		d[b[i]] = chr(ord('A') + i)
	s = ""
	for i in p:
		s += d[i]
	print("Case #" + str(t+1) + ": " + s)