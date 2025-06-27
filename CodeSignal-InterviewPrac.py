def solution1(arrayA, arrayB):
    indexA = 0
    indexB = 0
    visited = []
    indicesofB = []
    
    while True:
        indexB = arrayA[indexA]-1
        visited.append(indexA)
        indicesofB.append(indexB+1)
        indexA = arrayB[indexB]-1
        if indexA in visited:
            return indicesofB
        


def main():
    arrayA = [1, 3, 2, 5, 4]
    arrayB = [5, 4, 3, 2, 1]
    expected_output = [1, 4, 3, 2, 5]
    
    result = solution1(arrayA, arrayB)
    print("Output:", result)
    
    if result == expected_output:
        print("Test passed!")
    else:
        print("Test failed.")

def solution2(arrayA, arrayB, arrayC):
    indexA = 0
    indicesB = set()
    indicesC = set()
    maxB = 0
    maxC = 0 
    while True:
        if indexA >= len(arrayA):
            return maxB + maxC
        
        indexB = arrayA[indexA]
        if indexB in indicesB or indexB >= len(arrayA):
            return maxB + maxC
        indicesB.add(indexB)
            
        indexA = arrayB[indexB]
        maxB= max(maxB,indexA)

        if indexA >= len(arrayA):
            return maxB + maxC
        
        indexC = arrayA[indexA]
        if indexC in indicesC or indexC >= len(arrayA):
            return maxB + maxC
        indicesC.add(indexC)
        indexA = arrayC[indexC]
        maxC= max(maxC,indexA)

def main():
    arrayA = [2, 1, 3, 0]
    arrayB = [1, 3, 2, 4]
    arrayC = [4, 2, 5, 1]
    expected_output= 7
    result = solution2(arrayA, arrayB, arrayC)
    print("Output:", result)
    
    if result == expected_output:
        print("Test passed!")
    else:
        print("Test failed.")


# Call main
if __name__ == "__main__":
    main()
