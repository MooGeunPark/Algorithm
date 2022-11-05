n = int(input())
ans = 0

for _ in range(n):
  word = input()
  flag = 1
  for i in range(len(word) - 1):
    if word[i] != word[i + 1]:
      after = word[i + 1:]
      if after.count(word[i]) > 0:
        flag = 0
        break
  if flag:
    ans += 1

print(ans)
