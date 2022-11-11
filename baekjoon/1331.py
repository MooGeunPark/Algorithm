list = [input() for _ in range(36)]
graph = [[0 for _ in range(6)] for _ in range(6)]
ax, ay = ord(list[0][0]) - 65, int(list[0][1]) - 1
graph[ax][ay] = 1
flag = True

if abs(ord(list[0][0]) - ord(list[-1][0])) == 2 and abs(int(list[0][1]) - int(list[-1][1])) == 1 or abs(ord(list[0][0]) - ord(list[-1][0])) == 1 and abs(int(list[0][1]) - int(list[-1][1])) == 2:
  for i in range(1, 36):
    bx, by = ord(list[i][0]) - 65, int(list[i][1]) - 1
    if abs(ax - bx) == 1 and abs(ay - by) == 2 or abs(ax - bx) == 2 and abs(ay - by) == 1:
      graph[bx][by] += 1
      if graph[bx][by] != 1:
        flag = False
        break
    else:
      flag = False
      break
    ax, ay = bx, by
else:
  flag = False

if flag:
  print("Valid")
else:
  print("Invalid")
