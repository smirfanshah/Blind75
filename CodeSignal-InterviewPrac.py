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

def solution3(roadA, roadB):
    
    result = [] 
    for i in range(len(roadA)):
        indexA = i
        distance = 0
        visitedA = set()
        visitedB = set()
        
        for j in range(len(roadB)):
            if indexA in visitedA:
                break
            visitedA.add(indexA)
            distance += 1
            indexB = roadA[indexA]
            if indexB in visitedB:
                break
            visitedB.add(indexB)
            distance += 1
            indexA = roadB[indexB]
        result.append(distance)
    
    return result
            
            
def solution4(numbers):
    new_numbers = []
    for num in numbers:
        new_numbers.append(num + 1 if num % 10 != 0 else 1)
    
    freq = {} 
    for num in new_numbers:
        if num in freq:
            freq[num] += 1
        else:
            freq[num] = 1
    
    result = []
    for num in set(new_numbers):
        result.append(num * freq[num])
    
    result.sort()
    
    return result


def solution5(s): #Freq 2
    freq_dict = {}
    for letter in set(s):
        minus = ord(letter) - 3
        if minus >= ord('a'):
            num_rep = minus * s.count(letter)
        else:
            num_rep = (minus + 26) * s.count(letter)
        
        freq_dict[letter] = num_rep
        
    return freq_dict


def solution6(sentence):
    new_s = ""
    for letter in sentence:
        s = ord(letter)
        
        if letter.isalnum():
                
            if s == ord('0'):
                s += 10
            elif s == ord('A'):
                s += 26
            elif s == ord('a'):
                s += 26
            
            s-=1
            new_s += chr(s)
    
    result = []
    for letter in set(new_s):
        res = abs(ord(letter) - new_s.count(letter))
        result.append(res)
    result.sort()
    return result





def solution7(inputString, numbers):
    """You are given a string of length at most 100 and an array of at most 100 integers. The task requires you to process both the string and the array simultaneously from their first elements, and continue as long as certain condition on the array is satisfied. Return the modified string and certain portion of the original array.

    For the string, your goal is to replace every occurrence of a vowel with the next vowel in the sequence, wrapping around from 'u' to 'a'. If the character is a consonant, it should be replaced with the next consonant in alphabetical order, wrapping around from 'z' to 'b'.

    Meanwhile, for the array of integers, you are instructed to multiply each integer by 3 and add the result to a total until that total reaches or exceeds 100. Each integer in the array can range from
    50 to 50, inclusive.

    Finally, return the modified string and any unprocessed integers from the array in their original order.

    Stop processing when the total sum, restricted to 100, is met or when all elements have been processed. In other words, process both the string and the array while the condition holds true.

    If you process all elements in the array and the string, and the total sum still has not reached 100, simply return the processed string and an empty list.
    Consider using Python's built-in functions such as ord(), chr(), and round() to aid in achieving this.

    The final return format should be a tuple containing the modified string and the list of unprocessed integers.

    Example:

    Input:

    String: "examplestring"
    Array: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}"""



    vowels = 'aeiou'
    consonants = 'bcdfghjklmnpqrstvwxyz'
    total= 0
    result = ''
    for ch in inputString:
        if not numbers:
            break
            
        if ch in vowels:
            result += vowels[(vowels.index(ch)+1) %len(vowels)]
        else:
            result += consonants[(consonants.index(ch)+1) %len(consonants)]
        
        total += numbers[0]*3
            
        numbers.pop(0)
        if total>=100:
            break
        
    return result, numbers
        
                    
def solution8(arr, text):
    accumlator = 0
    res_text=''
    for char in text:
        num = arr[0]
        accumlator += abs(num-3)
        if(accumlator>30):
            break
        arr.pop(0)
        if ord(char)<(ord('a')+26) and ord(char)>=ord('a'):
            res_text+=chr(((ord(char)-ord('a')+1)%26)+ord('a'))
        else:
            res_text+=char
        
    return res_text, arr


import math
def solution9(dungeon, health):
    """
    You are given an array representing a dungeon where each element indicates the health points lost (negative value) or gained (positive value) at that position. You start with a certain amount of health points and can choose a step size to navigate through the dungeon. Your goal is to find the optimal step size that allows you to traverse the dungeon without your health dropping to zero or below, while minimizing the total health lost.
    """
    best_health=math.inf
    optimal_step=0
    
    for step in range(1, len(dungeon)+1):
        health_loss=0
        exit = False
        for i in range(0, len(dungeon),step):
            health_loss+= dungeon[i]
            if health_loss>health:
                exit = True
                break
        if not exit and health_loss<best_health:
            optimal_step = step
            best_health = health_loss
    
    if optimal_step:
        return optimal_step
    else:
        return -1
    

def solution10(garden, start, direction):
    """You are given a circular garden represented as an array of integers, where each integer represents a type of flower. You start at a specific position in the garden and can move in either a clockwise or counterclockwise direction. Your goal is to find the largest step size that allows you to visit all types of flowers in the garden at least once."""
    all_flowers = set(garden)
    n = len(garden)
    valid_steps = []

    path = garden[:]

    if direction == -1:
        path.reverse()
        start = n - 1 - start

    for step in range(1, n + 1):
        visited = set()

        for i in range(start, n, step):
            visited.add(path[i])
            if len(visited) == len(all_flowers):
                valid_steps.append(step)
                break

    return valid_steps[-1] if valid_steps else -1


# def main():
#     dungeon = [0, -1, 1, 0, -1]
#     health = 3
#     step= solution(dungeon, health)
#     print("Optimal Step:", step)
#     # if result == expected_output:
#     #     print("Test passed!")
#     # else:
#     #     print("Test failed.")


# # Call main
# if __name__ == "__main__":
#     main()