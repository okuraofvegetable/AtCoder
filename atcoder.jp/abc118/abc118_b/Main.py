N,M = [int(i) for i in input().split()]
food = list();
for i in range(M):
	food.append(0)
for i in range(N):
	a = list(map(int,input().split()));
	for j in range(a[0]):
		food[a[j+1]-1] += 1
ans = 0
for i in range(M):
	if food[i]==N:
		ans += 1
print(ans)