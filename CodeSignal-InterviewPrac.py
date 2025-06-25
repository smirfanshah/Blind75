def solution(arrayA, arrayB):
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
    
    result = solution(arrayA, arrayB)
    print("Output:", result)
    
    if result == expected_output:
        print("Test passed!")
    else:
        print("Test failed.")

# Call main
if __name__ == "__main__":
    main()
