#100 -> '*', 105 -> '#'
#keypad = [[1,2,3], [4,5,6], [7,8,9], [100,0,105]]
left = (3,0)
right = (3,2)

left_list = [1, 4, 7]
left_pos = [(0,0), (1,0), (2,0)]

right_list = [3, 6, 9]
right_pos = [(0,2), (1,2), (2,2)]

mid_list = [2, 5, 8, 0]
mid_pos = [(0,1), (1,1), (2,1), (3,1)]

def getDist(pair_a, pair_b) :
    return abs(pair_a[0] - pair_b[0]) + abs(pair_a[1]-pair_b[1])

def Decide_hand(target, hand) :
    global left, right
    global left_list, left_pos
    global mid_list, mid_pos
    global right_list, right_pos
    
    #Case 1 : 무조건 왼손 엄지로 눌러야 하는 경우
    for idx, elem in enumerate(left_list) :
        if target == elem : 
            left = left_pos[idx]
            return 'L'
    
    #Case 2 : 무조건 오른손 엄지로 눌러야 하는 경우
    for idx, elem in enumerate(right_list) :
        if target == elem : 
            right = right_pos[idx]
            return 'R'
    
    #Case 3 : 거리로 왼손, 오른손 결정하는 경우
    for idx, elem in enumerate(mid_list) :
        if elem == target :
            if getDist(left, mid_pos[idx]) < getDist(right, mid_pos[idx]) :
                left = mid_pos[idx]
                return 'L'
            elif getDist(left, mid_pos[idx]) == getDist(right, mid_pos[idx]) :
                if hand == "right" :
                    right = mid_pos[idx]
                    return 'R'
                else : 
                    left = mid_pos[idx]
                    return 'L'
            else :
                right = mid_pos[idx]
                return 'R'
            
def solution(numbers, hand):
    answer = ''
    for num in numbers :
        answer += Decide_hand(num, hand)
        
    return answer
