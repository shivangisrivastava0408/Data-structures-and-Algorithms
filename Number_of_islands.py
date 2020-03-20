def numIslands(grid):
    x = 0
    if len(grid)==0 or grid==[]:
        return 0
    one,zero=0,0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j]=='1':
                one+=1
            elif grid[i][j]=='0':
                zero+=1
    if one==0:
        return 0
    elif zero==0:
        return 1
    
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j]=='1':
                x += dfs(grid,i,j)
    return x

def dfs(grid, i, j):
    if i<0 or i>=len(grid) or j<0 or j>=len(grid[i]) or grid[i][j]=='0':
        return 0
    grid[i][j]='0'
    dfs(grid,i+1,j)
    dfs(grid,i-1,j)
    dfs(grid,i,j+1)
    dfs(grid,i,j-1)
    return 1

if __name__ == '__main__':
    row = input().split()
    n = int(row[0])
    m = int(row[1])
    grid = []
    for i in range(n):
        r = input()
        grid.append(list(r))
    result = numIslands(grid)
    print(result)
