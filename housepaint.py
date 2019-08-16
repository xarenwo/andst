def minCost(cost, currenthouse, color, cache):
    if cache[currenthouse][color] is not -1:
        return cache[currenthouse][color]
    if currenthouse == len(cost): # If the current house is the last one, it means we succesfully painted it with all colors so return cost as 0
        return 0
    if color == 0:
        # I start from red root, so children will be blue and green
        bluechildcost = minCost(cost,currenthouse+1,1,cache) #candidate 1
        greenchildcost = minCost(cost,currenthouse+1,2,cache) #candidate 2
        sol = cost[currenthouse][color] + min(bluechildcost,greenchildcost) # Return the best alternative in terms of minimum cost from the 2 children
        cache[currenthouse][color] = sol
        return sol
    if color == 1:
        # I start from blue root, so children will be red and green
        redchildcost = minCost(cost,currenthouse+1,0,cache) #candidate 1
        greenchildcost = minCost(cost,currenthouse+1,2,cache) #candidate 2
        sol = cost[currenthouse][color] + min(redchildcost,greenchildcost) # Return the best alternative in terms of minimum cost from the 2 children
        cache[currenthouse][color] = sol
        return sol
    if color == 2:
        # I start from green root, so children will be red and blue
        redchildcost = minCost(cost, currenthouse + 1, 0,cache) #candidate 1
        bluechildcost = minCost(cost, currenthouse + 1, 1,cache)  #candidate 2
        sol =  cost[currenthouse][color] + min(redchildcost,bluechildcost) # Return the best alternative in terms of minimum cost from the 2 children
        cache[currenthouse][color] = sol
        return sol

    return 0 # return 0 by default otherwise


cost = [
        [17,2,17],
        [16,16,5],
        [14,3,9],
        [17,3,9]
       ]

def PaintHouse(cost):
    cache = [[-1 for _ in range(len(cost)+1)] for _ in range(len(cost)+1)]
    print(cache)
    redroot = minCost(cost,0,0,cache) # min cost if first house is painted red
    blueroot = minCost(cost,0,1,cache) # min cost if first house is painted blue
    greenroot = minCost(cost,0,2,cache) # min cost if first house is painted green
    bestchoice = min(redroot,min(greenroot,blueroot)) # calculate minimum cost if we paint the first house in any of the 3 colors
    print(cache)
    return bestchoice



# print("Min cost is {}".format(PaintHouse(cost)))

def minPaint(cost):
    colors = [0,1,2]
    table = [[0 for _ in range(len(cost))] for _ in range(len(cost)+1)]
    print(table)
    for i in range(1,len(cost)+1):
        for j in range(0,len(cost)):

            table[i][0] = cost[i-1][0]+min(table[i-1][1],table[i-1][2])
            table[i][1] = cost[i-1][1]+min(table[i-1][0],table[i-1][2])
            table[i][2] = cost[i-1][2]+min(table[i-1][1],table[i-1][0])

    result = min([table[len(cost)][colors[i]] for i in range(0,len(colors))])
    print(table)
    print("Result is {}".format(result))


minPaint(cost)
